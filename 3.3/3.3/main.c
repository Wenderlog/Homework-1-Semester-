#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void myQuickSort(int array[], int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = array[low];
    int left = low + 1;
    int right = high;
    while (true) {
        while (left <= right && array[left] <= pivot)
            left++;
        while (array[right] >= pivot && right >= left)
            right--;
        if (right < left) {
            break;
        }
    }
    int temp = array[low];
    array[low] = array[right];
    array[right] = temp;
    myQuickSort(array, low, right - 1);
    myQuickSort(array, right + 1, high);
    }


int findMostFrequentElement(int array[], int lengthArray) {
    if (lengthArray == 0) {
        return -1;
    }
    myQuickSort(array, 0, lengthArray - 1);
    int maxCount = 1;
    int currentCount = 1;
    int mostFrequentElement = array[0];
    int currentElement = array[0];
    for (int i = 1; i < lengthArray; i++) {
        if (array[i] == array[i - 1]) {
            currentCount++;
        }
        else if (currentCount > maxCount) {
            maxCount = currentCount;
            mostFrequentElement = currentElement;
        }
        currentCount = 1;
        currentElement = array[i];
    }
    if (currentCount > maxCount) {
        mostFrequentElement = currentElement;
    }
    return mostFrequentElement;
}

bool testFindMostFrequentElement(int array[], int lengthArray, int expected) {
    int result = findMostFrequentElement(array, lengthArray);
    if (result == expected) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
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
        return 0;
    }

    int lengthArray = 0;
    printf("Введите размер массива: \n");
    scanf_s("%d", &lengthArray);
    int* array = (int*)malloc(lengthArray * sizeof(int));
    printf("Введите элементы массива: \n");
    for (int i = 0; i < lengthArray; i++) {
        scanf_s("%d", &array[i]);
    }
    int mostFrequentElement = findMostFrequentElement(array, lengthArray);
    printf("Наиболее встречающийся элемент в массиве - %d \n", mostFrequentElement);
    free(array);

    return 0;
}
