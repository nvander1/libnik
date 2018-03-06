# `nik::string::split`

## Signatures
1. `std::vector<string> split(size_t maxsplit = SIZE_MAX)`
2. `std::vector<string> split(std::string sep)`
3. `std::vector<string> split(std::string sep, size_t maxsplit)`

## Parameters
- **sep** : The delimeter to split on.
- **maxsplit**: The maximum number of splits to make.

## Returns
1. Tokens split by whitespace. Limited to **maxsplit** + 1 tokens if specified.
2. Tokens split by **sep**.
3. Tokens split by **sep**. Limited to **maxsplit** + 1 tokens.

## Example

```cpp
#include <nik/string.hpp>
#include <cassert>
#include <iostream>

int main() {
    // splitting on a comma
    auto csv = nik::string("a,b,c,d,e");

    auto csv_toks = csv.split(",");
    assert(csv_toks.size() == 5);

    auto csv_3toks = csv.split(",", 2);
    assert(csv_3toks.size() == 3);

    // splitting on whitespace
    auto text = nik::string("a    \t b \t\t\t c");
    assert(text.split().size() == 3);
}
```
