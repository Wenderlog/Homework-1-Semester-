#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int binatySearch(int array[], int n, int k){
    int left = 0;
    int right = n - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if (array[mid] == k) {
            return 1;
        }else if (array[mid] < k){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int n, k;
    printf("Введите размер массива \n");
    scanf("%d", &n);
    printf("Введите кол-во чисел для поиска \n");
    scanf("%d", &k);
    
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    
    qsort(array, n, sizeof(int), compare);
    int count = 0;
    for (int i = 0; i < k; i++) {
        int target = rand() % 100;
        if (binatySearch(array, n, target)) {
            count++;
//            printf("Число найдено %d \n" , target); если надо посмотреть какие числа были найдены
        }else{
//            printf("Число %d не найдено \n" , target);
        }
    }
    
    printf("Найдено %d чисел из %d  в массиве \n", count,k);
    
    free(array);
    return 0;
}
