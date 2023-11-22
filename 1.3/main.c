#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Введите а: ");
    int a = 0;
    scanf("%d", &a);
    printf("Введите b: ");
    int b = 0;
    scanf("%d", &b);
    int result = 0;
    int moduleA = abs(a);
    int moduleB = abs(b);
    if (b == 0) {
        printf("Деление на 0");
    }
    else {
        while ((moduleA - result * moduleB >= moduleB) || (a < 0 && moduleA > result * moduleB)) {
            result++;
        }
        if ((a > 0) ^ (b > 0)) {
            result = -result;
        }

        printf("Неполное частное : %d \n", result);
    }
    return 0;
}
