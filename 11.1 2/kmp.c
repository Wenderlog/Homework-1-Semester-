#include "kmp.h"
#include <stdlib.h>
#include <string.h>

void computePrefixFunction(const char* pattern, int* prefixFunction) {
    int length = strlen(pattern);
    int j = 0;

    prefixFunction[0] = 0;

    for (int i = 1; i < length; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefixFunction[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            j++;
        }

        prefixFunction[i] = j;
    }
}

int searchSubstring(const char* text, const char* pattern) {
    int lengthText = strlen(text);
    int lengthPattern = strlen(pattern);

    int* prefixFunction = (int*)malloc(lengthPattern * sizeof(int));
    if (prefixFunction == NULL) {
        return -1; // Ошибка выделения памяти
    }

    computePrefixFunction(pattern, prefixFunction);

    int j = 0;

    for (int i = 0; i < lengthText; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixFunction[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == lengthPattern) {
            free(prefixFunction);
            return i - lengthPattern + 1;
        }
    }

    free(prefixFunction);
    return -1;
}
