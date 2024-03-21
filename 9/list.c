#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Node* create_node(const char* key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("Failed to allocate memory for node");
        return NULL;
    }
    node->key = strdup(key);
    node->count = 1;
    node->next = NULL;
    return node;
}

void destroy_list(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp->key);
        free(temp);
    }
}
