#include <stdio.h>

int main() {
    int n, i, j, ctg = 0;
    scanf("%d", &n);
    
    for(i = 1; i <= 6; i++) {
        for(j = 1; j <= 6; j++) {
            if(i+j == n && i != j) {
                printf("D1: %d, D2: %d\n", i, j);
                ctg++;
            }
        }
    }
    if(ctg == 0) {
        printf("Combinacao impossivel\n");
    } else {
        printf("Ha %d possibilidades\n", ctg);
    }
    
    return 0;
}