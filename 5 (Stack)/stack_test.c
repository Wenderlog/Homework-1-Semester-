#include "stack_test.h"

void stackCreateTest(FILE* fp) {
    fprintf(fp, "stackCreateTest: ");
    Stack* stack = create_stack();
    int value = 5;
    push(stack, &value, sizeof(int));
    value = 3;
    push(stack, &value, sizeof(int));
    free_stack(stack);
    free(stack);
    fprintf( fp, "Завершено\n");
}

void stackPushTest(FILE* fp) {
    fprintf(fp, "stackPushTest: ");
    Stack* stack = create_stack();
    int value = 5;
    push(stack, &value, sizeof(int));
    assert(*(int*)peek(stack) == 5);
    value = 3;
    push(stack, &value, sizeof(int));
    assert(*(int*)peek(stack) == 3);
    free_stack(stack);
    free(stack);
    fprintf( fp, "Завершено\n");
}

void stackPopTest(FILE* fp) {
    fprintf(fp, "stackPushTest: ");
    Stack* stack = create_stack();
    int value = 5;
    push(stack, &value, sizeof(int));
    value = 3;
    push(stack, &value, sizeof(int));
    value = 7;
    push(stack, &value, sizeof(int));
    assert(*(int*)peek(stack) == 7);
    pop(stack);
    assert(*(int*)peek(stack) == 3);
    value = 2;
    push(stack, &value, sizeof(int));
    assert(*(int*)peek(stack) == 2);
    pop(stack);
    assert(*(int*)peek(stack) == 3);
    pop(stack);
    assert(*(int*)peek(stack) == 5);
    pop(stack);
    free_stack(stack);
    free(stack);
    fprintf( fp, "Завершено\n");
}