#include "error.hpp"

#include <cerrno>
#include <fcntl.h>
#include <system_error>

int main() {
  nik::posix::wrapper<int, const char *, int> wrapper{-1, open};
  try {
    wrapper("THIS FILE DOESN'T EXIST", O_RDONLY);
    return -1;
  } catch (std::system_error &error) {
    if (error.code().value() != ENOENT) {
      return -1;
    }
  }
}
