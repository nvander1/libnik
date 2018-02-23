cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(GTest)
include(GoogleTest)

# usage: new_test(name [args...])
function(new_test name)
    add_executable(${name} ${name}.cpp)
    add_test(${name} ${name} ${ARGN})
endfunction(new_test)

# usage: new_gtest(name [args...])
function(new_gtest name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} GTest::GTest)
    if(${ARGC} EQUAL 1)
    gtest_discover_tests(${name})
    else()
    gtest_discover_tests(${name} EXTRA_ARGS ${ARGN})
    endif()
endfunction(new_gtest)


new_test(main_macro_test "Hello," " World!")
new_gtest(syscall_except_tests)
new_gtest(sequence_stream_tests)
new_gtest(observer_ptr_tests)
