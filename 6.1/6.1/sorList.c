#include "sorList.h"

struct Node {
    int data;
    struct Node* next;
};

struct SortList {
    Node* head;
};

SortList* createList()
{
    SortList* list = (SortList*)malloc(sizeof(SortList));
    list->head = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertElement(SortList* list, int data) {
    if (list == NULL) {
        return;
    }
    Node* newNode = createNode(data);
    if (list->head == NULL || data < list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        Node* current = list->head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteElement(SortList* list, int data) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->data == data) {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return;
    }

    Node* tmp = current->next;
    current->next = current->next->next;
    free(tmp);
}

void printList(SortList* list) {
    Node* current = list->head;
    printf("List - ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(SortList* list)
{
    Node* newNode = list->head;
    while (newNode != NULL) {
        Node* tmp = newNode->next;
        free(newNode);
        newNode = tmp;
    }
}

int getSize(SortList* list)
{
    int size = 0;
    Node* newNode = list->head;
    while (newNode)
    {
        size++;
        newNode = newNode->next;
    }
    return size;
}

int getElement(SortList* list, int index)
{
    Node* newNode = list->head;
    for (int i = 0; i < index; i++)
    {
        newNode = newNode->next;
    }
    return newNode->data;
}
