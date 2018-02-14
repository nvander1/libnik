## Building

First, get the source.

    git clone https://www.github.com/nvander1/nik.git

Then, generate the build files.

    cd nik
    mkdir build && cd build
    cmake ..
    

Optionally, run the tests.

    make && make test

Finally, install it.

    sudo make install

If you need to, you can uninstall.

    sudo make uninstall


## Features

### Main Macro
Replaces `int argc, char **argv` with `std::vector<std::string> args`.

Usage:

    #include <nik/main.hpp>
    #include <iostream>

    int main() {
        std::cout << "Got " << args.size() << " arguments" << std::endl;
        std::cout << args[1] << args[2] << std::endl;
    }
