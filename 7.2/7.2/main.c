#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TreeNode {
    char operation;
    int number;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNumberNode(int number) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node) {
        node->operation = 'N';
        node->number = number;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

TreeNode* createOperationNode(char operation, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node) {
        node->operation = operation;
        node->left = left;
        node->right = right;
    }
    return node;
}

TreeNode* buildExpressionTree(FILE *file) {
    char token;
    fscanf(file, " %c", &token);

    if (isdigit(token)) {
        ungetc(token, file);
        int number;
        fscanf(file, "%d", &number);
        return createNumberNode(number);
    } else if (token == '(') {
        char operation;
        fscanf(file, " %c", &operation);
        TreeNode *left = buildExpressionTree(file);
        TreeNode *right = buildExpressionTree(file);
        fscanf(file, " )"); // Считываем закрывающую скобку
        return createOperationNode(operation, left, right);
    } else {
        return NULL;
    }
}

int evaluateExpression(TreeNode *root) {
    if (root->operation == 'N') {
        return root->number;
    } else {
        int leftValue = evaluateExpression(root->left);
        int rightValue = evaluateExpression(root->right);
        switch (root->operation) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    printf("Ошибка: деление на ноль.\n");
                    exit(1);
                }
            default:
                printf("Ошибка: некорректная операция.\n");
                exit(1);
        }
    }
}

void freeExpressionTree(TreeNode *root) {
    if (root == NULL) {
            return;
        }

        freeExpressionTree(root->left);
        freeExpressionTree(root->right);

        if (root->operation == 'N') {
            free(root);
        }
    }

void printExpressionTree(TreeNode *root) {
    if (root) {
        if (root->operation == 'N') {
            printf("%d", root->number);
        } else {
            printf("( %c ", root->operation);
            printExpressionTree(root->left);
            printf(" ");
            printExpressionTree(root->right);
            printf(" )");
        }
    }
}

int main() {
    FILE *file = fopen("7.2.txt", "r");
    if (!file) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    TreeNode *root = buildExpressionTree(file);
    fclose(file);

    if (root) {
        printf("Дерево разбора выражения:\n");
        printExpressionTree(root);
        printf("\n");

        int result = evaluateExpression(root);
        printf("Результат вычисления выражения: %d\n", result);

        freeExpressionTree(root);
    } else {
        printf("Ошибка: некорректное выражение.\n");
    }

    return 0;
}
