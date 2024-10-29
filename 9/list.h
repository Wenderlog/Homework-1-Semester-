#ifndef LIST_H
#define LIST_H

struct Node {
    char* key;
    int count;
    struct Node* next;
};

struct Node* create_node(const char* key);
void destroy_list(struct Node* head);

#endif 
