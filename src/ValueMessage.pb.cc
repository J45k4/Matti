// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ValueMessage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ValueMessage.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ValueMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ValueMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_ValueMessage_2eproto() {
  protobuf_AddDesc_ValueMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ValueMessage.proto");
  GOOGLE_CHECK(file != NULL);
  ValueMessage_descriptor_ = file->message_type(0);
  static const int ValueMessage_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueMessage, cpu_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueMessage, con_),
  };
  ValueMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ValueMessage_descriptor_,
      ValueMessage::default_instance_,
      ValueMessage_offsets_,
      -1,
      -1,
      -1,
      sizeof(ValueMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueMessage, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueMessage, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ValueMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ValueMessage_descriptor_, &ValueMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ValueMessage_2eproto() {
  delete ValueMessage::default_instance_;
  delete ValueMessage_reflection_;
}

void protobuf_AddDesc_ValueMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022ValueMessage.proto\"(\n\014ValueMessage\022\013\n\003"
    "cpu\030\001 \001(\r\022\013\n\003con\030\002 \001(\rb\006proto3", 70);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ValueMessage.proto", &protobuf_RegisterTypes);
  ValueMessage::default_instance_ = new ValueMessage();
  ValueMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ValueMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ValueMessage_2eproto {
  StaticDescriptorInitializer_ValueMessage_2eproto() {
    protobuf_AddDesc_ValueMessage_2eproto();
  }
} static_descriptor_initializer_ValueMessage_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ValueMessage::kCpuFieldNumber;
const int ValueMessage::kConFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ValueMessage::ValueMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ValueMessage)
}

void ValueMessage::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

ValueMessage::ValueMessage(const ValueMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ValueMessage)
}

void ValueMessage::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  cpu_ = 0u;
  con_ = 0u;
}

ValueMessage::~ValueMessage() {
  // @@protoc_insertion_point(destructor:ValueMessage)
  SharedDtor();
}

void ValueMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ValueMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ValueMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ValueMessage_descriptor_;
}

const ValueMessage& ValueMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ValueMessage_2eproto();
  return *default_instance_;
}

ValueMessage* ValueMessage::default_instance_ = NULL;

ValueMessage* ValueMessage::New(::google::protobuf::Arena* arena) const {
  ValueMessage* n = new ValueMessage;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ValueMessage::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<ValueMessage*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(cpu_, con_);

#undef ZR_HELPER_
#undef ZR_

}

bool ValueMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ValueMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 cpu = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &cpu_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_con;
        break;
      }

      // optional uint32 con = 2;
      case 2: {
        if (tag == 16) {
         parse_con:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &con_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ValueMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ValueMessage)
  return false;
#undef DO_
}

void ValueMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ValueMessage)
  // optional uint32 cpu = 1;
  if (this->cpu() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->cpu(), output);
  }

  // optional uint32 con = 2;
  if (this->con() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->con(), output);
  }

  // @@protoc_insertion_point(serialize_end:ValueMessage)
}

::google::protobuf::uint8* ValueMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ValueMessage)
  // optional uint32 cpu = 1;
  if (this->cpu() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->cpu(), target);
  }

  // optional uint32 con = 2;
  if (this->con() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->con(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:ValueMessage)
  return target;
}

int ValueMessage::ByteSize() const {
  int total_size = 0;

  // optional uint32 cpu = 1;
  if (this->cpu() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->cpu());
  }

  // optional uint32 con = 2;
  if (this->con() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->con());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ValueMessage::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ValueMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ValueMessage>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ValueMessage::MergeFrom(const ValueMessage& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.cpu() != 0) {
    set_cpu(from.cpu());
  }
  if (from.con() != 0) {
    set_con(from.con());
  }
}

void ValueMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ValueMessage::CopyFrom(const ValueMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ValueMessage::IsInitialized() const {

  return true;
}

void ValueMessage::Swap(ValueMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ValueMessage::InternalSwap(ValueMessage* other) {
  std::swap(cpu_, other->cpu_);
  std::swap(con_, other->con_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ValueMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ValueMessage_descriptor_;
  metadata.reflection = ValueMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ValueMessage

// optional uint32 cpu = 1;
void ValueMessage::clear_cpu() {
  cpu_ = 0u;
}
 ::google::protobuf::uint32 ValueMessage::cpu() const {
  // @@protoc_insertion_point(field_get:ValueMessage.cpu)
  return cpu_;
}
 void ValueMessage::set_cpu(::google::protobuf::uint32 value) {
  
  cpu_ = value;
  // @@protoc_insertion_point(field_set:ValueMessage.cpu)
}

// optional uint32 con = 2;
void ValueMessage::clear_con() {
  con_ = 0u;
}
 ::google::protobuf::uint32 ValueMessage::con() const {
  // @@protoc_insertion_point(field_get:ValueMessage.con)
  return con_;
}
 void ValueMessage::set_con(::google::protobuf::uint32 value) {
  
  con_ = value;
  // @@protoc_insertion_point(field_set:ValueMessage.con)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)