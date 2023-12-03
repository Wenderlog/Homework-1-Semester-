#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"
#include "Test.h"

void printDictionary(Dictionary* dict) {
    printf("Словарь: ");
    printInOrder(dict->root);
    printf("\n");
}

void runTests(FILE* fp) {
    // 1 тест вставка
    Dictionary dict;
    initializeDictionary(&dict);
    insert(&dict, 5, "apple");
    insert(&dict, 2, "banana");
    insert(&dict, 8, "orange");
    insert(&dict, 1, "grape");

    printf("После добавления:\n");
    printDictionary(&dict);
    // 2 тест поиска по ключу
    int keyToSearch = 8;
    char* result = search(&dict, keyToSearch);
    printf("Пoиск по ключу %d: %s\n", keyToSearch, result ? result : "Ключ не найден");
    // 3 тест проверяем существует ли ключ
    int keyToCheck = 3;
    printf("Проверка существует ли ключ: %s\n", contains(&dict, keyToCheck) ? "Да" : "Нет");
    // 4 тест удаление ключа
    int keyToRemove = 2;
    printf("Удалить ключ %d\n", keyToRemove);
    removeKey(&dict, keyToRemove);
    printDictionary(&dict);
    freeDictionary(&dict);

    dictionaryCreateTest (fp);
    dictionaryFindTest (fp);
    testCreateNode(fp);
    testInsertAndSearch(fp);
    testDelete(fp);
}

int main() {
    runTests(stdout);
    Dictionary dict;
    initializeDictionary(&dict);
    int choice = 0;
    int key = 0;
    char value[256] = { ' ' };
    int scanfResult = 0;

    do {
        printf("1. Добавить значение\n");
        printf("2. Получить значение\n");
        printf("3. Проверить наличие ключа\n");
        printf("4. Удалить ключ\n");
        printf("0. Выйти\n");
        printf("Выберите операцию: ");
        scanfResult = scanf("%d", &choice);
        
        if (scanfResult == 0) {
            printf("Некорректный ввод");
            freeDictionary(&dict);
            return 1;
        }
        
        if (scanfResult < 0) {
            freeDictionary(&dict);
            return 0;
        }

switch (choice) {
            case 1:
                printf("Введите ключ: ");
                scanf("%d", &key);
                printf("Введите значение: ");
                scanf("%s", value);
                insert(&dict, key, value);
                break;
            case 2:
                printf("Введите ключ: ");
                scanf("%d", &key);
                char *result = search(&dict, key);
                if (result) {
                    printf("Значение: %s\n", result);
                } else {
                    printf("Ключ не найден\n");
                }
                break;
            case 3:
                printf("Введите ключ: ");
                scanf("%d", &key);
                if (contains(&dict, key)) {
                    printf("Ключ найден\n");
                } else {
                    printf("Ключ не найден\n");
                }
                break;
            case 4:
                printf("Введите ключ: ");
                scanf("%d", &key);
                removeKey(&dict, key);
                break;
            case 0:
                break;
            default:
                printf("Некорректный выбор\n");
        }
    } while (choice != 0);
    freeDictionary(&dict);
    return 0;
}
