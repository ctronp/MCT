//
// Created by ctronp on 7/14/22.
//

//#define GOTO_HERE() goto##__COUNTER__##__LINE__##__FILE__:;
//#define SAVE_GOTO GOTO_HERE();

#define JUMP_LAST goto SAVE_GOTO;

#include "MCT.h"

// void cleanup() { printf("cleanup\n"); }

START_TESTING(NULL) {}

TEST(correct test, first test is correct){ASSERT(1)}

TEST(incorrect test, second test is incorrect){ASSERT(0)}

TEST(correct Lower Equal, third test is correct){ASSERT_LE_INT(1, 1)}

TEST(incorrect Lower Equal, fourth test is incorrect){ASSERT_LE_INT(2, 1)}

END_TESTING