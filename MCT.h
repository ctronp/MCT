#pragma once

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifdef _MSC_VER

#include <windows.h>

static inline void red_terminal() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

static inline void green_terminal() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

static inline void default_terminal() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 3);
}

#else

static inline void red_terminal() { printf("\033[0;31m"); }

static inline void green_terminal() { printf("\033[0;32m"); }

static inline void default_terminal() { printf("\033[0;39m"); }

#endif

typedef enum {
  TEST_PASSED,
  SIGNED,
  UNSIGNED,
  STR,
  FLOAT,
  DOUBLE,
  PTR,
  UNKNOWN,
} FAIL_TYPE;
typedef union {
  long long ll;
  long long unsigned llu;
  float flt;
  double dbl;
  char *str;
  void *ptr;
} FAIL_DATA;

typedef struct {
  FAIL_TYPE type;
  char *format;
  FAIL_DATA data1;
  FAIL_DATA data2;
  char *file;
  long long unsigned line;
} Failure;

#define ASSERT(x)                                                              \
  if (!(x)) {                                                                  \
    fail_data =                                                                \
        (Failure){.type = UNKNOWN, .file = __FILE__, .line = __LINE__};        \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ(x, y)                                                        \
  if ((x) != (y)) {                                                            \
    fail_data =                                                                \
        (Failure){.type = UNKNOWN, .file = __FILE__, .line = __LINE__};        \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE(x, y)                                                        \
  if ((x) == (y)) {                                                            \
    fail_data =                                                                \
        (Failure){.type = UNKNOWN, .file = __FILE__, .line = __LINE__};        \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_INT(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld == %lld",                     \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NEQ_INT(x, y)                                                   \
  if ((x) == (y)) {                                                            \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld != %lld",                     \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_LT_INT(x, y)                                                    \
  if ((x) >= (y)) {                                                            \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld < %lld",                      \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_LE_INT(x, y)                                                    \
  if ((x) > (y)) {                                                             \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld <= %lld",                     \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_GT_INT(x, y)                                                    \
  if ((x) <= (y)) {                                                            \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld > %lld",                      \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_GE_INT(x, y)                                                    \
  if ((x) < (y)) {                                                             \
    fail_data = (Failure){.type = SIGNED,                                      \
                          .format = "Error: %lld >= %lld",                     \
                          .data1.ll = (x),                                     \
                          .data2.ll = (y),                                     \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_UNS(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu == %llu",                     \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_UNS(x, y)                                                    \
  if ((x) == (y)) {                                                            \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu != %llu",                     \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_LT_UNS(x, y)                                                    \
  if ((x) >= (y)) {                                                            \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu < %llu",                      \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_LE_UNS(x, y)                                                    \
  if ((x) > (y)) {                                                             \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu <= %llu",                     \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_GT_UNS(x, y)                                                    \
  if ((x) <= (y)) {                                                            \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu > %llu",                      \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_GE_UNS(x, y)                                                    \
  if ((x) < (y)) {                                                             \
    fail_data = (Failure){.type = UNSIGNED,                                    \
                          .format = "Error: %llu >= %llu",                     \
                          .data1.llu = (x),                                    \
                          .data2.llu = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_STR(x, y)                                                    \
  if (strcmp((x), (y)) != 0) {                                                 \
    fail_data = (Failure){.type = STR,                                         \
                          .format = "Error: %s == %s",                         \
                          .data1.str = (x),                                    \
                          .data2.str = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_STR(x, y)                                                    \
  if (strcmp((x), (y)) == 0) {                                                 \
    fail_data = (Failure){.type = STR,                                         \
                          .format = "Error: %s != %s",                         \
                          .data1.str = (x),                                    \
                          .data2.str = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_PTR(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = (Failure){.type = PTR,                                         \
                          .format = "Error: %p == %p",                         \
                          .data1.ptr = (x),                                    \
                          .data2.ptr = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_PTR(x, y)                                                    \
  if ((x) == (y)) {                                                            \
    fail_data = (Failure){.type = PTR,                                         \
                          .format = "Error: %p != %p",                         \
                          .data1.ptr = (x),                                    \
                          .data2.ptr = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_FLT(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = (Failure){.type = FLOAT,                                       \
                          .format = "Error: %f == %f",                         \
                          .data1.flt = (x),                                    \
                          .data2.flt = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_FLT(x, y)                                                    \
  if ((x) == (y)) {                                                            \
    fail_data = (Failure){.type = FLOAT,                                       \
                          .format = "Error: %f != %f",                         \
                          .data1.flt = (x),                                    \
                          .data2.flt = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_ABS_FLT(x, y, eps)                                           \
  if (fabs((x) - (y)) > (eps)) {                                               \
    fail_data = (Failure){.type = FLOAT,                                       \
                          .format = "Error: %f == %f",                         \
                          .data1.flt = (x),                                    \
                          .data2.flt = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_ABS_FLT(x, y, eps)                                           \
  if (fabs((x) - (y)) <= (eps)) {                                              \
    fail_data = (Failure){.type = FLOAT,                                       \
                          .format = "Error: %f != %f",                         \
                          .data1.flt = (x),                                    \
                          .data2.flt = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_DBL(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = (Failure){.type = DOUBLE,                                      \
                          .format = "Error: %lf == %lf",                       \
                          .data1.dbl = (x),                                    \
                          .data2.dbl = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_DBL(x, y)                                                    \
  if ((x) == (y)) {                                                            \
    fail_data = (Failure){.type = DOUBLE,                                      \
                          .format = "Error: %lf != %lf",                       \
                          .data1.dbl = (x),                                    \
                          .data2.dbl = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_EQ_ABS_DBL(x, y, eps)                                           \
  if (fabs((x) - (y)) > (eps)) {                                               \
    fail_data = (Failure){.type = DOUBLE,                                      \
                          .format = "Error: %lf == %lf",                       \
                          .data1.dbl = (x),                                    \
                          .data2.dbl = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define ASSERT_NE_ABS_DBL(x, y, eps)                                           \
  if (fabs((x) - (y)) <= (eps)) {                                              \
    fail_data = (Failure){.type = DOUBLE,                                      \
                          .format = "Error: %lf != %lf",                       \
                          .data1.dbl = (x),                                    \
                          .data2.dbl = (y),                                    \
                          .file = __FILE__,                                    \
                          .line = __LINE__};                                   \
    fail_c++;                                                                  \
    goto TEST_INIT_LABEL;                                                      \
  }

#define PRINT_FAIL                                                             \
  red_terminal();                                                              \
  printf("\t\ttest failed in line %llu on file %s\n\t\t", fail_data.line,      \
         fail_data.file);                                                      \
  switch (fail_data.type) {                                                    \
  case SIGNED:                                                                 \
    printf(fail_data.format, fail_data.data1.ll, fail_data.data2.ll);          \
    break;                                                                     \
  case UNSIGNED:                                                               \
    printf(fail_data.format, fail_data.data1.llu, fail_data.data2.llu);        \
    break;                                                                     \
  case STR:                                                                    \
    printf(fail_data.format, fail_data.data1.str, fail_data.data2.str);        \
    break;                                                                     \
  case FLOAT:                                                                  \
    printf(fail_data.format, fail_data.data1.flt, fail_data.data2.flt);        \
    break;                                                                     \
  case DOUBLE:                                                                 \
    printf(fail_data.format, fail_data.data1.dbl, fail_data.data2.dbl);        \
    break;                                                                     \
  case PTR:                                                                    \
    printf(fail_data.format, fail_data.data1.ptr, fail_data.data2.ptr);        \
    break;                                                                     \
  case UNKNOWN:                                                                \
  default:                                                                     \
    break;                                                                     \
    printf("%s", fail_data.format);                                            \
    break;                                                                     \
  }                                                                            \
  printf("\n\n");

#define START_TESTING(pre_function)                                            \
  int main(int ARGC, char **ARGV) {                                            \
    void (*pre_fun)() = pre_function;                                          \
    unsigned test_c = 0, fail_c = 0, skip_test;                                \
    char *test_name, *test_desc;                                               \
    bool do_test;                                                              \
    Failure fail_data = (Failure){.type = TEST_PASSED};                        \
    default_terminal();                                                        \
  TEST_INIT_LABEL:;                                                            \
    if (fail_data.type != TEST_PASSED) {                                       \
      PRINT_FAIL                                                               \
    }                                                                          \
                                                                               \
    skip_test = test_c;                                                        \
    if (fail_data.type == TEST_PASSED)

// Don't use,  other macros will call this.
#define END_TEST                                                               \
  if (test_c != 0 && fail_data.type == TEST_PASSED) {                          \
    green_terminal();                                                          \
    printf("test %u pass.\n\n", test_c);                                       \
  }

#define END_TESTING                                                            \
  END_TEST;                                                                    \
                                                                               \
  /*  Printing Results  */                                                     \
  if (test_c == 0) {                                                           \
    red_terminal();                                                            \
    printf("no test was found.\n");                                            \
    return 1;                                                                  \
                                                                               \
  } else if (fail_c != 0) {                                                    \
    red_terminal();                                                            \
    printf("%.3lf%% of the results were correct.\n",                           \
           (100.0 * (test_c - fail_c)) / test_c);                              \
  } else {                                                                     \
    green_terminal();                                                          \
    printf("100%% of the results were correct.\n");                            \
  }                                                                            \
                                                                               \
  /* Return Value */                                                           \
  if (fail_c != 0) {                                                           \
    return 1;                                                                  \
  }                                                                            \
  return 0;                                                                    \
  }

#define TEST(name, description)                                                \
  END_TEST;                                                                    \
  do_test = true;                                                              \
                                                                               \
  if (skip_test > 0) {                                                         \
    do_test = false;                                                           \
    skip_test--;                                                               \
  } else {                                                                     \
    default_terminal();                                                        \
    if (pre_fun)                                                               \
      pre_fun();                                                               \
                                                                               \
    test_name = name;                                                          \
    test_desc = description;                                                   \
                                                                               \
    test_c++;                                                                  \
    printf("test %u:\t%s\n\t\t%s\n", test_c, test_name, test_desc);            \
                                                                               \
    fail_data.type = TEST_PASSED;                                              \
  }                                                                            \
  if (do_test)
