#include "Tests.h"
#include "loopList.h"

void test1() {
    printf("Test 1 (n = 5, m = 2) - ");

    const int expected = 3;
    int n = 5;
    int m = 2;

    int res = findAlive(n, m);
    if (res != expected) {
        printf("Failed, result = %d\n", res);
    } else {
        printf("OK\n");
    }
}

void test2() {
    printf("Test 2 (n = 5, m = 1) - ");

    const int expected = 5;
    int n = 5;
    int m = 1;

    int res = findAlive(n, m);
    if (res != expected) {
        printf("Failed, result = %d\n", res);
    } else {
        printf("OK\n");
    }
}

