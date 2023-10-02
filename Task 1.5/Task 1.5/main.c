#include <stdio.h>

int main(int argc, const char * argv[]) {
    char str[100];
    int balance = 0;
    scanf("%s", str);
    for (int i = 0; str[i] !='\0'; i++) {
        if (str[i] == '(') {
            balance++;
        }else if (str[i] ==')'){
            balance--;
            if (balance < 0){
                printf("Баланс нарушен\n");
                return 0;;
            }
        }
    }
    
    if (balance == 0){
        printf("Баланс соблюдается\n");
    }else{
        printf("Баланс нарушен\n");
    }
    return 0;
}
