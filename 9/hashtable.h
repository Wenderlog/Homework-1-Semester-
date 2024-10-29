#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Hashtable;

struct Hashtable* create_hashtable(int size);
void destroy_hashtable(struct Hashtable* hashtable);
void insert(struct Hashtable* hashtable, const char* key);
int get(struct Hashtable* hashtable, const char* key);
void print_word_frequencies(struct Hashtable* hashtable);
double fill_factor(struct Hashtable* hashtable);
int max_list_length(struct Hashtable* hashtable);
double average_list_length(struct Hashtable* hashtable);

#endif
