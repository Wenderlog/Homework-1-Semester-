#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"
#include "AVLTree.h"

void printMenu() {
    printf("Выберите операцию:\n");
    printf("1. Добавить значение по ключу\n");
    printf("2. Получить значение по ключу\n");
    printf("3. Проверить наличие ключа\n");
    printf("4. Удалить ключ и значение\n");
    printf("5. Выйти из программы\n");
    printf("Введите номер операции: ");
}

int main() {
    void run_tests();
    AVLNode *root = NULL;
    int choice = 0;
    char key[100] = { ' ' };
    char value[100] = { ' ' };

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите ключ: ");
                scanf("%s", key);
                printf("Введите значение: ");
                scanf("%s", value);
                root = insert(root, key, value);
                printf("Значение добавлено.\n");
                break;
            case 2:
                printf("Введите ключ: ");
                scanf("%s", key);
                char *result = search(root, key);
                if (result) {
                    printf("Значение: %s\n", result);
                } else {
                    printf("Ключ не найден.\n");
                }
                break;
            case 3:
                printf("Введите ключ: ");
                scanf("%s", key);
                if (search(root, key)) {
                    printf("Ключ существует.\n");
                } else {
                    printf("Ключ не существует.\n");
                }
                break;
            case 4:
                printf("Введите ключ: ");
                scanf("%s", key);
                root = delete(root, key);
                printf("Ключ и значение удалены.\n");
                break;
            case 5:
                freeAVLTree(root);
                return 0;
            default:
                printf("Некорректная операция. Пожалуйста, выберите существующую операцию.\n");
                break;
        }
    }
    return 0;
}
