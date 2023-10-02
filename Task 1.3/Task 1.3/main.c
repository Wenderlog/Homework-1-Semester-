#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int a1 = abs(a);
    int b1 = abs(b);
    
    if ((b == 0) && (a == 0)){
        printf("Деление на 0\n");
        return 0;
        
    }else{
        int result = 0;
        
        while(a1 >= b1){
            a1 -= b1;
            result++;
        }
        printf("Неполное частное: %d\n", result);
    }
    return 0;
}
