#include <stdio.h>
#include "kmp.h"
#include "kmpTest.h"

void testSearchSubstring() {
    char text[] = "Собока макароны на пародия ярик. С его присутствуют слова и кодик.";
    char searchString1[] = "на пародия";
    char searchString2[] = "хомопуполос";
    char searchString3[] = "";
    char searchString4[] = "Собока макароны на пародия ярик. С его присутствуют слова и кодик.";
    char searchString5[] = "кодик.";

    int position1 = searchSubstring(text, searchString1);
    if (position1 == 15) {
        printf("Test 1 passed\n");
    } else {
        printf("Test 1 failed\n");
    }

    int position2 = searchSubstring(text, searchString2);
    if (position2 == -1) {
        printf("Test 2 passed\n");
    } else {
        printf("Test 2 failed\n");
    }

    int position3 = searchSubstring(text, searchString3);
    if (position3 == -1) {
        printf("Test 3 passed\n");
    } else {
        printf("Test 3 failed\n");
    }

    int position4 = searchSubstring(text, searchString4);
    if (position4 == 0) {
        printf("Test 4 passed\n");
    } else {
        printf("Test 4 failed\n");
    }

    int position5 = searchSubstring(text, searchString5);
    if (position5 == 48) {
        printf("Test 5 passed\n");
    } else {
        printf("Test 5 failed\n");
    }
}

