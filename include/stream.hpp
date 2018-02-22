#ifndef NIK_STREAM_HPP
#define NIK_STREAM_HPP

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <ostream>

namespace nik {

template <template <typename, typename> class Sequence, typename T, typename A>
std::ostream &operator<<(std::ostream &os, Sequence<T, A> &seq) {
  os << "[";
  if (seq.empty()) {
    os << "]";
    return os;
  }
  auto cur = seq.begin();
  auto next = seq.begin();
  for (++next; next != seq.end(); ++cur, ++next) {
    os << *cur << ", ";
  }
  os << *cur << "]";
  return os;
}

template <template <typename, std::size_t> class Sequence, typename T,
          std::size_t N>
std::ostream &operator<<(std::ostream &os, Sequence<T, N> &seq) {
  os << "[";
  if (seq.empty()) {
    os << "]";
    return os;
  }
  auto cur = seq.begin();
  auto next = seq.begin();
  for (++next; next != seq.end(); ++cur, ++next) {
    os << *cur << ", ";
  }
  os << *cur << "]";
  return os;
}

} // namespace nik

#endif // NIK_STREAM_HPP
