#include "binaryTree.h"

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

void initializeDictionary(Dictionary *dict) {
    dict->root = NULL;
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
