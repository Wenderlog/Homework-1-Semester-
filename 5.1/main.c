#include "my_stack.h"
#include "tests_1.h"
#include "task5_1.h"

#include <stdio.h>

int main()
{
    test1();
    test2();
    test3();
    test4();

    char s[100];
    printf("Input string: ");
    int scanf_result = scanf("%s", s);
    if(scanf_result <= 0) {
         printf("Incorrect input value");
         return 1;
    }
    int result;
    int status = calculate(s, &result);
    if (status == SUCCESS) {
        printf("Result = %d", result);
    }
    else {
        printf("Incorrect input");
    }
    return 0;
}
