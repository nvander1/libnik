cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)
project(nik LANGUAGES CXX)

include(GNUInstallDirs)

add_library(nik INTERFACE)
set(CMAKE_CXX_STANDARD 17)

target_compile_options(nik INTERFACE
    -Werror -Wall -Wextra -Wpedantic
    -Wuninitialized -Wduplicated-cond -Wfloat-equal -Wshadow
    -Wcast-qual -Wcast-align -Wuseless-cast -Wlogical-op -Wredundant-decls
    -Winline -Wdisabled-optimization
)

target_include_directories(nik INTERFACE include
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>
)

enable_testing()
add_subdirectory(test)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/nik)

# https://cmake.org/Wiki/CMake_FAQ#Can_I_do_.22make_uninstall.22_with_CMake.3F
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
