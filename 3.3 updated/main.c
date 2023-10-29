#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void myQuickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = array[low];
        int left = low + 1;
        int right = high;
        while (1) {
            while (left <= right && array[left] <= pivot)
                left++;
            while (array[right] >= pivot && right >= left)
                right--;
            if (right < left) {
                break;
            }
            else
            {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
        int temp = array[low];
        array[low] = array[right];
        array[right] = temp;
        myQuickSort(array, low, right - 1);
        myQuickSort(array, right + 1, high);
    }
}

int findMostElement(int array[], int lenArray) {
    if (lenArray == 0) {
        return -1;
    }
    myQuickSort(array, 0, lenArray - 1);
    int maxCount = 1;
    int currentCount = 1;
    int mostElement = array[0];
    int currentElement = array[0];
    for (int i = 1; i < lenArray; i++) {
        if (array[i] == array[i - 1]) {
            currentCount++;
        } else if (currentCount > maxCount) {
            maxCount = currentCount;
            mostElement = currentElement;
        }
        currentCount = 1;
        currentElement = array[i];
    }
    if (currentCount > maxCount) {
        mostElement = currentElement;
    }
    return mostElement;
}

int main() {
    int lenArray = 0;
    printf("Введите размер массива: \n");
    scanf("%d", &lenArray);
    int *array = (int *)malloc(lenArray * sizeof(int));
    printf("Введите элементы массива: \n");
    for (int i = 0; i < lenArray; i++) {
        scanf("%d", &array[i]);
    }
    int mostElement = findMostElement(array, lenArray);
    if (mostElement == -1) {
        printf("В массиве нет элементов \n");
    }
    else
    {
        printf("Наиболее встречающийся элемент в массиве - %d \n", mostElement);
    }
    free(array);
    return 0;
}
