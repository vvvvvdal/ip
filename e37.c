#include <stdio.h>
 
void encontrarDivisoresPrimos(int n) {
    printf("%d = ", n);
 
    int contador = 0;
 
    while (n % 2 == 0) {
        if(contador > 0) {
            printf("x ");
        }
 
        printf("2 ");
        n /= 2;
 
        contador++;
 
    }
    
    int i;
    for (i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            if(contador > 0) {
                printf("x ");
            }
 
            printf("%d ", i);
            n /= i;
 
            contador++;
        }
    }
 
    if (n > 2) {
        if(contador > 0) {
            printf("x ");
            }
 
        printf("%d ", n);
 
        contador++;
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    if(n <= 0) {
        printf("Fatoracao nao e possivel para o numero %d!\n", n);
        
        return 0;
 
    } else {
        encontrarDivisoresPrimos(n);
    }
 
 
    return 0;
}
