#ifndef AVLTree_h
#define AVLTree_h

typedef struct AVLNode {
    char *key;
    char *value;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode* createNode(char *key, char *value);
int getHeight(AVLNode *node);
void updateHeight(AVLNode *node);
int getBalanceFactor(AVLNode *node);
AVLNode* rotateLeft(AVLNode *node);
AVLNode* rotateRight(AVLNode *node);
AVLNode* balance(AVLNode *node);
AVLNode* insert(AVLNode *root, char *key, char *value);
char* search(AVLNode *root, char *key);
AVLNode* findMinNode(AVLNode *node);
AVLNode* delete(AVLNode *root, char *key);
void freeAVLTree(AVLNode *root);

#endif 
