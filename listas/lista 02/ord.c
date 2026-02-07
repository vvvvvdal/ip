#include <stdio.h>

int main() {
    int n, i, j, k, temp, m[10][10];
    scanf("%d", &n);
    if(n < 1 || n > 50) return 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for(j = 0; j < n; j++) {
        for(i = 0; i < n - 1; i++) {
            for(k = 0; k < n - 1 - i; k++) {
                if (m[k][j] > m[k+1][j]) {
                    temp = m[k][j];
                    m[k][j] = m[k+1][j];
                    m[k+1][j] = temp;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}