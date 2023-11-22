#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 10;
    
    int b = 20;
    
    printf("Исходные значения: a = %d, b = %d\n ", a, b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("Обмен: a = %d, b = %d\n ", a, b);
    return 0;
}
