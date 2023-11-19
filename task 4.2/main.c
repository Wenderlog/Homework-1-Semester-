#include <stdio.h>
#include "sort.h"

#define PATH_MAX 4096

int findMostCommonNumber(size_t len, int *array)
{
    int mostCommonNumber = 0;
    size_t maxCount = 0;
    size_t currentNumberCount = 1;
    int currentNumber = array[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (array[i] == currentNumber)
        {
            ++currentNumberCount;
        }
        else
        {
            if (currentNumberCount > maxCount)
            {
                mostCommonNumber = currentNumber;
                maxCount = currentNumberCount;
            }
            currentNumberCount = 1;
            currentNumber = array[i];
        }
    }

    if (currentNumberCount > maxCount)
    {
        return currentNumber;
    }
    return mostCommonNumber;
}

int main()
{
    char filepath[PATH_MAX] = {'\0'};

    printf("Введите путь к файлу", PATH_MAX);
    scanf("%s", filepath);
    if (filepath[PATH_MAX - 1] != '\0')
    {
        printf("Указанный путь к файлу слишком длинный\n");
        return -3;
    }
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("Не удается открыть файл по заданному пути\n");
        return -4;
    }

    size_t arrSize = 0;
    int scanResult = fscanf(file, "%lu", &arrSize);
    if (scanResult == 0 || arrSize == 0)
    {
        printf("Данный файл содержит неверные данные\n");
        fclose(file);
        return -2;
    }

    int *array = calloc(arrSize, sizeof(int));
    if (array == NULL)
    {
        printf("Ошибка выделения памяти для массива\n");
        fclose(file);
        return -1;
    }
    for (size_t i = 0; i < arrSize; ++i)
    {
        scanResult = fscanf(file, "%d", &array[i]);
        if (scanResult == 0)
        {
            printf("Данный файл содержит неверные данные\n");
            fclose(file);
            free(array);
            return -2;
        }
    }
    fclose(file);

    sort(arrSize, array);

    printf("Наиболее распространенное значение в массиве: %d\n", findMostCommonNumber(arrSize, array));
    free(array);
    return 0;
}