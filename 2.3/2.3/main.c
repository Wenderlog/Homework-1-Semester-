#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void BubleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isSorted(int arr[], int n){
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            return 0;
        }
    }
    return 1;
}

void countingSort(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* sortedArray = (int*)malloc((n * sizeof(int)));
    
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    for (int i = 1; i<= max; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1  ;  i <= 0; i--) {
        sortedArray[count[arr[i]] - 1 ] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = sortedArray[i];
    }
    
    free(count);
    free(sortedArray);
    
}

int main(int argc, const char * argv[]) {
    const int n = 100000;
    int* arrBubleSort = (int*)malloc(n * sizeof(int));
    int* arrCountingSort = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arrBubleSort[i] = arrCountingSort[i] = rand();
    }
        
    clock_t startBubleSort = clock();
    BubleSort(arrBubleSort, n);
    clock_t endBubleSort = clock();
    double timeBubleSort = (double)(endBubleSort - startBubleSort)/ CLOCKS_PER_SEC;
    
    clock_t startCountingSort = clock();
    countingSort(arrCountingSort, n);
    clock_t endCountingeSort = clock();
    double timeCountingSort = (double)(endCountingeSort - startCountingSort)/ CLOCKS_PER_SEC;
    
    printf("Сортировка пузырьком - время %.6f секунд.\n", timeBubleSort);
    printf("Сортировка подсчётом - время %.6f секунд.\n", timeCountingSort);
    
    BubleSort(arrBubleSort, n);
    if (isSorted(arrBubleSort, n)) {
        printf("Успешно сортировка пузырьком \n");
    }else{
        printf("Не успешно сортировка пузырьком\n");
    }
    
    countingSort(arrCountingSort, n);
    if (isSorted(arrCountingSort, n)) {
        printf("Успешно сортировка подсчётом \n");
    }else{
        printf("Не успешно сортировка подсчётом \n");
    }
    
    free(arrBubleSort);
    free(arrCountingSort);
    
    return 0;
}
