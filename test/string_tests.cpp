#include "string.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(string, capitalize) {
  auto s = nik::string{"hello"};

  ASSERT_TRUE(s.capitalize() == nik::string{"Hello"});
}

TEST(string, center) {
  std::vector<nik::string> inputs{"a", "ab", "abc", "abcd", "abcde"};

  std::vector<std::vector<nik::string>> outputs{
      {"a", "a", "a ", " a ", " a  ", "  a  ", "  a   ", "   a   ", "   a    ",
       "    a    "},
      {"ab", "ab", "ab", " ab", " ab ", "  ab ", "  ab  ", "   ab  ",
       "   ab   ", "    ab   "},
      {"abc", "abc", "abc", "abc", "abc ", " abc ", " abc  ", "  abc  ",
       "  abc   ", "   abc   "},
      {"abcd", "abcd", "abcd", "abcd", "abcd", " abcd", " abcd ", "  abcd ",
       "  abcd  ", "   abcd  "},
      {"abcde", "abcde", "abcde", "abcde", "abcde", "abcde", "abcde ",
       " abcde ", " abcde  ", "  abcde  "}};

  for (auto i = 0; i < inputs.size(); ++i) {
    for (size_t width = 0; width < 10; ++width) {
      ASSERT_TRUE(inputs[i].center(width) == outputs[i][width]);
    }
  }

  ASSERT_TRUE(nik::string{"a"}.center(5, '_') == nik::string{"__a__"});
}

TEST(string, count) {
  ASSERT_EQ(5, nik::string{"aaaaa"}.count(nik::string{"a"}));
  ASSERT_EQ(2, nik::string{"hello hello"}.count(std::string{"hello"}));
  ASSERT_EQ(1, nik::string{"hello hello"}.count(std::string{"hello"}, 1));
  ASSERT_EQ(1, nik::string{"hello hello"}.count(std::string{"hello"}, 0, 6));
}
