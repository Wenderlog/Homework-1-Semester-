#include <stdio.h>

int main() {
    int sums1[1000] = { 0 }; // В условии не сказанно что билет не может начинаться с 0 поэтому сумма всех возможных трёх чисел равно 10 * 10 * 10
    int sums2[1000] = { 0 };

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                sums1[i + j + k]++;
                sums2[i + j + k]++;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 1000; i++) {
        count += sums1[i] * sums2[i];
    }
    printf("Число счастливых билетов: %d\n", count);
    return 0;
}
