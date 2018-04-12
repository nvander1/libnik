#pragma once

#ifdef __cpp_concepts
#include <type_traits>

namespace nik {

// Basic
template <typename T>
concept bool DefaultConstructible = std::is_default_constructible_v<T>;

template <typename T>
concept bool TriviallyDefaultConstructible =
    std::is_trivially_default_constructible_v<T>;

template <typename T>
concept bool NothrowDefaultConstructible =
    std::is_nothrow_default_constructible_v<T>;

template <typename T>
concept bool MoveConstructible = std::is_move_constructible_v<T>;

template <typename T>
concept bool TriviallyMoveConstructible =
    std::is_trivially_move_constructible_v<T>;

template <typename T>
concept bool NothrowMoveConstructible = std::is_nothrow_move_constructible_v<T>;

template <typename T>
concept bool CopyConstructible = std::is_copy_constructible_v<T>;

template <typename T>
concept bool TriviallyCopyConstructible =
    std::is_trivially_copy_constructible_v<T>;

template <typename T>
concept bool NothrowCopyConstructible = std::is_nothrow_copy_constructible_v<T>;

template <typename T>
concept bool MoveAssignable = std::is_move_assignable_v<T>;

template <typename T>
concept bool TriviallyMoveAssignable = std::is_trivially_move_assignable_v<T>;

template <typename T>
concept bool NothrowMoveAssignable = std::is_nothrow_move_assignable_v<T>;

template <typename T>
concept bool CopyAssignable = std::is_copy_assignable_v<T>;

template <typename T>
concept bool TriviallyCopyAssignable = std::is_trivially_copy_assignable_v<T>;

template <typename T>
concept bool NothrowCopyAssignable = std::is_nothrow_copy_assignable_v<T>;

template <typename T>
concept bool Destructible = std::is_destructible_v<T>;

template <typename T>
concept bool TriviallyDestructible = std::is_trivially_destructible_v<T>;

template <typename T>
concept bool NothrowDestructible = std::is_nothrow_destructible_v<T>;

// Layout
template <typename T>
concept bool TriviallyCopyable = std::is_trivially_copyable_v<T>;

template <typename T>
concept bool TrivialType = std::is_trivial_v<T>;

template <typename T>
concept bool StandardLayoutType = std::is_standard_layout_v<T>;

template <typename T>
concept bool PODType = std::is_pod_v<T>;

} // namespace nik

#endif // __cpp_concepts
