#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {

    double x, y, cosX = 0;
    int N;
    unsigned long int fatorial = 1;
    scanf("%lf %d", &x, &N);

    double doisPi = 2*M_PI;

    while(x >= doisPi) {
        x -= doisPi;
    }

    while(x < 0.0) {
        x += doisPi;
    }

    int n, i;
    for(n = 0; n <= N; n++) {

        fatorial = 1;

        for(i = 1; i <= (2*n); i++) {
            fatorial *= i;
        }

        cosX += pow(-1, n) * pow(x, 2*n)/ (fatorial);
    }

    printf("cos(%.2lf) = %.6lf", x, cosX);

    return 0;
}