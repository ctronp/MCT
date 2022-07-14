//
// Created by ctronp on 7/14/22.
//

//#define GOTO_HERE() goto##__COUNTER__##__LINE__##__FILE__:;
//#define SAVE_GOTO GOTO_HERE();

#define JUMP_LAST goto SAVE_GOTO;

#include "MCT.h"

void cleanup() {
    printf("cleanup\n");
}

START_TESTING(cleanup)

TEST(test1, test1) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3);
}

TEST(test2, descripcion del test 2) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c != 3);
}

TEST(a, a){ASSERT(true)}

TEST(a, a){ASSERT(true)}

TEST(a, a){ASSERT(true)}

TEST(a, a){ASSERT(true)}

TEST(a, a){ASSERT(false)}

TEST(a, a){ASSERT(false)}

TEST(a, a){ASSERT(false)}

TEST(a, a){ASSERT(false)}

TEST(a, a){ASSERT(false)}

TEST(a, a){ASSERT(true)}

END_TESTING