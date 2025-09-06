#include <stdio.h>
 
int main() {
 
    int n;
 
    int quantidadePares = 0;
    int quantidadeImpares = 0;
 
    int somaPares = 0;
    int somaImpares = 0;
 
    double mediaPares = 0.0;
    double mediaImpares = 0.0;
 
    while(scanf("%d", &n) == 1) {
 
        if(n == 0) {
            break;
        }
        
        if((n % 2) == 0) {
            somaPares += n;
            quantidadePares++;
        } else {
            somaImpares += n;
            quantidadeImpares++;
        }
    }
 
    if(quantidadePares > 0) {
        mediaPares = 1.0 * somaPares / quantidadePares;
    }
    
    if(quantidadeImpares > 0) {
        mediaImpares = 1.0 * somaImpares / quantidadeImpares;
    }
 
    printf("MEDIA PAR: %f\n", mediaPares);
    printf("MEDIA IMPAR: %f\n", mediaImpares);
 
    return 0;
}
