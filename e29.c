#include <stdio.h>
 
int main () {
    float lista[4], temp;
 
    int i, j;
    for(i = 0; i < 4; i++) {
        scanf("%f", &lista[i]);
    }
 
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 3 ; j++) {
            if(lista[j] > lista[j+1]) {  // troca de lugar entre os numeros
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
 
    printf("%.2f, %.2f, %.2f, %.2f\n", lista[0], lista[1], lista[2], lista[3]);
 
    return 0;
}
