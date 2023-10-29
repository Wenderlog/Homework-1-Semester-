#include <stdio.h>

int main(int argc, const char * argv[]) {
int lenArray = scanf("%d", &lenArray);
int array[lenArray] = { 0 };
int k = 0;
printf("введите значения элементов массива:\n");
for (int i = 0; i < lenArray; i++) {
scanf("%d", &array[i]);
if (array[i] == 0) {
k++;
}
}

printf("Кол-во нулевых в массиве: %d\n", k);

return 0;
}
