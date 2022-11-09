package main

import (
	"bufio"
	"context"
	"io"
	"log"
	"os"
	"os/exec"
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
					cmdStdin.Write(msg.GetMsg())
				}
			}
		}
	}()

	inReader := bufio.NewReader(os.Stdin)
	var s []byte
	for {
		if !runningCmd {
			s, err = inReader.ReadBytes('\n')
			if err != nil {
				log.Fatalln(err)
			}

		} else {
			n, err := cmdStdout.Read(s)
			if err != nil {
				log.Fatalln(err)
			}
			if n == 0 {
				continue
			}
		}
		sender.Send(&network.PDU{
			FwdNames: []string{remote_name},
			Sender:   name,
			Msg:      s,
		})

	}

}
