#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AVLNode* createNode(char *key, char *value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if (newNode) {
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
    }
    return newNode;
}

int getHeight(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

void updateHeight(AVLNode *node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int getBalanceFactor(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateLeft(AVLNode *node) {
    AVLNode *newRoot = node->right;
    AVLNode *subtree = newRoot->left;
    newRoot->left = node;
    node->right = subtree;

    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLNode* rotateRight(AVLNode *node) {
    AVLNode *newRoot = node->left;
    AVLNode *subtree = newRoot->right;
    newRoot->right = node;
    node->left = subtree;

    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLNode* balance(AVLNode *node) {
    updateHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* insert(AVLNode *root, char *key, char *value) {
    if (root == NULL) {
        return createNode(key, value);
    }

    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        root->left = insert(root->left, key, value);
    } else if (cmp > 0) {
        root->right = insert(root->right, key, value);
    } else {
        free(root->value);
        root->value = strdup(value);
        return root;
    }
    return balance(root);
}

char* search(AVLNode *root, char *key) {
    if (root == NULL) {
        return NULL;
    }
    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        return search(root->left, key);
    } else if (cmp > 0) {
        return search(root->right, key);
    } else {
        return root->value;
    }
}

AVLNode* findMinNode(AVLNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

AVLNode* delete(AVLNode *root, char *key) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        root->left = delete(root->left, key);
    } else if (cmp > 0) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            AVLNode *temp = (root->left) ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp->key);
            free(temp->value);
            free(temp);
        } else {
            AVLNode *minNode = findMinNode(root->right);
            free(root->key);
            free(root->value);
            root->key = strdup(minNode->key);
            root->value = strdup(minNode->value);
            root->right = delete(root->right, minNode->key);
        }
    }
    if (root == NULL) {
        return root;
    }
    return balance(root);
}

void freeAVLTree(AVLNode *root) {
    if (root) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root->key);
        free(root->value);
        free(root);
    }
}


