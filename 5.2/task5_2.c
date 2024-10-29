#include "task5_2.h"
#include "my_stack.h"

bool check_brackets(const char* s) {
    Stack* st = create_stack();
    bool check = true;

    for (int i = 0; i < strlen(s); ++i)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(st, &c, sizeof(char));
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (is_empty(st)) {
                check = false;
                break;
            }
            char* p = pop(st);
            char open_bracket = *p;
            if (c == ')' && open_bracket != '(' || c == ']' && open_bracket != '[' || c == '}' && open_bracket != '{') {
                check = false;
                break;
            }
        }
    }
    if (!check) {
        free_stack(st);
        free(st);
        return false;
    }

    check = is_empty(st);
    free_stack(st);
    free(st);
    return check;
}