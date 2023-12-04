#include <stdio.h>

int main() {
    int sums1[28] = { 0 }; 
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                sums1[i + j + k]++;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 1000; i++) {
        count += sums1[i] * sums1[i];
    }
    printf("Число счастливых билетов: %d\n", count);
    return 0;
}