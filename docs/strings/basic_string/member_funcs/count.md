# `nik::basic_string::count`

## Signatures

- `size_type count(std_basic_string sub, size_type start = 0, size_type end = 0)`

## Parameters

- **sub** : The substring for which to look.
- **start** : The index at which to start searching.
- **end** : The index at which to end searching.

## Returns

A count of the number of non-overlapping occurences of **sub** in the
range [**start** : **end**].

## Example

```cpp
#include <nik/string.hpp>
#inlcude <iostream>

int main() {
    auto hello = nik::string("hello hello hello");
    std::cout << hello.count("hello") << std::endl;        // prints 3
    std::cout << hello.count("hello", 5) << std::endl;     // prints 2
    std::cout << hello.count("hello", 5, 12) << std::endl; // prints 1
}
```
