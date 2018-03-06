# `nik::string::center`

## Signatures

- `string center(size_t width, char fillchar=' ')`

## Parameters

- **width** : The desired buffer width.
- **fillchar** : The character to use for padding.

## Returns

Returns a copy of the string centered in a string of length **width**.
Padding is done with **fillchar**. If **width** is less than the length of
the string, a copy of the string is returned.

## Example

```cpp
#include <nik/string.hpp>
#inlcude <iostream>

int main() {
    auto hello = nik::string("hello");
    std::cout << hello.center(9) << std::endl;      // prints "  hello  "
    std::cout << hello.center(9, '-') << std::endl; // prints "--hello--"
    std::cout << hello.center(1) << std::endl;      // prints "hello"
}
```
