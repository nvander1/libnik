#ifndef NIK_STRING_HPP
#define NIK_STRING_HPP

#include <string>

namespace nik {

template <typename CharT, typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>>
class basic_string {
 public:
  // Member types
  using string_type = std::basic_string<CharT, Traits, Allocator>;
  using traits_type = typename string_type::traits_type;
  using value_type = typename string_type::value_type;
  using allocator_type = typename string_type::allocator_type;
  using size_type = typename string_type::size_type;
  using difference_type = typename string_type::difference_type;
  using reference = typename string_type::reference;
  using const_reference = typename string_type::const_reference;
  using pointer = typename string_type::pointer;
  using const_pointer = typename string_type::const_pointer;
  using iterator = typename string_type::iterator;
  using const_iterator = typename string_type::const_iterator;
  using reverse_iterator = typename string_type::reverse_iterator;
  using const_reverse_iterator = typename string_type::const_reverse_iterator;

  // Member functions

  /// Constructors

  //// Copy conversion constructor
  basic_string(const string_type& other) : s{other} {}

  //// Move conversion constructor
  basic_string(string_type&& other) : s{other} {}

  /// Conversion operator
  operator string_type() { return s; }

  // Members
  string_type s;
};

} // namespace nik

#endif // NIK_STRING_HPP
