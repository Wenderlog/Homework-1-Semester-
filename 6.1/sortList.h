//
//  sortList.h
//  6.1
//
//  Created by Кирилл on 03.12.2023.
//

#ifndef sortList_h

#define sortList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct SortList SortList;

typedef struct Node Node;

SortList* createList();
Node* createNode(int data);
void insertElement(SortList* list, int data);
void deleteElement(SortList* list, int data);
void printList(SortList* list);
void freeList(SortList* list);
int getSize(SortList* list);
int getElement(SortList* list, int index);


#endif /* sortList_h */
