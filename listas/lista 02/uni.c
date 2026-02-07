#include <stdio.h>
#define N 1000
 
int main() {
    int n, lista[N], imprimir[N], temp;

    scanf("%d", &n);
 
    int i, j;
    for(i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    for(i = 0; i < (n-1); i++) {
        for(j = 0; j < (n-1-i); j++) {
            if(lista[j] >= lista[j+1]) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    if(n > 0) {
        printf("%d\n", lista[0]);
        
        for(i = 1; i < n; i++){
            if(lista[i] != lista[i-1]) {
                printf("%d\n", lista[i]);
            } else {
                continue;
            }
        }
    }

    return 0;
}