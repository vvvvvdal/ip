#include <stdio.h>

double absoluto(double n) { // calcula o módulo de n - rN²
    if (n < 0) {
        n *= -1;
    }

    return n;
}

void calcularRaiz(double n, double e) {
    double rN, r0 = 1.0, erro = absoluto(n - (r0 * r0));

    while (erro > e) {
        rN = (r0 +(n/r0)) / 2;
        
        erro = absoluto(n - (rN * rN));

        printf("r: %.9f, err: %.9f\n", rN, erro);

        r0 = rN;
    }

}

int main() {
    double n, e;

    scanf("%lf %lf", &n, &e);

    calcularRaiz(n, e);

    return 0;
}