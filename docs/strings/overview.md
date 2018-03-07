# Strings library

The Nik strings library provides user-friendly functionality for manipulating
strings. All classes and functions referenced without an explicit namespace
are members of `namespace nik`.

## Classes

---

| Name           | Brief description                                                              |
|----------------|--------------------------------------------------------------------------------|
| `basic_string` | A subclass of `std::string` providing functionality similar to Python strings. |


## `string`

---

### Member functions

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
