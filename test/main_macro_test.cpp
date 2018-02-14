#include "main.hpp"

#include <iostream>
#include <string>

int main()
{
  std::cout << args[1] + args[2] << std::endl;
  if (0 != std::string{"Hello, World!"}.compare(args[1] + args[2])) {
    return -1;
  }
  return 0;
}
