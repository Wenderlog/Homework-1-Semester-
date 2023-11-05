#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int array[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void qsortCustom(int array[], int low, int high) {
    if (low < high) {
        if (high - low + 1 < 10) {
            printf("Используется сортировка вставками \n");
            insertionSort(array, low, high);
        }
        else
        {
            printf("Используется Быстрая сортировка \n");
            int pivot = array[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (array[j] < pivot) {
                    i++;
                    swap(&array[i], &array[j]);
                }
            }
            swap(&array[i + 1], &array[high]);
            int pivotIndex = i + 1;
            qsortCustom(array, low, pivotIndex - 1);
            qsortCustom(array, pivotIndex, high);
        }
    }
}

void myQSort(int array[], int n){
    qsortCustom(array, 0, n - 1);
}

int main() {
    int array[] = {4, 2, 1, 3, 5, 6, 7, 8, 6, 12, 3, 5};
    int lenArray = sizeof(array) / sizeof(array[0]);
    myQSort(array, lenArray);
    printf("\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
