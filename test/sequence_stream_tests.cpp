#include "stream.hpp"

#include <gtest/gtest.h>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using nik::operator<<;

const std::string expected{"[1, 2, 3, 4, 5]"};

TEST(ostream, stl_array) {
  std::array seq{1, 2, 3, 4, 5};
  std::ostringstream os{};
  os << seq;

  ASSERT_EQ(expected, os.str());
}

TEST(ostream, stl_deque) {
  std::deque seq{1, 2, 3, 4, 5};
  std::ostringstream os{};
  os << seq;

  ASSERT_EQ(expected, os.str());
}

TEST(ostream, stl_forward_list) {
  std::forward_list seq{1, 2, 3, 4, 5};
  std::ostringstream os{};
  os << seq;

  ASSERT_EQ(expected, os.str());
}

TEST(ostream, stl_list) {
  std::list seq{1, 2, 3, 4, 5};
  std::ostringstream os{};
  os << seq;

  ASSERT_EQ(expected, os.str());
}

TEST(ostream, stl_vector) {
  std::vector seq{1, 2, 3, 4, 5};
  std::ostringstream os{};
  os << seq;
  ASSERT_EQ(expected, os.str());
}

TEST(ostream, empty) {
  std::vector<int> seq{};
  std::ostringstream os{};
  os << seq;

  ASSERT_EQ(std::string{"[]"}, os.str());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
