cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_executable(main_macro_test main_macro_test.cpp)
add_test(main_macro_test main_macro_test "Hello," " World!")

add_executable(basic_posix_wrapper_test basic_posix_wrapper_test.cpp)
add_test(basic_posix_wrapper_test basic_posix_wrapper_test "Hello," " World!")

add_executable(sequence_stream_test sequence_stream_test.cpp)
add_test(sequence_stream_test sequence_stream_test)
