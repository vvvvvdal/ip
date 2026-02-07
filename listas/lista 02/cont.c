#include <stdio.h>
#define N 1000

int main() {
    int n, vetor[N], k, ctg = 0;

    while(1) {
        scanf("%d", &n);

        if(1 <= n && n <= 1000) {
            break;
        }
    }

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        if(vetor[i] >= k) {
            ctg++;
        }
    }

    printf("%d\n", ctg);










    return 0;
}