#include <stdio.h>
#define N 100000
#define M 1000

int main() {
    int n, m, vetor[N], numeros[M], ctgA = 0, ctgNA = 0;

    scanf("%d", &n);

    if(n < 0 || n > 100000) {
        return 0;
    }

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &m);

    if(m < 0 || m > 1000) {
        return 0;
    }

    for(i = 0; i < m; i++) {
        scanf("%d", &numeros[i]);
    }

    int j = 0, k = 0;
    while(j < m && k < n) {

        if(numeros[j] == vetor[k]) { // se achar, reseta o contador de k, passa para o proximo j
            k = 0;
            j++;
            printf("ACHEI\n");
        } else { // se nao achar, passa para o proximo k
            k++;
        }

        if(k == n) { // se k chegar no ultimo numero do vetor, reseta o k e passa para o proximo j
            k = 0;
            j++;
            printf("NAO ACHEI\n");
        }

        if(j == m) {
            break;
        }
    }

    return 0;
}