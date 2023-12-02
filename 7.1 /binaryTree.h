#ifndef binaryTree_h

#define binaryTree_h

#include <string.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    char *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Dictionary {
    TreeNode *root;
} Dictionary;

TreeNode* createNode(int key, const char *value);
TreeNode* insertNode(TreeNode *node, int key, const char *value);
TreeNode* deleteNode(TreeNode *node, int key);
void initializeDictionary(Dictionary *dict);
void removeKey(Dictionary *dict, int key);
void freeTree(TreeNode *node);
void freeDictionary(Dictionary *dict);
char* searchNode(TreeNode *node, int key);
void insert(Dictionary *dict, int key, const char *value);
char* search(Dictionary *dict, int key);
int containsNode(TreeNode *node, int key);
int contains(Dictionary *dict, int key);

#endif /* binaryTree_h */
