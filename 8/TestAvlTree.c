#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"

void run_tests() {
    AVLNode *root = NULL;
    root = insert(root, "apple", "fruit");
    printf("Вставка 'apple'\n");
    char *result = search(root, "apple");
    if (result) {
        printf("Результат поиска для 'apple': %s\n", result);
    } else {
        printf("Искать 'apple' не прошло.\n");
    }
    freeAVLTree(root);

    root = insert(root, "orange", "fruit");
    root = insert(root, "banana", "fruit");
    printf("Удаление 'orange'\n");
    root = delete(root, "orange");
    result = search(root, "orange");
    if (result) {
        printf("Результат поиска для 'orange': %s\n", result);
    } else {
        printf("Искать 'orange' не удалось.\n");
    }
    freeAVLTree(root);

    root = NULL;
    printf("Поиск в пустом дереве\n");
    result = search(root, "test");
    if (result) {
        printf("Результат поиска для 'test' на пустом дереве: %s\n", result);
    } else {
        printf("Искать 'test' в пустом дереве не удалось.\n");
    }
    freeAVLTree(root);

    root = insert(root, "cat", "animal");
    root = insert(root, "dog", "animal");
    root = insert(root, "bird", "animal");
    root = insert(root, "fish", "animal");
    printf("Удаление 'cat'\n");
    root = delete(root, "cat");
    result = search(root, "cat");
    if (result) {
        printf("Результат поиска для 'cat': %s\n", result);
    } else {
        printf("Искать 'cat' не удалось.\n");
    }
    freeAVLTree(root);
}

