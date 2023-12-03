#include "my_stack.h"
#include "tests_2.h"

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
    };

    if (check_brackets(s)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}
