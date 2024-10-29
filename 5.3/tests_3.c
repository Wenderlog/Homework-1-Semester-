#include "tests_3.h"
#include "task5_3.h"

void test1() {
    printf("Test correct expression 2 + 3 * 5 - ");
    int status;
    char* result = convert_postfix("2 + 3 * 5", &status);
    if (status == 1 && strcmp("2 3 5 * +", result) == 0) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
    free(result);
}

void test2() {
    printf("Test correct expression (2 + 3) * 5 - ");
    int status;
    char* result = convert_postfix("(2 + 3) * 5", &status);
    if (status == 1 && strcmp("2 3 + 5 *", result) == 0) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
    free(result);
}

void test3() {
    printf("Test incorrect expression (2 + 3 * 5 - ");
    int status;
    char* result = convert_postfix("(2 + 3 * 5", &status);
    if (status == 0 && result == NULL) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
    free(result);
}

void test4() {
    printf("Test incorrect expression (2 + 3 * 5)) - ");
    int status;
    char* result = convert_postfix("(2 + 3 * 5))", &status);
    if (status == 0 && result == NULL) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
    free(result);
}