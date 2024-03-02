// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mine_rds.proto

#include "mine_rds.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_mine_5frds_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_mine_5frds_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_RdsMessage;
extern PROTOBUF_INTERNAL_EXPORT_protobuf_mine_5frds_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_VehMessage;
}  // namespace protobuf_mine_5frds_2eproto
namespace robocar_rds {
class ProtocolDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Protocol>
      _instance;
} _Protocol_default_instance_;
class VehMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<VehMessage>
      _instance;
} _VehMessage_default_instance_;
class RdsMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<RdsMessage>
      _instance;
} _RdsMessage_default_instance_;
}  // namespace robocar_rds
namespace protobuf_mine_5frds_2eproto {
static void InitDefaultsProtocol() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::robocar_rds::_Protocol_default_instance_;
    new (ptr) ::robocar_rds::Protocol();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::robocar_rds::Protocol::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<2> scc_info_Protocol =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsProtocol}, {
      &protobuf_mine_5frds_2eproto::scc_info_VehMessage.base,
      &protobuf_mine_5frds_2eproto::scc_info_RdsMessage.base,}};

static void InitDefaultsVehMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::robocar_rds::_VehMessage_default_instance_;
    new (ptr) ::robocar_rds::VehMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::robocar_rds::VehMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_VehMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsVehMessage}, {}};

static void InitDefaultsRdsMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::robocar_rds::_RdsMessage_default_instance_;
    new (ptr) ::robocar_rds::RdsMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::robocar_rds::RdsMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_RdsMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsRdsMessage}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Protocol.base);
  ::google::protobuf::internal::InitSCC(&scc_info_VehMessage.base);
  ::google::protobuf::internal::InitSCC(&scc_info_RdsMessage.base);
}

::google::protobuf::Metadata file_level_metadata[3];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::Protocol, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::Protocol, veh_message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::Protocol, rds_message_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::VehMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::VehMessage, linear_x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::VehMessage, angular_z_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::RdsMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::RdsMessage, linear_x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::robocar_rds::RdsMessage, angular_z_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::robocar_rds::Protocol)},
  { 7, -1, sizeof(::robocar_rds::VehMessage)},
  { 14, -1, sizeof(::robocar_rds::RdsMessage)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::robocar_rds::_Protocol_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::robocar_rds::_VehMessage_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::robocar_rds::_RdsMessage_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "mine_rds.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\016mine_rds.proto\022\013robocar_rds\"f\n\010Protoco"
      "l\022,\n\013veh_message\030\001 \001(\0132\027.robocar_rds.Veh"
      "Message\022,\n\013rds_message\030\002 \001(\0132\027.robocar_r"
      "ds.RdsMessage\"1\n\nVehMessage\022\020\n\010linear_x\030"
      "\001 \001(\001\022\021\n\tangular_z\030\002 \001(\001\"1\n\nRdsMessage\022\020"
      "\n\010linear_x\030\001 \001(\001\022\021\n\tangular_z\030\002 \001(\001b\006pro"
      "to3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 243);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "mine_rds.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_mine_5frds_2eproto
namespace robocar_rds {

// ===================================================================

void Protocol::InitAsDefaultInstance() {
  ::robocar_rds::_Protocol_default_instance_._instance.get_mutable()->veh_message_ = const_cast< ::robocar_rds::VehMessage*>(
      ::robocar_rds::VehMessage::internal_default_instance());
  ::robocar_rds::_Protocol_default_instance_._instance.get_mutable()->rds_message_ = const_cast< ::robocar_rds::RdsMessage*>(
      ::robocar_rds::RdsMessage::internal_default_instance());
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Protocol::kVehMessageFieldNumber;
const int Protocol::kRdsMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Protocol::Protocol()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_mine_5frds_2eproto::scc_info_Protocol.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:robocar_rds.Protocol)
}
Protocol::Protocol(const Protocol& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_veh_message()) {
    veh_message_ = new ::robocar_rds::VehMessage(*from.veh_message_);
  } else {
    veh_message_ = NULL;
  }
  if (from.has_rds_message()) {
    rds_message_ = new ::robocar_rds::RdsMessage(*from.rds_message_);
  } else {
    rds_message_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:robocar_rds.Protocol)
}

void Protocol::SharedCtor() {
  ::memset(&veh_message_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rds_message_) -
      reinterpret_cast<char*>(&veh_message_)) + sizeof(rds_message_));
}

Protocol::~Protocol() {
  // @@protoc_insertion_point(destructor:robocar_rds.Protocol)
  SharedDtor();
}

void Protocol::SharedDtor() {
  if (this != internal_default_instance()) delete veh_message_;
  if (this != internal_default_instance()) delete rds_message_;
}

void Protocol::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Protocol::descriptor() {
  ::protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Protocol& Protocol::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_mine_5frds_2eproto::scc_info_Protocol.base);
  return *internal_default_instance();
}


void Protocol::Clear() {
// @@protoc_insertion_point(message_clear_start:robocar_rds.Protocol)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && veh_message_ != NULL) {
    delete veh_message_;
  }
  veh_message_ = NULL;
  if (GetArenaNoVirtual() == NULL && rds_message_ != NULL) {
    delete rds_message_;
  }
  rds_message_ = NULL;
  _internal_metadata_.Clear();
}

bool Protocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:robocar_rds.Protocol)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .robocar_rds.VehMessage veh_message = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_veh_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .robocar_rds.RdsMessage rds_message = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_rds_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:robocar_rds.Protocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:robocar_rds.Protocol)
  return false;
#undef DO_
}

void Protocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:robocar_rds.Protocol)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .robocar_rds.VehMessage veh_message = 1;
  if (this->has_veh_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->_internal_veh_message(), output);
  }

  // .robocar_rds.RdsMessage rds_message = 2;
  if (this->has_rds_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->_internal_rds_message(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:robocar_rds.Protocol)
}

::google::protobuf::uint8* Protocol::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:robocar_rds.Protocol)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .robocar_rds.VehMessage veh_message = 1;
  if (this->has_veh_message()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->_internal_veh_message(), deterministic, target);
  }

  // .robocar_rds.RdsMessage rds_message = 2;
  if (this->has_rds_message()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->_internal_rds_message(), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:robocar_rds.Protocol)
  return target;
}

size_t Protocol::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:robocar_rds.Protocol)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .robocar_rds.VehMessage veh_message = 1;
  if (this->has_veh_message()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *veh_message_);
  }

  // .robocar_rds.RdsMessage rds_message = 2;
  if (this->has_rds_message()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *rds_message_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Protocol::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:robocar_rds.Protocol)
  GOOGLE_DCHECK_NE(&from, this);
  const Protocol* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Protocol>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:robocar_rds.Protocol)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:robocar_rds.Protocol)
    MergeFrom(*source);
  }
}

void Protocol::MergeFrom(const Protocol& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:robocar_rds.Protocol)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_veh_message()) {
    mutable_veh_message()->::robocar_rds::VehMessage::MergeFrom(from.veh_message());
  }
  if (from.has_rds_message()) {
    mutable_rds_message()->::robocar_rds::RdsMessage::MergeFrom(from.rds_message());
  }
}

void Protocol::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:robocar_rds.Protocol)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Protocol::CopyFrom(const Protocol& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:robocar_rds.Protocol)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Protocol::IsInitialized() const {
  return true;
}

void Protocol::Swap(Protocol* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Protocol::InternalSwap(Protocol* other) {
  using std::swap;
  swap(veh_message_, other->veh_message_);
  swap(rds_message_, other->rds_message_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Protocol::GetMetadata() const {
  protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void VehMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int VehMessage::kLinearXFieldNumber;
const int VehMessage::kAngularZFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

VehMessage::VehMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_mine_5frds_2eproto::scc_info_VehMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:robocar_rds.VehMessage)
}
VehMessage::VehMessage(const VehMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&linear_x_, &from.linear_x_,
    static_cast<size_t>(reinterpret_cast<char*>(&angular_z_) -
    reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
  // @@protoc_insertion_point(copy_constructor:robocar_rds.VehMessage)
}

void VehMessage::SharedCtor() {
  ::memset(&linear_x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&angular_z_) -
      reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
}

VehMessage::~VehMessage() {
  // @@protoc_insertion_point(destructor:robocar_rds.VehMessage)
  SharedDtor();
}

void VehMessage::SharedDtor() {
}

void VehMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* VehMessage::descriptor() {
  ::protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const VehMessage& VehMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_mine_5frds_2eproto::scc_info_VehMessage.base);
  return *internal_default_instance();
}


void VehMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:robocar_rds.VehMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&linear_x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&angular_z_) -
      reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
  _internal_metadata_.Clear();
}

bool VehMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:robocar_rds.VehMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // double linear_x = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &linear_x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double angular_z = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &angular_z_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:robocar_rds.VehMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:robocar_rds.VehMessage)
  return false;
#undef DO_
}

void VehMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:robocar_rds.VehMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double linear_x = 1;
  if (this->linear_x() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->linear_x(), output);
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->angular_z(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:robocar_rds.VehMessage)
}

::google::protobuf::uint8* VehMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:robocar_rds.VehMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double linear_x = 1;
  if (this->linear_x() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->linear_x(), target);
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->angular_z(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:robocar_rds.VehMessage)
  return target;
}

size_t VehMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:robocar_rds.VehMessage)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // double linear_x = 1;
  if (this->linear_x() != 0) {
    total_size += 1 + 8;
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    total_size += 1 + 8;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VehMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:robocar_rds.VehMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const VehMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const VehMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:robocar_rds.VehMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:robocar_rds.VehMessage)
    MergeFrom(*source);
  }
}

void VehMessage::MergeFrom(const VehMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:robocar_rds.VehMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.linear_x() != 0) {
    set_linear_x(from.linear_x());
  }
  if (from.angular_z() != 0) {
    set_angular_z(from.angular_z());
  }
}

void VehMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:robocar_rds.VehMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VehMessage::CopyFrom(const VehMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:robocar_rds.VehMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VehMessage::IsInitialized() const {
  return true;
}

void VehMessage::Swap(VehMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void VehMessage::InternalSwap(VehMessage* other) {
  using std::swap;
  swap(linear_x_, other->linear_x_);
  swap(angular_z_, other->angular_z_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata VehMessage::GetMetadata() const {
  protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void RdsMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RdsMessage::kLinearXFieldNumber;
const int RdsMessage::kAngularZFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RdsMessage::RdsMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_mine_5frds_2eproto::scc_info_RdsMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:robocar_rds.RdsMessage)
}
RdsMessage::RdsMessage(const RdsMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&linear_x_, &from.linear_x_,
    static_cast<size_t>(reinterpret_cast<char*>(&angular_z_) -
    reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
  // @@protoc_insertion_point(copy_constructor:robocar_rds.RdsMessage)
}

void RdsMessage::SharedCtor() {
  ::memset(&linear_x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&angular_z_) -
      reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
}

RdsMessage::~RdsMessage() {
  // @@protoc_insertion_point(destructor:robocar_rds.RdsMessage)
  SharedDtor();
}

void RdsMessage::SharedDtor() {
}

void RdsMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* RdsMessage::descriptor() {
  ::protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RdsMessage& RdsMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_mine_5frds_2eproto::scc_info_RdsMessage.base);
  return *internal_default_instance();
}


void RdsMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:robocar_rds.RdsMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&linear_x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&angular_z_) -
      reinterpret_cast<char*>(&linear_x_)) + sizeof(angular_z_));
  _internal_metadata_.Clear();
}

bool RdsMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:robocar_rds.RdsMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // double linear_x = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &linear_x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double angular_z = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &angular_z_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:robocar_rds.RdsMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:robocar_rds.RdsMessage)
  return false;
#undef DO_
}

void RdsMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:robocar_rds.RdsMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double linear_x = 1;
  if (this->linear_x() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->linear_x(), output);
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->angular_z(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:robocar_rds.RdsMessage)
}

::google::protobuf::uint8* RdsMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:robocar_rds.RdsMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double linear_x = 1;
  if (this->linear_x() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->linear_x(), target);
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->angular_z(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:robocar_rds.RdsMessage)
  return target;
}

size_t RdsMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:robocar_rds.RdsMessage)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // double linear_x = 1;
  if (this->linear_x() != 0) {
    total_size += 1 + 8;
  }

  // double angular_z = 2;
  if (this->angular_z() != 0) {
    total_size += 1 + 8;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RdsMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:robocar_rds.RdsMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const RdsMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RdsMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:robocar_rds.RdsMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:robocar_rds.RdsMessage)
    MergeFrom(*source);
  }
}

void RdsMessage::MergeFrom(const RdsMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:robocar_rds.RdsMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.linear_x() != 0) {
    set_linear_x(from.linear_x());
  }
  if (from.angular_z() != 0) {
    set_angular_z(from.angular_z());
  }
}

void RdsMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:robocar_rds.RdsMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RdsMessage::CopyFrom(const RdsMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:robocar_rds.RdsMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RdsMessage::IsInitialized() const {
  return true;
}

void RdsMessage::Swap(RdsMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RdsMessage::InternalSwap(RdsMessage* other) {
  using std::swap;
  swap(linear_x_, other->linear_x_);
  swap(angular_z_, other->angular_z_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata RdsMessage::GetMetadata() const {
  protobuf_mine_5frds_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_mine_5frds_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace robocar_rds
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::robocar_rds::Protocol* Arena::CreateMaybeMessage< ::robocar_rds::Protocol >(Arena* arena) {
  return Arena::CreateInternal< ::robocar_rds::Protocol >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::robocar_rds::VehMessage* Arena::CreateMaybeMessage< ::robocar_rds::VehMessage >(Arena* arena) {
  return Arena::CreateInternal< ::robocar_rds::VehMessage >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::robocar_rds::RdsMessage* Arena::CreateMaybeMessage< ::robocar_rds::RdsMessage >(Arena* arena) {
  return Arena::CreateInternal< ::robocar_rds::RdsMessage >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)