
#ifndef loopList_h
#define loopList_h

typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct loopList {
    Node* tail;
    Node* current;
}LoopList;


LoopList* createList();
Node* createNode(void* data);
void addElement(LoopList* list, void* data);
Node* next(LoopList* list);
void removeNode(LoopList* list, Node* p);
void freeList(LoopList* list);
int findAlive(int n, int m);

#endif
