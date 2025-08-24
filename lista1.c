#include <stdio.h>
#include <math.h>

#define PI 3.14159

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

void questao3() {
    float raio, altura;
    scanf("%f", &raio);
    scanf("%f", &altura);
    
    float areaCirculo = PI*raio*raio;
    float areaLateral = 2.00*PI*raio*altura;
 
    float areaTotal = (2.00*areaCirculo) + areaLateral;
 
    float custo = areaTotal*100.00;
 
    printf("O VALOR DO CUSTO E = %.2f\n", custo);
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

void questao5() {
    float a, b, c, d;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    
    float det = (a*d) - (b*c);
    
    printf("O VALOR DO DETERMINANTE E = %.2f\n", det);
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

void questao7() {
    float altura, aresta;
    scanf("%f %f", &altura, &aresta);
 
    float areaBase = (3*aresta*aresta*sqrt(3.0))/2;
    float volume = (1*areaBase*altura)/3;
 
    printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS\n", volume);
}

void questao8() {
    int horas, minutos, segundos;
    scanf("%d %d %d", &horas, &minutos, &segundos);

    int convHoras = horas * 3600;
    int convMinutos = minutos * 60;

    int tempoTotal = convHoras + convMinutos + segundos;

    printf("O TEMPO EM SEGUNDOS E = %d\n", tempoTotal);
}

void questao9() {
    double n;
    scanf("%lf", &n);

    double n10 = 10;

    int i = 0;
    for(i; i < 3; i++) {
        
        double a = n * n10;
        double b = a + 0.5;
        int c = b;
        double d = c / n10;

        printf("%.6lf\n", d);

        n10 *= 10;
    }
}

void questao10() {
    float la, lb, lc;
    scanf("%f %f %f", &la, &lb, &lc);

    float t = (la+lb+lc)/2;
    float area = sqrt(t*(t-la)*(t-lb)*(t-lc));

    printf("A AREA DO TRIANGULO E = %.2f\n", area);
}

int main() {
        
        questao1();
        questao2();
        questao3();
        questao4();
        questao5();
        questao6();
        questao7();
        questao8();
        questao9();
        questao10();
    
    return 0;
}
