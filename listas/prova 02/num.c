#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    //a*b = 1 || (a*b)%n == 1
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if((i*j)%n == 1 && i <= j) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }

    return 0;
}