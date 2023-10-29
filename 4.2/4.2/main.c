#include <stdio.h>
#include <stdlib.h>
#include "sortArray.h"

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
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mostElement = currentElement;
            }
            currentCount = 1;
            currentElement = array[i];
        }
    }
    
    if (currentCount > maxCount) {
        mostElement = currentElement;
    }
    
    return mostElement;
}

int main(int argc, const char *argv[]) {
    FILE *file = fopen("4.2.txt", "r");
        if (file == NULL) {
            perror("Failed to open the file");
            return 1;
        }

    int len = 0;
    fscanf(file, "%d", &len);
    
    int *array = (int *)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);

    int mostElement = findMostElement(array, len);

    if (mostElement == -1) {
        printf("В массиве нет элементов\n");
    } else {
        printf("Наиболее встречающийся элемент в массиве - %d\n", mostElement);
    }
    free(array);
    return 0;
}
