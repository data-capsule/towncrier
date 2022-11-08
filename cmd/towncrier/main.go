package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net"
	"os"

	"google.golang.org/grpc"
	"google.golang.org/grpc/keepalive"

	"towncrier/pkg/network"
)

type RemoteConfig struct {
	Name string `json:"name"`
	Addr string `json:"addr"`
}

type Config struct {
	Name    string         `json:"name"`
	Port    int32          `json:"port"`
	Locals  []string       `json:"locals"`
	Remotes []RemoteConfig `json:"remotes"`
}

func main() {
	args := os.Args
	log.SetOutput(os.Stderr)

	if len(args) != 2 {
		log.Fatalln("Usage: towncrier path/to/config.json")
	}

	f, err := os.Open(args[1])
	if err != nil {
		log.Fatal(err)
	}

	jsonContent, err := ioutil.ReadAll(f)
	if err != nil {
		log.Fatal(err)
	}

	var config Config
	err = json.Unmarshal(jsonContent, &config)
	if err != nil {
		log.Fatal(err)
	}
	f.Close()

	port := fmt.Sprintf(":%d", config.Port)

	var serv_opts []grpc.ServerOption
	serv_opts = append(serv_opts, grpc.KeepaliveParams(keepalive.ServerParameters{}))
	grpcServer := grpc.NewServer(serv_opts...)

	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatal(err)
	}

	var ex network.Exchange
	ex.Self_name = config.Name
	ex.Locals = make(map[string]chan *network.PDU)
	for _, name := range config.Locals {
		ex.Locals[name] = make(chan *network.PDU)
	}

	ex.Remotes = make(map[string]network.ClientProxy)
	for _, r := range config.Remotes {
		ex.Remotes[r.Name] = network.ClientProxy{
			Name:        r.Name,
			Addr:        r.Addr,
			IsConnected: true,
		}
	}

	network.RegisterNetworkExchangeServer(grpcServer, &ex)

	grpcServer.Serve(lis)

}
