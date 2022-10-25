// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gameState.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_gameState_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_gameState_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021007 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_gameState_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_gameState_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_gameState_2eproto;
class gameState;
struct gameStateDefaultTypeInternal;
extern gameStateDefaultTypeInternal _gameState_default_instance_;
class gameState_playerState;
struct gameState_playerStateDefaultTypeInternal;
extern gameState_playerStateDefaultTypeInternal _gameState_playerState_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::gameState* Arena::CreateMaybeMessage<::gameState>(Arena*);
template<> ::gameState_playerState* Arena::CreateMaybeMessage<::gameState_playerState>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class gameState_playerState final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:gameState.playerState) */ {
 public:
  inline gameState_playerState() : gameState_playerState(nullptr) {}
  ~gameState_playerState() override;
  explicit PROTOBUF_CONSTEXPR gameState_playerState(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  gameState_playerState(const gameState_playerState& from);
  gameState_playerState(gameState_playerState&& from) noexcept
    : gameState_playerState() {
    *this = ::std::move(from);
  }

  inline gameState_playerState& operator=(const gameState_playerState& from) {
    CopyFrom(from);
    return *this;
  }
  inline gameState_playerState& operator=(gameState_playerState&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const gameState_playerState& default_instance() {
    return *internal_default_instance();
  }
  static inline const gameState_playerState* internal_default_instance() {
    return reinterpret_cast<const gameState_playerState*>(
               &_gameState_playerState_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(gameState_playerState& a, gameState_playerState& b) {
    a.Swap(&b);
  }
  inline void Swap(gameState_playerState* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(gameState_playerState* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  gameState_playerState* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<gameState_playerState>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const gameState_playerState& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const gameState_playerState& from) {
    gameState_playerState::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(gameState_playerState* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "gameState.playerState";
  }
  protected:
  explicit gameState_playerState(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kActionFieldNumber = 8,
    kHpFieldNumber = 1,
    kBulletsFieldNumber = 2,
    kGrenadesFieldNumber = 3,
    kShieldTimeFieldNumber = 4,
    kShieldHealthFieldNumber = 5,
    kNumDeathsFieldNumber = 6,
    kNumShieldFieldNumber = 7,
  };
  // required string action = 8;
  bool has_action() const;
  private:
  bool _internal_has_action() const;
  public:
  void clear_action();
  const std::string& action() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_action(ArgT0&& arg0, ArgT... args);
  std::string* mutable_action();
  PROTOBUF_NODISCARD std::string* release_action();
  void set_allocated_action(std::string* action);
  private:
  const std::string& _internal_action() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_action(const std::string& value);
  std::string* _internal_mutable_action();
  public:

  // required int32 hp = 1;
  bool has_hp() const;
  private:
  bool _internal_has_hp() const;
  public:
  void clear_hp();
  int32_t hp() const;
  void set_hp(int32_t value);
  private:
  int32_t _internal_hp() const;
  void _internal_set_hp(int32_t value);
  public:

  // required int32 bullets = 2;
  bool has_bullets() const;
  private:
  bool _internal_has_bullets() const;
  public:
  void clear_bullets();
  int32_t bullets() const;
  void set_bullets(int32_t value);
  private:
  int32_t _internal_bullets() const;
  void _internal_set_bullets(int32_t value);
  public:

  // required int32 grenades = 3;
  bool has_grenades() const;
  private:
  bool _internal_has_grenades() const;
  public:
  void clear_grenades();
  int32_t grenades() const;
  void set_grenades(int32_t value);
  private:
  int32_t _internal_grenades() const;
  void _internal_set_grenades(int32_t value);
  public:

  // required float shield_time = 4;
  bool has_shield_time() const;
  private:
  bool _internal_has_shield_time() const;
  public:
  void clear_shield_time();
  float shield_time() const;
  void set_shield_time(float value);
  private:
  float _internal_shield_time() const;
  void _internal_set_shield_time(float value);
  public:

  // required int32 shield_health = 5;
  bool has_shield_health() const;
  private:
  bool _internal_has_shield_health() const;
  public:
  void clear_shield_health();
  int32_t shield_health() const;
  void set_shield_health(int32_t value);
  private:
  int32_t _internal_shield_health() const;
  void _internal_set_shield_health(int32_t value);
  public:

  // required int32 num_deaths = 6;
  bool has_num_deaths() const;
  private:
  bool _internal_has_num_deaths() const;
  public:
  void clear_num_deaths();
  int32_t num_deaths() const;
  void set_num_deaths(int32_t value);
  private:
  int32_t _internal_num_deaths() const;
  void _internal_set_num_deaths(int32_t value);
  public:

  // required int32 num_shield = 7;
  bool has_num_shield() const;
  private:
  bool _internal_has_num_shield() const;
  public:
  void clear_num_shield();
  int32_t num_shield() const;
  void set_num_shield(int32_t value);
  private:
  int32_t _internal_num_shield() const;
  void _internal_set_num_shield(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:gameState.playerState)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr action_;
    int32_t hp_;
    int32_t bullets_;
    int32_t grenades_;
    float shield_time_;
    int32_t shield_health_;
    int32_t num_deaths_;
    int32_t num_shield_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_gameState_2eproto;
};
// -------------------------------------------------------------------

class gameState final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:gameState) */ {
 public:
  inline gameState() : gameState(nullptr) {}
  ~gameState() override;
  explicit PROTOBUF_CONSTEXPR gameState(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  gameState(const gameState& from);
  gameState(gameState&& from) noexcept
    : gameState() {
    *this = ::std::move(from);
  }

  inline gameState& operator=(const gameState& from) {
    CopyFrom(from);
    return *this;
  }
  inline gameState& operator=(gameState&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const gameState& default_instance() {
    return *internal_default_instance();
  }
  static inline const gameState* internal_default_instance() {
    return reinterpret_cast<const gameState*>(
               &_gameState_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(gameState& a, gameState& b) {
    a.Swap(&b);
  }
  inline void Swap(gameState* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(gameState* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  gameState* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<gameState>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const gameState& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const gameState& from) {
    gameState::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(gameState* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "gameState";
  }
  protected:
  explicit gameState(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef gameState_playerState playerState;

  // accessors -------------------------------------------------------

  enum : int {
    kP1FieldNumber = 1,
    kP2FieldNumber = 2,
  };
  // required .gameState.playerState p1 = 1;
  bool has_p1() const;
  private:
  bool _internal_has_p1() const;
  public:
  void clear_p1();
  const ::gameState_playerState& p1() const;
  PROTOBUF_NODISCARD ::gameState_playerState* release_p1();
  ::gameState_playerState* mutable_p1();
  void set_allocated_p1(::gameState_playerState* p1);
  private:
  const ::gameState_playerState& _internal_p1() const;
  ::gameState_playerState* _internal_mutable_p1();
  public:
  void unsafe_arena_set_allocated_p1(
      ::gameState_playerState* p1);
  ::gameState_playerState* unsafe_arena_release_p1();

  // required .gameState.playerState p2 = 2;
  bool has_p2() const;
  private:
  bool _internal_has_p2() const;
  public:
  void clear_p2();
  const ::gameState_playerState& p2() const;
  PROTOBUF_NODISCARD ::gameState_playerState* release_p2();
  ::gameState_playerState* mutable_p2();
  void set_allocated_p2(::gameState_playerState* p2);
  private:
  const ::gameState_playerState& _internal_p2() const;
  ::gameState_playerState* _internal_mutable_p2();
  public:
  void unsafe_arena_set_allocated_p2(
      ::gameState_playerState* p2);
  ::gameState_playerState* unsafe_arena_release_p2();

  // @@protoc_insertion_point(class_scope:gameState)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::gameState_playerState* p1_;
    ::gameState_playerState* p2_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_gameState_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// gameState_playerState

// required int32 hp = 1;
inline bool gameState_playerState::_internal_has_hp() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool gameState_playerState::has_hp() const {
  return _internal_has_hp();
}
inline void gameState_playerState::clear_hp() {
  _impl_.hp_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline int32_t gameState_playerState::_internal_hp() const {
  return _impl_.hp_;
}
inline int32_t gameState_playerState::hp() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.hp)
  return _internal_hp();
}
inline void gameState_playerState::_internal_set_hp(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.hp_ = value;
}
inline void gameState_playerState::set_hp(int32_t value) {
  _internal_set_hp(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.hp)
}

// required int32 bullets = 2;
inline bool gameState_playerState::_internal_has_bullets() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool gameState_playerState::has_bullets() const {
  return _internal_has_bullets();
}
inline void gameState_playerState::clear_bullets() {
  _impl_.bullets_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline int32_t gameState_playerState::_internal_bullets() const {
  return _impl_.bullets_;
}
inline int32_t gameState_playerState::bullets() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.bullets)
  return _internal_bullets();
}
inline void gameState_playerState::_internal_set_bullets(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.bullets_ = value;
}
inline void gameState_playerState::set_bullets(int32_t value) {
  _internal_set_bullets(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.bullets)
}

// required int32 grenades = 3;
inline bool gameState_playerState::_internal_has_grenades() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool gameState_playerState::has_grenades() const {
  return _internal_has_grenades();
}
inline void gameState_playerState::clear_grenades() {
  _impl_.grenades_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline int32_t gameState_playerState::_internal_grenades() const {
  return _impl_.grenades_;
}
inline int32_t gameState_playerState::grenades() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.grenades)
  return _internal_grenades();
}
inline void gameState_playerState::_internal_set_grenades(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.grenades_ = value;
}
inline void gameState_playerState::set_grenades(int32_t value) {
  _internal_set_grenades(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.grenades)
}

// required float shield_time = 4;
inline bool gameState_playerState::_internal_has_shield_time() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool gameState_playerState::has_shield_time() const {
  return _internal_has_shield_time();
}
inline void gameState_playerState::clear_shield_time() {
  _impl_.shield_time_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline float gameState_playerState::_internal_shield_time() const {
  return _impl_.shield_time_;
}
inline float gameState_playerState::shield_time() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.shield_time)
  return _internal_shield_time();
}
inline void gameState_playerState::_internal_set_shield_time(float value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.shield_time_ = value;
}
inline void gameState_playerState::set_shield_time(float value) {
  _internal_set_shield_time(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.shield_time)
}

// required int32 shield_health = 5;
inline bool gameState_playerState::_internal_has_shield_health() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool gameState_playerState::has_shield_health() const {
  return _internal_has_shield_health();
}
inline void gameState_playerState::clear_shield_health() {
  _impl_.shield_health_ = 0;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline int32_t gameState_playerState::_internal_shield_health() const {
  return _impl_.shield_health_;
}
inline int32_t gameState_playerState::shield_health() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.shield_health)
  return _internal_shield_health();
}
inline void gameState_playerState::_internal_set_shield_health(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000020u;
  _impl_.shield_health_ = value;
}
inline void gameState_playerState::set_shield_health(int32_t value) {
  _internal_set_shield_health(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.shield_health)
}

// required int32 num_deaths = 6;
inline bool gameState_playerState::_internal_has_num_deaths() const {
  bool value = (_impl_._has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool gameState_playerState::has_num_deaths() const {
  return _internal_has_num_deaths();
}
inline void gameState_playerState::clear_num_deaths() {
  _impl_.num_deaths_ = 0;
  _impl_._has_bits_[0] &= ~0x00000040u;
}
inline int32_t gameState_playerState::_internal_num_deaths() const {
  return _impl_.num_deaths_;
}
inline int32_t gameState_playerState::num_deaths() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.num_deaths)
  return _internal_num_deaths();
}
inline void gameState_playerState::_internal_set_num_deaths(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000040u;
  _impl_.num_deaths_ = value;
}
inline void gameState_playerState::set_num_deaths(int32_t value) {
  _internal_set_num_deaths(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.num_deaths)
}

// required int32 num_shield = 7;
inline bool gameState_playerState::_internal_has_num_shield() const {
  bool value = (_impl_._has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool gameState_playerState::has_num_shield() const {
  return _internal_has_num_shield();
}
inline void gameState_playerState::clear_num_shield() {
  _impl_.num_shield_ = 0;
  _impl_._has_bits_[0] &= ~0x00000080u;
}
inline int32_t gameState_playerState::_internal_num_shield() const {
  return _impl_.num_shield_;
}
inline int32_t gameState_playerState::num_shield() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.num_shield)
  return _internal_num_shield();
}
inline void gameState_playerState::_internal_set_num_shield(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000080u;
  _impl_.num_shield_ = value;
}
inline void gameState_playerState::set_num_shield(int32_t value) {
  _internal_set_num_shield(value);
  // @@protoc_insertion_point(field_set:gameState.playerState.num_shield)
}

// required string action = 8;
inline bool gameState_playerState::_internal_has_action() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool gameState_playerState::has_action() const {
  return _internal_has_action();
}
inline void gameState_playerState::clear_action() {
  _impl_.action_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& gameState_playerState::action() const {
  // @@protoc_insertion_point(field_get:gameState.playerState.action)
  return _internal_action();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void gameState_playerState::set_action(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.action_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:gameState.playerState.action)
}
inline std::string* gameState_playerState::mutable_action() {
  std::string* _s = _internal_mutable_action();
  // @@protoc_insertion_point(field_mutable:gameState.playerState.action)
  return _s;
}
inline const std::string& gameState_playerState::_internal_action() const {
  return _impl_.action_.Get();
}
inline void gameState_playerState::_internal_set_action(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.action_.Set(value, GetArenaForAllocation());
}
inline std::string* gameState_playerState::_internal_mutable_action() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.action_.Mutable(GetArenaForAllocation());
}
inline std::string* gameState_playerState::release_action() {
  // @@protoc_insertion_point(field_release:gameState.playerState.action)
  if (!_internal_has_action()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.action_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.action_.IsDefault()) {
    _impl_.action_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void gameState_playerState::set_allocated_action(std::string* action) {
  if (action != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.action_.SetAllocated(action, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.action_.IsDefault()) {
    _impl_.action_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:gameState.playerState.action)
}

// -------------------------------------------------------------------

// gameState

// required .gameState.playerState p1 = 1;
inline bool gameState::_internal_has_p1() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.p1_ != nullptr);
  return value;
}
inline bool gameState::has_p1() const {
  return _internal_has_p1();
}
inline void gameState::clear_p1() {
  if (_impl_.p1_ != nullptr) _impl_.p1_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const ::gameState_playerState& gameState::_internal_p1() const {
  const ::gameState_playerState* p = _impl_.p1_;
  return p != nullptr ? *p : reinterpret_cast<const ::gameState_playerState&>(
      ::_gameState_playerState_default_instance_);
}
inline const ::gameState_playerState& gameState::p1() const {
  // @@protoc_insertion_point(field_get:gameState.p1)
  return _internal_p1();
}
inline void gameState::unsafe_arena_set_allocated_p1(
    ::gameState_playerState* p1) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.p1_);
  }
  _impl_.p1_ = p1;
  if (p1) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:gameState.p1)
}
inline ::gameState_playerState* gameState::release_p1() {
  _impl_._has_bits_[0] &= ~0x00000001u;
  ::gameState_playerState* temp = _impl_.p1_;
  _impl_.p1_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::gameState_playerState* gameState::unsafe_arena_release_p1() {
  // @@protoc_insertion_point(field_release:gameState.p1)
  _impl_._has_bits_[0] &= ~0x00000001u;
  ::gameState_playerState* temp = _impl_.p1_;
  _impl_.p1_ = nullptr;
  return temp;
}
inline ::gameState_playerState* gameState::_internal_mutable_p1() {
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.p1_ == nullptr) {
    auto* p = CreateMaybeMessage<::gameState_playerState>(GetArenaForAllocation());
    _impl_.p1_ = p;
  }
  return _impl_.p1_;
}
inline ::gameState_playerState* gameState::mutable_p1() {
  ::gameState_playerState* _msg = _internal_mutable_p1();
  // @@protoc_insertion_point(field_mutable:gameState.p1)
  return _msg;
}
inline void gameState::set_allocated_p1(::gameState_playerState* p1) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.p1_;
  }
  if (p1) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(p1);
    if (message_arena != submessage_arena) {
      p1 = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, p1, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.p1_ = p1;
  // @@protoc_insertion_point(field_set_allocated:gameState.p1)
}

// required .gameState.playerState p2 = 2;
inline bool gameState::_internal_has_p2() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.p2_ != nullptr);
  return value;
}
inline bool gameState::has_p2() const {
  return _internal_has_p2();
}
inline void gameState::clear_p2() {
  if (_impl_.p2_ != nullptr) _impl_.p2_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const ::gameState_playerState& gameState::_internal_p2() const {
  const ::gameState_playerState* p = _impl_.p2_;
  return p != nullptr ? *p : reinterpret_cast<const ::gameState_playerState&>(
      ::_gameState_playerState_default_instance_);
}
inline const ::gameState_playerState& gameState::p2() const {
  // @@protoc_insertion_point(field_get:gameState.p2)
  return _internal_p2();
}
inline void gameState::unsafe_arena_set_allocated_p2(
    ::gameState_playerState* p2) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.p2_);
  }
  _impl_.p2_ = p2;
  if (p2) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:gameState.p2)
}
inline ::gameState_playerState* gameState::release_p2() {
  _impl_._has_bits_[0] &= ~0x00000002u;
  ::gameState_playerState* temp = _impl_.p2_;
  _impl_.p2_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::gameState_playerState* gameState::unsafe_arena_release_p2() {
  // @@protoc_insertion_point(field_release:gameState.p2)
  _impl_._has_bits_[0] &= ~0x00000002u;
  ::gameState_playerState* temp = _impl_.p2_;
  _impl_.p2_ = nullptr;
  return temp;
}
inline ::gameState_playerState* gameState::_internal_mutable_p2() {
  _impl_._has_bits_[0] |= 0x00000002u;
  if (_impl_.p2_ == nullptr) {
    auto* p = CreateMaybeMessage<::gameState_playerState>(GetArenaForAllocation());
    _impl_.p2_ = p;
  }
  return _impl_.p2_;
}
inline ::gameState_playerState* gameState::mutable_p2() {
  ::gameState_playerState* _msg = _internal_mutable_p2();
  // @@protoc_insertion_point(field_mutable:gameState.p2)
  return _msg;
}
inline void gameState::set_allocated_p2(::gameState_playerState* p2) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.p2_;
  }
  if (p2) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(p2);
    if (message_arena != submessage_arena) {
      p2 = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, p2, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.p2_ = p2;
  // @@protoc_insertion_point(field_set_allocated:gameState.p2)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_gameState_2eproto