#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, j, l, p;
    scanf("%d %d", &n, &k);

    if(n < 1 || n > 10) return 0; 
    if(k <= 0) return 0;

    double **m, **a, **temp;

    m = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i++) {
        m[i] = (double*)malloc(n*sizeof(double));
    }

    a = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i++) {
        a[i] = (double*)malloc(n*sizeof(double));
    }

    temp = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i++) {
        temp[i] = (double*)malloc(n*sizeof(double));
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = m[i][j];
        }
    }

    for(p = 2; p <= k; p++) {
        
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                
                double soma = 0.0;
                for(l = 0; l < n; l++) {
                    soma += a[i][l] * m[l][j];
                }
                temp[i][j] = soma;
            }
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                a[i][j] = temp[i][j];
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++) {
        free(m[i]);
        free(a[i]);
        free(temp[i]);
    }
    free(m);
    free(a);
    free(temp);

    return 0;
}