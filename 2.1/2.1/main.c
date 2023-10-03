#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long long fibonacy_recursion(int number) {
if (number <= 1) {
return number;
} else {
return fibonacy_recursion(number - 1) + fibonacy_recursion(number - 2);
}
}

unsigned long long fibonacy_itrer(int number) {
if (number <= 1) {
return number;
} else {
unsigned long long a = 0;
unsigned long long b = 1;
unsigned long long tmp;
for (int i = 2; i <= number; i++) {
tmp = a + b;
a = b;
b = tmp;
}
return b;
}
}

int main(int argc, const char * argv[]) {
assert(fibonacy_recursion(0) == 0);
assert(fibonacy_recursion(1) == 1);
assert(fibonacy_recursion(2) == 1);
assert(fibonacy_recursion(3) == 2);
assert(fibonacy_recursion(4) == 3);

assert(fibonacy_itrer(0) == 0);
assert(fibonacy_itrer(1) == 1);
assert(fibonacy_itrer(2) == 1);
assert(fibonacy_itrer(3) == 2);
assert(fibonacy_itrer(4) == 3);
printf("Test complete\n");
return 0;
}
