#include <math.h>
#include <assert.h>
#include <stdio.h>
double power_lin(double number, int degree ) {
double result = 1.0;
if (degree == 0) {
return 1.0;
}
if (degree < 0){
number = 1 / number;
degree = -degree;
}

for (int i = 0; i < degree; i++) {
result *= number;
}
return result;
}

double power_log(double number, int degree) {
if (degree == 0) {
return 1.0;
}
if (degree < 0) {
number = 1 / number;
degree = -degree;
}
double result = 1.0;
while(degree > 0) {
if (degree % 2 == 1) {
result *= number;
}
number *= number;
degree /=2;
}
return result;
}

int main(int argc, const char * argv[]) {
double number;
int degree;
scanf("%lf", &number);
scanf("%d", &degree);

double result1 = power_lin(number, degree);
double result2 = power_log(number, degree);

printf("%.2lf in %d: %.2lf \n ", number, degree, result1);
printf("%.2lf in %d: %.2lf \n ", number, degree, result2);
assert(fabs(power_lin(2.0, 2) - 4.0) < 1e-6);
assert(fabs(power_lin(1.2, 2) - 1.44) < 1e-6);
assert(fabs(power_lin(1.8, 3) - 5.832) < 1e-6);

assert(fabs(power_log(2.0, 2) - 4.0) < 1e-6);
assert(fabs(power_log(1.2, 2) - 1.44) < 1e-6);
assert(fabs(power_log(1.8, 3) - 5.832) < 1e-6);
printf("Test complete \n");

return 0;
}
