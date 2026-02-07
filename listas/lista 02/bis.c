#include <stdio.h>
#include <stdlib.h>

int **matriz_alocar(int n) {
    int i, j;
    int **m = NULL;
    
    m = (int**)malloc(n * sizeof(int*)); 
    if(m == NULL) exit(1);

    for(i = 0; i < n; i++) {
        m[i] = (int*)malloc(n * sizeof(int));
        if(m[i] == NULL) exit(1);
    }

    return m;
}

void matriz_free(int **m, int n) {
    int i;
    for(i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int n, i, j, dp_simetrica = 1, ds_simetrica = 1;
    int **m;

    scanf("%d", &n);
    if(n < 1 || n > 11) {
        printf("dimensao invalida\n");
        return 0;
    }

    m = matriz_alocar(n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }


    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(m[i][j] != m[j][i]) { 
                dp_simetrica = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) { 
            if (m[i][j] != m[n-1-j][n-1-i]) { 
                ds_simetrica = 0;
            }
        }
    }

    if(dp_simetrica == 1 && ds_simetrica == 1) {
        printf("bissimetrica\n");
    } else {
        printf("nao bissimetrica\n");
    }

    matriz_free(m, n);

    return 0;
}