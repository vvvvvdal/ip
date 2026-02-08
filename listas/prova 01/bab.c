#include <stdio.h>

double calcularErro(double n, double r0) {
    double erro = (n - (r0*r0));

    if(erro < 0) {
        erro *= -1;
    }

    return erro;
}

double calcularR(double n, double r0) {
    double rN = (r0 + (n/r0)) / 2;

    return rN;
}
int main() {
    double n, e, r0 = 1, rN, erro;
    scanf("%lf %lf", &n, &e);

    erro = calcularErro(n, r0);

    while(erro > e) {
        rN = calcularR(n, r0);

        r0 = rN;
        
        erro = calcularErro(n, r0);

        printf("r: %.9lf, err: %.9lf\n", rN, erro);
    }

    return 0;
}