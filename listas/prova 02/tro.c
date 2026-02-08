#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n, **ma, i, j, k, temp;
    scanf("%d %d", &m, &n);
    if(m < 0 || m > 1001) return 0;
    if(n < 0 || n > 1001) return 0;

    ma = (int**)malloc(m*sizeof(int*));
    for(i = 0; i < m; i++) {
        ma[i] = (int*)malloc(n*sizeof(int));
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &ma[i][j]);
        }
    }

    int maior = ma[0][0], menor = ma[0][0], maiorl = 0, menorl = 0,  maiorc = 0, menorc = 0;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(ma[i][j] < menor) {
                menor = ma[i][j];
                menorl = i;
                menorc = j;
            }

            if(ma[i][j] > maior) {
                maior = ma[i][j];
                maiorl = i;
                maiorc = j;
            }
        }
    }

    temp = ma[maiorl][maiorc];
    ma[maiorl][maiorc] = ma[menorl][menorc];
    ma[menorl][menorc] = temp;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
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