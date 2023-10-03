#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void compute_prefix_function(const char* pattern, int* prefix_function) {
    int m = strlen(pattern);
    int j = 0;

    prefix_function[0] = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix_function[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            j++;
        }

        prefix_function[i] = j;
    }
}

//  алгоритм KMP
int search_substring(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int* prefix_function = (int*)malloc(m * sizeof(int));
    compute_prefix_function(pattern, prefix_function);

    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix_function[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {
            free(prefix_function);
            return i - m + 1;
        }
    }

    free(prefix_function);
    return -1;
}

int main() {
    FILE* file = fopen("11.1.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[1000];
    char search_string[100];

    printf("Введите строку для поиска: ");
    scanf("%s", search_string);

    int position = -1;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        position = search_substring(buffer, search_string);
        if (position != -1) {
            printf("Первое вхождение строки '%s' в файле на позиции %d.\n", search_string, position);
            break;
        }
    }

    fclose(file);

    if (position == -1) {
        printf("Строка '%s' не найдена в файле.\n", search_string);
    }

    return 0;
}
