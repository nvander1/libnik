# Strings library

The Nik strings library provides user-friendly functionality for manipulating
strings. All classes and functions referenced without an explicit namespace
are members of `namespace nik`.

## Classes

---

| Name     | Brief description                                                              |
|----------|--------------------------------------------------------------------------------|
| `string` | A subclass of `std::string` providing functionality similar to Python strings. |


## `string`

---

### Member functions

| Name                              | Return type           | Brief Description                                                  |
|-----------------------------------|-----------------------|--------------------------------------------------------------------|
| [`capitalize`][string_capitalize] | `string`              | Returns a copy of the string with its first character capitalized. |
| [`center`][string_center]         | `string`              | Returns a copy of the string centered in a buffer.                 |
| [`count`][string_count]           | `size_t`              | Counts the number of non-overlapping occurances of a substring.    |
| [`split`][string_split]           | `std::vector<string>` | Splits a string by a delimeter into tokens.                        |

[string_capitalize]: ./string/member_funcs/capitalize.md
[string_center]: ./string/member_funcs/center.md
[string_count]: ./string/member_funcs/count.md
[string_split]: ./string/member_funcs/split.md
