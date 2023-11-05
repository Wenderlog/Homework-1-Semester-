#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "list.h"

struct Hashtable {
    int size;
    struct Node** table;
    int* list_lengths;
};

struct Hashtable* create_hashtable(int size) {
    struct Hashtable* hashtable = (struct Hashtable*)malloc(sizeof(struct Hashtable));
    if (hashtable == NULL) {
        perror("Failed to allocate memory for hashtable");
        return NULL;
    }
    hashtable->size = size;
    hashtable->table = (struct Node**)malloc(sizeof(struct Node*) * size);
    if (hashtable->table == NULL) {
        perror("Failed to allocate memory for hashtable table");
        free(hashtable);
        return NULL;
    }
    hashtable->list_lengths = (int*)malloc(sizeof(int) * size);
    if (hashtable->list_lengths == NULL) {
        perror("Failed to allocate memory for list_lengths");
        free(hashtable->table);
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
        hashtable->list_lengths[i] = 0;
    }
    return hashtable;
}

void destroy_hashtable(struct Hashtable* hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        destroy_list(hashtable->table[i]);
    }
    free(hashtable->table);
    free(hashtable->list_lengths);
    free(hashtable);
}

unsigned int hash(const char* key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    }
    return hash % size;
}

void insert(struct Hashtable* hashtable, const char* key) {
    unsigned int index = hash(key, hashtable->size);
    struct Node* current = hashtable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    struct Node* new_node = create_node(key);
    new_node->next = hashtable->table[index];
    hashtable->table[index] = new_node;
    hashtable->list_lengths[index]++;
}

int get(struct Hashtable* hashtable, const char* key) {
    unsigned int index = hash(key, hashtable->size);
    struct Node* current = hashtable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void print_word_frequencies(struct Hashtable* hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        struct Node* current = hashtable->table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->key, current->count);
            current = current->next;
        }
    }
}

double fill_factor(struct Hashtable* hashtable) {
    int used_slots = 0;
    for (int i = 0; i < hashtable->size; i++) {
        if (hashtable->table[i] != NULL) {
            used_slots++;
        }
    }
    return (double)used_slots / hashtable->size;
}

int max_list_length(struct Hashtable* hashtable) {
    int max_length = 0;
    for (int i = 0; i < hashtable->size; i++) {
        if (hashtable->list_lengths[i] > max_length) {
            max_length = hashtable->list_lengths[i];
        }
    }
    return max_length;
}

double average_list_length(struct Hashtable* hashtable) {
    int total_length = 0;
    for (int i = 0; i < hashtable->size; i++) {
        total_length += hashtable->list_lengths[i];
    }
    return (double)total_length / hashtable->size;
}
