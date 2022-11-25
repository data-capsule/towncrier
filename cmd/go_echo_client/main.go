package main

import (
	"bufio"
	"bytes"
	"context"
	"io"
	"log"
	"os"
	"os/exec"
	"time"
	"towncrier/pkg/network"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

func main() {
	args := os.Args
	if !(len(args) == 4 || len(args) >= 6) {
		log.Fatalln("Usage: ./client name remote_name towncrier_addr:port [-- cmd arg1 arg2 ...]")
	}
	var cmdStdin io.WriteCloser
	var cmdStdout io.ReadCloser
	runningCmd := false

	if len(args) > 4 {
		if args[4] != "--" {
			log.Fatalln("Usage: ./client name remote_name towncrier_addr:port [-- cmd arg1 arg2 ...]")
		}
		cmd := exec.Command(args[5], args[6:]...)
		stdin, err := cmd.StdinPipe()
		if err != nil {
			log.Fatalln(err)
		}
		cmdStdin = stdin
		stdout, err := cmd.StdoutPipe()
		if err != nil {
			log.Fatalln(err)
		}
		cmdStdout = stdout
		cmd.Stderr = os.Stderr

		err = cmd.Start()
		if err != nil {
			log.Fatalln(err)
		}
		runningCmd = true
	}

	name := args[1]
	remote_name := args[2]
	addr := args[3]

	var opts []grpc.DialOption
	var call_opts []grpc.CallOption

	opts = append(opts, grpc.WithTransportCredentials(insecure.NewCredentials()))

	conn, err := grpc.Dial(addr, opts...)
	if err != nil {
		log.Fatalln(err)
	}

	defer conn.Close()

	client := network.NewNetworkExchangeClient(conn)
	sender, err := client.Send(context.Background(), call_opts...)
	if err != nil {
		log.Fatalln(err)
	}

	req_cnt := 0
	res_cnt := 0

	go func() {
		receiver, err := client.Recv(context.Background(), &network.SYN{
			Name: name,
		}, call_opts...)

		if err != nil {
			log.Fatalln(err)
		}

		for {
			msg, err := receiver.Recv()
			if err != nil {
				if err != io.EOF {
					log.Println(err)
					return
				}

			} else {

				if !runningCmd {
					log.Printf("%+v\n", msg)
				} else {
					__msg := bytes.Join(msg.GetMsg(), []byte(" "))
					cmdStdin.Write(__msg)
				}

				res_cnt++
			}
		}
	}()

	inReader := bufio.NewReader(os.Stdin)
	var s []byte
	outReader := bufio.NewReader(cmdStdout)
	for {
		if !runningCmd {
			s, err = inReader.ReadBytes('\n')
			if len(s) >= 1 {
				s = s[:len(s)-1]
			}
			if err != nil {
				log.Println(err)
				break
			}

		} else {
			s, err = outReader.ReadBytes('\n')
			if len(s) >= 1 {
				s = s[:len(s)-1]
			}
			if err != nil {
				log.Println(err)
				break
			}
		}

		__msg := bytes.Split(s, []byte(" "))

		sender.Send(&network.PDU{
			FwdNames: []string{remote_name},
			Origin:   name,
			Sender:   name,
			Msg:      __msg,
		})
		req_cnt++

	}

	log.Println("End of Input")
	for req_cnt > res_cnt {
		time.Sleep(1 * time.Second)
	}
	log.Fatalln("All responses received")

}
