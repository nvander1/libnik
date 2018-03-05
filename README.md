## Dependencies

   - cmake >= 3.9.2
   - clang >= 5.0.1 or gcc >= 7.3.0

   Only tested on Linux.

## Building

First, get the source.

    git clone https://www.github.com/nvander1/nik.git

Then, generate the build files.

    cd nik
    mkdir build && cd build

Build with gcc (default),

    cmake ..

or build with clang

    cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ ..
    

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


### Observer Ptr
As specified [here.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4336.html#memory.observer.ptr)
Also specified at [cppreference.](http://en.cppreference.com/w/cpp/experimental/observer_ptr)
Used to express intent that something is a non-owning pointer.

Usage:

    #include <nik/memory.hpp>

    int main() {

    Object some_object{};

    auto obj_ptr = nik::make_observer<Object>(&some_object);
    obj_ptr->foo();

    auto another_ptr = nik::observer_ptr<Object>(obj_ptr);
    another_ptr->foo();

    }


### Python style strings
A subclass of [std::string](http://en.cppreference.com/w/cpp/string/basic_string<Paste>)
that implements some Python string [methods](https://docs.python.org/3/library/stdtypes.html#string-methods).

Since `std::string` doesn't have a virtual destructor, don't try to delete a
`nik::string` through a pointer to `std::string`!

Methods implemented so far:

* [capitalize](https://docs.python.org/3/library/stdtypes.html#str.capitalize)
* [center](https://docs.python.org/3/library/stdtypes.html#str.center)
* [count](https://docs.python.org/3/library/stdtypes.html#str.count)
* [split (partially)](https://docs.python.org/3/library/stdtypes.html#str.split)
