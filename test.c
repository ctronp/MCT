//
// Created by ctronp on 7/14/22.
//

//#define GOTO_HERE() goto##__COUNTER__##__LINE__##__FILE__:;
//#define SAVE_GOTO GOTO_HERE();

#define JUMP_LAST goto SAVE_GOTO;

#include "MCT.h"

START_TESTING(NULL)

TEST(test1, test1) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3);
}
END_TESTING