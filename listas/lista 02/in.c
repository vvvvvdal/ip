#include <stdio.h>
#define Q 500000

int main() {
    int q1, q2, i, j, anum[Q], bnum[Q];
    char avetor[Q], bvetor[Q], temp;
    scanf("%d%*c%d%*c", &q1, &q2);

    if((q1 < 0 || q1 > Q) || (q2 < 0 || q2 > Q)) {
        return 0;
    }

    for(i = 0; i < q1; i++) {
        scanf("%c", &avetor[i]);
        anum[i] = avetor[i] - '0';
    }

    for(i = 0; i < q2; i++) {
        scanf("%c", &bvetor[i]);
        bnum[i] = bvetor[i] - '0';
    }

    for(i = 0; i < q1-1; i++) {
        for(j = 0; j < q1-1-i; j++) {
            if(anum[j] > anum[j+1]) {
                temp = anum[j];
                anum[j] = anum[j+1];
                anum[j+1] = temp;
            }
        }
    }

    for(i = 0; i < q2-1; i++) {
        for(j = 0; j < q2-1-i; j++) {
            if(bnum[j] > bnum[j+1]) {
                temp = bnum[j];
                bnum[j] = bnum[j+1];
                bnum[j+1] = temp;
            }
        }
    }

    for(i = 0; i < q1; i++) {
        printf("%d\n", anum[i]);
    }

    for(i = 0; i < q2; i++) {
        printf("%d\n", bnum[i]);
    }

    return 0;
}