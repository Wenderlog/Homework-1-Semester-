#include "my_stack.h"

#include "tests_3.h"

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

    int status;
    char* result = convert_postfix(s, &status);

    if (status == 1) {
        printf("%s", result);
        free(result);
    }
    else {
        printf("Incorrect string");
    }

    return 0;
}