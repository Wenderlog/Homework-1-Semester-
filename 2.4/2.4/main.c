#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int first, int last){
    int pivot = arr[first];
    int i = first + 1;
    
    for (int j = first + 1; j <= last; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[first], &arr[i - 1]);
    return i - 1;
}

void transformathionArray(int arr[], int first, int last ){
    if (first < last) {
        int indexOfPivot = partition(arr, first, last);
        transformathionArray(arr, first, indexOfPivot - 1);
        transformathionArray(arr, indexOfPivot + 1, last);
    }
}

int main(int argc, const char * argv[]) {
    int n = 12;
    int *arr = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    
    printf("Начальный массив:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    transformathionArray(arr, 0, n - 1);
    
    printf("Массив после преобразования:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
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

    free(arr);
    
    return 0;
}
