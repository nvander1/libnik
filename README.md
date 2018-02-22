## Dependencies

   - cmake >= 3.10.2
   - clang >= 5.0.1

   Only tested on Linux.

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

### C++ Exceptions for Linux system calls
Might not be a great idea since you still have to check error code.

Perhaps I could define one exception per ERRNO value and you could
catch those exceptions separately.

Anyways, here's an example.

Usage:

    #include <nik/error.hpp>
    #include <unistd.h>

    int main() {
        nik::syscall_except<decltype(close), close> wrapped_close{};

        try {
            wrapped_close(-500);
        } catch (std::system_error &error) {
            // here error.code().value() should equal ENOENT
        }
    }


### \<\< Operator for Sequence Containers
Helpful for debugging and printing out elements of a sequence or a std::array.

Usage:

    #include <nik/stream.hpp>
    #include <iostream>
    #include <vector>

    using nik::operator<<;

    int main() {
        std::vector vector{1, 2, 3, 4, 5};

        std::cout << vector << std::endl;
        // prints out [1, 2, 3, 4, 5]
    }
