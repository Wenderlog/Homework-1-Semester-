#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Tests.h"

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
            printList(list);
            break;

        default:
            printf("Неверный выбор");
        }
    } while (choice != 0);


    freeList(list);
    return 0;
}

