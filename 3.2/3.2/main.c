#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool testBinarySearch(int array[], int lengthArray, int target) {
    for (int i = 0; i < lengthArray; i++) {
        if (array[i] == target) {
            return true;
        }
    }
    return false;
}

bool binarySearch(int array[], int lenArray, int count) {
    int left = 0;
    int right = lenArray - 1;
    while (left <= right) {
        int const mid = left + (right - left) / 2;
        if (array[mid] == count) {
            return true;
        }
        else if (array[mid] < count) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

void printArray(int array[], int lenghtArray) {
    printf("Исходный массив: ");
    for (int i = 0; i < lenghtArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int lenghtArray1 = sizeof(array1) / sizeof(array1[0]);
    int numbersToSearch[] = { 1, 5, 10, 0, 11 };
    printArray(array1, lenghtArray1);
    for (int i = 0; i < 5; i++) {
        printf("Test %d: Searching for %d - %s \n", i + 1, numbersToSearch[i]);
        printf(testBinarySearch(array1, lenghtArray1, numbersToSearch[i]) ? "Found\n" : "Not found\n");
    }

    int lenghtArray = 0;
    int numbersForSearch  = 0;
    printf("Введите размер массива \n");
    scanf_s("%d", &lenghtArray);
    printf("Введите кол-во чисел для поиска \n");
    scanf_s("%d", &numbersForSearch);
    int* array = (int*)malloc(lenghtArray * sizeof(int));
    for (int i = 0; i < lenghtArray; i++) {
        array[i] = rand() % 100;
    }
    qsort(array, lenghtArray, sizeof(int), compare);
    printArray(array, lenghtArray);
    int count = 0;
    for (int i = 0; i < numbersForSearch; i++) {
        int target = rand() % 100;
        if (binarySearch(array, lenghtArray, target)) {
            count++;
            printf("Число найдено %d \n" , target);
        }
        else
        {
            printf("Число %d не найдено \n" , target);
        }
    }
    printf("Найдено %d чисел из %d в массиве \n", count, numbersForSearch);
    free(array);
    return 0;
}
