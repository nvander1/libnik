#ifndef NIK_MAIN_HPP
#define NIK_MAIN_HPP

#include <string>
#include <vector>

int nik_main(std::vector<std::string> args);

#define main()                                                                 \
  main(int argc, char **argv) {                                                \
    std::vector<std::string> args{};                                           \
    for (int i = 0; i < argc; ++i) {                                           \
      args.push_back(std::string{argv[i]});                                    \
    }                                                                          \
    return nik_main(args);                                                     \
  }                                                                            \
                                                                               \
  int nik_main(std::vector<std::string> args)

#endif // NIK_MAIN_HPP
