# `nik::basic_string`

---

Defined in header `<nik/string.hpp>`

```cpp
template<
    typename CharT,
    typename Traits = std::char_traits<CharT>,
    typename Allocator = std::allocator<CharT>
> class basic_string;
```

The class template `basic_string` adds functionality to the class template
[`std::basic_string`][std_basic_string].

Several typedefs for common character types are provided:

| Type            | Definition                   |
|-----------------|------------------------------|
|`nik::string`    | `nik::basic_string<char>`    |
|`nik::wstring`   | `nik::basic_string<wchar_t>` |
|`nik::u16string` | `nik::basic_string<char16_t>`|
|`nik::u32string` | `nik::basic_string<char32_t>`|

## Template parameters
- **CharT** : character type
- **Traits** : traits class specifying the operations on the character type
- **Allocator** : [Allocator][concepts_allocator] type used to allocate internal storage

## Member types

| Member type              | Definition                                                                      |
|--------------------------|---------------------------------------------------------------------------------|
| `std_basic_string`       | `std::basic_string<CharT, Traits, Allocator>`                                   |
| `traits_type`            | `typename std_basic_string::traits_type;`                                       |
| `value_type`             | `typename std_basic_string::value_type;`                                        |
| `allocator_type`         | `typename std_basic_string::allocator_type;`                                    |
| `size_type`              | `typename std_basic_string::size_type;`                                         |
| `difference_type`        | `typename std_basic_string::difference_type;`                                   |
| `reference`              | `typename std_basic_string::reference;`                                         |
| `const_reference`        | `typename std_basic_string::const_reference;`                                   |
| `pointer`                | `typename std_basic_string::pointer;`                                           |
| `const_pointer`          | `typename std_basic_string::const_pointer;`                                     |
| `iterator`               | `typename std_basic_string::iterator;`                                          |
| `const_iterator`         | `typename std_basic_string::const_iterator;`                                    |
| `reverse_iterator`       | `typename std_basic_string::reverse_iterator;`                                  |
| `const_reverse_iterator` | `typename std_basic_string::const_reverse_iterator;`                            |

[std_basic_string]: http://en.cppreference.com/w/cpp/string/basic_string
[concepts_allocator]: http://en.cppreference.com/w/cpp/concept/Allocator
