#include <stdio.h>


void questao1() {
    double salario;
    // digite o salario
    scanf("%lf", &salario);
    // salario = R$ x

    double qtdkW;
    //digite a quantidade de kW
    scanf("%lf", &qtdkW);
    // qtdkW = y kW

    double custokW = (7*salario/1000);
    double custoConsumo = (7*salario*qtdkW/1000);
    double custoDesconto = (0.9*7*salario*qtdkW/1000);

    printf("Custo por kW: R$ %.2lf\n", custokW);
    printf("Custo do consumo: R$ %.2lf\n", custoConsumo);
    printf("Custo com desconto: R$ %.2lf", custoDesconto);
}

void questao6() {
        int a, b;

    // digite o a
    scanf("%d", &a);

    // digite o b
    scanf("%d", &b);

    double m = (a+b)/2.0;

    // a média é: 
    printf("%.3lf", m);
}

int main() {
        
        questao1();
        questao6();

    return 0;
}
