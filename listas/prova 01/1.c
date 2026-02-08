#include <stdio.h>
#include <math.h>

long int bin2dec(long int bin) {
    int b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;

    b0 = bin/1 % 10;
    b1 = bin/10 % 10;
    b2 = bin/100 % 10;
    b3 = bin/1000 % 10;
    b4 = bin/10000 % 10;
    b5 = bin/100000 % 10;
    b6 = bin/1000000 % 10;
    b7 = bin/10000000 % 10;
    b8 = bin/100000000 % 10;
    b9 = bin/1000000000 % 10;
    b10 = bin/1000000000 % 10;

    int numero = b10*pow(2,10) + b9*pow(2,9) + b8*pow(2,8) + b7*pow(2,7) + b6*pow(2,6) + b5*pow(2,5) + b4*pow(2,4) + b3*pow(2,3) + b2*pow(2,2) + b1*pow(2,1) + b0*pow(2,0);

    printf("%d\n", numero);

}

int main() {

    int n;
    scanf("%ld", &n);

    bin2dec(n);

    return 0;
}