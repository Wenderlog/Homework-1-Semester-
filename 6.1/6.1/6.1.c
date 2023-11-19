#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "sortList.c"

void test1() {
    SortList* list = createList();

    insertElement(list, 34);
    insertElement(list, 12);
    insertElement(list, 56);

    printf("Test insert - ");

    if (getElement(list, 0) == 12 && getElement(list, 1) == 34 && getElement(list, 2) == 56) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

void test2() {
    SortList* list = createList();

    insertElement(list, 34);
    insertElement(list, 12);
    insertElement(list, 56);

    deleteElement(list, 12);

    int check;

    printf("Test delete - ");

    if (getElement(list, 0) == 34 && getElement(list, 1) == 56) {
        printf("OK\n");
    }
    else {
        printf("Failed\n");
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    test1();
    test2();

    SortList* list = createList();
    int choice = 0;
    int value = 0;

    do {
        printf("Выберите операцию: \n");
        printf("0 - выйти \n");
        printf("1 - добавить значение в сортированный список \n");
        printf("2 - удалить значение из списка \n");
        printf("3 - распечатать список \n");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Введите значение для добавления ");
            scanf("%d", &value);
            insertElement(list, value);
            break;
        case 2:
            printf("Введите значение для удаления ");
            scanf("%d", &value);
            deleteElement(list, value);
            break;
        case 3:
            print_list(list);
            break;

        default:
            printf("Неверный выбор");
        }
    } while (choice != 0);

   
    free_list(list);
    free(list);

    return 0;
}