#include <stdbool.h>
#include "stdio.h"

bool isSorted(int array[], int n) {
    for (int i = 1; i < n; ++i) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

void swap(int* a, int* b) {
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
    if (low >= high) {
        return;
    }
    if (high - low + 1 < 10) {
        insertionSort(array, low, high);
        return;
    }
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

void myQSort(int array[], int n) {
    qsortCustom(array, 0, n - 1);
}

int main() {
    int test1[] = { 4, 2, 1, 3, 5, 6, 7, 8, 6, 12, 3, 5 };
    int lenghtTest1 = sizeof(test1) / sizeof(test1[0]);
    myQSort(test1, lenghtTest1);
    printf("Test 1 %s\n", isSorted(test1, lenghtTest1) ? "Passed" : "Failed");

    int test2[] = { 5, 4, 3, 2, 1 };
    int lenghtTest2 = sizeof(test2) / sizeof(test2[0]);
    myQSort(test2, lenghtTest2);
    printf("Test 1 %s\n", isSorted(test2, lenghtTest2) ? "Passed" : "Failed");

    int test3[] = { 1, 2, 3, 4, 5 };
    int lenghtTest3 = sizeof(test3) / sizeof(test3[0]);
    myQSort(test3, lenghtTest3);
    printf("Test 1 %s\n", isSorted(test3, lenghtTest3) ? "Passed" : "Failed");

    int test4[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    int lenghtTest4 = sizeof(test4) / sizeof(test4[0]);
    myQSort(test4, lenghtTest4);
    printf("Test 1 %s\n", isSorted(test4, lenghtTest4) ? "Passed" : "Failed");
}
