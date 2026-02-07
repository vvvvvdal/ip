#include <stdio.h>
#define MAX 100

int main() {
    int m[MAX][MAX], nl, nc, lborda, vborda, i, j;
    scanf("%d %d %d %d", &nc, &nl, &lborda, &vborda);
    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            if(i < lborda || j < lborda || i >= (nl - lborda) || j >= (nc - lborda)) {
                m[i][j] = vborda;
            } else {
                m[i][j] = 0;
            }
        }
    }

    printf("P2\n");
    printf("%d %d\n", nc, nl);
    printf("255\n");
    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}