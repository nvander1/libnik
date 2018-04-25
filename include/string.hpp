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

// template <typename CharT, typename Traits = std::char_traits<CharT>,
//           typename Allocator = std::allocator<CharT>>


template <typename StringT>
StringT capitalize(StringT string) {
  auto& front_char = string.front();
  front_char = std::toupper(front_char);
  return string;
}

// https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L93-L120
template <typename StringT>
StringT pad(StringT string, typename StringT::size_type left,
            typename StringT::size_type right,
            typename StringT::value_type fill) {
  if (left < 0) left = 0;
  if (right < 0) right = 0;

  if (left == 0 && right == 0) return string;

  auto padded = StringT(left + string.size() + right, fill);
  padded.replace(left, string.size(), string);

  return padded;
}

// https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L156-L174
template <typename StringT>
StringT center(StringT string, typename StringT::size_type width,
               typename StringT::value_type fillchar = ' ') {
  if (string.size() >= width) return string;

  auto marg = width - string.size();
  auto left = marg / 2 + (marg & width & 1);

  return pad(string, left, marg - left, fillchar);
}

template <typename StringT>
typename StringT::size_type count(StringT string, StringT sub,
                                  typename StringT::size_type start = 0,
                                  typename StringT::size_type end = 0) {
  if (end == 0) end += string.size();
  auto searched_portion = string.substr(start, end - start);
  typename StringT::size_type seen = 0;
  int pos = -1;
  while ((pos = searched_portion.find(
              sub, static_cast<typename StringT::size_type>(pos + 1))) !=
         StringT::npos) {
    seen++;
  }
  return seen;
}

template <typename StringT>
std::vector<StringT> split(StringT string, StringT sep) {
  auto tokens = std::vector<StringT>();
  typename StringT::size_type prev = 0;
  typename StringT::size_type next = 0;

  while ((next = string.find(sep, prev)) != StringT::npos) {
    tokens.push_back(string.substr(prev, next - prev));
    prev = next + sep.size();
  }
  tokens.push_back(string.substr(prev, next - prev));

  return tokens;
}

template <typename StringT>
std::vector<StringT> split(StringT string, StringT sep,
                           typename StringT::size_type maxsplit) {
  auto tokens = std::vector<StringT>();
  if (maxsplit == 0) return tokens;

  typename StringT::size_type prev = 0;
  typename StringT::size_type next = 0;

  while ((next = string.find(sep, prev)) != StringT::npos) {
    tokens.push_back(string.substr(prev, next - prev));
    if (tokens.size() == maxsplit + 1) return tokens;
    prev = next + sep.size();
  }
  tokens.push_back(string.substr(prev, next - prev));

  return tokens;
}

template <typename StringT>
std::vector<StringT> split(StringT string,
                           typename StringT::size_type maxsplit = SIZE_MAX) {
  auto tokens = std::vector<StringT>();
  if (maxsplit == 0) return tokens;

  auto iss = std::istringstream(string);
  using Iterator = std::istream_iterator<StringT>;

  if (maxsplit == SIZE_MAX)
    std::copy(Iterator(iss), Iterator(), std::back_inserter(tokens));
  else
    std::copy_n(Iterator(iss), maxsplit, std::back_inserter(tokens));

  return tokens;
}


} // namespace nik

#endif // NIK_STRING_HPP
