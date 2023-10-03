#include <stdbool.h>
#include <stdio.h>

bool isPrime(int num){
if (num < 1) {
return false;
}
for (int i = 2; i * i <= num; i++) {
if (num % i == 0) {
return false;
}
}
return true;
}

int main(int argc, const char * argv[]) {
int number;
scanf("%d", &number);
printf("Простые числа до %d \n", number);
printf("1");
for (int i = 2; i <= number; i++) {
if (isPrime(i)) {
printf("%d ", i);
}
}
printf("\n");

return 0;
}
