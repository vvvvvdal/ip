#include <stdio.h>
 
int main () {
    int linhaInicial, linhaFinal;
    scanf("%d %d", &linhaInicial, &linhaFinal);
 
    int n = linhaInicial;
    for(n; n <= linhaFinal; n++) {
        long long termo = 1;
 
        int p = 0;
        for(p; p <= n; p++) {
            if(p == 0) {
                printf("%lld", termo);
            } else {
                printf(",%lld", termo);
            }
            termo = termo * (n - p) / (p + 1);  // C(n,p) = C(n,p - 1)
        }
        printf("\n");
    }
 
    return 0;
}
