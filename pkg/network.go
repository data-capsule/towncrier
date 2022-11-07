package network

import (
	"context"
	"errors"
	"io"
)

/* IMPORTANT: Create topology such that clients don't send redundant messages */

type Exchange struct {
	locals        map[string]chan *PDU                  // fwd_name => client
	remotes       map[string]NetworkExchange_SendClient // sender => client
	self_name     string
	client_ctx    []context.Context
	client_cancel []context.CancelFunc

	UnimplementedNetworkExchangeServer
}

const (
	FIN_MAGIC = int64(0xdeadbeef)
	SYN_MAGIC = int64(0xcafebabe)
)

func (ex *Exchange) Send(stream NetworkExchange_SendServer) error {
	for {
		pdu, err := stream.Recv()
		if err == io.EOF {
			break
		}

		// Send to a local node if name matches
		for _, name := range pdu.FwdNames {
			client, ok := ex.locals[name]
			if !ok {
				continue
			}

			client <- pdu // I don't care if it fails
		}

		// Send to all peers except the sender

		sender := pdu.Sender
		pdu.Sender = ex.self_name

		for peer, client := range ex.remotes {
			if sender == peer {
				continue
			}
			client.Send(pdu)
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
	ex.client_ctx = append(ex.client_ctx, ctx)
	ex.client_cancel = append(ex.client_cancel, cancel)

	src, ok := ex.locals[name]
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
