# Strings library

The Nik strings library provides user-friendly functionality for manipulating
strings. All classes and functions referenced without an explicit namespace
are members of `namespace nik`.

## Classes

---

| Name           | Brief description                                                              |
|----------------|--------------------------------------------------------------------------------|
| `basic_string` | An adapter for string types providing functionality similar to Python strings. |


## `basic_string`

---

### Member types

| Name                     | Definition                                       |
|--------------------------|--------------------------------------------------|
| `string_type`            | `std::basic_string<CharT, Traits, Allocator>`    |
| `traits_type`            | `typename string_type::traits_type`              |
| `value_type`             | `typename string_type::value_type`               |
| `allocator_type`         | `typename string_type::allocator_type`           |
| `size_type`              | `typename string_type::size_type`                |
| `difference_type`        | `typename string_type::difference_type`          |
| `reference`              | `typename string_type::reference`                |
| `const_reference`        | `typename string_type::const_reference`          |
| `pointer`                | `typename string_type::pointer`                  |
| `const_pointer`          | `typename string_type::const_pointer`            |
| `iterator`               | `typename string_type::iterator`                 |
| `const_iterator`         | `typename string_type::const_iterator`           |
| `reverse_iterator`       | `typename string_type::reverse_iterator`         |
| `const_reverse_iterator` | `typename string_type::const_reverse_iterator`   |

### Member functions

#### Constructors

| Signature                                | Brief Description                |
|------------------------------------------|----------------------------------|
| `basic_string(const string_type& other)` | Copy conversion constructor.     |
| `basic_string(string_type&& other)`      | Move conversion constructor.     |

#### Transformations

| Name                                    | Return type                 | Brief Description                                                  |
|-----------------------------------------|-----------------------------|--------------------------------------------------------------------|
| [`capitalize`][basic_string_capitalize] | `basic_string`              | Returns a copy of the string with its first character capitalized. |
| [`center`][basic_string_center]         | `basic_string`              | Returns a copy of the string centered in a buffer.                 |
| [`count`][basic_string_count]           | `size_t`                    | Counts the number of non-overlapping occurances of a substring.    |
| [`split`][basic_string_split]           | `std::vector<basic_string>` | Splits a string by a delimeter into tokens.                        |

[basic_string_capitalize]: ./basic_string/member_funcs/capitalize.md
[basic_string_center]: ./basic_string/member_funcs/center.md
[basic_string_count]: ./basic_string/member_funcs/count.md
[basic_string_split]: ./basic_string/member_funcs/split.md
