#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int findMostElement(int array[], int n){
    if (n == 0) {
        return -1;
    }
    qsort(array, n, sizeof(int), compare);//O(nlogn)
    
    int maxCount = 1;
    int currentCount = 1;
    
    int mostElement = array[0];
    int currentElement = array[0];
    
    for (int i = 1; i < n; i++) {// O(n) -> max(O(nlogn),O(n)) = O(nlogn)
        if (array[i] == array[i - 1]) {
            currentCount++;
        }else if (currentCount > maxCount){
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

int main(int argc, const char * argv[]) {
    int n;
    printf("Введите размер массива \n");
    scanf("%d",&n);
    
    int *array = (int*)malloc(n * sizeof(int));
    
    printf("введите элементы массива \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    int mostElement = findMostElement(array, n);
    
    if (mostElement == -1) {
        printf("В массиве нет элементов \n");
    }else{
        printf("Наиболее встречающийся элемент в массиве - %d \n", mostElement);
    }
    
    free(array);

    return 0;
}
