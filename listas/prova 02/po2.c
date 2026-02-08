#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, j ,l, p;
    scanf("%d", &n);
    if(n < 0 || n > 10) return 0;
    scanf("%d", &k);
    double **m, **a, soma = 0.0;
    m = (double**)malloc(n*sizeof(double*));
    a = (double**)malloc(n*sizeof(double*));

    for(i=0;i<n;i++){
        m[i]=(double*)malloc(n*sizeof(double));
        a[i]=(double*)malloc(n*sizeof(double));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf", &m[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j] = m[i][j];
        }
    }

    for(p = 2; p <= k; p++) {
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                soma = 0.0;
                for(l=0;l<n;l++) {
                    soma += m[i][l]*m[l][j];
                }
                a[i][j] = soma;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++){
        free(m[i]);
        free(a[i]);
    }
    free(m);
    free(a);

    return 0;
}