#ifndef NIK_ERROR_HPP
#define NIK_ERROR_HPP

#include <system_error>
#include <tuple>

namespace nik::posix {

template <typename R, typename... Args> class wrapper {
public:
  wrapper(R failure, R (*function)(Args...))
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
  R (*d_function)(Args...);
  R d_failure;
};

template <typename R, typename... Args>
wrapper(R, R(Args...))->wrapper<R, Args...>;

} // namespace nik::posix

#endif // NIK_ERROR_HPP
