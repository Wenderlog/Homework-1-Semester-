#include <stdio.h>
#include <stdbool.h>

#define STATE_START 0
#define STATE_SLASH 1
#define STATE_STAR 2
#define STATE_COMMENT 3
#define STATE_INNER_COMMENT 4

int main() {
    FILE* file = fopen("12.2.cpp", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int state = STATE_START;
    char c;
    char prev_c = ' ';

    while ((c = fgetc(file)) != EOF) {
        switch (state) {
            case STATE_START:
                if (c == '/') {
                    state = STATE_SLASH;
                }
                break;

            case STATE_SLASH:
                if (c == '*') {
                    state = STATE_COMMENT;
                    putchar('/');
                    putchar('*');
                } else {
                    state = STATE_START;
                }
                break;

            case STATE_COMMENT:
                putchar(c);
                if (c == '*') {
                    state = STATE_STAR;
                }
                break;

            case STATE_STAR:
                putchar(c);
                if (c == '/') {
                    putchar('\n');
                    state = STATE_START;
                } else if (c == '*') {
                    state = STATE_INNER_COMMENT;
                } else {
                    state = STATE_COMMENT;
                }
                break;

            case STATE_INNER_COMMENT:
                putchar(c);
                if (c == '/') {
                    state = STATE_STAR;
                } else if (c != '*') {
                    state = STATE_COMMENT;
                }
                break;
        }
        prev_c = c;
    }

    fclose(file);

    return 0;
}
