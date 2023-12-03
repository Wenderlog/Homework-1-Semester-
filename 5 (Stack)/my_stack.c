#include "my_stack.h"

Stack* create_stack()
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;

    return st;
}

void push(Stack* st, void* value, size_t element_size)
{
    StackElement* elem = (StackElement*)malloc(sizeof(StackElement));
    void* data = malloc(element_size);
    memcpy(data, value, element_size);

    elem->value = data;
    elem->next = st->top;
    st->top = elem;
}

void* pop(Stack* st)
{
    if (st->top == NULL) {
        return NULL;
    }
    void* data = st->top->value;
    StackElement* temp = st->top;
    st->top = temp->next;
    free(temp);

    return data;
}

void* peek(Stack* st)
{
    if (st->top == NULL) {
        return NULL;
    }
    return st->top->value;
}

bool is_empty(Stack* st)
{
    return st->top == NULL;
}

void free_stack(Stack* st)
{
    StackElement* p = st->top;
    while (p)
    {
        StackElement* t = p->next;
        free(p);
        p = t;
    }
}
