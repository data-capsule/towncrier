PROTO_FILES := pkg/network/network.pb.go pkg/network/network_grpc.pb.go

CPP_PROTO := pkg/connectors/cpp/network.pb.h pkg/connectors/cpp/network.pb.cc pkg/connectors/cpp/network.grpc.pb.h pkg/connectors/cpp/network.grpc.pb.cc

all: bin/towncrier bin/go_echo_client $(CPP_PROTO)

bin/towncrier: pkg/* cmd/towncrier/main.go
	mkdir -p bin
	go build -o bin/towncrier cmd/towncrier/main.go

bin/go_echo_client: pkg/* $(PROTO_FILES) cmd/go_echo_client/main.go
	mkdir -p bin
	go build -o bin/go_echo_client cmd/go_echo_client/main.go


$(PROTO_FILES): pkg/network.proto
	protoc --go_out=. --go_opt=paths=source_relative \
    --go-grpc_out=. --go-grpc_opt=paths=source_relative \
    pkg/network.proto

	mv pkg/network.pb.go pkg/network/network.pb.go
	mv pkg/network_grpc.pb.go pkg/network/network_grpc_pb.go

$(CPP_PROTO): pkg/network.proto
	mkdir -p pkg/connectors/cpp
	protoc -I pkg --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` pkg/network.proto
	protoc -I pkg --cpp_out=. pkg/network.proto

	mv network.pb.h pkg/connectors/cpp/network.pb.h
	mv network.pb.cc pkg/connectors/cpp/network.pb.cc
	mv network.grpc.pb.h pkg/connectors/cpp/network.grpc.pb.h
	mv network.grpc.pb.cc pkg/connectors/cpp/network.grpc.pb.cc


