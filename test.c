//
// Created by ctronp on 7/14/22.
//

#include "MCT.h"

START_TESTING(NULL) { printf("starting tests\n"); }

TEST(test de prueba 1,
     este test se encargara de probar que el programa funciona) {
  int a = 1;
  int b = 2;
  int c = a + b;
  ASSERT(c == 3)
}

TEST(test random, descripcion cualquiera) {
  unsigned a = 1;
  unsigned b = 2;

  ASSERT_EQ_UNS(a, b)
}

END_TESTING
