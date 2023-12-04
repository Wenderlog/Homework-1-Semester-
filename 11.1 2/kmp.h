#ifndef kmp_h
#define kmp_h

#include <stdio.h>

void computePrefixFunction(const char* pattern, int* prefixFunction);
int searchSubstring(const char* text, const char* pattern);


#endif /* kmp_h */
