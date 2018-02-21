#include "error.hpp"

#include <cerrno>
#include <fcntl.h>
#include <system_error>
#include <unistd.h>

int main() {
  nik::posix::syscall_except<decltype(open), open> wrapped_open{};
  nik::posix::syscall_except<decltype(close), close> wrapped_close{};

  try {
    wrapped_close(-500);
    return -1;
  } catch (std::system_error &error) {
    if (error.code().value() != EBADF) {
      return -1;
    }
  }

  try {
    wrapped_open("THIS FILE DOESN'T EXIST", O_RDONLY);
    return -1;
  } catch (std::system_error &error) {
    if (error.code().value() != ENOENT) {
      return -1;
    }
  }
}
