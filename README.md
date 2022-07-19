# MCT

MCT (Micro C Test) is a single header library for fast and efficient testing.

The purpose of creating this library as a single header is to easily integrate it with CMake or any other compilation
method.

## Usage

just copy the [MCT.h](/MCT.h) file to the project in which you want to use it.

## Example

```C
#include "MCT.h"

// We call the macro to start the tests
START_TESTING(NULL){
    printf("Only run on first execution.");
}

// Code that is not between the START_TESTING
// or TEST will be evaluated countless times,
// no code must be outside the curly brackets.

TEST(test name, test description){
// Code for the first test
ASSERT(1)
ASSERT_EQ_INT(1, 1)
ASSERT_EQ_DBL(1.0, 1.0)
ASSERT_EQ_STR("test", "test")
ASSERT_EQ_PTR(NULL, NULL)
}



TEST(failed test, description of failed test){
// Code for the second test
ASSERT(0)
ASSERT_EQ_INT(1, 2)
ASSERT_EQ_DBL(1.0, 2.0)
ASSERT_EQ_STR("test", "test2")
ASSERT_EQ_PTR(NULL, "test")
}

END_TESTING
```

a longer example can be found [here](https://github.com/ctronp/EfficientDataStructures/tree/dev/tests)
or [here](/pass_test.c)

## Macros

### START_TESTING

This macro generates the basic structure for test execution.

It receives as argument a function ```void (*fun)()``` which will be executed prior to each test, in case it is not
required, set NULL.

this macro must be used in conjunction with 2 curly brackets that will contain the code to be executed prior to
all tests.

#### Example

```C
START_TESTING(NULL) { printf("starting tests"); }
```

### TEST

This macro generates a test. The macro receives 2 parameters, the first is the name the test takes, the second is the
description of the test.

This macro must be used in conjunction with 2 curly brackets that will contain the code to be executed.

a TEST can only be placed after START_TESTING or another TEST.

### ASSERT_*

Multiple ````ASSERT``` macros were created that work to validate inside a [TEST](#TEST), in case they fail they will stop
the execution of the test, print the error to the stdout, and continue with the next TEST in case it exists.

#### Example

```C
TEST(test name, test description){
// Code for the first test
ASSERT(1)
ASSERT_EQ_INT(1, 1)
ASSERT_EQ_DBL(1.0, 1.0)
ASSERT_EQ_STR("test", "test")
ASSERT_EQ_PTR(NULL, NULL)
}
```

### END_TESTING

This macro prints the final results and ends the program execution.

in case 1 or more tests have failed the program will close with code 1.

in case there is no TEST the program will close with code 1.

in case there is at least 1 TEST and no test has failed, the program will close with code 0.

## Include in CMake

can be included directly as an ``add_executable`` file or as an ``INTERFACE`` library.
