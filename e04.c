#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    double listaFar[n], cel;

    int i = 0;
    for(i; i < n; i++) {
        scanf("%lf", &listaFar[i]);
    }
    
    int j = 0;
    for(j; j < n; j++) {
        double far = listaFar[j];
        cel = 5*(far-32) / 9.00;
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2f CELSIUS\n", far, cel);
    }

    return 0;
}
