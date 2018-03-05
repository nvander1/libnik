#ifndef NIK_STRING_HPP
#define NIK_STRING_HPP

#include <cctype>
#include <string>

namespace nik {

class string : public std::string {
public:
  string capitalize() {
    auto copied = *this;
    auto& front_char = copied.front();
    front_char = std::toupper(front_char);
    return copied;
  }
};

} // namespace nik

#endif // NIK_STRING_HPP
