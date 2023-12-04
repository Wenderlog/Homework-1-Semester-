#include "loopList.h"
#include "Tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus");

    test1();
    test2();

    int n, m;
    printf("Введите количество воинов: ");
    scanf("%d", &n);
    printf("Введите количество убийств: ");
    scanf("%d", &m);

    int k = findAlive(n, m);
    printf("Результат = %d", k);

    return 0;
}
