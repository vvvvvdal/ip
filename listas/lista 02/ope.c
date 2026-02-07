#include <stdio.h>

int main() {
    int n, m[100][100], t[100][100], i, j, soma = 0;

    scanf("%d", &n);
    if(n < 1 || n > 1001) return 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);

            if(i == j) {
                soma += m[i][j];
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            t[i][j] = m[j][i];
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            m[i][j] = soma*m[i][j];

            m[i][j] += t[i][j];
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}