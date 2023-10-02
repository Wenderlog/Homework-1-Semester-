#include <stdio.h>


void reverseArr(int array[], int left, int right){
    while (left < right){
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;
        left++;
        right--;
    }
}

void swapFirstAndLastArr(int array[], int m, int n){
    reverseArr(array, 0, m-1);
    reverseArr(array, m, m+n-1);
    reverseArr(array, 0, m+n-1);
}


int main(int argc, const char * argv[]) {
    int m = 5;
    int n = 10;
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for (int i = 0; i < m + n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    swapFirstAndLastArr(array,m,n);
    
    for (int i = 0; i < m + n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
