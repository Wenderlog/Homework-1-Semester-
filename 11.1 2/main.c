#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"
#include "fileReader.h"

int main() {
    char* fileContent = readFile("11.1.txt");
    if (fileContent == NULL) {
        printf("Не удалось прочитать файл.\n");
        return 1;
    }

    char searchString[100] = { ' ' };

    printf("Введите строку для поиска: ");
    scanf("%s", searchString);

    int position = searchSubstring(fileContent, searchString);

    if (position != -1) {
        printf("Первое вхождение строки '%s' в файле на позиции %d.\n", searchString, position);
    } else {
        printf("Строка '%s' не найдена в файле.\n", searchString);
    }

    free(fileContent);
    return 0;
}
