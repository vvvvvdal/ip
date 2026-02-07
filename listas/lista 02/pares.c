#include <stdio.h>
#define N 1000

int main() {
    int n, vetor[N], ctg = 0;
    
    scanf("%d", &n);
    if(n < 0 || n > 1000) {
        return 0;
    }

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < n; i++) {
        if(vetor[i]%2 == 0) {
            ctg++;
            printf("%d ", vetor[i]);
        }
    }

    printf("%d\n", ctg);



    return 0;
}