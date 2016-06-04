// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MattiRequest.proto

#ifndef PROTOBUF_MattiRequest_2eproto__INCLUDED
#define PROTOBUF_MattiRequest_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "VideoConnection.pb.h"
#include "KwmConnection.pb.h"
#include "RequestValue.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_MattiRequest_2eproto();
void protobuf_AssignDesc_MattiRequest_2eproto();
void protobuf_ShutdownFile_MattiRequest_2eproto();

class MattiRequest;

// ===================================================================

class MattiRequest : public ::google::protobuf::Message {
 public:
  MattiRequest();
  virtual ~MattiRequest();

  MattiRequest(const MattiRequest& from);

  inline MattiRequest& operator=(const MattiRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MattiRequest& default_instance();

  enum RequestMessageCase {
    kVideoConnection = 2,
    kKwmConnection = 3,
    kRequestValue = 4,
    REQUESTMESSAGE_NOT_SET = 0,
  };

  void Swap(MattiRequest* other);

  // implements Message ----------------------------------------------

  inline MattiRequest* New() const { return New(NULL); }

  MattiRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MattiRequest& from);
  void MergeFrom(const MattiRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MattiRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 ticket = 1;
  void clear_ticket();
  static const int kTicketFieldNumber = 1;
  ::google::protobuf::uint32 ticket() const;
  void set_ticket(::google::protobuf::uint32 value);

  // optional .VideoConnection videoConnection = 2;
  bool has_videoconnection() const;
  void clear_videoconnection();
  static const int kVideoConnectionFieldNumber = 2;
  const ::VideoConnection& videoconnection() const;
  ::VideoConnection* mutable_videoconnection();
  ::VideoConnection* release_videoconnection();
  void set_allocated_videoconnection(::VideoConnection* videoconnection);

  // optional .KwmConnection kwmConnection = 3;
  bool has_kwmconnection() const;
  void clear_kwmconnection();
  static const int kKwmConnectionFieldNumber = 3;
  const ::KwmConnection& kwmconnection() const;
  ::KwmConnection* mutable_kwmconnection();
  ::KwmConnection* release_kwmconnection();
  void set_allocated_kwmconnection(::KwmConnection* kwmconnection);

  // optional .RequestValue requestValue = 4;
  bool has_requestvalue() const;
  void clear_requestvalue();
  static const int kRequestValueFieldNumber = 4;
  const ::RequestValue& requestvalue() const;
  ::RequestValue* mutable_requestvalue();
  ::RequestValue* release_requestvalue();
  void set_allocated_requestvalue(::RequestValue* requestvalue);

  RequestMessageCase requestMessage_case() const;
  // @@protoc_insertion_point(class_scope:MattiRequest)
 private:
  inline void set_has_videoconnection();
  inline void set_has_kwmconnection();
  inline void set_has_requestvalue();

  inline bool has_requestMessage() const;
  void clear_requestMessage();
  inline void clear_has_requestMessage();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::uint32 ticket_;
  union RequestMessageUnion {
    RequestMessageUnion() {}
    ::VideoConnection* videoconnection_;
    ::KwmConnection* kwmconnection_;
    ::RequestValue* requestvalue_;
  } requestMessage_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend void  protobuf_AddDesc_MattiRequest_2eproto();
  friend void protobuf_AssignDesc_MattiRequest_2eproto();
  friend void protobuf_ShutdownFile_MattiRequest_2eproto();

  void InitAsDefaultInstance();
  static MattiRequest* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// MattiRequest

// optional uint32 ticket = 1;
inline void MattiRequest::clear_ticket() {
  ticket_ = 0u;
}
inline ::google::protobuf::uint32 MattiRequest::ticket() const {
  // @@protoc_insertion_point(field_get:MattiRequest.ticket)
  return ticket_;
}
inline void MattiRequest::set_ticket(::google::protobuf::uint32 value) {
  
  ticket_ = value;
  // @@protoc_insertion_point(field_set:MattiRequest.ticket)
}

// optional .VideoConnection videoConnection = 2;
inline bool MattiRequest::has_videoconnection() const {
  return requestMessage_case() == kVideoConnection;
}
inline void MattiRequest::set_has_videoconnection() {
  _oneof_case_[0] = kVideoConnection;
}
inline void MattiRequest::clear_videoconnection() {
  if (has_videoconnection()) {
    delete requestMessage_.videoconnection_;
    clear_has_requestMessage();
  }
}
inline  const ::VideoConnection& MattiRequest::videoconnection() const {
  // @@protoc_insertion_point(field_get:MattiRequest.videoConnection)
  return has_videoconnection()
      ? *requestMessage_.videoconnection_
      : ::VideoConnection::default_instance();
}
inline ::VideoConnection* MattiRequest::mutable_videoconnection() {
  if (!has_videoconnection()) {
    clear_requestMessage();
    set_has_videoconnection();
    requestMessage_.videoconnection_ = new ::VideoConnection;
  }
  // @@protoc_insertion_point(field_mutable:MattiRequest.videoConnection)
  return requestMessage_.videoconnection_;
}
inline ::VideoConnection* MattiRequest::release_videoconnection() {
  if (has_videoconnection()) {
    clear_has_requestMessage();
    ::VideoConnection* temp = requestMessage_.videoconnection_;
    requestMessage_.videoconnection_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void MattiRequest::set_allocated_videoconnection(::VideoConnection* videoconnection) {
  clear_requestMessage();
  if (videoconnection) {
    set_has_videoconnection();
    requestMessage_.videoconnection_ = videoconnection;
  }
  // @@protoc_insertion_point(field_set_allocated:MattiRequest.videoConnection)
}

// optional .KwmConnection kwmConnection = 3;
inline bool MattiRequest::has_kwmconnection() const {
  return requestMessage_case() == kKwmConnection;
}
inline void MattiRequest::set_has_kwmconnection() {
  _oneof_case_[0] = kKwmConnection;
}
inline void MattiRequest::clear_kwmconnection() {
  if (has_kwmconnection()) {
    delete requestMessage_.kwmconnection_;
    clear_has_requestMessage();
  }
}
inline  const ::KwmConnection& MattiRequest::kwmconnection() const {
  // @@protoc_insertion_point(field_get:MattiRequest.kwmConnection)
  return has_kwmconnection()
      ? *requestMessage_.kwmconnection_
      : ::KwmConnection::default_instance();
}
inline ::KwmConnection* MattiRequest::mutable_kwmconnection() {
  if (!has_kwmconnection()) {
    clear_requestMessage();
    set_has_kwmconnection();
    requestMessage_.kwmconnection_ = new ::KwmConnection;
  }
  // @@protoc_insertion_point(field_mutable:MattiRequest.kwmConnection)
  return requestMessage_.kwmconnection_;
}
inline ::KwmConnection* MattiRequest::release_kwmconnection() {
  if (has_kwmconnection()) {
    clear_has_requestMessage();
    ::KwmConnection* temp = requestMessage_.kwmconnection_;
    requestMessage_.kwmconnection_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void MattiRequest::set_allocated_kwmconnection(::KwmConnection* kwmconnection) {
  clear_requestMessage();
  if (kwmconnection) {
    set_has_kwmconnection();
    requestMessage_.kwmconnection_ = kwmconnection;
  }
  // @@protoc_insertion_point(field_set_allocated:MattiRequest.kwmConnection)
}

// optional .RequestValue requestValue = 4;
inline bool MattiRequest::has_requestvalue() const {
  return requestMessage_case() == kRequestValue;
}
inline void MattiRequest::set_has_requestvalue() {
  _oneof_case_[0] = kRequestValue;
}
inline void MattiRequest::clear_requestvalue() {
  if (has_requestvalue()) {
    delete requestMessage_.requestvalue_;
    clear_has_requestMessage();
  }
}
inline  const ::RequestValue& MattiRequest::requestvalue() const {
  // @@protoc_insertion_point(field_get:MattiRequest.requestValue)
  return has_requestvalue()
      ? *requestMessage_.requestvalue_
      : ::RequestValue::default_instance();
}
inline ::RequestValue* MattiRequest::mutable_requestvalue() {
  if (!has_requestvalue()) {
    clear_requestMessage();
    set_has_requestvalue();
    requestMessage_.requestvalue_ = new ::RequestValue;
  }
  // @@protoc_insertion_point(field_mutable:MattiRequest.requestValue)
  return requestMessage_.requestvalue_;
}
inline ::RequestValue* MattiRequest::release_requestvalue() {
  if (has_requestvalue()) {
    clear_has_requestMessage();
    ::RequestValue* temp = requestMessage_.requestvalue_;
    requestMessage_.requestvalue_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void MattiRequest::set_allocated_requestvalue(::RequestValue* requestvalue) {
  clear_requestMessage();
  if (requestvalue) {
    set_has_requestvalue();
    requestMessage_.requestvalue_ = requestvalue;
  }
  // @@protoc_insertion_point(field_set_allocated:MattiRequest.requestValue)
}

inline bool MattiRequest::has_requestMessage() const {
  return requestMessage_case() != REQUESTMESSAGE_NOT_SET;
}
inline void MattiRequest::clear_has_requestMessage() {
  _oneof_case_[0] = REQUESTMESSAGE_NOT_SET;
}
inline MattiRequest::RequestMessageCase MattiRequest::requestMessage_case() const {
  return MattiRequest::RequestMessageCase(_oneof_case_[0]);
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MattiRequest_2eproto__INCLUDED