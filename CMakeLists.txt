cmake_minimum_required(VERSION 3.22)
project(MCT C)

set(CMAKE_C_STANDARD 11)

include(CTest)
include_directories(.)

add_executable(pass_test
        MCT.h pass_test.c)
add_executable(fail_test
        MCT.h fail_test.c)

add_test(pass_test pass_test)
add_test(fail_test fail_test)

set_tests_properties(fail_test PROPERTIES
        WILL_FAIL on)
