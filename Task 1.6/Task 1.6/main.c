#include <stdbool.h>
#include <stdio.h>

bool isPrime(int num){
    if (num < 1){
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0){
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    printf("Простые числа до %d \n", n);
    printf("1 ");
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)){
            printf("%d ",i);
        }
    }
    printf("\n");
    
    
    return 0;
}
