#include "string.hpp"

#include <gtest/gtest.h>
#include <string>
#include <utility>

TEST(string, copy_conversion_constructor) {
  auto a = std::string{"hello"};
  auto b = nik::basic_string{a};

  ASSERT_TRUE(b.s == a);
}

TEST(string, move_conversion_constructor) {
  auto a = std::string{"hello"};
  auto b = nik::basic_string{std::move(a)};

  ASSERT_TRUE(b.s == std::string{"hello"});
}

TEST(string, conversion_operator) {
  auto a = nik::basic_string{std::string{"hello"}};
  auto b = std::string{a};

  auto foo = [&](const std::string& x) {
    return x;
  };

  ASSERT_TRUE(b == foo(b));
}
