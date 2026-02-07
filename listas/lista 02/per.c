#include <stdio.h>

/**
* Função que verifica se a matriz é de permutação
* @param matriz Indica a matriz a ser verificada
* @param n indica a dimensão da matriz
* @param *soma parâmetro de saída, que armazenará a soma de todos os ’n’ elementos
da matriz.
* @return int
*/
int ehPermutacao(int matriz[500][500], int n) {
    int i, j, ehPermut = 0, soma = 0,ctd_um, ctd_zero;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            soma += matriz[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        ctd_um = 0, ctd_zero = 0;

        for(j = 0; j < n; j++) {
            if(matriz[i][j] == 1) {
                ctd_um++;
            } else if(matriz[i][j] == 0) {
                ctd_zero++;
            }
        }

        if(ctd_um == 1 && ctd_zero == (n-1)) {
            ehPermut++;
        }
    }

    printf("%d\n", n);
    if(ehPermut == n) {
        printf("PERMUTACAO\n");
    } else {
        printf("NAO EH PERMUTACAO\n");
    }
    printf("%d\n", soma);

    return soma;
}


int main() {
    int matriz[500][500], n;
    scanf("%d", &n);
    ehPermutacao(matriz, n);

    return 0;
}