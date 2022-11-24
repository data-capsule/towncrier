package network

import (
	"context"
	"errors"
	"io"
	"log"

	grpc "google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

/* IMPORTANT: Create topology such that clients don't send redundant messages */

type Exchange struct {
	Locals        map[string]chan *PDU // fwd_name => msg channel
	Remotes       map[string]chan *PDU // remote location => msg channel
	Self_name     string
	Client_ctx    []context.Context
	Client_cancel []context.CancelFunc
	Remote_ctx    []context.Context
	Remote_cancel []context.CancelFunc

	UnimplementedNetworkExchangeServer
}

const (
	FIN_MAGIC = int64(0xdeadbeef)
)

func (ex *Exchange) Send(stream NetworkExchange_SendServer) error {
	for {
		pdu, err := stream.Recv()
		if err == io.EOF || err == grpc.ErrClientConnClosing || err == grpc.ErrServerStopped {
			break
		}

		if err != nil {
			log.Println(err)
			return err
		}

		log.Printf("%+v\n", pdu)

		fwd_to_a_local := false

		// Send to a local node if name matches
		for _, name := range pdu.FwdNames {
			client, ok := ex.Locals[name]
			if !ok {
				continue
			}

			log.Println("Forwarding to", name)
			fwd_to_a_local = true
			client <- pdu
		}

		if fwd_to_a_local {
			// Don't forward remote peers, if name was found locally.
			continue
		}

		// Send to all peers except the sender

		sender := pdu.Sender
		pdu.Sender = ex.Self_name

		for peer, c := range ex.Remotes {
			if sender == peer {
				continue
			}
			log.Println("Forwarding to", peer)

			c <- pdu
		}

	}

	err := stream.SendAndClose(&FIN{
		Magic: FIN_MAGIC,
	})
	return err
}

func Forward(ctx context.Context, addr string, c chan *PDU) {
	connected := false
	var conn *grpc.ClientConn
	var send_client NetworkExchange_SendClient

	for {
		select {
		case <-ctx.Done():
			if connected {
				conn.Close()
			}
			break
		case msg, chan_open := <-c:
			if !chan_open {
				return
			}
			var err error
			log.Println("Forwarding to", addr)
			if !connected {
				conn, err = grpc.Dial(addr,
					grpc.WithTransportCredentials(insecure.NewCredentials()))
				if err != nil {
					log.Println(err)
					continue
				}
				connected = true
			}
			cl := NewNetworkExchangeClient(conn)
			send_client, err = cl.Send(ctx)
			if err != nil {
				connected = false
				log.Println(err, "Connection reset")
				continue
			}

			send_client.Send(msg)
			log.Println("Forwarding complete")
		}
	}
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

	for {
		select {
		case <-ctx.Done():
			return nil
		case msg, chan_open := <-src:
			if !chan_open {
				return nil
			}
			err := receiver.Send(msg)
			if err != nil {
				log.Println(err)
				return err
			}
			log.Println("Forwarding complete")
		}
	}
}
