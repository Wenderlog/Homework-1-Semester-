#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "myList.h"

struct Record {
    char name[100];
    char phoneNumber[20];
};

typedef struct Record Record;

int compareByName(const void* a, const void* b) {
    return strcmp(((Record*)a)->name, ((Record*)b)->name);
}

int compareByPhoneNumber(const void* a, const void* b) {
    return strcmp(((Record*)a)->phoneNumber, ((Record*)b)->phoneNumber);
}

void showList(MyList* list) {
    Node* p = next(list);
    while (p != NULL)
    {
        printf("%s - %s\n", ((Record*)p->data)->name, ((Record*)p->data)->phoneNumber);
        p = next(list);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "rus");

    FILE* inputFile = fopen("6.3.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Не удалось открыть файл.\n");
        return 1;
    }

    MyList* list = createList();

    char name[100];
    char phoneNumber[20];

    while (!feof(inputFile)) {
        fscanf(inputFile, "%[^-]s", name);
        fscanf(inputFile, "-%*c");
        fscanf(inputFile, "%[^\n]s", phoneNumber);
        fgetc(inputFile);

        Record* rec = (Record*)malloc(sizeof(Record));
        strcpy(rec->name, name);
        strcpy(rec->phoneNumber, phoneNumber);
        addElement(list, rec);
    }
    fclose(inputFile);

    showList(list);
    
    int choice = 0;
    printf("Выберите способ сортировки (1 - по имени, 2 - по номеру телефона): ");
    scanf("%d", &choice);

    int (*compareFunction)(const void*, const void*);
    if (choice == 1) {
        compareFunction = compareByName;
    }
    else if (choice == 2) {
        compareFunction = compareByPhoneNumber;
    }
    else {
        fprintf(stderr, "Некорректный выбор сортировки.\n");
        return 1;
    }
    

    mergeSort(list, compareFunction);
    showList(list);

    freeMemory(list);

    return 0;
}
