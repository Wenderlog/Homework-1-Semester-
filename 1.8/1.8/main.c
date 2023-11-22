#include <stdio.h>

void reverseArray(int array[], int left, int right) {
    while (left < right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;
        left++;
        right--;
    }
}

void swapFirstAndLastArray(int array[], int m, int n) {
    reverseArray(array, 0, m - 1);
    reverseArray(array, m, m + n - 1);
    reverseArray(array, 0, m + n - 1);
}


int main() {
    int m = 5;
    int n = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int i = 0; i < m + n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    swapFirstAndLastArray(array, m, n);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
