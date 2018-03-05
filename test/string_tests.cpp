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

TEST(string, split) {
  auto string = nik::string("a\nb\tc  d\t e  ");

  auto tokens = string.split();
  EXPECT_EQ(5, tokens.size());
  EXPECT_TRUE(tokens[0] == nik::string("a"));
  EXPECT_TRUE(tokens[1] == nik::string("b"));
  EXPECT_TRUE(tokens[2] == nik::string("c"));
  EXPECT_TRUE(tokens[3] == nik::string("d"));
  EXPECT_TRUE(tokens[4] == nik::string("e"));

  auto tokens2 = string.split(nullptr, 2);
  EXPECT_EQ(2, tokens2.size());
  EXPECT_TRUE(tokens[0] == nik::string("a"));
  EXPECT_TRUE(tokens[1] == nik::string("b"));

  auto tokens_empty = string.split(nullptr, 0);
  EXPECT_EQ(0, tokens_empty.size());

  auto csv = nik::string("a,b,c,d");
  auto tokens_sep = csv.split(',');
  EXPECT_EQ(4, tokens_sep.size());
  EXPECT_TRUE(tokens_sep[0] == nik::string("a"));
  EXPECT_TRUE(tokens_sep[1] == nik::string("b"));
  EXPECT_TRUE(tokens_sep[2] == nik::string("c"));
  EXPECT_TRUE(tokens_sep[3] == nik::string("d"));

  // auto tokens_sep_limited = csv.split(',', 2);
  // EXPECT_EQ(3, tokens_sep_limited.size());
  // EXPECT_TRUE(tokens_sep_limited[0] == nik::string("a"));
  // EXPECT_TRUE(tokens_sep_limited[1] == nik::string("b"));
  // EXPECT_TRUE(tokens_sep_limited[2] == nik::string("c"));
  // std::cout << tokens_sep_limited[2] << std::endl;

  auto double_sep = nik::string("a,,b,,c,,d");
  auto tokens_double_sep = double_sep.split(",,");
  EXPECT_EQ(4, tokens_double_sep.size());
  EXPECT_TRUE(tokens_double_sep[0] == nik::string("a"));
  EXPECT_TRUE(tokens_double_sep[1] == nik::string("b"));
  EXPECT_TRUE(tokens_double_sep[2] == nik::string("c"));
  EXPECT_TRUE(tokens_double_sep[3] == nik::string("d"));

  // auto tokens_double_sep_limited = double_sep.split(",,", 2);
  // EXPECT_EQ(3, tokens_double_sep_limited.size());
  // EXPECT_TRUE(tokens_double_sep_limited[0] == nik::string("a"));
  // EXPECT_TRUE(tokens_double_sep_limited[1] == nik::string("b"));
  // EXPECT_TRUE(tokens_double_sep_limited[2] == nik::string("c"));
}
