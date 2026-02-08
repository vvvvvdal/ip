#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n, **ma, i, j;
    scanf("%d %d", &m, &n);

    ma = (int**)malloc(m*sizeof(int*));

    for(i = 0; i < m; i++) {
        ma[i] = (int*)malloc(n*sizeof(int));
    }

    for(i = 0; i < m; i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &ma[i][j]);
        }
    }

    int maior = ma[0][0], menor = ma[0][0], lmen = 0, cmen = 0, lmai = 0, cmai = 0, temp;

    for(i = 0; i < m; i++) {
        for(j=0;j<n;j++) {
            if(ma[i][j] < menor) {
                menor = ma[i][j];
                lmen = i;
                cmen = j;
            }

            if(ma[i][j] > maior) {
                maior = ma[i][j];
                lmai = i;
                cmai = j;
            }
        }
    }

    for(i = 0; i < m; i++) {
        for(j=0;j<n;j++) {
            if(ma[i][j] == menor) {
                ma[i][j] = maior;
            } else if(ma[i][j] == maior) {
                ma[i][j] = menor;
            }
        }
    }

    for(i = 0; i < m; i++) {
        for(j=0;j<n;j++) {
            printf("%d ", ma[i][j]);
        }
        printf("\n");
    }


    for(i = 0; i < m; i++) {
        free(ma[i]);
    }
    free(ma);


    return 0;
}