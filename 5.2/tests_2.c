#include "tests_2.h"
#include "task5_2.h"

void test1() {
    printf("Test correct brackets ([]{[]}) - ");
    if (check_brackets("([]{[]})")) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test2() {
    printf("Test incorrect brackets ([])) - ");
    if (!check_brackets("([]))")) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test3() {
    printf("Test incorrect brackets (([]) - ");
    if (!check_brackets("(([])")) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test4() {
    printf("Test incorrect brackets (([])] - ");
    if (!check_brackets("(([])]")) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}