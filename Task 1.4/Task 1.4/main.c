#include <stdio.h>

int main(int argc, const char * argv[]) {
    int array[19] = {0};
    
    
    for (int i = 0; i <= 9; i++) {
        for (int j = 0 ; j <= 9; j++) {
            for (int q = 0; q<=9; q++) {
                int s = i + j + q;
                if (s <= 18){
                    array[s]++;
                }
            }
        }
    }
    
    long count = 0;
    
    for (int i = 0; i <= 18; i++ ){
        count+= (long)array[i] * array[i];
    }
    
    printf("Кол - во счасливых билетов: %ld\n", count);
    return 0;
}
