// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#include "user.pb.h"

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

namespace test
{
  PROTOBUF_CONSTEXPR ResultCode::ResultCode(
      ::_pbi::ConstantInitialized) : _impl_{
                                         /*decltype(_impl_.errmsg_)*/ {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}, /*decltype(_impl_.errcode_)*/ 0, /*decltype(_impl_._cached_size_)*/ {}} {}
  struct ResultCodeDefaultTypeInternal
  {
    PROTOBUF_CONSTEXPR ResultCodeDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~ResultCodeDefaultTypeInternal() {}
    union
    {
      ResultCode _instance;
    };
  };
  PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResultCodeDefaultTypeInternal _ResultCode_default_instance_;
  PROTOBUF_CONSTEXPR LoginRequest::LoginRequest(
      ::_pbi::ConstantInitialized) : _impl_{
                                         /*decltype(_impl_.username_)*/ {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}, /*decltype(_impl_.password_)*/ {&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}, /*decltype(_impl_._cached_size_)*/ {}} {}
  struct LoginRequestDefaultTypeInternal
  {
    PROTOBUF_CONSTEXPR LoginRequestDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~LoginRequestDefaultTypeInternal() {}
    union
    {
      LoginRequest _instance;
    };
  };
  PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
  PROTOBUF_CONSTEXPR LoginResponse::LoginResponse(
      ::_pbi::ConstantInitialized) : _impl_{
                                         /*decltype(_impl_.result_)*/ nullptr, /*decltype(_impl_.success_)*/ false, /*decltype(_impl_._cached_size_)*/ {}} {}
  struct LoginResponseDefaultTypeInternal
  {
    PROTOBUF_CONSTEXPR LoginResponseDefaultTypeInternal()
        : _instance(::_pbi::ConstantInitialized{}) {}
    ~LoginResponseDefaultTypeInternal() {}
    union
    {
      LoginResponse _instance;
    };
  };
  PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
} // namespace test
static ::_pb::Metadata file_level_metadata_user_2eproto[3];
static constexpr ::_pb::EnumDescriptor const **file_level_enum_descriptors_user_2eproto = nullptr;
static const ::_pb::ServiceDescriptor *file_level_service_descriptors_user_2eproto[1];

const uint32_t TableStruct_user_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    ~0u, // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::test::ResultCode, _internal_metadata_),
    ~0u, // no _extensions_
    ~0u, // no _oneof_case_
    ~0u, // no _weak_field_map_
    ~0u, // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::test::ResultCode, _impl_.errcode_),
    PROTOBUF_FIELD_OFFSET(::test::ResultCode, _impl_.errmsg_),
    ~0u, // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::test::LoginRequest, _internal_metadata_),
    ~0u, // no _extensions_
    ~0u, // no _oneof_case_
    ~0u, // no _weak_field_map_
    ~0u, // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::test::LoginRequest, _impl_.username_),
    PROTOBUF_FIELD_OFFSET(::test::LoginRequest, _impl_.password_),
    ~0u, // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::test::LoginResponse, _internal_metadata_),
    ~0u, // no _extensions_
    ~0u, // no _oneof_case_
    ~0u, // no _weak_field_map_
    ~0u, // no _inlined_string_donated_
    PROTOBUF_FIELD_OFFSET(::test::LoginResponse, _impl_.result_),
    PROTOBUF_FIELD_OFFSET(::test::LoginResponse, _impl_.success_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    {0, -1, -1, sizeof(::test::ResultCode)},
    {8, -1, -1, sizeof(::test::LoginRequest)},
    {16, -1, -1, sizeof(::test::LoginResponse)},
};

static const ::_pb::Message *const file_default_instances[] = {
    &::test::_ResultCode_default_instance_._instance,
    &::test::_LoginRequest_default_instance_._instance,
    &::test::_LoginResponse_default_instance_._instance,
};

const char descriptor_table_protodef_user_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
    "\n\nuser.proto\022\004test\"-\n\nResultCode\022\017\n\007errc"
    "ode\030\001 \001(\005\022\016\n\006errmsg\030\002 \001(\014\"2\n\014LoginReques"
    "t\022\020\n\010username\030\001 \001(\014\022\020\n\010password\030\002 \001(\014\"B\n"
    "\rLoginResponse\022 \n\006result\030\001 \001(\0132\020.test.Re"
    "sultCode\022\017\n\007success\030\002 \001(\0102B\n\016UserService"
    "RPC\0220\n\005Login\022\022.test.LoginRequest\032\023.test."
    "LoginResponseB\003\200\001\001b\006proto3";
static ::_pbi::once_flag descriptor_table_user_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_user_2eproto = {
    false,
    false,
    266,
    descriptor_table_protodef_user_2eproto,
    "user.proto",
    &descriptor_table_user_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_user_2eproto::offsets,
    file_level_metadata_user_2eproto,
    file_level_enum_descriptors_user_2eproto,
    file_level_service_descriptors_user_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable *descriptor_table_user_2eproto_getter()
{
  return &descriptor_table_user_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_user_2eproto(&descriptor_table_user_2eproto);
namespace test
{

  // ===================================================================

  class ResultCode::_Internal
  {
  public:
  };

  ResultCode::ResultCode(::PROTOBUF_NAMESPACE_ID::Arena *arena,
                         bool is_message_owned)
      : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned)
  {
    SharedCtor(arena, is_message_owned);
    // @@protoc_insertion_point(arena_constructor:test.ResultCode)
  }
  ResultCode::ResultCode(const ResultCode &from)
      : ::PROTOBUF_NAMESPACE_ID::Message()
  {
    ResultCode *const _this = this;
    (void)_this;
    new (&_impl_) Impl_{
        decltype(_impl_.errmsg_){}, decltype(_impl_.errcode_){}, /*decltype(_impl_._cached_size_)*/ {}};

    _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
    _impl_.errmsg_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.errmsg_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_errmsg().empty())
    {
      _this->_impl_.errmsg_.Set(from._internal_errmsg(),
                                _this->GetArenaForAllocation());
    }
    _this->_impl_.errcode_ = from._impl_.errcode_;
    // @@protoc_insertion_point(copy_constructor:test.ResultCode)
  }

  inline void ResultCode::SharedCtor(
      ::_pb::Arena *arena, bool is_message_owned)
  {
    (void)arena;
    (void)is_message_owned;
    new (&_impl_) Impl_{
        decltype(_impl_.errmsg_){}, decltype(_impl_.errcode_){0}, /*decltype(_impl_._cached_size_)*/ {}};
    _impl_.errmsg_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.errmsg_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  }

  ResultCode::~ResultCode()
  {
    // @@protoc_insertion_point(destructor:test.ResultCode)
    if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>())
    {
      (void)arena;
      return;
    }
    SharedDtor();
  }

  inline void ResultCode::SharedDtor()
  {
    GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
    _impl_.errmsg_.Destroy();
  }

  void ResultCode::SetCachedSize(int size) const
  {
    _impl_._cached_size_.Set(size);
  }

  void ResultCode::Clear()
  {
    // @@protoc_insertion_point(message_clear_start:test.ResultCode)
    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    _impl_.errmsg_.ClearToEmpty();
    _impl_.errcode_ = 0;
    _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  const char *ResultCode::_InternalParse(const char *ptr, ::_pbi::ParseContext *ctx)
  {
#define CHK_(x)                     \
  if (PROTOBUF_PREDICT_FALSE(!(x))) \
  goto failure
    while (!ctx->Done(&ptr))
    {
      uint32_t tag;
      ptr = ::_pbi::ReadTag(ptr, &tag);
      switch (tag >> 3)
      {
      // int32 errcode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8))
        {
          _impl_.errcode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      // bytes errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18))
        {
          auto str = _internal_mutable_errmsg();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
      } // switch
    handle_unusual:
      if ((tag == 0) || ((tag & 7) == 4))
      {
        CHK_(ptr);
        ctx->SetLastTag(tag);
        goto message_done;
      }
      ptr = UnknownFieldParse(
          tag,
          _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
          ptr, ctx);
      CHK_(ptr != nullptr);
    } // while
  message_done:
    return ptr;
  failure:
    ptr = nullptr;
    goto message_done;
#undef CHK_
  }

  uint8_t *ResultCode::_InternalSerialize(
      uint8_t *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const
  {
    // @@protoc_insertion_point(serialize_to_array_start:test.ResultCode)
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    // int32 errcode = 1;
    if (this->_internal_errcode() != 0)
    {
      target = stream->EnsureSpace(target);
      target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_errcode(), target);
    }

    // bytes errmsg = 2;
    if (!this->_internal_errmsg().empty())
    {
      target = stream->WriteBytesMaybeAliased(
          2, this->_internal_errmsg(), target);
    }

    if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
    {
      target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
          _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
    }
    // @@protoc_insertion_point(serialize_to_array_end:test.ResultCode)
    return target;
  }

  size_t ResultCode::ByteSizeLong() const
  {
    // @@protoc_insertion_point(message_byte_size_start:test.ResultCode)
    size_t total_size = 0;

    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // bytes errmsg = 2;
    if (!this->_internal_errmsg().empty())
    {
      total_size += 1 +
                    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
                        this->_internal_errmsg());
    }

    // int32 errcode = 1;
    if (this->_internal_errcode() != 0)
    {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_errcode());
    }

    return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
  }

  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResultCode::_class_data_ = {
      ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
      ResultCode::MergeImpl};
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *ResultCode::GetClassData() const { return &_class_data_; }

  void ResultCode::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message &to_msg, const ::PROTOBUF_NAMESPACE_ID::Message &from_msg)
  {
    auto *const _this = static_cast<ResultCode *>(&to_msg);
    auto &from = static_cast<const ResultCode &>(from_msg);
    // @@protoc_insertion_point(class_specific_merge_from_start:test.ResultCode)
    GOOGLE_DCHECK_NE(&from, _this);
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    if (!from._internal_errmsg().empty())
    {
      _this->_internal_set_errmsg(from._internal_errmsg());
    }
    if (from._internal_errcode() != 0)
    {
      _this->_internal_set_errcode(from._internal_errcode());
    }
    _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  }

  void ResultCode::CopyFrom(const ResultCode &from)
  {
    // @@protoc_insertion_point(class_specific_copy_from_start:test.ResultCode)
    if (&from == this)
      return;
    Clear();
    MergeFrom(from);
  }

  bool ResultCode::IsInitialized() const
  {
    return true;
  }

  void ResultCode::InternalSwap(ResultCode *other)
  {
    using std::swap;
    auto *lhs_arena = GetArenaForAllocation();
    auto *rhs_arena = other->GetArenaForAllocation();
    _internal_metadata_.InternalSwap(&other->_internal_metadata_);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.errmsg_, lhs_arena,
        &other->_impl_.errmsg_, rhs_arena);
    swap(_impl_.errcode_, other->_impl_.errcode_);
  }

  ::PROTOBUF_NAMESPACE_ID::Metadata ResultCode::GetMetadata() const
  {
    return ::_pbi::AssignDescriptors(
        &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
        file_level_metadata_user_2eproto[0]);
  }

  // ===================================================================

  class LoginRequest::_Internal
  {
  public:
  };

  LoginRequest::LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena *arena,
                             bool is_message_owned)
      : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned)
  {
    SharedCtor(arena, is_message_owned);
    // @@protoc_insertion_point(arena_constructor:test.LoginRequest)
  }
  LoginRequest::LoginRequest(const LoginRequest &from)
      : ::PROTOBUF_NAMESPACE_ID::Message()
  {
    LoginRequest *const _this = this;
    (void)_this;
    new (&_impl_) Impl_{
        decltype(_impl_.username_){}, decltype(_impl_.password_){}, /*decltype(_impl_._cached_size_)*/ {}};

    _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
    _impl_.username_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.username_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_username().empty())
    {
      _this->_impl_.username_.Set(from._internal_username(),
                                  _this->GetArenaForAllocation());
    }
    _impl_.password_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.password_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    if (!from._internal_password().empty())
    {
      _this->_impl_.password_.Set(from._internal_password(),
                                  _this->GetArenaForAllocation());
    }
    // @@protoc_insertion_point(copy_constructor:test.LoginRequest)
  }

  inline void LoginRequest::SharedCtor(
      ::_pb::Arena *arena, bool is_message_owned)
  {
    (void)arena;
    (void)is_message_owned;
    new (&_impl_) Impl_{
        decltype(_impl_.username_){}, decltype(_impl_.password_){}, /*decltype(_impl_._cached_size_)*/ {}};
    _impl_.username_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.username_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.password_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.password_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  }

  LoginRequest::~LoginRequest()
  {
    // @@protoc_insertion_point(destructor:test.LoginRequest)
    if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>())
    {
      (void)arena;
      return;
    }
    SharedDtor();
  }

  inline void LoginRequest::SharedDtor()
  {
    GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
    _impl_.username_.Destroy();
    _impl_.password_.Destroy();
  }

  void LoginRequest::SetCachedSize(int size) const
  {
    _impl_._cached_size_.Set(size);
  }

  void LoginRequest::Clear()
  {
    // @@protoc_insertion_point(message_clear_start:test.LoginRequest)
    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    _impl_.username_.ClearToEmpty();
    _impl_.password_.ClearToEmpty();
    _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  const char *LoginRequest::_InternalParse(const char *ptr, ::_pbi::ParseContext *ctx)
  {
#define CHK_(x)                     \
  if (PROTOBUF_PREDICT_FALSE(!(x))) \
  goto failure
    while (!ctx->Done(&ptr))
    {
      uint32_t tag;
      ptr = ::_pbi::ReadTag(ptr, &tag);
      switch (tag >> 3)
      {
      // bytes username = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10))
        {
          auto str = _internal_mutable_username();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      // bytes password = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18))
        {
          auto str = _internal_mutable_password();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
      } // switch
    handle_unusual:
      if ((tag == 0) || ((tag & 7) == 4))
      {
        CHK_(ptr);
        ctx->SetLastTag(tag);
        goto message_done;
      }
      ptr = UnknownFieldParse(
          tag,
          _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
          ptr, ctx);
      CHK_(ptr != nullptr);
    } // while
  message_done:
    return ptr;
  failure:
    ptr = nullptr;
    goto message_done;
#undef CHK_
  }

  uint8_t *LoginRequest::_InternalSerialize(
      uint8_t *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const
  {
    // @@protoc_insertion_point(serialize_to_array_start:test.LoginRequest)
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    // bytes username = 1;
    if (!this->_internal_username().empty())
    {
      target = stream->WriteBytesMaybeAliased(
          1, this->_internal_username(), target);
    }

    // bytes password = 2;
    if (!this->_internal_password().empty())
    {
      target = stream->WriteBytesMaybeAliased(
          2, this->_internal_password(), target);
    }

    if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
    {
      target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
          _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
    }
    // @@protoc_insertion_point(serialize_to_array_end:test.LoginRequest)
    return target;
  }

  size_t LoginRequest::ByteSizeLong() const
  {
    // @@protoc_insertion_point(message_byte_size_start:test.LoginRequest)
    size_t total_size = 0;

    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // bytes username = 1;
    if (!this->_internal_username().empty())
    {
      total_size += 1 +
                    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
                        this->_internal_username());
    }

    // bytes password = 2;
    if (!this->_internal_password().empty())
    {
      total_size += 1 +
                    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
                        this->_internal_password());
    }

    return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
  }

  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LoginRequest::_class_data_ = {
      ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
      LoginRequest::MergeImpl};
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *LoginRequest::GetClassData() const { return &_class_data_; }

  void LoginRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message &to_msg, const ::PROTOBUF_NAMESPACE_ID::Message &from_msg)
  {
    auto *const _this = static_cast<LoginRequest *>(&to_msg);
    auto &from = static_cast<const LoginRequest &>(from_msg);
    // @@protoc_insertion_point(class_specific_merge_from_start:test.LoginRequest)
    GOOGLE_DCHECK_NE(&from, _this);
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    if (!from._internal_username().empty())
    {
      _this->_internal_set_username(from._internal_username());
    }
    if (!from._internal_password().empty())
    {
      _this->_internal_set_password(from._internal_password());
    }
    _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  }

  void LoginRequest::CopyFrom(const LoginRequest &from)
  {
    // @@protoc_insertion_point(class_specific_copy_from_start:test.LoginRequest)
    if (&from == this)
      return;
    Clear();
    MergeFrom(from);
  }

  bool LoginRequest::IsInitialized() const
  {
    return true;
  }

  void LoginRequest::InternalSwap(LoginRequest *other)
  {
    using std::swap;
    auto *lhs_arena = GetArenaForAllocation();
    auto *rhs_arena = other->GetArenaForAllocation();
    _internal_metadata_.InternalSwap(&other->_internal_metadata_);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.username_, lhs_arena,
        &other->_impl_.username_, rhs_arena);
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
        &_impl_.password_, lhs_arena,
        &other->_impl_.password_, rhs_arena);
  }

  ::PROTOBUF_NAMESPACE_ID::Metadata LoginRequest::GetMetadata() const
  {
    return ::_pbi::AssignDescriptors(
        &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
        file_level_metadata_user_2eproto[1]);
  }

  // ===================================================================

  class LoginResponse::_Internal
  {
  public:
    static const ::test::ResultCode &result(const LoginResponse *msg);
  };

  const ::test::ResultCode &
  LoginResponse::_Internal::result(const LoginResponse *msg)
  {
    return *msg->_impl_.result_;
  }
  LoginResponse::LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena *arena,
                               bool is_message_owned)
      : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned)
  {
    SharedCtor(arena, is_message_owned);
    // @@protoc_insertion_point(arena_constructor:test.LoginResponse)
  }
  LoginResponse::LoginResponse(const LoginResponse &from)
      : ::PROTOBUF_NAMESPACE_ID::Message()
  {
    LoginResponse *const _this = this;
    (void)_this;
    new (&_impl_) Impl_{
        decltype(_impl_.result_){nullptr}, decltype(_impl_.success_){}, /*decltype(_impl_._cached_size_)*/ {}};

    _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
    if (from._internal_has_result())
    {
      _this->_impl_.result_ = new ::test::ResultCode(*from._impl_.result_);
    }
    _this->_impl_.success_ = from._impl_.success_;
    // @@protoc_insertion_point(copy_constructor:test.LoginResponse)
  }

  inline void LoginResponse::SharedCtor(
      ::_pb::Arena *arena, bool is_message_owned)
  {
    (void)arena;
    (void)is_message_owned;
    new (&_impl_) Impl_{
        decltype(_impl_.result_){nullptr}, decltype(_impl_.success_){false}, /*decltype(_impl_._cached_size_)*/ {}};
  }

  LoginResponse::~LoginResponse()
  {
    // @@protoc_insertion_point(destructor:test.LoginResponse)
    if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>())
    {
      (void)arena;
      return;
    }
    SharedDtor();
  }

  inline void LoginResponse::SharedDtor()
  {
    GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
    if (this != internal_default_instance())
      delete _impl_.result_;
  }

  void LoginResponse::SetCachedSize(int size) const
  {
    _impl_._cached_size_.Set(size);
  }

  void LoginResponse::Clear()
  {
    // @@protoc_insertion_point(message_clear_start:test.LoginResponse)
    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    if (GetArenaForAllocation() == nullptr && _impl_.result_ != nullptr)
    {
      delete _impl_.result_;
    }
    _impl_.result_ = nullptr;
    _impl_.success_ = false;
    _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  const char *LoginResponse::_InternalParse(const char *ptr, ::_pbi::ParseContext *ctx)
  {
#define CHK_(x)                     \
  if (PROTOBUF_PREDICT_FALSE(!(x))) \
  goto failure
    while (!ctx->Done(&ptr))
    {
      uint32_t tag;
      ptr = ::_pbi::ReadTag(ptr, &tag);
      switch (tag >> 3)
      {
      // .test.ResultCode result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10))
        {
          ptr = ctx->ParseMessage(_internal_mutable_result(), ptr);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      // bool success = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16))
        {
          _impl_.success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        }
        else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
      } // switch
    handle_unusual:
      if ((tag == 0) || ((tag & 7) == 4))
      {
        CHK_(ptr);
        ctx->SetLastTag(tag);
        goto message_done;
      }
      ptr = UnknownFieldParse(
          tag,
          _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
          ptr, ctx);
      CHK_(ptr != nullptr);
    } // while
  message_done:
    return ptr;
  failure:
    ptr = nullptr;
    goto message_done;
#undef CHK_
  }

  uint8_t *LoginResponse::_InternalSerialize(
      uint8_t *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const
  {
    // @@protoc_insertion_point(serialize_to_array_start:test.LoginResponse)
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    // .test.ResultCode result = 1;
    if (this->_internal_has_result())
    {
      target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
          InternalWriteMessage(1, _Internal::result(this),
                               _Internal::result(this).GetCachedSize(), target, stream);
    }

    // bool success = 2;
    if (this->_internal_success() != 0)
    {
      target = stream->EnsureSpace(target);
      target = ::_pbi::WireFormatLite::WriteBoolToArray(2, this->_internal_success(), target);
    }

    if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
    {
      target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
          _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
    }
    // @@protoc_insertion_point(serialize_to_array_end:test.LoginResponse)
    return target;
  }

  size_t LoginResponse::ByteSizeLong() const
  {
    // @@protoc_insertion_point(message_byte_size_start:test.LoginResponse)
    size_t total_size = 0;

    uint32_t cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // .test.ResultCode result = 1;
    if (this->_internal_has_result())
    {
      total_size += 1 +
                    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
                        *_impl_.result_);
    }

    // bool success = 2;
    if (this->_internal_success() != 0)
    {
      total_size += 1 + 1;
    }

    return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
  }

  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LoginResponse::_class_data_ = {
      ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
      LoginResponse::MergeImpl};
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *LoginResponse::GetClassData() const { return &_class_data_; }

  void LoginResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message &to_msg, const ::PROTOBUF_NAMESPACE_ID::Message &from_msg)
  {
    auto *const _this = static_cast<LoginResponse *>(&to_msg);
    auto &from = static_cast<const LoginResponse &>(from_msg);
    // @@protoc_insertion_point(class_specific_merge_from_start:test.LoginResponse)
    GOOGLE_DCHECK_NE(&from, _this);
    uint32_t cached_has_bits = 0;
    (void)cached_has_bits;

    if (from._internal_has_result())
    {
      _this->_internal_mutable_result()->::test::ResultCode::MergeFrom(
          from._internal_result());
    }
    if (from._internal_success() != 0)
    {
      _this->_internal_set_success(from._internal_success());
    }
    _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  }

  void LoginResponse::CopyFrom(const LoginResponse &from)
  {
    // @@protoc_insertion_point(class_specific_copy_from_start:test.LoginResponse)
    if (&from == this)
      return;
    Clear();
    MergeFrom(from);
  }

  bool LoginResponse::IsInitialized() const
  {
    return true;
  }

  void LoginResponse::InternalSwap(LoginResponse *other)
  {
    using std::swap;
    _internal_metadata_.InternalSwap(&other->_internal_metadata_);
    ::PROTOBUF_NAMESPACE_ID::internal::memswap<
        PROTOBUF_FIELD_OFFSET(LoginResponse, _impl_.success_) + sizeof(LoginResponse::_impl_.success_) - PROTOBUF_FIELD_OFFSET(LoginResponse, _impl_.result_)>(
        reinterpret_cast<char *>(&_impl_.result_),
        reinterpret_cast<char *>(&other->_impl_.result_));
  }

  ::PROTOBUF_NAMESPACE_ID::Metadata LoginResponse::GetMetadata() const
  {
    return ::_pbi::AssignDescriptors(
        &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
        file_level_metadata_user_2eproto[2]);
  }

  // ===================================================================

  UserServiceRPC::~UserServiceRPC() {}

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor *UserServiceRPC::descriptor()
  {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_user_2eproto);
    return file_level_service_descriptors_user_2eproto[0];
  }

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor *UserServiceRPC::GetDescriptor()
  {
    return descriptor();
  }

  void UserServiceRPC::Login(::PROTOBUF_NAMESPACE_ID::RpcController *controller,
                             const ::test::LoginRequest *,
                             ::test::LoginResponse *,
                             ::google::protobuf::Closure *done)
  {
    controller->SetFailed("Method Login() not implemented.");
    done->Run();
  }

  void UserServiceRPC::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor *method,
                                  ::PROTOBUF_NAMESPACE_ID::RpcController *controller,
                                  const ::PROTOBUF_NAMESPACE_ID::Message *request,
                                  ::PROTOBUF_NAMESPACE_ID::Message *response,
                                  ::google::protobuf::Closure *done)
  {
    GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_user_2eproto[0]);
    switch (method->index())
    {
    case 0:
      Login(controller,
            ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::test::LoginRequest *>(
                request),
            ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::test::LoginResponse *>(
                response),
            done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
    }
  }

  const ::PROTOBUF_NAMESPACE_ID::Message &UserServiceRPC::GetRequestPrototype(
      const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor *method) const
  {
    GOOGLE_DCHECK_EQ(method->service(), descriptor());
    switch (method->index())
    {
    case 0:
      return ::test::LoginRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
                  ->GetPrototype(method->input_type());
    }
  }

  const ::PROTOBUF_NAMESPACE_ID::Message &UserServiceRPC::GetResponsePrototype(
      const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor *method) const
  {
    GOOGLE_DCHECK_EQ(method->service(), descriptor());
    switch (method->index())
    {
    case 0:
      return ::test::LoginResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
                  ->GetPrototype(method->output_type());
    }
  }

  UserServiceRPC_Stub::UserServiceRPC_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel *channel)
      : channel_(channel), owns_channel_(false) {}
  UserServiceRPC_Stub::UserServiceRPC_Stub(
      ::PROTOBUF_NAMESPACE_ID::RpcChannel *channel,
      ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
      : channel_(channel),
        owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
  UserServiceRPC_Stub::~UserServiceRPC_Stub()
  {
    if (owns_channel_)
      delete channel_;
  }

  void UserServiceRPC_Stub::Login(::PROTOBUF_NAMESPACE_ID::RpcController *controller,
                                  const ::test::LoginRequest *request,
                                  ::test::LoginResponse *response,
                                  ::google::protobuf::Closure *done)
  {
    channel_->CallMethod(descriptor()->method(0),
                         controller, request, response, done);
  }

  // @@protoc_insertion_point(namespace_scope)
} // namespace test
PROTOBUF_NAMESPACE_OPEN
template <>
PROTOBUF_NOINLINE ::test::ResultCode *
Arena::CreateMaybeMessage<::test::ResultCode>(Arena *arena)
{
  return Arena::CreateMessageInternal<::test::ResultCode>(arena);
}
template <>
PROTOBUF_NOINLINE ::test::LoginRequest *
Arena::CreateMaybeMessage<::test::LoginRequest>(Arena *arena)
{
  return Arena::CreateMessageInternal<::test::LoginRequest>(arena);
}
template <>
PROTOBUF_NOINLINE ::test::LoginResponse *
Arena::CreateMaybeMessage<::test::LoginResponse>(Arena *arena)
{
  return Arena::CreateMessageInternal<::test::LoginResponse>(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
