#include <stdio.h>

int main() {
    double salario;
    // digite o salario
    scanf("%lf", &salario);
    // salario = 81
    double qtdEnergia = (1000/7*salario);

    double undEnergia = (7*salario/1000);
    printf("Custo do consumo: R$ %.2lf", undEnergia);



    return 0;
}