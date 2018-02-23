#include "error.hpp"

#include <gtest/gtest.h>

#include <cerrno>
#include <fcntl.h>
#include <system_error>
#include <unistd.h>

TEST(syscall_except, open) {
  nik::syscall_except<decltype(open), open> wrapped_open{};

  try {
    wrapped_open("THIS FILE DOESN'T EXIST", O_RDONLY);
    ASSERT_TRUE(false);
  } catch (std::system_error& error) {
    ASSERT_EQ(error.code().value(), ENOENT);
  }
}

TEST(syscall_except, close) {
  nik::syscall_except<decltype(close), close> wrapped_close{};

  try {
    wrapped_close(-420);
    ASSERT_TRUE(false);
  } catch (std::system_error& error) {
    ASSERT_EQ(error.code().value(), EBADF);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
