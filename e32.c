#include <stdio.h>
 
int main() {
 
    int n;
 
    while (scanf("%d", &n) == 1 && n != 0) {
 
        int lista[n];
        int contador = 0;
 
        int i = 0;
        for (i; i < n; i++) {
            scanf("%d", &lista[i]);
        }
 
        if (n < 3) {
            printf("Nao intercalada\n");
            continue;
        }
 
        int j = 1;
        for (j; j < n - 1; j++) {
            int ehMaior = (lista[j-1] < lista[j] && lista[j] > lista[j+1]); // é maior que o anterior e maior que o próximo
            int ehMenor = (lista[j-1] > lista[j] && lista[j] < lista[j+1]); // é menor que o anterior e menor que o próximo
 
            if (ehMaior || ehMenor) {
                contador++;
            }
        }
 
        if (contador == (n - 2)) { // (n - 2) é a quantidade de numeros do meio da lista. se todos tiveram sequencias de maior e menor, então é intercalada
            printf("Intercalada\n");
        } else {
            printf("Nao intercalada\n");
        }
    }
 
    return 0;
}
