#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long long fibonacciRecursion(int number) {
   if (number <= 1) {
       return number;
   }
   else
   {
       return fibonacciRecursion(number - 1) + fibonacciRecursion(number - 2);
   }
}

unsigned long long fibonacciIterative(int number) {
   if (number <= 1) {
       return number;
   }
   else
   {
       unsigned long long a = 0;
       unsigned long long b = 1;
       unsigned long long tmp = 0;
       for (int i = 2; i <= number; i++) {
           tmp = a + b;
           a = b;
           b = tmp;
       }
       return b;
   }
}

int main() {
   assert(fibonacciRecursion(0) == 0);
   assert(fibonacciRecursion(1) == 1);
   assert(fibonacciRecursion(2) == 1);
   assert(fibonacciRecursion(3) == 2);
   assert(fibonacciRecursion(4) == 3);

   assert(fibonacciIterative(0) == 0);
   assert(fibonacciIterative(1) == 1);
   assert(fibonacciIterative(2) == 1);
   assert(fibonacciIterative(3) == 2);
   assert(fibonacciIterative(4) == 3);
   printf("Test complete\n");
   return 0;
}
