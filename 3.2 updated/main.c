#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binatySearch(int array[], int lenArray, int count) {
    int left = 0;
    int right = lenArray - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if (array[mid] == count) {
            return 1;
        } else if (array[mid] < count) {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int lenArray;
    int countk;
    printf("Введите размер массива \n");
    scanf("%d", &lenArray);
    printf("Введите кол-во чисел для поиска \n");
    scanf("%d", &countk);
    int *array = (int*)malloc(lenArray * sizeof(int));
    for (int i = 0; i < lenArray; i++) {
        array[i] = rand() % 100;
    }
    qsort(array, lenArray, sizeof(int), compare);
    int count = 0;
    for (int i = 0; i < countk; i++) {
        int target = rand() % 100;
        if (binatySearch(array, lenArray, target)) {
            count++;
            // printf("Число найдено %d \n" , target); если надо посмотреть какие числа были найдены
        }
        else
        {
            // printf("Число %d не найдено \n" , target);
        }
    }
    printf("Найдено %d чисел из %d в массиве \n", count, countk);
    free(array);
    return 0;
}
