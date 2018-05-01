#include "string.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(string, capitalize) {
  auto s = std::string{"hello"};

  ASSERT_TRUE(nik::capitalize(s) == std::string{"Hello"});
}

TEST(string, center) {
  std::vector<std::string> inputs{"a", "ab", "abc", "abcd", "abcde"};

  std::vector<std::vector<std::string>> outputs{
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
      ASSERT_TRUE(nik::center(inputs[i], width) == outputs[i][width]);
    }
  }

  ASSERT_TRUE(nik::center(std::string{"a"}, 5, '_') == std::string{"__a__"});
}

TEST(string, count) {
  ASSERT_EQ(5, nik::count(std::string{"aaaaa"}, std::string{"a"}));
  ASSERT_EQ(2, nik::count(std::string{"hello hello"}, std::string{"hello"}));
  ASSERT_EQ(1, nik::count(std::string{"hello hello"}, std::string{"hello"}, 1));
  ASSERT_EQ(1,
            nik::count(std::string{"hello hello"}, std::string{"hello"}, 0, 6));
}

TEST(string, split) {
  auto string = std::string("a\nb\tc  d\t e  ");

  auto tokens = nik::split(string);
  EXPECT_EQ(5, tokens.size());
  EXPECT_TRUE(tokens[0] == std::string("a"));
  EXPECT_TRUE(tokens[1] == std::string("b"));
  EXPECT_TRUE(tokens[2] == std::string("c"));
  EXPECT_TRUE(tokens[3] == std::string("d"));
  EXPECT_TRUE(tokens[4] == std::string("e"));

  auto tokens2 = nik::split(string, 2);
  EXPECT_EQ(2, tokens2.size());
  EXPECT_TRUE(tokens[0] == std::string("a"));
  EXPECT_TRUE(tokens[1] == std::string("b"));

  auto tokens_empty = nik::split(string, 0);
  EXPECT_EQ(0, tokens_empty.size());

  auto csv = std::string("a,b,c,d");
  auto tokens_sep = nik::split(csv, std::string(","));
  EXPECT_EQ(4, tokens_sep.size());
  EXPECT_TRUE(tokens_sep[0] == std::string("a"));
  EXPECT_TRUE(tokens_sep[1] == std::string("b"));
  EXPECT_TRUE(tokens_sep[2] == std::string("c"));
  EXPECT_TRUE(tokens_sep[3] == std::string("d"));

  auto tokens_sep_limited = nik::split(csv, std::string(","), 2);
  EXPECT_EQ(3, tokens_sep_limited.size());
  EXPECT_TRUE(tokens_sep_limited[0] == std::string("a"));
  EXPECT_TRUE(tokens_sep_limited[1] == std::string("b"));
  EXPECT_TRUE(tokens_sep_limited[2] == std::string("c"));
  std::cout << tokens_sep_limited[2] << std::endl;

  auto double_sep = std::string("a,,b,,c,,d");
  auto tokens_double_sep = nik::split(double_sep, std::string(",,"));
  EXPECT_EQ(4, tokens_double_sep.size());
  EXPECT_TRUE(tokens_double_sep[0] == std::string("a"));
  EXPECT_TRUE(tokens_double_sep[1] == std::string("b"));
  EXPECT_TRUE(tokens_double_sep[2] == std::string("c"));
  EXPECT_TRUE(tokens_double_sep[3] == std::string("d"));

  auto tokens_double_sep_limited = nik::split(double_sep, std::string(",,"), 2);
  EXPECT_EQ(3, tokens_double_sep_limited.size());
  EXPECT_TRUE(tokens_double_sep_limited[0] == std::string("a"));
  EXPECT_TRUE(tokens_double_sep_limited[1] == std::string("b"));
  EXPECT_TRUE(tokens_double_sep_limited[2] == std::string("c"));
}
