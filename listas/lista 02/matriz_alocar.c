#include <stdio.h>
#include <stdlib.h>

int **matriz_new(int nl, int nc) {
    int i;
    int **M = NULL;
    M = (int**)malloc(nl*sizeof(int*));
    
    for(i = 0; i < nl; i++) {
        M[i] = (int*)malloc(nc*sizeof(int));
    }

    return M;
}

void matriz_scanf(int **M, int nl, int nc) {
    int i, j;
    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            scanf("%d", &M[i][j]);
        }
    }
}

void matriz_printf(int **M, int nl, int nc, char *pos) {
    int i, j;
    
    for(i = 0; i < nl; i++) {
        printf("|");
        for(j = 0; j < nc; j++) {
            printf("%5d ", M[i][j]);
        }
        printf("|");
        printf("\n");
    }

    if(pos != NULL) printf("%s", pos);
}

void matriz_soma(int **A, int **B, int **C, int nl, int nc) {
    int i, j;
    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            C[i][j] = A[i][j]+B[i][j];
        }
    }
}

void matriz_free(int **A, int nl) {
    int i;
    for(i = 0; i < nl; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    int **A, **B, **C;
    
    A = matriz_new(3,2);
    B = matriz_new(3,2);
    C = matriz_new(3,2);

    matriz_scanf(A, 3, 2);
    matriz_scanf(B, 3, 2);

    matriz_printf(A, 3, 2, "\n");
    matriz_printf(B, 3, 2, "\n");

    matriz_soma(A, B, C, 3, 2);
    
    matriz_printf(C, 3, 2, "\n");

    matriz_free(A, 3);
    matriz_free(B, 3);
    matriz_free(C, 3);

    return 0;
}