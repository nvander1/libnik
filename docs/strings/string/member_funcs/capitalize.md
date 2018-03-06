# `nik::string::capitalize`

---

## Signatures
- `string capitalize()`

## Parameters
(none)

## Returns

Returns a copy of the string with its first character capitalized.
The behavior is undefined if `empty() == true`.

## Example

```cpp
#include <nik/string.hpp>
#inlcude <iostream>

int main() {
    auto hello = nik::string("hello");
    std::cout << hello.capitalize() << std::endl; // prints "Hello"
}
```
