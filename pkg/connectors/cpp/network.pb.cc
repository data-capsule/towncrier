// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network.proto

#include "network.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace network {
PROTOBUF_CONSTEXPR PDU::PDU(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.fwd_names_)*/{}
  , /*decltype(_impl_.sender_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.msg_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}} {}
struct PDUDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PDUDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PDUDefaultTypeInternal() {}
  union {
    PDU _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PDUDefaultTypeInternal _PDU_default_instance_;
PROTOBUF_CONSTEXPR SYN::SYN(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct SYNDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SYNDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~SYNDefaultTypeInternal() {}
  union {
    SYN _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SYNDefaultTypeInternal _SYN_default_instance_;
PROTOBUF_CONSTEXPR FIN::FIN(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.magic_)*/int64_t{0}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct FINDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FINDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FINDefaultTypeInternal() {}
  union {
    FIN _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FINDefaultTypeInternal _FIN_default_instance_;
}  // namespace network
static ::_pb::Metadata file_level_metadata_network_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_network_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_network_2eproto = nullptr;

const uint32_t TableStruct_network_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::network::PDU, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::network::PDU, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::network::PDU, _impl_.sender_),
  PROTOBUF_FIELD_OFFSET(::network::PDU, _impl_.fwd_names_),
  PROTOBUF_FIELD_OFFSET(::network::PDU, _impl_.msg_),
  ~0u,
  ~0u,
  0,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::network::SYN, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::network::SYN, _impl_.name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::network::FIN, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::network::FIN, _impl_.magic_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::network::PDU)},
  { 12, -1, -1, sizeof(::network::SYN)},
  { 19, -1, -1, sizeof(::network::FIN)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::network::_PDU_default_instance_._instance,
  &::network::_SYN_default_instance_._instance,
  &::network::_FIN_default_instance_._instance,
};

const char descriptor_table_protodef_network_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rnetwork.proto\022\007network\"B\n\003PDU\022\016\n\006sende"
  "r\030\001 \001(\t\022\021\n\tfwd_names\030\002 \003(\t\022\020\n\003msg\030\003 \001(\014H"
  "\000\210\001\001B\006\n\004_msg\"\023\n\003SYN\022\014\n\004name\030\001 \001(\t\"\024\n\003FIN"
  "\022\r\n\005magic\030\001 \001(\0032]\n\017NetworkExchange\022$\n\004Se"
  "nd\022\014.network.PDU\032\014.network.FIN(\001\022$\n\004Recv"
  "\022\014.network.SYN\032\014.network.PDU0\001B\023Z\021towncr"
  "ier/networkb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_network_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_network_2eproto = {
    false, false, 259, descriptor_table_protodef_network_2eproto,
    "network.proto",
    &descriptor_table_network_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_network_2eproto::offsets,
    file_level_metadata_network_2eproto, file_level_enum_descriptors_network_2eproto,
    file_level_service_descriptors_network_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_network_2eproto_getter() {
  return &descriptor_table_network_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_network_2eproto(&descriptor_table_network_2eproto);
namespace network {

// ===================================================================

class PDU::_Internal {
 public:
  using HasBits = decltype(std::declval<PDU>()._impl_._has_bits_);
  static void set_has_msg(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

PDU::PDU(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:network.PDU)
}
PDU::PDU(const PDU& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  PDU* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.fwd_names_){from._impl_.fwd_names_}
    , decltype(_impl_.sender_){}
    , decltype(_impl_.msg_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.sender_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_sender().empty()) {
    _this->_impl_.sender_.Set(from._internal_sender(), 
      _this->GetArenaForAllocation());
  }
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_msg()) {
    _this->_impl_.msg_.Set(from._internal_msg(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:network.PDU)
}

inline void PDU::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.fwd_names_){arena}
    , decltype(_impl_.sender_){}
    , decltype(_impl_.msg_){}
  };
  _impl_.sender_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

PDU::~PDU() {
  // @@protoc_insertion_point(destructor:network.PDU)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PDU::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.fwd_names_.~RepeatedPtrField();
  _impl_.sender_.Destroy();
  _impl_.msg_.Destroy();
}

void PDU::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void PDU::Clear() {
// @@protoc_insertion_point(message_clear_start:network.PDU)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.fwd_names_.Clear();
  _impl_.sender_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.msg_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PDU::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string sender = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_sender();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "network.PDU.sender"));
        } else
          goto handle_unusual;
        continue;
      // repeated string fwd_names = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_fwd_names();
            ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            CHK_(::_pbi::VerifyUTF8(str, "network.PDU.fwd_names"));
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      // optional bytes msg = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_msg();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PDU::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:network.PDU)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string sender = 1;
  if (!this->_internal_sender().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sender().data(), static_cast<int>(this->_internal_sender().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "network.PDU.sender");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sender(), target);
  }

  // repeated string fwd_names = 2;
  for (int i = 0, n = this->_internal_fwd_names_size(); i < n; i++) {
    const auto& s = this->_internal_fwd_names(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "network.PDU.fwd_names");
    target = stream->WriteString(2, s, target);
  }

  // optional bytes msg = 3;
  if (_internal_has_msg()) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:network.PDU)
  return target;
}

size_t PDU::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:network.PDU)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string fwd_names = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_impl_.fwd_names_.size());
  for (int i = 0, n = _impl_.fwd_names_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      _impl_.fwd_names_.Get(i));
  }

  // string sender = 1;
  if (!this->_internal_sender().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sender());
  }

  // optional bytes msg = 3;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PDU::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    PDU::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PDU::GetClassData() const { return &_class_data_; }


void PDU::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<PDU*>(&to_msg);
  auto& from = static_cast<const PDU&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:network.PDU)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.fwd_names_.MergeFrom(from._impl_.fwd_names_);
  if (!from._internal_sender().empty()) {
    _this->_internal_set_sender(from._internal_sender());
  }
  if (from._internal_has_msg()) {
    _this->_internal_set_msg(from._internal_msg());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PDU::CopyFrom(const PDU& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:network.PDU)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PDU::IsInitialized() const {
  return true;
}

void PDU::InternalSwap(PDU* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.fwd_names_.InternalSwap(&other->_impl_.fwd_names_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.sender_, lhs_arena,
      &other->_impl_.sender_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.msg_, lhs_arena,
      &other->_impl_.msg_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata PDU::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_network_2eproto_getter, &descriptor_table_network_2eproto_once,
      file_level_metadata_network_2eproto[0]);
}

// ===================================================================

class SYN::_Internal {
 public:
};

SYN::SYN(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:network.SYN)
}
SYN::SYN(const SYN& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  SYN* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:network.SYN)
}

inline void SYN::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

SYN::~SYN() {
  // @@protoc_insertion_point(destructor:network.SYN)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void SYN::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void SYN::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void SYN::Clear() {
// @@protoc_insertion_point(message_clear_start:network.SYN)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SYN::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "network.SYN.name"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* SYN::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:network.SYN)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "network.SYN.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:network.SYN)
  return target;
}

size_t SYN::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:network.SYN)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData SYN::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    SYN::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*SYN::GetClassData() const { return &_class_data_; }


void SYN::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<SYN*>(&to_msg);
  auto& from = static_cast<const SYN&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:network.SYN)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void SYN::CopyFrom(const SYN& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:network.SYN)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SYN::IsInitialized() const {
  return true;
}

void SYN::InternalSwap(SYN* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata SYN::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_network_2eproto_getter, &descriptor_table_network_2eproto_once,
      file_level_metadata_network_2eproto[1]);
}

// ===================================================================

class FIN::_Internal {
 public:
};

FIN::FIN(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:network.FIN)
}
FIN::FIN(const FIN& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  FIN* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.magic_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.magic_ = from._impl_.magic_;
  // @@protoc_insertion_point(copy_constructor:network.FIN)
}

inline void FIN::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.magic_){int64_t{0}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

FIN::~FIN() {
  // @@protoc_insertion_point(destructor:network.FIN)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void FIN::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void FIN::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void FIN::Clear() {
// @@protoc_insertion_point(message_clear_start:network.FIN)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.magic_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FIN::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 magic = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.magic_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FIN::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:network.FIN)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 magic = 1;
  if (this->_internal_magic() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(1, this->_internal_magic(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:network.FIN)
  return target;
}

size_t FIN::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:network.FIN)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int64 magic = 1;
  if (this->_internal_magic() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_magic());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FIN::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    FIN::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FIN::GetClassData() const { return &_class_data_; }


void FIN::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<FIN*>(&to_msg);
  auto& from = static_cast<const FIN&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:network.FIN)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_magic() != 0) {
    _this->_internal_set_magic(from._internal_magic());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FIN::CopyFrom(const FIN& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:network.FIN)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FIN::IsInitialized() const {
  return true;
}

void FIN::InternalSwap(FIN* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.magic_, other->_impl_.magic_);
}

::PROTOBUF_NAMESPACE_ID::Metadata FIN::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_network_2eproto_getter, &descriptor_table_network_2eproto_once,
      file_level_metadata_network_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace network
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::network::PDU*
Arena::CreateMaybeMessage< ::network::PDU >(Arena* arena) {
  return Arena::CreateMessageInternal< ::network::PDU >(arena);
}
template<> PROTOBUF_NOINLINE ::network::SYN*
Arena::CreateMaybeMessage< ::network::SYN >(Arena* arena) {
  return Arena::CreateMessageInternal< ::network::SYN >(arena);
}
template<> PROTOBUF_NOINLINE ::network::FIN*
Arena::CreateMaybeMessage< ::network::FIN >(Arena* arena) {
  return Arena::CreateMessageInternal< ::network::FIN >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
