// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.28.1
// 	protoc        v3.21.9
// source: pkg/network/network.proto

package network

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type PDU struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Sender   string   `protobuf:"bytes,1,opt,name=sender,proto3" json:"sender,omitempty"`
	FwdNames []string `protobuf:"bytes,2,rep,name=fwd_names,json=fwdNames,proto3" json:"fwd_names,omitempty"`
	Msg      []byte   `protobuf:"bytes,3,opt,name=msg,proto3,oneof" json:"msg,omitempty"`
}

func (x *PDU) Reset() {
	*x = PDU{}
	if protoimpl.UnsafeEnabled {
		mi := &file_pkg_network_network_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *PDU) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*PDU) ProtoMessage() {}

func (x *PDU) ProtoReflect() protoreflect.Message {
	mi := &file_pkg_network_network_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use PDU.ProtoReflect.Descriptor instead.
func (*PDU) Descriptor() ([]byte, []int) {
	return file_pkg_network_network_proto_rawDescGZIP(), []int{0}
}

func (x *PDU) GetSender() string {
	if x != nil {
		return x.Sender
	}
	return ""
}

func (x *PDU) GetFwdNames() []string {
	if x != nil {
		return x.FwdNames
	}
	return nil
}

func (x *PDU) GetMsg() []byte {
	if x != nil {
		return x.Msg
	}
	return nil
}

type SYN struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Name string `protobuf:"bytes,1,opt,name=name,proto3" json:"name,omitempty"`
}

func (x *SYN) Reset() {
	*x = SYN{}
	if protoimpl.UnsafeEnabled {
		mi := &file_pkg_network_network_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *SYN) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*SYN) ProtoMessage() {}

func (x *SYN) ProtoReflect() protoreflect.Message {
	mi := &file_pkg_network_network_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use SYN.ProtoReflect.Descriptor instead.
func (*SYN) Descriptor() ([]byte, []int) {
	return file_pkg_network_network_proto_rawDescGZIP(), []int{1}
}

func (x *SYN) GetName() string {
	if x != nil {
		return x.Name
	}
	return ""
}

type FIN struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Magic int64 `protobuf:"varint,1,opt,name=magic,proto3" json:"magic,omitempty"` // Don't send an empty message
}

func (x *FIN) Reset() {
	*x = FIN{}
	if protoimpl.UnsafeEnabled {
		mi := &file_pkg_network_network_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FIN) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FIN) ProtoMessage() {}

func (x *FIN) ProtoReflect() protoreflect.Message {
	mi := &file_pkg_network_network_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FIN.ProtoReflect.Descriptor instead.
func (*FIN) Descriptor() ([]byte, []int) {
	return file_pkg_network_network_proto_rawDescGZIP(), []int{2}
}

func (x *FIN) GetMagic() int64 {
	if x != nil {
		return x.Magic
	}
	return 0
}

var File_pkg_network_network_proto protoreflect.FileDescriptor

var file_pkg_network_network_proto_rawDesc = []byte{
	0x0a, 0x19, 0x70, 0x6b, 0x67, 0x2f, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x2f, 0x6e, 0x65,
	0x74, 0x77, 0x6f, 0x72, 0x6b, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x07, 0x6e, 0x65, 0x74,
	0x77, 0x6f, 0x72, 0x6b, 0x22, 0x59, 0x0a, 0x03, 0x50, 0x44, 0x55, 0x12, 0x16, 0x0a, 0x06, 0x73,
	0x65, 0x6e, 0x64, 0x65, 0x72, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x73, 0x65, 0x6e,
	0x64, 0x65, 0x72, 0x12, 0x1b, 0x0a, 0x09, 0x66, 0x77, 0x64, 0x5f, 0x6e, 0x61, 0x6d, 0x65, 0x73,
	0x18, 0x02, 0x20, 0x03, 0x28, 0x09, 0x52, 0x08, 0x66, 0x77, 0x64, 0x4e, 0x61, 0x6d, 0x65, 0x73,
	0x12, 0x15, 0x0a, 0x03, 0x6d, 0x73, 0x67, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0c, 0x48, 0x00, 0x52,
	0x03, 0x6d, 0x73, 0x67, 0x88, 0x01, 0x01, 0x42, 0x06, 0x0a, 0x04, 0x5f, 0x6d, 0x73, 0x67, 0x22,
	0x19, 0x0a, 0x03, 0x53, 0x59, 0x4e, 0x12, 0x12, 0x0a, 0x04, 0x6e, 0x61, 0x6d, 0x65, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x04, 0x6e, 0x61, 0x6d, 0x65, 0x22, 0x1b, 0x0a, 0x03, 0x46, 0x49,
	0x4e, 0x12, 0x14, 0x0a, 0x05, 0x6d, 0x61, 0x67, 0x69, 0x63, 0x18, 0x01, 0x20, 0x01, 0x28, 0x03,
	0x52, 0x05, 0x6d, 0x61, 0x67, 0x69, 0x63, 0x32, 0x5d, 0x0a, 0x0f, 0x4e, 0x65, 0x74, 0x77, 0x6f,
	0x72, 0x6b, 0x45, 0x78, 0x63, 0x68, 0x61, 0x6e, 0x67, 0x65, 0x12, 0x24, 0x0a, 0x04, 0x53, 0x65,
	0x6e, 0x64, 0x12, 0x0c, 0x2e, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x2e, 0x50, 0x44, 0x55,
	0x1a, 0x0c, 0x2e, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x2e, 0x46, 0x49, 0x4e, 0x28, 0x01,
	0x12, 0x24, 0x0a, 0x04, 0x52, 0x65, 0x63, 0x76, 0x12, 0x0c, 0x2e, 0x6e, 0x65, 0x74, 0x77, 0x6f,
	0x72, 0x6b, 0x2e, 0x53, 0x59, 0x4e, 0x1a, 0x0c, 0x2e, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b,
	0x2e, 0x50, 0x44, 0x55, 0x30, 0x01, 0x42, 0x13, 0x5a, 0x11, 0x74, 0x6f, 0x77, 0x6e, 0x63, 0x72,
	0x69, 0x65, 0x72, 0x2f, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, 0x6b, 0x62, 0x06, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x33,
}

var (
	file_pkg_network_network_proto_rawDescOnce sync.Once
	file_pkg_network_network_proto_rawDescData = file_pkg_network_network_proto_rawDesc
)

func file_pkg_network_network_proto_rawDescGZIP() []byte {
	file_pkg_network_network_proto_rawDescOnce.Do(func() {
		file_pkg_network_network_proto_rawDescData = protoimpl.X.CompressGZIP(file_pkg_network_network_proto_rawDescData)
	})
	return file_pkg_network_network_proto_rawDescData
}

var file_pkg_network_network_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_pkg_network_network_proto_goTypes = []interface{}{
	(*PDU)(nil), // 0: network.PDU
	(*SYN)(nil), // 1: network.SYN
	(*FIN)(nil), // 2: network.FIN
}
var file_pkg_network_network_proto_depIdxs = []int32{
	0, // 0: network.NetworkExchange.Send:input_type -> network.PDU
	1, // 1: network.NetworkExchange.Recv:input_type -> network.SYN
	2, // 2: network.NetworkExchange.Send:output_type -> network.FIN
	0, // 3: network.NetworkExchange.Recv:output_type -> network.PDU
	2, // [2:4] is the sub-list for method output_type
	0, // [0:2] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_pkg_network_network_proto_init() }
func file_pkg_network_network_proto_init() {
	if File_pkg_network_network_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_pkg_network_network_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*PDU); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_pkg_network_network_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*SYN); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_pkg_network_network_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*FIN); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	file_pkg_network_network_proto_msgTypes[0].OneofWrappers = []interface{}{}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_pkg_network_network_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_pkg_network_network_proto_goTypes,
		DependencyIndexes: file_pkg_network_network_proto_depIdxs,
		MessageInfos:      file_pkg_network_network_proto_msgTypes,
	}.Build()
	File_pkg_network_network_proto = out.File
	file_pkg_network_network_proto_rawDesc = nil
	file_pkg_network_network_proto_goTypes = nil
	file_pkg_network_network_proto_depIdxs = nil
}