#ifndef NIK_ERROR_HPP
#define NIK_ERROR_HPP

#include <system_error>

namespace nik {

template <typename F, F *function>
struct syscall_except {
  template <typename... Args>
  auto operator()(Args... args) {
    auto ret = function(args...);

    if (static_cast<decltype(function(args...))>(-1) == ret) {
      throw std::system_error(errno, std::system_category());
    }

    return ret;
  }
};

} // namespace nik

#endif // NIK_ERROR_HPP
