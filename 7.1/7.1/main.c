#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int key;
    char *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Dictionary {
    TreeNode *root;
} Dictionary;

TreeNode* createNode(int key, const char *value) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node) {
        node->key = key;
        node->value = strdup(value);
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void initializeDictionary(Dictionary *dict) {
    dict->root = NULL;
}

TreeNode* insertNode(TreeNode *node, int key, const char *value) {
    if (node == NULL) {
        return createNode(key, value);
    }
    
    if (key < node->key) {
        node->left = insertNode(node->left, key, value);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key, value);
    } else {
        free(node->value);
        node->value = strdup(value);
    }
    
    return node;
}

void insert(Dictionary *dict, int key, const char *value) {
    dict->root = insertNode(dict->root, key, value);
}

char* searchNode(TreeNode *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    
    if (key < node->key) {
        return searchNode(node->left, key);
    } else if (key > node->key) {
        return searchNode(node->right, key);
    } else {
        return node->value;
    }
}

char* search(Dictionary *dict, int key) {
    return searchNode(dict->root, key);
}

int containsNode(TreeNode *node, int key) {
    if (node == NULL) {
        return 0;
    }
    
    if (key < node->key) {
        return containsNode(node->left, key);
    } else if (key > node->key) {
        return containsNode(node->right, key);
    } else {
        return 1;
    }
}

int contains(Dictionary *dict, int key) {
    return containsNode(dict->root, key);
}

TreeNode* deleteNode(TreeNode *node, int key) {
    if (node == NULL) {
        return node;
    }
    
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            TreeNode *temp = node->right;
            free(node->value);
            free(node);
            return temp;
        } else if (node->right == NULL) {
            TreeNode *temp = node->left;
            free(node->value);
            free(node);
            return temp;
        }
        
        TreeNode *minRight = node->right;
        while (minRight->left != NULL) {
            minRight = minRight->left;
        }
        
        node->key = minRight->key;
        free(node->value);
        node->value = strdup(minRight->value);
        node->right = deleteNode(node->right, minRight->key);
    }
    
    return node;
}

void removeKey(Dictionary *dict, int key) {
    dict->root = deleteNode(dict->root, key);
}

void freeTree(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node->value);
    free(node);
}

void freeDictionary(Dictionary *dict) {
    freeTree(dict->root);
}

int main() {
    Dictionary dict;
    initializeDictionary(&dict);
    
    int choice, key;
    char value[256];
    
    do {
        printf("1. Добавить значение\n");
        printf("2. Получить значение\n");
        printf("3. Проверить наличие ключа\n");
        printf("4. Удалить ключ\n");
        printf("0. Выйти\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        
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
}
