#include "string.hpp"

#include <gtest/gtest.h>

TEST(string, capitalize) {
  auto s = nik::string{"hello"};

  ASSERT_TRUE(s.capitalize() == nik::string{"Hello"});
}
