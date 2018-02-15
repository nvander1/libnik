#include "error.hpp"

#include <cerrno>
#include <fcntl.h>
#include <system_error>
#include <unistd.h>

int main() {
  nik::posix::wrapper wrapped_close{-1, close};

  // XXX: C-style variable arguments break the deduction
  // int open(const char *pathname, int fd, ...);
  //
  // nik::posix::wrapper wrapped_open{-1, open};

  try {
    wrapped_close(-500);
    return -1;
  } catch (std::system_error &error) {
    if (error.code().value() != EBADF) {
      return -1;
    }
  }
}
