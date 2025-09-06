#include <stdio.h>
 
int main() {
 
    int n, f1, f2;
    scanf("%d %d %d", &n, &f1, &f2);
 
    int lista[n], fibo[n];
    int contador = 0;
    int i;
 
    for(i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
 
    fibo[0] = f1;
    fibo[1] = f2;
 
    if(lista[0] == fibo[0]) {
        printf("OK\n");
        contador++;
    } else {
        printf("Nao e Fibonacci\n");
        return 0;
    }
 
    if(lista[1] == fibo[1]) {
        printf("OK\n");
        contador++;
    } else {
        printf("Nao e Fibonacci\n");
        return 0;
    }
 
    for(i = 2; i < n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
 
        if(lista[i] == fibo[i]) {
            printf("OK\n");
            contador++;
        } else {
            printf("Nao e Fibonacci\n");
            return 0;
        }
    }
 
    if(contador == n) {
        printf("A serie informada e de Fibonacci\n");
    } else {
        printf("Nao e Fibonacci\n");
    }
 
    return 0;
}
