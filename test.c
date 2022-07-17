//
// Created by ctronp on 7/14/22.
//

#include "MCT.h"

START_TESTING(NULL) { printf("starting tests\n"); }

// TEST PASSED
TEST(Test ASSERT,
     este test debería aprobarse) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3)
}

TEST(Test ASSERT_EQ,
     este test debería aprobarse) {
  char a = 'A';
  char b = 'A';
  ASSERT_EQ(a, b)
}

TEST(Test ASSERT_NE,
     este test debería aprobarse) {
  char a = 'A';
  char b = 'B';
  ASSERT_NE(a, b)
}

TEST(Test ASSERT_EQ_INT,
     este test debería aprobarse) {
  int a = 4;
  int b = 4;
  ASSERT_EQ_INT(a, b)
}

TEST(Test ASSERT_NEQ_INT,
     este test debería aprobarse) {
  int a = 4;
  int b = 3;
  ASSERT_NEQ_INT(a, b)
}

TEST(Test ASSERT_LT_INT,
     este test debería aprobarse) {
  int a = 4;
  int b = 3;
  ASSERT_LT_INT(a, b)
}

TEST(Test ASSERT_LT_INT,
     este test debería aprobarse) {
  int a = 4;
  int b = 3;
  ASSERT_LT_INT(a, b)
}

TEST(Test ASSERT_LE_INT,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_GT_INT,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_GT_INT,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_GE_INT,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_EQ_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_NE_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_LT_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_LE_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST(Test ASSERT_GT_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_GT_UNS(a, b)
}

TEST(Test ASSERT_GT_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_GT_UNS(a, b)
}

TEST(Test ASSERT_GE_UNS,
     este test debería aprobarse) {
  int a = 3;
  int b = 4;
  ASSERT_GT_UNS(a, b)
}

//TEST FAILED

TEST(Test ASSERT_EQ_UNS, este test debería fallar) {
  unsigned a = 1;
  unsigned b = 2;

  ASSERT_EQ_UNS(a, b)
}

TEST(test random, descripcion cualquiera) {
  int a = 1;
  int b = 2;

  ASSERT_EQ_INT(a, b)
}

END_TESTING
