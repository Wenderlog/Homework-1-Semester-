#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack_element{
    void* value;
    struct stack_element* next;
}StackElement;

typedef struct stack{
    StackElement* top;
} Stack;

Stack* create_stack();
void push(Stack* st, void* value, size_t element_size);
void* pop(Stack* st);
void* peek(Stack* st);
bool is_empty(Stack* st);
void free_stack(Stack* st);
