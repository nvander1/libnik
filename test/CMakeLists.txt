cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_executable(main_macro_test main_macro_test.cpp)
add_test(main_macro_test main_macro_test "Hello," " World!")
