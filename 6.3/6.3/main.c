#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char name[100];
    char phoneNumber[20];
};

int compareByName(const void* a, const void* b) {
    return strcmp(((struct Record*)a)->name, ((struct Record*)b)->name);
}

int compareByPhoneNumber(const void* a, const void* b) {
    return strcmp(((struct Record*)a)->phoneNumber, ((struct Record*)b)->phoneNumber);
}

void bubbleSort(struct Record* array, int len, int (*cmp)(const void*, const void*)) {
    int swapped = 0;
    struct Record temp;

    do {
        swapped = 0;
        for (int i = 0; i < len - 1; i++) {
            if (cmp(&array[i], &array[i + 1]) > 0) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    FILE* inputFile = fopen("6.3.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Не удалось открыть файл.\n");
        return 1;
    }

    int maxSize = 1000;
    struct Record* records = (struct Record*)malloc(sizeof(struct Record) * maxSize);
    int count = 0;

    while (fscanf(inputFile, "%99[^—] — %19[^\n]\n", records[count].name, records[count].phoneNumber) != EOF) {
        count++;
    }

    fclose(inputFile);

    int choice = 0;
    printf("Выберите способ сортировки (1 - по имени, 2 - по номеру телефона): ");
    scanf("%d", &choice);

    int (*compareFunction)(const void*, const void*);
    if (choice == 1) {
        compareFunction = compareByName;
    } else if (choice == 2) {
        compareFunction = compareByPhoneNumber;
    } else {
        fprintf(stderr, "Некорректный выбор сортировки.\n");
        return 1;
    }

    bubbleSort(records, count, compareFunction);

    for (int i = 0; i < count; i++) {
        printf("%s — %s\n", records[i].name, records[i].phoneNumber);
    }
    free(records);
    return 0;
}
