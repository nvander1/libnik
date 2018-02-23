#ifndef NIK_MEMORY_HPP
#define NIK_MEMORY_HPP

#include <cstddef>
#include <functional>
#include <type_traits>
#include <utility>

namespace nik {

template <typename W>
class observer_ptr {
public:
  // Member types
  using element_type = W;

  // Member functions
  constexpr observer_ptr() noexcept : m_watched(nullptr) {}

  constexpr observer_ptr(std::nullptr_t) noexcept : m_watched(nullptr) {}

  explicit observer_ptr(element_type* p) noexcept : m_watched(p) {}

  template <typename W2>
  observer_ptr(observer_ptr<W2> other) noexcept : m_watched(other.get()) {}

  observer_ptr(const observer_ptr& other) = default;

  observer_ptr(observer_ptr&& other) = default;

  /// Modifiers
  constexpr element_type* release() noexcept {
    auto previously_watched = get();
    reset(nullptr);
    return previously_watched;
  }

  constexpr void reset(element_type* p = nullptr) noexcept { m_watched = p; }

  constexpr void swap(observer_ptr& other) noexcept {
    std::swap(m_watched, other.m_watched);
  }
  /// Observers

  constexpr element_type* get() const noexcept { return m_watched; }

  constexpr explicit operator bool() const noexcept { return get() != nullptr; }

  constexpr std::add_lvalue_reference_t<element_type> operator*() const {
    return *get();
  }

  constexpr element_type* operator->() const noexcept { return get(); }

  /// Conversions
  constexpr explicit operator element_type*() const noexcept { return get(); }

private:
  element_type* m_watched;
};

// Non-member functions
template <typename W>
observer_ptr<W> make_observer(W* p) noexcept {
  return observer_ptr<W>{p};
}

template <typename W1, typename W2>
inline bool operator==(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return p1.get() == p2.get();
}

template <typename W1, typename W2>
inline bool operator!=(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return !(p1 == p2);
}

template <typename W>
inline bool operator==(const observer_ptr<W>& p, std::nullptr_t) noexcept {
  return !p;
}

template <typename W>
inline bool operator==(std::nullptr_t, const observer_ptr<W>& p) noexcept {
  return !p;
}

template <typename W>
inline bool operator!=(const observer_ptr<W>& p, std::nullptr_t) noexcept {
  return static_cast<bool>(p);
}

template <typename W>
inline bool operator!=(std::nullptr_t, const observer_ptr<W>& p) noexcept {
  return static_cast<bool>(p);
}

template <typename W1, typename W2>
inline bool operator<(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return std::less<std::common_type_t<W1*, W2*>>{}(p1.get(), p2.get());
}

template <typename W1, typename W2>
inline bool operator>(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return p2 < p1;
}

template <typename W1, typename W2>
inline bool operator<=(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return !(p2 < p1);
}

template <typename W1, typename W2>
inline bool operator>=(const observer_ptr<W1>& p1, const observer_ptr<W2>& p2) {
  return !(p1 < p2);
}

} // namespace nik

namespace std {

template <typename W>
void swap(nik::observer_ptr<W>& lhs, nik::observer_ptr<W>& rhs) {
  lhs.swap(rhs);
}

template <typename T>
struct hash<nik::observer_ptr<T>> {
  auto operator()(nik::observer_ptr<T> ptr) { return hash<T*>()(ptr.get()); }
};

} // namespace std

#endif // NIK_MEMORY_HPP
