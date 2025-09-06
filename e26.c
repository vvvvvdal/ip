#include <stdio.h>
 
int main() {
 
    int n;
    int d0, d1, d2, d3, d4;
    scanf("%d", &n);
 
    if(n > 99999) {
        printf("NUMERO INVALIDO\n");
    } else {
        d0 = (n/1) % 10;
        d1 = (n/10) % 10;
        d2 = (n/100) % 10;
        d3 = (n/1000) % 10;
        d4 = (n/10000) % 10;
 
        if(n > 9999) {
            if(d0 == d4 && d1 == d3) {
            printf("PALINDROMO\n");
            } else {
            printf("NAO PALINDROMO\n");
            }
        } else if(n > 999) {
            if(d0 == d3 && d1 == d2) {
            printf("PALINDROMO\n");
            } else {
                printf("NAO PALINDROMO\n");
            }
        } else if(n > 99) {
            if(d0 == d2) {
                printf("PALINDROMO\n");
            } else {
                printf("NAO PALINDROMO\n");
            }
        } else if(n > 9) {
            if(d0 == d1) {
                printf("PALINDROMO\n");
            } else {
                printf("NAO PALINDROMO\n");
            }
        } else {
            printf("PALINDROMO\n");
        }
    }
 
    return 0;
}
