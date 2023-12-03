#ifndef TASK5_3_H
#define TASK5_3_H

#include<stdbool.h>

bool check_operator(char c);
int priority(char c);
char* convert_postfix(const char* s, int* status);

#endif /*TASK5_3_H*/