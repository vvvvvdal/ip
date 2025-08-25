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

    double n10 = 10.0;

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

void questao11() {
    float pFabrica, percDistrib, percImpostos;
    scanf("%f %f %f", &pFabrica, &percDistrib, &percImpostos);

    float custoconsum = pFabrica + pFabrica*((percDistrib + percImpostos)/100);

    printf("O VALOR DO CARRO E = %.2f\n", custoconsum);
}

void questao12() {
    double m, a, t; // massa em toneladas, aceleração em m/s², tempo em segundos.
    scanf("%lf %lf %lf", &m,&a, &t);
    
    double v0 = 0;
    double s0 = 0;

    double v = 3.6*(v0 + (a * t)); // v em m/s -> km/h
    double vms = v/3.6; // v em km/h -> m/s
    double s = s0 + (v0*t) + (a*t*t)/2;
    double w = ((1000*m*vms*vms))/2 - ((1000*m*v0*v0))/2;


    printf("VELOCIDADE = %.2lf\n", v);
    printf("ESPACO PERCORRIDO = %.2lf\n", s);
    printf("TRABALHO REALIZADO = %.2lf\n", w);
}

void questao13() {
    float xa, ya, xb, yb;
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);

    float d = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));

    printf("A DISTANCIA ENTRE A e B = %.2f\n", d);
}

void questao14() {
    int n;
    scanf("%d", &n);
    int a10, a11, a20, a21, a30, a31;

    // 123/100 = 1.23 -> inteiro ... 1 -> 1 % 10 = 1           // o resto vem da divisão inteira.
    a10 = n/100;
    a11 = a10 % 10;

    // 123/100 = 12.3 -> inteiro ... 12 -> 12 % 10 = 2         // o resto vem da divisão inteira.
    a20 = n/10;
    a21 = a20 % 10;

    // 123/100 = 123 -> inteiro ... 123 -> 123 % 10 = 3        // o resto vem da divisão inteira.
    a30 = n/1;
    a31 = a30 % 10;

    int dControle = (a11 + (a21*3) + (a31*5)) % 7;

    printf("O NOVO NUMERO E = %d%d\n", n, dControle);
}

void questao15() {
    int n;
    scanf("%d", &n);

    int nbin1, nbin2, nbin3, nbin4, nbin5, nbin6, nbin7, nbin8;

    if(0<= n && n <= 255) {

        nbin1 = n % 2;
        nbin2 = n/2 % 2;
        nbin3 = n/4 % 2;
        nbin4 = n/8 % 2;
        nbin5 = n/16 % 2;
        nbin6 = n/32 % 2;
        nbin7 = n/64 % 2;
        nbin8 = n/128 % 2;
        
        printf("%d%d%d%d%d%d%d%d\n", nbin8, nbin7, nbin6, nbin5, nbin4, nbin3, nbin2, nbin1);

    } else {
        printf("Numero invalido!\n");
    }
}

void questao16() {
    int n;
    scanf("%d", &n);
 
    int n1, n2, n3;
 
    // pega o primeiro algarismo
    n1 = n / 100;
    n1 = n1 % 10;
 
    // pega o segundo algarismo
    n2 = n / 10;
    n2 = n2 % 10;
 
    // pega o terceiro algarismo
    n3 = n / 1;
    n3 = n3 % 10;
 
    printf("%d%d%d\n", n3, n2, n1);
}

void questao17() {
    int valor;
    scanf("%d", &valor);

    int n100, n50, n10, n1;
    int vr100, vr50, vr10, vr1;

    vr100 = valor % 100;
    vr50 = vr100 % 50;
    vr10 = vr50 % 10;
    vr1 = vr10 % 1;

    // valor = notas * x + resto
    // valor - resto = notas * x
    // x = (valor - resto) / notas

    n100 = (valor - vr100) / 100;
    n50 = (vr100 - vr50) / 50;
    n10 = (vr50 - vr10) / 10; 
    n1 = (vr10 - vr1) / 1;

    printf("NOTAS DE 100 = %d\n", n100);
    printf("NOTAS DE 50 = %d\n", n50);
    printf("NOTAS DE 10 = %d\n", n10);
    printf("MOEDAS DE 1 = %d\n", n1);
}

void questao18() {
    float a, b, c, d, e, f;
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    
    float x = ((e*c)-(b*f))/((a*e)-(b*d)*1.00);
    float y = (f - (d*x))/e*1.00;

    printf("O VALOR DE X E = %.2f\n", x);
    printf("O VALOR DE Y E = %.2f\n", y);
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
        questao11();
        questao12();
        questao13();
        questao14();
        questao15();
        questao16();
        questao17();
        questao18();

    return 0;
}
