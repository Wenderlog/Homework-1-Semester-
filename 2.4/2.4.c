#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int array[], int first, int last) {
    int pivot = array[first];
    int i = first + 1;
    for (int j = first + 1; j <= last; j++) {
        if (array[j] < pivot) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[first], &array[i - 1]);
    return i - 1;
}

int main() {
    int test1[] = { 15, 24, 33, 12, 11 };
    int first = test1[0];
    partition(test1, 0, 4);
    assert(test1[0] < first);
    assert(test1[4] > first);

    int lenArray = 12;
    int* array = (int*)malloc(lenArray * sizeof(int));
    srand(time(NULL));
    printf("Начальный массив:\n");
    for (int i = 0; i < lenArray; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");
    partition(array, 0, lenArray - 1);
    printf("Массив после преобразования:\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
   
    free(array);
    return 0;
}