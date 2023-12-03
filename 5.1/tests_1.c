#include "tests_1.h"

void test1() {
    printf("Test 1 2 + : ");
    int result;
    int status = calculate("1 2 +", &result);

    if (status == SUCCESS && result == 3) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test2() {
    printf("Test 9 6 - 1 2 + * : ");
    int result;
    int status = calculate("9 6 - 1 2 + *", &result);

    if (status == SUCCESS && result == 9) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test3() {
    printf("Test 3 + : ");
    int result;
    int status = calculate("2 +", &result);

    if (status == STACK_EMPTY) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test4() {
    printf("Test 3 4 5 + : ");
    int result;
    int status = calculate("3 4 5 +", &result);

    if (status == STACK_NOT_EMPTY) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}