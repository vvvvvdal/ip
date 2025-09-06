#include <stdio.h>
 
int main () {
    int n;
    scanf("%d", &n);
    int contador = 0;
    int divisoresDeN[1000];
    int somaDiv = 0;
 
    int i = 1;
    for(i; i < n; i++){
        if(n%i == 0) {
            divisoresDeN[contador] = i;
            somaDiv += divisoresDeN[contador];
            contador++;
        }
    }
    
    printf("%d = ", n);
 
    int j = 0;
    for(j; j < contador; j++) {
        printf("%d ", divisoresDeN[j]);
 
        if(j < contador - 1) { // imprime a quantidade certa de "+"
            printf("+ ");
        }
    }
 
    printf("= %d ", somaDiv);
    
    if(somaDiv == n) {
        printf("(NUMERO PERFEITO)\n");
    } else {
        printf("(NUMERO NAO E PERFEITO)\n");
    }
 
    return 0;
}
