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
    scanf("%s", s);

    if (check_brackets(s)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}