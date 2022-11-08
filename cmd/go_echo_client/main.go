package main

import (
	"context"
	"fmt"
	"io"
	"log"
	"os"
	"towncrier/pkg/network"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

func main() {
	args := os.Args
	if len(args) != 4 {
		log.Fatalln("Usage: ./client name remote_name towncrier_addr:port")
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
				log.Printf("%+v\n", msg)
			}
		}
	}()

	var s string
	for {
		fmt.Scanf("%s", &s)
		sender.Send(&network.PDU{
			FwdNames: []string{remote_name},
			Sender:   name,
			Msg:      []byte(s),
		})

	}

}
