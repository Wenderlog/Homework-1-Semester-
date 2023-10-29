#include <string.h>
#include <stdio.h>

int countOccurrences(const char* haystack, const char* needle) {
    int count = 0;
    const long lenHaystack = strlen(haystack);
    const long lenNeedle = strlen(needle);
    for (int i = 0; i <= lenHaystack - lenNeedle; i++) {
        int j = 0;
        for (j = 0; j < lenNeedle; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == lenNeedle) {
            count++;
        }
    }
    return count;
}

int main() {
    const char* string1 = "bnbnbnbnnb";
    const char* string2 = "bn";
    int count = countOccurrences(string1, string2);
    printf("Количество вхождений string2 в string1: %d\n", count);
    return 0;
}
