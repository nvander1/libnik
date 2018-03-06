# Welcome to Libnik!

--------------------

## Overview

Libnik is my little C++ library. Its got some doodads and thingamajigs.

## Building

Make sure you've got these before you start building.

- git
- cmake >= 3.10.2
- gcc >= 7.3.0 or clang >= 5.0.1

Next, get the source.

    git clone https://www.github.com/nvander1/libnik.git

Then, generate the build files.

    cd libnik
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
