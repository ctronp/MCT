//
// Created by ctronp on 7/14/22.
//

#include "MCT.h"

START_TESTING(NULL) { printf("starting tests\n"); }

// TEST PASSED
TEST("Test ASSERT", "este test debería aprobarse") {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3)
}

TEST("Test ASSERT", "este test debería aprobarse") {
  int a = 1;
  int b = -2;
  int c = a + b;
  ASSERT(c == -1)
}

TEST("Test ASSERT_EQ", "este test debería aprobarse") {
  char a = 'A';
  char b = 'A';
  ASSERT_EQ(a, b)
}

TEST("Test ASSERT_NE", "este test debería aprobarse") {
  char a = 'A';
  char b = 'B';
  ASSERT_NE(a, b)
}

TEST("Test ASSERT_EQ_INT", "este test debería aprobarse") {
  int a = 4;
  int b = 4;
  ASSERT_EQ_INT(a, b)
}

TEST("Test ASSERT_EQ_INT", "este test debería aprobarse") {
  int a = -4;
  int b = -4;
  ASSERT_EQ_INT(a, b)
}

TEST("Test ASSERT_EQ_INT", "este test debería aprobarse") {
  int a = 0;
  int b = 0;
  ASSERT_EQ_INT(a, b)
}

TEST("Test ASSERT_NEQ_INT", "este test debería aprobarse") {
  int a = 4;
  int b = 3;
  ASSERT_NEQ_INT(a, b)
}

TEST("Test ASSERT_LT_INT", "este test debería aprobarse") {
  int a = 2;
  int b = 3;
  ASSERT_LT_INT(a, b)
}

TEST("Test ASSERT_LE_INT", "este test debería aprobarse") {
  int a = 3;
  int b = 4;
  ASSERT_LE_INT(a, b)
}

TEST("Test ASSERT_LE_INT", "este test debería aprobarse") {
  int a = 3;
  int b = 3;
  ASSERT_LE_INT(a, b)
}

TEST("Test ASSERT_GT_INT", "este test debería aprobarse") {
  int a = 5;
  int b = 4;
  ASSERT_GT_INT(a, b)
}

TEST("Test ASSERT_GT_INT", "este test debería aprobarse") {
  int a = -1;
  int b = -5;
  ASSERT_GT_INT(a, b)
}

TEST("Test ASSERT_GE_INT", "este test debería aprobarse") {
  int a = 5;
  int b = 4;
  ASSERT_GE_INT(a, b)
}

TEST("Test ASSERT_GE_INT", "este test debería aprobarse") {
  int a = -4;
  int b = -4;
  ASSERT_GE_INT(a, b)
}

TEST("Test ASSERT_EQ_UNS", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned b = 3;
  ASSERT_EQ_UNS(a, b)
}

TEST("Test ASSERT_NE_UNS", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned b = 4;
  ASSERT_NE_UNS(a, b)
}

TEST("Test ASSERT_LT_UNS", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned b = 4;
  ASSERT_LT_UNS(a, b)
}

TEST("Test ASSERT_LE_UNS", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned b = 4;
  ASSERT_LE_UNS(a, b)
}

TEST("Test ASSERT_LE_UNS", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned b = 3;
  ASSERT_LE_UNS(a, b)
}

TEST("Test ASSERT_GT_UNS", "este test debería aprobarse") {
  unsigned a = 5;
  unsigned b = 4;
  ASSERT_GT_UNS(a, b)
}

TEST("Test ASSERT_GE_UNS", "este test debería aprobarse") {
  unsigned a = 4;
  unsigned b = 4;
  ASSERT_GE_UNS(a, b)
}

TEST("Test ASSERT_EQ_STR", "este test debería aprobarse") {
  char *a = "Water";
  char *b = "Water";
  ASSERT_EQ_STR(a, b)
}

TEST("Test ASSERT_NE_STR", "este test debería aprobarse") {
  char *a = "Water";
  char *b = "Fire";
  ASSERT_NE_STR(a, b)
}

TEST("Test ASSERT_EQ_PTR", "este test debería aprobarse") {
  int a = 3;
  int *b = &a;
  int *c = &a;
  ASSERT_EQ_PTR(b, c)
}

TEST("Test ASSERT_EQ_PTR", "este test debería aprobarse") {
  int a = -3;
  int *b = &a;
  int *c = &a;
  ASSERT_EQ_PTR(b, c)
}

TEST("Test ASSERT_EQ_PTR", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned *b = &a;
  unsigned *c = &a;
  ASSERT_EQ_PTR(b, c)
}

TEST("Test ASSERT_EQ_PTR", "este test debería aprobarse") {
  char a = 'W';
  char *b = &a;
  char *c = &a;
  ASSERT_EQ_PTR(b, c)
}

TEST("Test ASSERT_NE_PTR", "este test debería aprobarse") {
  char a = 'W';
  char n = 'Q';
  char *b = &a;
  char *c = &n;
  ASSERT_NE_PTR(b, c)
}

TEST("Test ASSERT_NE_PTR", "este test debería aprobarse") {
  int a = 3;
  int n = 4;
  int *b = &a;
  int *c = &n;
  ASSERT_NE_PTR(b, c)
}

TEST("Test ASSERT_NE_PTR", "este test debería aprobarse") {
  int a = -3;
  int n = 4;
  int *b = &a;
  int *c = &n;
  ASSERT_NE_PTR(b, c)
}

TEST("Test ASSERT_NE_PTR", "este test debería aprobarse") {
  int a = -3;
  int n = -4;
  int *b = &a;
  int *c = &n;
  ASSERT_NE_PTR(b, c)
}

TEST("Test ASSERT_NE_PTR", "este test debería aprobarse") {
  unsigned a = 3;
  unsigned n = 4;
  unsigned *b = &a;
  unsigned *c = &n;
  ASSERT_NE_PTR(b, c)
}

TEST("Test ASSERT_EQ_FLT", "este test debería aprobarse") {
  float a = 3.0f;
  float b = 3.0f;
  ASSERT_EQ_FLT(a, b)
}

TEST("Test ASSERT_EQ_FLT", "este test debería aprobarse") {
  float a = -3.0f;
  float b = -3.0f;
  ASSERT_EQ_FLT(a, b)
}

TEST("Test ASSERT_NE_FLT", "este test debería aprobarse") {
  float a = 3.0f;
  float b = 4.0f;
  ASSERT_NE_FLT(a, b)
}

TEST("Test ASSERT_NE_FLT", "este test debería aprobarse") {
  float a = -3.0f;
  float b = -4.0f;
  ASSERT_NE_FLT(a, b)
}

TEST("Test ASSERT_EQ_ABS_FLT", "este test debería aprobarse") {
  float a = 3.0f;
  float b = 3.0f;
  float eps = 0.05f;
  ASSERT_EQ_ABS_FLT(a, b, eps)
}

TEST("Test ASSERT_EQ_ABS_FLT", "este test debería aprobarse") {
  float a = -3.0f;
  float b = -3.0f;
  float eps = 0.05f;
  ASSERT_EQ_ABS_FLT(a, b, eps)
}

TEST("Test ASSERT_NE_ABS_FLT", "este test debería aprobarse") {
  float a = -3.0f;
  float b = 3.0f;
  float eps = 0.05f;
  ASSERT_NE_ABS_FLT(a, b, eps)
}

TEST("Test ASSERT_NE_ABS_FLT", "este test debería aprobarse") {
  float a = -4.0f;
  float b = 3.0f;
  float eps = 0.05f;
  ASSERT_NE_ABS_FLT(a, b, eps)
}

TEST("Test ASSERT_EQ_DBL", "este test debería aprobarse") {
  double a = 3.111111111111111;
  double b = 3.111111111111111;
  ASSERT_EQ_DBL(a, b)
}

TEST("Test ASSERT_EQ_DBL", "este test debería aprobarse") {
  double a = -3.111111111111111;
  double b = -3.111111111111111;
  ASSERT_EQ_DBL(a, b)
}

TEST("Test ASSERT_NE_DBL", "este test debería aprobarse") {
  double a = 3.111111111111111;
  double b = 4.111111111111111;
  ASSERT_NE_DBL(a, b)
}

TEST("Test ASSERT_NE_DBL", "este test debería aprobarse") {
  double a = 3.111111111111111;
  double b = -3.111111111111111;
  ASSERT_NE_DBL(a, b)
}

TEST("Test ASSERT_EQ_ABS_DBL", "este test debería aprobarse") {
  double a = 3.111111111111111;
  double b = 3.111111111111111;
  double eps = 0.05;
  ASSERT_EQ_ABS_DBL(a, b, eps)
}

TEST("Test ASSERT_EQ_ABS_DBL", "este test debería aprobarse") {
  double a = -3.111111111111111;
  double b = -3.111111111111111;
  double eps = 0.05;
  ASSERT_EQ_ABS_DBL(a, b, eps)
}

TEST("Test ASSERT_NE_ABS_DBL", "este test debería aprobarse") {
  double a = -3.111111111111111;
  double b = 3.111111111111111;
  double eps = 0.05;
  ASSERT_NE_ABS_DBL(a, b, eps)
}

TEST("Test ASSERT_NE_ABS_DBL", "este test debería aprobarse") {
  double a = -4.111111111111111;
  double b = 3.111111111111111;
  double eps = 0.05;
  ASSERT_NE_ABS_DBL(a, b, eps)
}

END_TESTING
