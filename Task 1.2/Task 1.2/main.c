#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n; // размер массива
    scanf("%d", &n);
    int array[n];
    int k = 0;
    printf("введите значения элементов массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] == 0) {
            k++;
        }
    }
    
    printf("Кол-во нулевых в массиве: %d\n", k);
    
    return 0;
}
