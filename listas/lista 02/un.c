#include <stdio.h>

int main() {
    int m[10][10], nl, nc, i, j, uni[100], k, l, s = 0;
    scanf("%d %d", &nl, &nc);

    if(nl < 1 || nc < 1 || nl > 10 || nc > 10) {
        printf("dimensao invalida\n");
        return 0;
    }

    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            int ehUnico = 0;

            for(k = 0; k < nl; k++) {
                for(l = 0; l < nc; l++) {
                    if(m[i][j] == m[k][l]) {
                        ehUnico++;
                    }
                }
            }
            
            if(ehUnico == 1) {
                uni[s] = m[i][j];
                s++;
            }
        }
    }

    if(s > 0) {
        for(i = 0; i < s; i++) {
                if(i == 0) {
                    printf("%d", uni[i]);
                } else {
                    printf(",%d", uni[i]);
                }
            }
        printf("\n");
    } else {
        printf("sem elementos unicos\n");
    }

    return 0;
}