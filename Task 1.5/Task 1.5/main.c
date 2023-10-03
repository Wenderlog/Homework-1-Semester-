#include <stdio.h>

int main(int argc, const char * argv[]) {
char string[100];
int balance = 0;
scanf("%s", string);
for (int i = 0; string[i] != '\0'; i++) {
if (string[i] == '(') {
balance++;
} else if (string[i] == ')') {
balance--;
if (balance < 0) {
printf("Баланс нарушен \n");
return 0;
}
}
}

if (balance == 0) {
printf("Баланс соблюдается\n");
} else {
printf("Баланс нарушен\n");
}
return 0;
}
