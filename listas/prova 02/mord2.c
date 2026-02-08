#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, **m, i, j, k, temp;
    scanf("%d", &n);

    m = (int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++) {
        m[i]=(int*)malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for(j=0;j<n;j++) {
        for(i=0;i<n-1;i++) {
            for(k=0;k<n-1-i;k++) {
                if(m[k][j] > m[k+1][j]) {
                    temp = m[k+1][j];
                    m[k+1][j] = m[k][j];
                    m[k][j] = temp;
                }
            }
        }
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}