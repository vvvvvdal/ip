#include <stdio.h>

int calculoFatorial(int n) {
    int fatorial = 1;

    int i;
    for(i = 1; i <= n; i++) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int linhaInicial, linhaFinal, n, p, nMenosP, elemento;
    scanf("%d %d", &linhaInicial, &linhaFinal);


    int i;
    for(i = linhaInicial; i <= linhaFinal; i++) {
        int j;
        for(j = 0; j <= i; j++) {
            int q = i - j;

            n = calculoFatorial(i);
            p = calculoFatorial(j);
            nMenosP = calculoFatorial(q);

            elemento = n/(p * (nMenosP));

            if(j == 0) {
                printf("%d", elemento);
            } else {
                printf(",%d", elemento);
            }
        }
        printf("\n");
    }

    return 0;
}