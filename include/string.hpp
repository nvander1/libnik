#ifndef NIK_STRING_HPP
#define NIK_STRING_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace nik {

class string : public std::string {

public:
  using std::string::string;
  string(std::string other) : std::string{other} {}
  string capitalize() {
    auto copied = *this;
    auto& front_char = copied.front();
    front_char = std::toupper(front_char);
    return copied;
  }

  // https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L156-L174
  string center(int width, char fillchar = ' ') {
    if (size() >= width)
      return *this;

    auto marg = width - size();
    auto left = marg / 2 + (marg & width & 1);

    return pad(left, marg - left, fillchar);
  }

  size_t count(std::string sub, size_t start = 0, size_t end = 0) {
    if (end == 0)
      end += size();
    auto searched_portion = substr(start, end - start);
    size_t seen = 0;
    size_t pos = -1;
    while ((pos = searched_portion.find(sub, pos + 1)) != string::npos) {
      seen++;
    }
    return seen;
  }

  std::vector<nik::string> split(std::string sep, int maxsplit = -1) {
    auto tokens = std::vector<nik::string>();
    if (maxsplit == 0)
      return tokens;

    size_t prev = 0;
    size_t next = 0;

    while ((next = find(sep, prev)) != string::npos) {
      tokens.push_back(substr(prev, next - prev));
      prev = next + sep.size();
    }
    tokens.push_back(substr(prev, next - prev));

    return tokens;
  }

  std::vector<nik::string> split(char sep, int maxsplit = -1) {
    return split(std::string{sep}, maxsplit);
  }

  std::vector<nik::string> split(nullptr_t sep = nullptr, int maxsplit = -1) {
    auto tokens = std::vector<nik::string>();
    if (maxsplit == 0)
      return tokens;

    auto iss = std::istringstream(*this);
    using Iterator = std::istream_iterator<nik::string>;

    if (maxsplit > 0)
      std::copy_n(Iterator(iss), maxsplit, std::back_inserter(tokens));
    else
      std::copy(Iterator(iss), Iterator(), std::back_inserter(tokens));

    return tokens;
  }

private:
  // https://github.com/python/cpython/blob/master/Objects/stringlib/transmogrify.h#L93-L120
  string pad(size_t left, size_t right, char fill) {
    if (left < 0)
      left = 0;
    if (right < 0)
      right = 0;

    if (left == 0 && right == 0)
      return *this;

    auto padded = nik::string(left + size() + right, fill);
    padded.replace(left, size(), *this);

    return padded;
  }
};

} // namespace nik

#endif // NIK_STRING_HPP
