#include <stdio.h>
#include <math.h>
 
int main () {
    double base, eElevado, resposta;
    int qtd, fatorial;
    scanf("%lf %d", &base, &qtd);
 
    if(qtd > 9) {
        return 0;
    } else {
        eElevado = 1;  // pq x^0 / 0! = 1 / 1 = 1
        fatorial = 1;
 
        int i = 1;
        for(i; i <= qtd; i++) {
            float baseElevada = (pow(base,i)); // função que faz base^i
            fatorial *= i;
            eElevado += baseElevada / fatorial * 1.0;
        }
 
        resposta = eElevado;
        printf("e^%.2lf = %.6lf\n", base, resposta);
    }
 
    return 0;
}
