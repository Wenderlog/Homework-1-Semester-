#include <stdio.h>

int main() {
int sumCount[28] = {0};
int count = 0;

for (int i = 100; i <= 999; i++) {
int num = i;
int sum = 0;

while (num > 0) {
sum += num % 10;
num /= 10;
}
sumCount[sum]++;
}

for (int i = 0; i < 28; i++) {
count += sumCount[i] * sumCount[i];
}
printf("Кол-во счасливых билетов: %d \n", count);
return 0;
}
