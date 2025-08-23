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
    printf("Custo com desconto: R$ %.2lf\n\n", custoDesconto);
}

void questao2() {
    int tempFar;
    // digite a temperatura em Farenheit
    scanf("%d", &tempFar);

    int pol;
    // digite a quantidade de chuva em polegadas
    scanf("%d", &pol);

    // cálculo da temperatura de Farenheit para Celsius
    double tempCel = 5*(tempFar-32)/9.00;

    // cálculo da quantidade de chuvas de polegadas para milímetros
    double qtdChuva = pol*25.4;

    printf("O VALOR EM CELSIUS = %.2lf\n", tempCel);
    printf("A QUANTIDADE DE CHUVA E = %.2lf\n\n", qtdChuva);
}

void questao4() {
    double A, B, C;

    // leitura dos valores de A, B e C
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    double delta = (B*B) - (4*A*C);

    printf("O VALOR DE DELTA E = %.2lf\n\n", delta);
}

void questao6() {
        int a, b;

    // digite o a
    scanf("%d", &a);

    // digite o b
    scanf("%d", &b);

    double m = (a+b)/2.0;

    // a média é: 
    printf("%.3lf\n\n", m);
}

int main() {
        
        questao1();
        questao2();
        questao4();
        questao6();

    return 0;
}
