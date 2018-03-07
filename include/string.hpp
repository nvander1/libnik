#ifndef NIK_STRING_HPP
#define NIK_STRING_HPP

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace nik {

template <typename CharT, typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>>
class basic_string : public std::basic_string<CharT, Traits, Allocator> {
  using std_basic_string = std::basic_string<CharT, Traits, Allocator>;

public:
  // Member types
  using traits_type = typename std_basic_string::traits_type;
  using value_type = typename std_basic_string::value_type;
  using allocator_type = typename std_basic_string::allocator_type;
  using size_type = typename std_basic_string::size_type;
  using difference_type = typename std_basic_string::difference_type;
  using reference = typename std_basic_string::reference;
  using const_reference = typename std_basic_string::const_reference;
  using pointer = typename std_basic_string::pointer;
  using const_pointer = typename std_basic_string::const_pointer;
  using iterator = typename std_basic_string::iterator;
  using const_iterator = typename std_basic_string::const_iterator;
  using reverse_iterator = typename std_basic_string::reverse_iterator;
  using const_reverse_iterator =
      typename std_basic_string::const_reverse_iterator;

  // Member functions
  using std_basic_string::basic_string;

  basic_string(std_basic_string other) : std_basic_string{other} {}

  basic_string capitalize() {
    auto copied = *this;
    auto &front_char = copied.front();
    front_char = std::toupper(front_char);
    return copied;
  }

  // https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L156-L174
  basic_string center(size_type width, CharT fillchar = ' ') {
    if (this->size() >= width)
      return *this;

    auto marg = width - this->size();
    auto left = marg / 2 + (marg & width & 1);

    return pad(left, marg - left, fillchar);
  }

  size_type count(std_basic_string sub, size_type start = 0,
                  size_type end = 0) {
    if (end == 0)
      end += this->size();
    auto searched_portion = this->substr(start, end - start);
    size_type seen = 0;
    int pos = -1;
    while ((pos = searched_portion.find(
                sub, static_cast<size_type>(pos + 1))) != basic_string::npos) {
      seen++;
    }
    return seen;
  }

  std::vector<std_basic_string> split(std_basic_string sep) {
    auto tokens = std::vector<std_basic_string>();
    size_type prev = 0;
    size_type next = 0;

    while ((next = this->find(sep, prev)) != basic_string::npos) {
      tokens.push_back(this->substr(prev, next - prev));
      prev = next + sep.size();
    }
    tokens.push_back(this->substr(prev, next - prev));

    return tokens;
  }

  std::vector<std_basic_string> split(std_basic_string sep,
                                      size_type maxsplit) {
    auto tokens = std::vector<std_basic_string>();
    if (maxsplit == 0)
      return tokens;

    size_type prev = 0;
    size_type next = 0;

    while ((next = this->find(sep, prev)) != basic_string::npos) {
      tokens.push_back(this->substr(prev, next - prev));
      if (tokens.size() == maxsplit + 1)
        return tokens;
      prev = next + sep.size();
    }
    tokens.push_back(this->substr(prev, next - prev));

    return tokens;
  }

  std::vector<std_basic_string> split(size_type maxsplit = SIZE_MAX) {
    auto tokens = std::vector<std_basic_string>();
    if (maxsplit == 0)
      return tokens;

    auto iss = std::istringstream(*this);
    using Iterator = std::istream_iterator<std_basic_string>;

    if (maxsplit == SIZE_MAX)
      std::copy(Iterator(iss), Iterator(), std::back_inserter(tokens));
    else
      std::copy_n(Iterator(iss), maxsplit, std::back_inserter(tokens));

    return tokens;
  }

private:
  // https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L93-L120
  basic_string pad(size_type left, size_type right, CharT fill) {
    if (left < 0)
      left = 0;
    if (right < 0)
      right = 0;

    if (left == 0 && right == 0)
      return *this;

    auto padded = basic_string(left + this->size() + right, fill);
    padded.replace(left, this->size(), *this);

    return padded;
  }
};

using string = basic_string<char>;

} // namespace nik

#endif // NIK_STRING_HPP
