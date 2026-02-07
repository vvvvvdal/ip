#include <stdio.h>

int main() {
    int m[6][6], i, j, k, soma = -100, somaN, a, b, c, d, e, f, g;

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for(i = 0; i < 6; i++) {
        if(i == 4) break;
        for(j = 0; j < 6; j++) {
            if(j == 4) break;
            a = m[i][j], b = m[i][j+1], c = m[i][j+2], d = m[i+1][j+1], e = m[i+2][j], f = m[i+2][j+1], g = m[i+2][j+2];
            somaN = a+b+c+d+e+f+g;
            if(somaN > soma) {
                soma = somaN;
            }
        }
    }

    printf("%d\n", soma);

    return 0;

}