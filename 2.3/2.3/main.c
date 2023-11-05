#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void BubleSort(int array[], int lenArray) {
    for (int i = 0; i < lenArray - 1; i++) {
        for (int j = 0; j < lenArray - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int isSorted(int array[], int lenArray) {
    for (int i = 0; i < lenArray; i++) {
        if (array[i] < array[i-1]) {
            return 0;
        }
    }
    return 1;
}

void countingSort(int array[], int lenArray){
    int max = array[0];
    for (int i = 1; i < lenArray; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* sortedArray = (int*)malloc((lenArray * sizeof(int)));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < lenArray; i++) {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = lenArray - 1; i <= 0; i--) {
        sortedArray[count[array[i]] - 1 ] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < lenArray; i++) {
        array[i] = sortedArray[i];
    }
    free(count);
    free(sortedArray);
}

int main() {
    const int lenArray = 100000;
    int* arrayBubleSort = (int*)malloc(lenArray * sizeof(int));
    int* arrayCountingSort = (int*)malloc(lenArray * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < lenArray; i++) {
        arrayBubleSort[i] = arrayCountingSort[i] = rand();
    }
    clock_t startBubleSort = clock();
    BubleSort(arrayBubleSort, lenArray);
    clock_t endBubleSort = clock();
    double timeBubleSort = (double)(endBubleSort - startBubleSort) / CLOCKS_PER_SEC;
    clock_t startCountingSort = clock();
    countingSort(arrayCountingSort, lenArray);
    clock_t endCountingeSort = clock();
    double timeCountingSort = (double)(endCountingeSort - startCountingSort)/ CLOCKS_PER_SEC;
    printf("Сортировка пузырьком - время %.6f секунд.\n", timeBubleSort);
    printf("Сортировка подсчётом - время %.6f секунд.\n", timeCountingSort);
    BubleSort(arrayBubleSort, lenArray);
    if (isSorted(arrayBubleSort, lenArray)) {
        printf("Успешно сортировка пузырьком \n");
    }
    else
    {
        printf("Не успешно сортировка пузырьком\n");
    }
    countingSort(arrayCountingSort, lenArray);
    if (isSorted(arrayCountingSort, lenArray)) {
        printf("Успешно сортировка подсчётом \n");
    }
    else
    {
        printf("Не успешно сортировка подсчётом \n");
    }
    free(arrayBubleSort);
    free(arrayCountingSort);
    return 0;
}
