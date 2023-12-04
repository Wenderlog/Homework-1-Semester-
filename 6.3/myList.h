#ifndef myList_h
#define myList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    void* data;
    struct node* next;
}Node;

typedef struct my_list{
    Node* head;
    Node* tail;
    Node* current;
}MyList;

MyList* createList();
Node* createNode(void* data);
void addElement(MyList* list, void* data);
Node* next(MyList* list);
Node* sortedMerge(Node* x, Node* y, int (*cmp)(const void*, const void*));
Node* getMiddle(Node* head);
Node* mergeSortRec(Node* head, int (*cmp)(const void*, const void*));
void mergeSort(MyList* list, int (*cmp)(const void*, const void*));
void freeMemory(MyList* list);


#endif
