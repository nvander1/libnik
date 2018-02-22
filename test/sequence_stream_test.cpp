#include "stream.hpp"

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using nik::operator<<;

int main() {
  std::string expected{"[1, 2, 3, 4, 5]"};

  std::array array{1, 2, 3, 4, 5};
  std::deque deque{1, 2, 3, 4, 5};
  std::forward_list forward_list{1, 2, 3, 4, 5};
  std::list list{1, 2, 3, 4, 5};
  std::vector vector{1, 2, 3, 4, 5};
  std::vector<int> empty{};

  {
    std::ostringstream os{};
    os << array;
    if (expected != os.str())
      return -1;
  }

  {
    std::ostringstream os{};
    os << deque;
    if (expected != os.str())
      return -1;
  }

  {
    std::ostringstream os{};
    os << forward_list;
    if (expected != os.str())
      return -1;
  }

  {
    std::ostringstream os{};
    os << list;
    if (expected != os.str())
      return -1;
  }

  {
    std::ostringstream os{};
    os << vector;
    if (expected != os.str())
      return -1;
  }
  {
    std::ostringstream os{};
    os << empty;
    if (std::string{"[]"} != os.str())
      return -1;
  }
}
