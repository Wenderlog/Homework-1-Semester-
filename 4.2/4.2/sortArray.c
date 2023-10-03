#include <stdio.h>
#include <stdlib.h>

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
            if (right < left)
                break;
            else {
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
