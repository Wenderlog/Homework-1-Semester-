#include <stdio.h>
#include <stdbool.h>

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isRealNumber(const char* str) {
    enum State {START, AFTER_DIGIT, AFTER_POINT, AFTER_EXPONENT, AFTER_EXP_SIGN, AFTER_EXP_DIGIT};
    
    enum State currentState = START;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        switch (currentState) {
            case START:
                if (isDigit(c)) {
                    currentState = AFTER_DIGIT;
                } else {
                    return false;
                }
                break;
            case AFTER_DIGIT:
                if (isDigit(c)) {
                    
                } else if (c == '.') {
                    currentState = AFTER_POINT;
                } else if (c == 'E' || c == 'e') {
                    currentState = AFTER_EXPONENT;
                } else {
                    return false;
                }
                break;
                
            case AFTER_EXPONENT:
                if (c == '+' || c == '-') {
                    currentState = AFTER_EXP_SIGN;
                } else if (isDigit(c)) {
                    currentState = AFTER_EXP_DIGIT;
                } else {
                    return false;
                }
                break;
                
            case AFTER_POINT:
                if (isDigit(c)) {
                } else if (c == 'E' || c == 'e') {
                    currentState = AFTER_EXPONENT;
                } else {
                    return false;
                }
                break;
                
            case AFTER_EXP_SIGN:
                if (isDigit(c)) {
                    currentState = AFTER_EXP_DIGIT;
                } else {
                    return false;
                }
                break;
                
            case AFTER_EXP_DIGIT:
                if (isDigit(c)) {
                    
                } else {
                    return false;
                }
                break;
        }
    }
    return (currentState == AFTER_DIGIT, currentState == AFTER_POINT, currentState == AFTER_EXP_DIGIT);
}

int main(int argc, const char * argv[]) {
    char input[100];
    printf("Введите строку: ");
    scanf("%s", input);
    
    if (isRealNumber(input)) {
        printf("Введенная строка является вещественным числом. \n");
    } else {
        printf("Введенная строка не является вещественным числом. \n");
    }

    return 0;
}
