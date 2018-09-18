#ifndef NIK_STRING_HPP
#define NIK_STRING_HPP

#include <string>

namespace nik {

template <typename CharT, typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>>
class basic_string {
 public:
  // Member types
  using StringT = std::basic_string<CharT, Traits, Allocator>;

  // Member functions

  /// Constructors

  //// Copy conversion constructor
  basic_string(const StringT& other) : s{other} {}

  //// Move conversion constructor
  basic_string(StringT&& other) : s{other} {}

  /// Conversion operator
  operator StringT() { return s; }

  // Members
  StringT s;
};

} // namespace nik

#endif // NIK_STRING_HPP
