PROTO_FILES := pkg/network.pb.go pkg/network_grpc_pb.go

all: bin/towncrier

bin/towncrier: pkg/* $(PROTO_FILES) cmd/towncrier/main.go
	mkdir -p bin
	go build -o bin/towncrier cmd/towncrier/main.go


$(PROTO_FILES): pkg/network.proto
	protoc --go_out=. --go_opt=paths=source_relative \
    --go-grpc_out=. --go-grpc_opt=paths=source_relative \
    pkg/network.proto