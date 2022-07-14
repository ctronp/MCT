//
// Created by ctronp on 7/14/22.
//

#include "MCT.h"

START_TESTING(NULL)

TEST(test1, test1) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3);
}

END_TESTING