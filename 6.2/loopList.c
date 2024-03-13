#include "loopList.h"
#include <stdio.h>
#include <stdlib.h>

LoopList* createList() {
    LoopList* list = (LoopList*)malloc(sizeof(LoopList));
    if (list != NULL) {
        list->tail = NULL;
        list->current = NULL;
    }
    return list;
}

Node* createNode(void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

void addElement(LoopList* list, void* data) {
    if (list == NULL)
        return;

    Node* p = createNode(data);
    if (p == NULL)
        return;

    if (list->tail == NULL) {
        list->tail = p;
        p->next = p;
        p->prev = p;
    } else {
        Node* head = list->tail->next;
        p->next = head;
        head->prev = p;
        list->tail->next = p;
        p->prev = list->tail;
        list->tail = p;
    }
}

Node* next(LoopList* list) {
    if (list == NULL || list->tail == NULL)
        return NULL;

    if (list->current == NULL) {
        list->current = list->tail->next;
    } else {
        list->current = list->current->next;
    }
    return list->current;
}

void removeNode(LoopList* list, Node* p) {
    if (list == NULL || p == NULL || list->tail == NULL)
        return;

    if (p == list->current) {
        list->current = p->prev;
    }

    Node* t = list->tail;
    if (t == p) {
        if (list->tail->next == t) {
            list->tail = NULL;
        } else {
            Node* pred = list->tail->prev;
            Node* next = list->tail->next;
            pred->next = next;
            next->prev = pred;
            list->tail = pred;
        }
    } else {
        Node* pred = p->prev;
        Node* next = p->next;
        pred->next = next;
        next->prev = pred;
    }
    free(p);
}

void freeList(LoopList* list) {
    if (list == NULL)
        return;

    Node* t = list->tail;
    if (t != NULL) {
        Node* head = t->next;
        while (head != t) {
            Node* p = head;
            head = head->next;
            free(p->data);
            free(p);
        }
        free(t->data);
        free(t);
    }
    free(list);
}

int findAlive(int n, int m) {
    LoopList* list = createList();
    for (int i = 1; i <= n; i++) {
        int* val = malloc(sizeof(int));
        *val = i;
        addElement(list, val);
    }

    Node* p;
    int i = 0;
    p = p->next;

    do {
        i++;
        if (i % m == 0) {
            removeNode(list, p);
        }
        p = next(list);
    } while (p->next != p);

    int* result = p->data;
    int res = *result;

    freeList(list);

    return res;
}
