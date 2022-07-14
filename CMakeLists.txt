cmake_minimum_required(VERSION 3.22)
project(MCT C)

set(CMAKE_C_STANDARD 11)

include(CTest)
include_directories(.)

add_executable(MCT
        MCT.h test.c)
add_test(MCT MCT)
