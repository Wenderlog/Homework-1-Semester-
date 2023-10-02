#include <math.h>
#include <assert.h>
#include <stdio.h>
double power_l(double x, int n ){
    double r = 1.0;
    if (n == 0){
        return 1.0;
    }
    if (n < 0){
        x = 1 / x;
        n = -n;
    }
    
    for (int i = 0; i < n; i++){
        r *= x;
    }
    
    return r;
}

double power_log(double x, int n){
    if (n == 0){
        return 1.0;
    }
    if (n < 0){
        x = 1 / x;
        n = -n;
    }
    double r = 1.0;
    while(n > 0){
        if ( n % 2 == 1){
            r *= x;
        }
        x *= x;
        n /=2;
    }
    return r;
}


int main(int argc, const char * argv[]) {
    double x;
    int n;
    scanf("%lf", &x);
    scanf("%d", &n);

    double r1 = power_l(x, n);
    double r2 = power_log(x, n);

    printf("%.2lf in %d: %.2lf \n ", x, n, r1  );
    printf("%.2lf in %d: %.2lf \n ", x, n, r2  );
//    assert(fabs(power_l(2.0, 2) - 4.0)< 1e-6);
//    assert(fabs(power_l(1.2, 2) - 1.44)< 1e-6);
//    assert(fabs(power_l(1.8, 3) - 5.832)< 1e-6);
//
//    assert(fabs(power_log(2.0, 2) - 4.0)< 1e-6);
//    assert(fabs(power_log(1.2, 2) - 1.44)< 1e-6);
//    assert(fabs(power_log(1.8, 3) - 5.832)< 1e-6);
//    printf("Test complete \n");
//
    return 0;
}
