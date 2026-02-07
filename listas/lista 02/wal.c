#include <stdio.h>

int main() {
    int camisa = 1111, gorro = 4, braso = 0, perna = 8, n, m, matriz[10][10], i, j, cima, baixo, esquerda, direita;
    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] == camisa) {
                cima = (i-1+n)%n;
                baixo = (i+1)%n;
                esquerda = (j-1+m)%m;
                direita = (j+1)%m;

                if(matriz[cima][j] == gorro && matriz[baixo][j] == perna && matriz[i][esquerda] == braso && matriz[i][direita] == braso) {
                    printf("%d %d\n", i, j);
                    return 0;
                }
            }
        }
    }

    printf("WALLY NAO ESTA NA MATRIZ\n");

    return 0;
}