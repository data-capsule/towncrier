package network

import (
	"context"
	"errors"
	"io"
	"log"

	grpc "google.golang.org/grpc"
)

/* IMPORTANT: Create topology such that clients don't send redundant messages */

type ClientProxy struct {
	Name        string
	Addr        string
	IsConnected bool
	Client      NetworkExchangeClient
}

type Exchange struct {
	Locals        map[string]chan *PDU   // fwd_name => client
	Remotes       map[string]ClientProxy // sender => client
	Self_name     string
	Client_ctx    []context.Context
	Client_cancel []context.CancelFunc

	UnimplementedNetworkExchangeServer
}

const (
	FIN_MAGIC = int64(0xdeadbeef)
)

func (ex *Exchange) Send(stream NetworkExchange_SendServer) error {
	for {
		pdu, err := stream.Recv()
		if err == io.EOF {
			break
		}

		// Send to a local node if name matches
		for _, name := range pdu.FwdNames {
			client, ok := ex.Locals[name]
			if !ok {
				continue
			}

			client <- pdu // I don't care if it fails
		}

		// Send to all peers except the sender

		sender := pdu.Sender
		pdu.Sender = ex.Self_name

		for peer, cProxy := range ex.Remotes {
			if sender == peer {
				continue
			}

			if !cProxy.IsConnected {
				var cl_opts []grpc.DialOption

				conn, err := grpc.Dial(cProxy.Addr, cl_opts...)
				if err != nil {
					log.Println("Couldn't establish connection with:", peer)
					continue
				}

				cProxy.IsConnected = true
				cProxy.Client = NewNetworkExchangeClient(conn)
			}

			client := cProxy.Client
			send_cl, err := client.Send(context.Background())
			if err != nil {
				continue
			}
			send_cl.Send(pdu)
		}

	}

	err := stream.SendAndClose(&FIN{
		Magic: FIN_MAGIC,
	})
	return err
}

func (ex *Exchange) Recv(in *SYN, receiver NetworkExchange_RecvServer) error {
	name := in.Name
	ctx, cancel := context.WithCancel(context.Background())
	ex.Client_ctx = append(ex.Client_ctx, ctx)
	ex.Client_cancel = append(ex.Client_cancel, cancel)

	src, ok := ex.Locals[name]
	if !ok {
		return errors.New("Name not registered")
	}

	go func() {

		for {
			select {
			case <-ctx.Done():
				return
			case msg := <-src:
				err := receiver.Send(msg)
				if err != nil {
					return
				}
			}
		}
	}()

	return nil
}
