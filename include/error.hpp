#ifndef NIK_ERROR_HPP
#define NIK_ERROR_HPP

#include <functional>
#include <system_error>

namespace nik::posix {

template <typename R, typename... Args> class wrapper {
public:
  wrapper(R failure, std::function<R(Args...)> function)
      : d_function{std::move(function)}, d_failure{failure} {}

  R operator()(Args... args) {
    auto arguments = std::make_tuple(args...);

    R ret = d_function(args...);
    if (d_failure == ret) {
      throw std::system_error(errno, std::system_category());
    }

    return ret;
  }

private:
  std::function<R(Args...)> d_function;
  R d_failure;
};

} // namespace nik::posix

#endif // NIK_ERROR_HPP
