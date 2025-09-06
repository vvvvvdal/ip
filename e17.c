#include <stdio.h>
 
int main() {
 
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
 
    int menoresNumeros[3];
 
    int maior = a;
 
    if(b > a) {
        maior = b;
    } else if(c > a) {
        maior = c;
    } else if(d > a) {
        maior = d;
    }
 
    int somaTotal = a+b+c+d;
    int somaMenores = somaTotal - maior;
 
    printf("%d\n", somaMenores);
 
    return 0;
}
