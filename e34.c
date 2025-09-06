#include <stdio.h>
 
int main() {
    double n;
    scanf("%lf", &n);
 
    int qtdCasasDecimais = 0;
 
    while(n != (int)n) {
        n *= 10;
        qtdCasasDecimais++;
 
    }
    
    int num = (int)n;
    int den = 1;
    int mdc = 1;
 
    int i;
    for(i = 0; i < qtdCasasDecimais; i++) {
        den *= 10;
    }
    
    int menor;
    if(num < den) {
        menor = num;
    } else {
        menor = den;
    }
 
    int j;
    for(j = 2; j <= menor; j++) {
        if(num%j == 0 && den%j == 0) {
            mdc = j;
        }
    }
 
    num /= mdc;
    den /= mdc;
 
    printf("%d/%d\n", num, den);
 
    return 0;
}
