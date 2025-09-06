#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    int primeiroImpar;
 
    int i, j;
    for(i = 1; i <= n; i++) {
        printf("%d*%d*%d = ", i, i, i);
        primeiroImpar = (i*i) - i + 1;           // 4² - 4 + 1 = 16 - 4 + 1 = 12 +1 = 13 .
 
        for(j = 0; j < i; j++) {
            int atualImpar = primeiroImpar + (2*j);
 
            printf("%d", atualImpar);
 
            if(j < i - 1) {
                printf("+");
            }
        }
        printf("\n");
    }
 
 
 
    return 0;
}
