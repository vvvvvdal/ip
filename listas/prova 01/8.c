#include <stdio.h>

int digit_count(long int n) {
    int m, qtd = 1;

    while(n%10 != n) {
        n /= 10;
        qtd++;
    }
    
    printf("Numero de digitos: %d", qtd);
}



int main() {
    long int n;
    scanf("%d", &n);

    digit_count(n);

    return 0;
}