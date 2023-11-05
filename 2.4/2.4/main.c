#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void swap(int *a, int *b) {
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

void transformathionArray(int array[], int first, int last ) {
    if (first < last) {
        int indexOfPivot = partition(array, first, last);
        transformathionArray(array, first, indexOfPivot - 1);
        transformathionArray(array, indexOfPivot + 1, last);
    }
}

int main() {
    int lenArray = 12;
    int *array = (int*)malloc(lenArray * sizeof(int));
    srand(time(NULL));
    printf("Начальный массив:\n");
    for (int i = 0; i < lenArray; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");
    transformathionArray(array, 0, lenArray - 1);
    printf("Массив после преобразования:\n");
    for (int i = 0; i < lenArray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    int test1[] = {5, 4, 3, 2, 1};
    int test2[] = {1, 2, 3, 4, 5};
    transformathionArray(test1, 0, 4);
    transformathionArray(test2, 0, 4);
    for (int i = 0; i < 5; i++) {
        assert(test1[i] == i + 1);
        assert(test2[i] == i + 1);
    }
    free(array);
    return 0;
}
