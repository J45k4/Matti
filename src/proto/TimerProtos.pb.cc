// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TimerProtos.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "TimerProtos.pb.h"

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

const ::google::protobuf::Descriptor* TimerProtos_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TimerProtos_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_TimerProtos_2eproto() {
  protobuf_AddDesc_TimerProtos_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "TimerProtos.proto");
  GOOGLE_CHECK(file != NULL);
  TimerProtos_descriptor_ = file->message_type(0);
  static const int TimerProtos_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimerProtos, timers_),
  };
  TimerProtos_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      TimerProtos_descriptor_,
      TimerProtos::default_instance_,
      TimerProtos_offsets_,
      -1,
      -1,
      -1,
      sizeof(TimerProtos),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimerProtos, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimerProtos, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_TimerProtos_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      TimerProtos_descriptor_, &TimerProtos::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_TimerProtos_2eproto() {
  delete TimerProtos::default_instance_;
  delete TimerProtos_reflection_;
}

void protobuf_AddDesc_TimerProtos_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_TimerProto_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021TimerProtos.proto\032\020TimerProto.proto\"*\n"
    "\013TimerProtos\022\033\n\006timers\030\001 \003(\0132\013.TimerProt"
    "ob\006proto3", 89);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "TimerProtos.proto", &protobuf_RegisterTypes);
  TimerProtos::default_instance_ = new TimerProtos();
  TimerProtos::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_TimerProtos_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_TimerProtos_2eproto {
  StaticDescriptorInitializer_TimerProtos_2eproto() {
    protobuf_AddDesc_TimerProtos_2eproto();
  }
} static_descriptor_initializer_TimerProtos_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TimerProtos::kTimersFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TimerProtos::TimerProtos()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TimerProtos)
}

void TimerProtos::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

TimerProtos::TimerProtos(const TimerProtos& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:TimerProtos)
}

void TimerProtos::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

TimerProtos::~TimerProtos() {
  // @@protoc_insertion_point(destructor:TimerProtos)
  SharedDtor();
}

void TimerProtos::SharedDtor() {
  if (this != default_instance_) {
  }
}

void TimerProtos::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TimerProtos::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TimerProtos_descriptor_;
}

const TimerProtos& TimerProtos::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_TimerProtos_2eproto();
  return *default_instance_;
}

TimerProtos* TimerProtos::default_instance_ = NULL;

TimerProtos* TimerProtos::New(::google::protobuf::Arena* arena) const {
  TimerProtos* n = new TimerProtos;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void TimerProtos::Clear() {
  timers_.Clear();
}

bool TimerProtos::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:TimerProtos)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .TimerProto timers = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_timers:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_timers()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_timers;
        input->UnsafeDecrementRecursionDepth();
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
  // @@protoc_insertion_point(parse_success:TimerProtos)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TimerProtos)
  return false;
#undef DO_
}

void TimerProtos::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TimerProtos)
  // repeated .TimerProto timers = 1;
  for (unsigned int i = 0, n = this->timers_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->timers(i), output);
  }

  // @@protoc_insertion_point(serialize_end:TimerProtos)
}

::google::protobuf::uint8* TimerProtos::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:TimerProtos)
  // repeated .TimerProto timers = 1;
  for (unsigned int i = 0, n = this->timers_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->timers(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:TimerProtos)
  return target;
}

int TimerProtos::ByteSize() const {
  int total_size = 0;

  // repeated .TimerProto timers = 1;
  total_size += 1 * this->timers_size();
  for (int i = 0; i < this->timers_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->timers(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TimerProtos::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const TimerProtos* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const TimerProtos>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TimerProtos::MergeFrom(const TimerProtos& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  timers_.MergeFrom(from.timers_);
}

void TimerProtos::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TimerProtos::CopyFrom(const TimerProtos& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TimerProtos::IsInitialized() const {

  return true;
}

void TimerProtos::Swap(TimerProtos* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TimerProtos::InternalSwap(TimerProtos* other) {
  timers_.UnsafeArenaSwap(&other->timers_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata TimerProtos::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TimerProtos_descriptor_;
  metadata.reflection = TimerProtos_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TimerProtos

// repeated .TimerProto timers = 1;
int TimerProtos::timers_size() const {
  return timers_.size();
}
void TimerProtos::clear_timers() {
  timers_.Clear();
}
const ::TimerProto& TimerProtos::timers(int index) const {
  // @@protoc_insertion_point(field_get:TimerProtos.timers)
  return timers_.Get(index);
}
::TimerProto* TimerProtos::mutable_timers(int index) {
  // @@protoc_insertion_point(field_mutable:TimerProtos.timers)
  return timers_.Mutable(index);
}
::TimerProto* TimerProtos::add_timers() {
  // @@protoc_insertion_point(field_add:TimerProtos.timers)
  return timers_.Add();
}
::google::protobuf::RepeatedPtrField< ::TimerProto >*
TimerProtos::mutable_timers() {
  // @@protoc_insertion_point(field_mutable_list:TimerProtos.timers)
  return &timers_;
}
const ::google::protobuf::RepeatedPtrField< ::TimerProto >&
TimerProtos::timers() const {
  // @@protoc_insertion_point(field_list:TimerProtos.timers)
  return timers_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
