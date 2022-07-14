#define IS_SIG(x) (((x)*0 - 1) < (x * 0))
#define INT_PRINT(x) printf(#x ": %llu\n", (long long unsigned)(x))
#define UNS_PRINT(x) printf(#x ": %lld\n", (long long)(x))
#define DEBUG_P(x) IS_SIG(x) ? INT_PRINT(x) : UNS_PRINT(x)

#include <stdbool.h>
#include <stdio.h>

#ifdef _MSC_VER

#include <windows.h>

static inline void red_terminal() {
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

static inline void green_terminal() {
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

static inline void default_terminal() {
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 3);
}

#else

static inline void red_terminal() { printf("\033[0;31m"); }

static inline void green_terminal() { printf("\033[0;32m"); }

static inline void default_terminal() { printf("\033[0;34m"); }

#endif

typedef enum {
  TEST_PASSED,
  SIGNED,
  UNSIGNED,
  STR,
  FLOAT,
  DOUBLE,
  CUSTOM,
  UNKNOWN,
} FAIL_TYPE;
typedef union {
  long long ll;
  long long unsigned llu;
  char *str;
} FAIL_DATA;

typedef struct {
  FAIL_TYPE type;
  FAIL_DATA data1;
  FAIL_DATA data2;
  unsigned long long line;
} Failure;

#define ASSERT(x)                                                              \
  if (!(x)) {                                                                  \
    fail_data = {.type = UNKNOWN, .line = __LINE__};                           \
    break;                                                                     \
  }

#define ASSERT_EQ_INT(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = {                                                              \
        .type = SIGNED, .data1.ll = (x), .data2.ll = (y), .line = __LINE__};   \
    break;                                                                     \
  }

#define ASSERT_LT_INT(x, y)                                                    \
  if ((x) >= (y)) {                                                            \
    fail_data = {                                                              \
        .type = SIGNED, .data1.ll = (x), .data2.ll = (y), .line = __LINE__};   \
    break;                                                                     \
  }

#define ASSERT_LE_INT(x, y)                                                    \
  if ((x) > (y)) {                                                             \
    fail_data = {                                                              \
        .type = SIGNED, .data1.ll = (x), .data2.ll = (y), .line = __LINE__};   \
    break;                                                                     \
  }

#define ASSERT_GT_INT(x, y)                                                    \
  if ((x) <= (y)) {                                                            \
    fail_data = {                                                              \
        .type = SIGNED, .data1.ll = (x), .data2.ll = (y), .line = __LINE__};   \
    break;                                                                     \
  }

#define ASSERT_GE_INT(x, y)                                                    \
  if ((x) < (y)) {                                                             \
    fail_data = {                                                              \
        .type = SIGNED, .data1.ll = (x), .data2.ll = (y), .line = __LINE__};   \
    break;                                                                     \
  }

#define ASSERT_EQ_UNS(x, y)                                                    \
  if ((x) != (y)) {                                                            \
    fail_data = {.type = UNSIGNED,                                             \
                 .data1.llu = (x),                                             \
                 .data2.llu = (y),                                             \
                 .line = __LINE__};                                            \
    break;                                                                     \
  }

#define ASSERT_LT_UNS(x, y)                                                    \
  if ((x) >= (y)) {                                                            \
    fail_data = {.type = UNSIGNED,                                             \
                 .data1.llu = (x),                                             \
                 .data2.llu = (y),                                             \
                 .line = __LINE__};                                            \
    break;                                                                     \
  }

#define ASSERT_LE_UNS(x, y)                                                    \
  if ((x) > (y)) {                                                             \
    fail_data = {.type = UNSIGNED,                                             \
                 .data1.llu = (x),                                             \
                 .data2.llu = (y),                                             \
                 .line = __LINE__};                                            \
    break;                                                                     \
  }

#define ASSERT_GT_UNS(x, y)                                                    \
  if ((x) <= (y)) {                                                            \
    fail_data = {.type = UNSIGNED,                                             \
                 .data1.llu = (x),                                             \
                 .data2.llu = (y),                                             \
                 .line = __LINE__};                                            \
    break;                                                                     \
  }

#define ASSERT_GE_UNS(x, y)                                                    \
  if ((x) < (y)) {                                                             \
    fail_data = {.type = UNSIGNED,                                             \
                 .data1.llu = (x),                                             \
                 .data2.llu = (y),                                             \
                 .line = __LINE__};                                            \
    break;                                                                     \
  }

#define START_TESTING(pre_function)                                            \
  int main(int ARGC, char **ARGV) {                                            \
    const void (*fun_ptr)() = pre_function;                                    \
    unsigned test_c = 0, pos_c = 0, fail_c = 0;                                \
    char *test_name, *test_desc;                                               \
    bool test_success;                                                         \
    Failure fail_data;                                                         \
    default_terminal();                                                        \
    do {

// Don't use,  other macros will call this.
#define END_TEST                                                               \
  }                                                                            \
  while (false)                                                                \
    ;                                                                          \
  if (test_c != 0) {                                                           \
    if (test_success) {                                                        \
      green_terminal();                                                        \
      printf("test %u pass.\n", test_c);                                       \
    } else {                                                                   \
      red_terminal();                                                          \
      printf("test %u failed.\n", test_c);                                     \
    }                                                                          \
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
    red_termminal();                                                           \
    printf("%d\% of the results were correct.\n", pos_c / test_c)              \
  } else {                                                                     \
    green_terminal();                                                          \
    printf("100\% of the results were correct.\n")                             \
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
  default_terminal();                                                          \
                                                                               \
  test_name = #name;                                                           \
  test_desc = #description;                                                    \
                                                                               \
  test_num++;                                                                  \
  if (pre_execution) {                                                         \
    pre_execution();                                                           \
  }                                                                            \
  do {                                                                         \
  \