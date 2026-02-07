#include <stdio.h>

/**
* Valor absoluto de um numero qualquer
* @param n um número real qualquer
* @return ovalor absoluto de n
*/
double absoluto(double n) {
    if (n < 0) {
        n *= -1;
    }

    return n;
}

/**
* Função que calcula a raiz quadrada den.
* @param n um numero real qualquer
* @param p precisão dos cálculos
* @return a raiz quadrada de n
*/
double raiz(double n, double p) {
    double r0 = 1.0, rk, erro = n - (r0*r0);
    erro = absoluto(erro);

    while(erro > p) {
        rk = (r0 + (n)/r0) / 2.0;
        r0 = rk;
        erro = n - (r0*r0);
        erro = absoluto(erro);
        printf("r: %.9lf, err: %.9lf\n", rk, erro);
    }
}
 

int main() {
    double n, e;
    scanf("%lf %lf", &n, &e);
    raiz(n, e);
    
    return 0;
}