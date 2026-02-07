#include <stdio.h>
#include <math.h>

int raizesEq2Grau(double a, double b, double c) {
    double delta = (b*b) - (4 * a * c), x1, x2;

    if(delta > 0) {
        x1 = (-b + sqrt(delta));
        x1 /= 2*a;
        x2 = (-b - sqrt(delta));
        x2 /= 2*a;

        printf("RAIZES DISTINTAS\n");

        if(x1 > x2) {
            printf("X1 = %.2lf\n", x2);
            printf("X2 = %.2lf\n", x1);
        } else {
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);
        }
        return 2;
        
    } else if(delta < 0) {
        printf("RAIZES IMAGINARIAS\n");
        return 0;
    } else if(delta == 0) {
        x1 = (-b);
        x1 /= 2*a;
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", x1);
        return 1;
    }
}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    raizesEq2Grau(a,b,c);

    return 0;
}