#pragma once

#include <type_traits>

#ifndef NDEBUG
#include <tuple>
#include <vector>
#endif

namespace nik {

template <typename T>
struct remove_cvref {
  using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

template <typename T, template <typename...> class Template>
struct is_specialization_of : std::false_type{};

template <template <typename...> class Template, typename... Args>
struct is_specialization_of<Template<Args...>, Template> : std::true_type{};

template <typename T, template <typename...> class Template>
constexpr bool is_specialization_of_v = is_specialization_of<T, Template>::value;

#ifndef NDEBUG
static_assert(is_specialization_of_v<std::tuple<int, double, bool>, std::tuple>);
static_assert(is_specialization_of_v<std::vector<int>, std::vector>);
static_assert(!is_specialization_of_v<std::tuple<int>, std::vector>);
#endif

} // namespace nik
