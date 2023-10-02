#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long long fib_rec(int n){
    if (n <= 1){
        return n;
    }else {
        return fib_rec(n-1) + fib_rec(n - 2);
    }
}

unsigned long long fib_itr(int n){
    if (n <= 1){
        return n;
    }else{
        unsigned long long a = 0, b = 1, tmp;
        for (int i  =  2; i <= n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
}



int main(int argc, const char * argv[]) {
    assert(fib_rec(0) == 0);
    assert(fib_rec(1) == 1);
    assert(fib_rec(2) == 1);
    assert(fib_rec(3) == 2);
    assert(fib_rec(4) == 3);
    
    assert(fib_itr(0) == 0);
    assert(fib_itr(1) == 1);
    assert(fib_itr(2) == 1);
    assert(fib_itr(3) == 2);
    assert(fib_itr(4) == 3);
    printf("Test complete\n");
    return 0;
}
