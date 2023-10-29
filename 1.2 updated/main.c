#include <stdio.h>

int main() {
    int lenArray = 0;
    scanf("%d", &lenArray);
    int array[lenArray];
    for (int i = 0; i < lenArray; i++) {
        array[i] = 0;
    }
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
