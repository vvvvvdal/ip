#include <stdio.h>
#include <math.h>
 
int main() {
 
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
 
    if (a == 0) {
        printf("RAIZES IMAGINARIAS\n");
        return 0;
    }
 
    double delta = (b*b) - (4*a*c);
    
    double x1, x2;
 
    if (delta < 0) {
        printf("RAIZES IMAGINARIAS\n");
    } 
    else if (delta == 0) {
        x1 = (-b) / (2.0*a);
 
        printf("RAIZ UNICA\n");
        printf("X1 = %.2f\n", x1);
    } 
    else {
        double raizDelta = sqrt(delta);
        x1 = ((-b) - raizDelta) / (2.0*a);
        x2 = ((-b) + raizDelta) / (2.0*a);
 
        printf("RAIZES DISTINTAS\n");
        
        if (x1 < x2) {
            printf("X1 = %.2f\n", x1);
            printf("X2 = %.2f\n", x2);
        } else {
            printf("X1 = %.2f\n", x2);
            printf("X2 = %.2f\n", x1);
        }
    }
 
    return 0;
}
