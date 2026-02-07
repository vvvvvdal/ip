#include <stdio.h>
 
int main() {
 
    float a, b, c, d, menor, teste = 12345;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    
    if(a == b && b == c && c == d) {
        printf("%.2f, %.2f, %.2f, %.2f\n", a, a, a, a);
        return 0;
    }

    int i;
    for(i = 0; i < 4; i++) {
        if(a <= b && a <= c && a <= d) {
            menor = a;
            a = teste;
        } else if(b <= a && b <= c && b <= d) {
            menor = b;
            b = teste;
        } else if (c <= b && c <= a && c <= d) {
            menor = c;
            c = teste;
        } else if(d <= b && d <= c && d <= a) {
            menor = d;
            d = teste;
        }

        if(i == 0) {
            printf("%.2f", menor);
        } else {
            printf(", %.2f", menor);
        }
    }

    printf("\n");

    return 0;
}