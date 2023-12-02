#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#define SUCCESS 1
#define DIVIDE_ZERO 2
#define INCORRECT_OPERATION 3


typedef struct TreeNode {
	char operation;
	int number;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* createNumberNode(int number) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node) {
		node->operation = 'N';
		node->number = number;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

TreeNode* createOperationNode(char operation, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node) {
		node->operation = operation;
		node->left = left;
		node->right = right;
	}
	return node;
}

TreeNode* buildExpressionTree(FILE* file) {
	char token = ' ';
	fscanf(file, " %c", &token);

	if (isdigit(token)) {
		ungetc(token, file);
		int number = 0;
		fscanf(file, "%d", &number);
		return createNumberNode(number);
	}
	else if (token == '(') {
		char operation = ' ';
		fscanf(file, " %c", &operation);
		TreeNode* left = buildExpressionTree(file);
		TreeNode* right = buildExpressionTree(file);
		fscanf(file, " )"); // Считываем закрывающую скобку
		return createOperationNode(operation, left, right);
	}
	else {
		return NULL;
	}
}

int evaluateExpression(TreeNode* root, int* status) {
	*status = SUCCESS;

	if (root->operation == 'N') {
		return root->number;
	}
	int leftValue = evaluateExpression(root->left, status);
	if (*status != SUCCESS) {
		return 0;
	}
	int rightValue = evaluateExpression(root->right, status);
	if (*status != SUCCESS) {
		return 0;
	}
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
		}
		else {
			*status = DIVIDE_ZERO;
			return 0;
		}
	default:
		*status = INCORRECT_OPERATION;
		return 0;
	}
}

void freeExpressionTree(TreeNode* root) {
	if (root) {
		freeExpressionTree(root->left);
		freeExpressionTree(root->right);
		free(root);
	}
}

void printExpressionTree(TreeNode* root) {
	if (root) {
		if (root->operation == 'N') {
			printf("%d", root->number);
		}
		else {
			printf("( %c ", root->operation);
			printExpressionTree(root->left);
			printf(" ");
			printExpressionTree(root->right);
			printf(" )");
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	FILE* file = fopen("7.2.txt", "r");
	if (!file) {
		printf("Не удалось открыть файл.\n");
		return 1;
	}

	TreeNode* root = buildExpressionTree(file);
	fclose(file);

	if (root) {
		printf("Дерево разбора выражения:\n");
		printExpressionTree(root);
		printf("\n");

		int status;
		int result = evaluateExpression(root, &status);
		if (status == SUCCESS) {
			printf("Результат вычисления выражения: %d\n", result);
		}
		else if (status == DIVIDE_ZERO) {
			printf("Ошибка: деление на ноль.\n");
		}
		else if (status == INCORRECT_OPERATION) {
			printf("Ошибка: некорректная операция.\n");
		}

		freeExpressionTree(root);
	}
	else {
		printf("Ошибка: некорректное выражение.\n");
	}
	return 0;
}