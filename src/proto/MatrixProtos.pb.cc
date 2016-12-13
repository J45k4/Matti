// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MatrixProtos.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MatrixProtos.pb.h"

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

const ::google::protobuf::Descriptor* MatrixProtos_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MatrixProtos_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MatrixProtos_2eproto() {
  protobuf_AddDesc_MatrixProtos_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MatrixProtos.proto");
  GOOGLE_CHECK(file != NULL);
  MatrixProtos_descriptor_ = file->message_type(0);
  static const int MatrixProtos_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MatrixProtos, matrixs_),
  };
  MatrixProtos_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      MatrixProtos_descriptor_,
      MatrixProtos::default_instance_,
      MatrixProtos_offsets_,
      -1,
      -1,
      -1,
      sizeof(MatrixProtos),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MatrixProtos, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MatrixProtos, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MatrixProtos_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      MatrixProtos_descriptor_, &MatrixProtos::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MatrixProtos_2eproto() {
  delete MatrixProtos::default_instance_;
  delete MatrixProtos_reflection_;
}

void protobuf_AddDesc_MatrixProtos_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_MatrixProto_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022MatrixProtos.proto\032\021MatrixProto.proto\""
    "-\n\014MatrixProtos\022\035\n\007matrixs\030\001 \003(\0132\014.Matri"
    "xProtob\006proto3", 94);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MatrixProtos.proto", &protobuf_RegisterTypes);
  MatrixProtos::default_instance_ = new MatrixProtos();
  MatrixProtos::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MatrixProtos_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MatrixProtos_2eproto {
  StaticDescriptorInitializer_MatrixProtos_2eproto() {
    protobuf_AddDesc_MatrixProtos_2eproto();
  }
} static_descriptor_initializer_MatrixProtos_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MatrixProtos::kMatrixsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MatrixProtos::MatrixProtos()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MatrixProtos)
}

void MatrixProtos::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

MatrixProtos::MatrixProtos(const MatrixProtos& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MatrixProtos)
}

void MatrixProtos::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
}

MatrixProtos::~MatrixProtos() {
  // @@protoc_insertion_point(destructor:MatrixProtos)
  SharedDtor();
}

void MatrixProtos::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MatrixProtos::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MatrixProtos::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MatrixProtos_descriptor_;
}

const MatrixProtos& MatrixProtos::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MatrixProtos_2eproto();
  return *default_instance_;
}

MatrixProtos* MatrixProtos::default_instance_ = NULL;

MatrixProtos* MatrixProtos::New(::google::protobuf::Arena* arena) const {
  MatrixProtos* n = new MatrixProtos;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MatrixProtos::Clear() {
  matrixs_.Clear();
}

bool MatrixProtos::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MatrixProtos)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .MatrixProto matrixs = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_matrixs:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_matrixs()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_matrixs;
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
  // @@protoc_insertion_point(parse_success:MatrixProtos)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MatrixProtos)
  return false;
#undef DO_
}

void MatrixProtos::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MatrixProtos)
  // repeated .MatrixProto matrixs = 1;
  for (unsigned int i = 0, n = this->matrixs_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->matrixs(i), output);
  }

  // @@protoc_insertion_point(serialize_end:MatrixProtos)
}

::google::protobuf::uint8* MatrixProtos::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MatrixProtos)
  // repeated .MatrixProto matrixs = 1;
  for (unsigned int i = 0, n = this->matrixs_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->matrixs(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:MatrixProtos)
  return target;
}

int MatrixProtos::ByteSize() const {
  int total_size = 0;

  // repeated .MatrixProto matrixs = 1;
  total_size += 1 * this->matrixs_size();
  for (int i = 0; i < this->matrixs_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->matrixs(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MatrixProtos::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const MatrixProtos* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const MatrixProtos>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MatrixProtos::MergeFrom(const MatrixProtos& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  matrixs_.MergeFrom(from.matrixs_);
}

void MatrixProtos::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MatrixProtos::CopyFrom(const MatrixProtos& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MatrixProtos::IsInitialized() const {

  return true;
}

void MatrixProtos::Swap(MatrixProtos* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MatrixProtos::InternalSwap(MatrixProtos* other) {
  matrixs_.UnsafeArenaSwap(&other->matrixs_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MatrixProtos::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MatrixProtos_descriptor_;
  metadata.reflection = MatrixProtos_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// MatrixProtos

// repeated .MatrixProto matrixs = 1;
int MatrixProtos::matrixs_size() const {
  return matrixs_.size();
}
void MatrixProtos::clear_matrixs() {
  matrixs_.Clear();
}
const ::MatrixProto& MatrixProtos::matrixs(int index) const {
  // @@protoc_insertion_point(field_get:MatrixProtos.matrixs)
  return matrixs_.Get(index);
}
::MatrixProto* MatrixProtos::mutable_matrixs(int index) {
  // @@protoc_insertion_point(field_mutable:MatrixProtos.matrixs)
  return matrixs_.Mutable(index);
}
::MatrixProto* MatrixProtos::add_matrixs() {
  // @@protoc_insertion_point(field_add:MatrixProtos.matrixs)
  return matrixs_.Add();
}
::google::protobuf::RepeatedPtrField< ::MatrixProto >*
MatrixProtos::mutable_matrixs() {
  // @@protoc_insertion_point(field_mutable_list:MatrixProtos.matrixs)
  return &matrixs_;
}
const ::google::protobuf::RepeatedPtrField< ::MatrixProto >&
MatrixProtos::matrixs() const {
  // @@protoc_insertion_point(field_list:MatrixProtos.matrixs)
  return matrixs_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)