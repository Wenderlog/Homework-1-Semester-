#include "task5_3.h"
#include "my_stack.h"


bool check_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char c) {
    switch (c)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 100;
    }
}

char* convert_postfix(const char* s, int* status) {
    char res[100];
    int ind = 0;
    *status = 1;

    Stack* st = create_stack();
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') {
            res[ind] = s[i];
            res[ind + 1] = ' ';
            ind += 2;
        }
        else if (s[i] == '(') {
            push(st, &s[i], sizeof(char));
        }
        else if (s[i] == ')') {
            while (true)
            {
                if (is_empty(st)) {
                    *status = 0;
                    free_stack(st);
                    free(st);
                    return NULL;
                }
                char* t = pop(st);
                char v = *t;
                if (v == '(')
                    break;
                else {
                    res[ind] = v;
                    res[ind + 1] = ' ';
                    ind += 2;
                }
            }
        }
        else if (check_operator(s[i])) {
            if (is_empty(st)) {
                push(st, &s[i], sizeof(char));
            }
            else {
                while (!is_empty(st))
                {
                    char* t = peek(st);
                    char v = *t;
                    if (priority(s[i]) < priority(v)) {
                        res[ind] = v;
                        res[ind + 1] = ' ';
                        ind += 2;
                        pop(st);
                    }
                    else {
                        break;
                    }
                }
                push(st, &s[i], sizeof(char));
            }
        }
    }

    while (!is_empty(st))
    {
        char* t = pop(st);
        if (*t == '(') {
            *status = 0;
            free_stack(st);
            free(st);
            return NULL;
        }
        res[ind] = *t;
        res[ind + 1] = ' ';
        ind += 2;
    }
    res[ind-1] = '\0';

    free_stack(st);
    free(st);

    char* result = (char*)malloc(sizeof(char) * (ind + 1));
    strcpy(result, res);
    return result;
}