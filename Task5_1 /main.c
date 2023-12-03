﻿#define _CRT_SECURE_NO_WARNINGS
#include "my_stack.h"
#include "my_stack.c"
#include <stdio.h>
#include "Tests.h"

#define SUCCESS 0
#define STACK_NOT_EMPTY 1
#define STACK_EMPTY 2
#define DIVIDE_BY_ZERO 3
#define INVALID_CHARS 4

int calculate(const char* s, int* result) {
    Stack* st = create_stack();

    int status = SUCCESS;

    for (int i = 0; i < strlen(s); ++i)
    {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            int p = c - '0';
            push(st, &p);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (is_empty(st)) {
                status = STACK_EMPTY;
                break;
            }
            int* first = pop(st);
            if (is_empty(st)) {
                status = STACK_EMPTY;
                break;
            }
            int* second = pop(st);

            int result;
            if (c == '+') {
                result = *first + *second;
            }
            else if (c == '-') {
                result = *second - *first;
            }
            else if (c == '*') {
                result = *first * *second;
            }
            else {
                if (*first == 0) {
                    status = DIVIDE_BY_ZERO;
                    break;
                }
                result = *second / *first;
            }

            push(st, &result);
        }
        else if (c != ' ') {
            status = INVALID_CHARS;
        }
    }

    if (status == 0) {
        if (is_empty(st)) {
            status = STACK_EMPTY;
        }
        else {
            int* total = pop(st);

            if (!is_empty(st)) {
                status = STACK_NOT_EMPTY;
            }
            else {
                *result = *total;
            }
        }
    }

    free_stack(st);
    free(st);

    return status;
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    char s[100];
    printf("Input string: ");
    gets(s);

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
