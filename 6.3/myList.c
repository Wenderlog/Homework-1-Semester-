#include "myList.h"

MyList* createList()
{
    MyList* list = (MyList*)malloc(sizeof(MyList));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addElement(MyList* list, void* data) {
    Node* p = createNode(data);
    if (list->head == NULL) {
        list->head = p;
        list->tail = p;
    }
    else {
        list->tail->next = p;
        list->tail = p;
    }
}

Node* next(MyList* list) {
    if (list->current == NULL) {
        list->current = list->head;
    }
    else {
        list->current = list->current->next;
    }
    return list->current;
}

Node* sortedMerge(Node* x, Node* y, int (*cmp)(const void*, const void*)) {
    Node* result = NULL;

    if (!x)
        return y;
    if (!y)
        return x;

    if (cmp(x->data, y->data) <= 0) {
        result = x;
        result->next = sortedMerge(x->next, y, cmp);
    }
    else {
        result = y;
        result->next = sortedMerge(x, y->next, cmp);
    }
    return result;
}

Node* getMiddle(Node* head) {
    if (!head)
        return head;

    Node* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortRec(Node* head, int (*cmp)(const void*, const void*)) {
    if (!head || !head->next)
        return head;

    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;
    middle->next = NULL;

    Node* left = mergeSortRec(head, cmp);
    Node* right = mergeSortRec(nextOfMiddle, cmp);

    Node* sortedList = sortedMerge(left, right, cmp);
    return sortedList;
}

void mergeSort(MyList* list, int (*cmp)(const void*, const void*)) {
    list->head = mergeSortRec(list->head, cmp);
}

void freeMemory(MyList* list) {
    Node* p = list->head;
    while (p)
    {
        Node* t = p->next;
        free(p->data);
        free(p);
        p = t;
    }
}
