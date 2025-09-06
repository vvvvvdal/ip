#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    if(n < 0){
        printf("Numero invalido!\n");
    } else if(n <= 1) {
        printf("NAO PRIMO\n");
    } else {
        int i;
        int ehPrimo = 1;
        for(i = 2; i <= (n/2); i++) {
            if((n % i) == 0) {
                ehPrimo = 0;
                break;
            }
        }
 
        if(ehPrimo == 1) {
            printf("PRIMO\n");
        } else {
            printf("NAO PRIMO\n");
        }
    }
 
    return 0;
}
