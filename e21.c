#include <stdio.h>
 
int main() {
 
    int t;
    scanf("%d", &t);
    
    int resultados[t], valA[t],valB[t];
 
    int i;
    for(i = 0; i < t; i++) {
        scanf("%d %d", &valA[i], &valB[i]);
    }
 
    int j;
    for(j = 0; j < t; j++){
 
        int a = valA[j];
        int b = valB[j];
        int invertidoA, invertidoB;
 
        int a1, a2, a3;
        a1 = (a/100) % 10;
        a2 = (a/10) % 10;
        a3 = (a/1) % 10;
        invertidoA = (a3*100) + (a2*10) + a1;
 
        int b1, b2, b3;
        b1 = (b/100) % 10;
        b2 = (b/10) % 10;
        b3 = (b/1) % 10;
        invertidoB = (b3*100) + (b2*10) + b1;
 
        if(invertidoA > invertidoB) {
            resultados[j] = invertidoA;
        } else {
            resultados[j] = invertidoB;
        }
    }
 
    int k;
    for(k = 0; k < t; k++) {
        printf("%d\n", resultados[k]);
    }
 
    return 0;
}
