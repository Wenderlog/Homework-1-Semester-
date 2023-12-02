#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void myQuickSort(int array[], int low, int high) {
    int i = low;
    int j = high;

    int pivot = array[(low + (high - low) / 2)];
    do {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            if (j > 0) {
                j--;
            }
        }
    } while (i <= j);

    if (i < high) {
        myQuickSort(array, i, high);
    }
    if (j > low) {
        myQuickSort(array, low, j);
    }
}

const int findMostFrequentElement(int array[], int lengthArray) {
    if (lengthArray == 0) {
        return -1;
    }
    myQuickSort(array, 0, lengthArray - 1);
    int maxCount = 1;
    int currentCount = 1;
    int mostFrequentElement = array[0];
    for (int i = 1; i < lengthArray; i++) {
        if (array[i] == array[i - 1]) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mostFrequentElement = array[i];
            }
        }
        else {
            currentCount = 1;
        }
    }

    return mostFrequentElement;
}

bool testFindMostFrequentElement(int array[], int lengthArray, int expected) {
    int result = findMostFrequentElement(array, lengthArray);
    return result == expected;
}

int main() {
    setlocale(LC_ALL, "rus");

    int testArray1[] = { 5 };
    int testArray2[] = { 2, 2, 2, 2 };
    int testArray3[] = { 10, 20, 10, 30, 20 };
    if ((testFindMostFrequentElement(testArray1, 1, 5)) &&
        (testFindMostFrequentElement(testArray2, 4, 2)) &&
        (testFindMostFrequentElement(testArray3, 5, 10))) {
        printf("Тесты прошли\n");
    }
    else {
        printf("Тесты не прошли\n");
        return 1;
    }

    int lengthArray = 0;
    printf("Введите размер массива: \n");
    scanf("%d", &lengthArray);
    int* array = (int*)malloc(lengthArray * sizeof(int));
    printf("Введите элементы массива: \n");
    for (int i = 0; i < lengthArray; i++) {
        scanf("%d", &array[i]);
    }
    const int mostFrequentElement = findMostFrequentElement(array, lengthArray);
    printf("Наиболее встречающийся элемент в массиве - %d \n", mostFrequentElement);
    free(array);

    return 0;
}
