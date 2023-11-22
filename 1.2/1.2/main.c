#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 0 };
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (array[i] == 0) {
            count++;
        }
    }
    printf("Кол-во нулевых в массиве: %d\n", count);
    return 0;
}
