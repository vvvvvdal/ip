#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Complex {
    float pt_real;
    float pt_img;
};

struct RaizEqu2{
    struct Complex x1;
    struct Complex x2;
};

/**
* Função que calula as raízes de uma equação de segundo grau.
*
* @param a coeficiente quadrado
* @param b coeficiente linear
* @param c constante
* @return retorna uma estrutura RaizEqu2 com dois números complexos
*/
struct RaizEqu2 calcula_raiz_equ_2(float a, float b, float c){
    struct RaizEqu2 r;
    double qtd_i;
    double delta = (b*b) - 4*a*c;

    if(delta == 0){
        r.x1.pt_real = -b/(2*a), r.x1.pt_img = 0;
        r.x2.pt_real = -b/(2*a), r.x2.pt_img = 0;
    } else if(delta > 0) {
        r.x1.pt_real = (-b + sqrt(delta))/(2*a), r.x1.pt_img = 0;
        r.x2.pt_real = (-b - sqrt(delta))/(2*a), r.x2.pt_img = 0;
    } else if(delta < 0) {
        qtd_i = delta * -1;
        r.x1.pt_real = -b /(2*a), r.x1.pt_img = sqrt(qtd_i)/(2*a);
        r.x2.pt_real = -b /(2*a), r.x2.pt_img = -1*(sqrt(qtd_i)/(2*a));
    }
    return r;
}

/**
* Imprime numeros complexos na saída padrão do sistema. A impressão segue o formato
* a + bi, onde a é a parte real e b a imaginária. Os valores são apresentados
* somente se forem diferente de zero. No caso de a e b forem zero, o valor 0 é
* apresentado. Se o valor de b for 1 ou-1, somente o caracter i ou-i é
apresentado.
*
* @param c Numero complexo a ser impresso.
*/
void complex_print(struct Complex c){
    if(c.pt_real == 0 && c.pt_img == 0) printf("0.00");

    if(c.pt_real != 0) printf("%.2f", c.pt_real);

    if(c.pt_img != 0) {
        if(c.pt_real != 0 && c.pt_img > 0) printf("+");

        if(c.pt_img == 1) printf("i");
        else if(c.pt_img == -1) printf("-i");
        else printf("%.2fi", c.pt_img);
    }

    printf("\n");
}

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    struct RaizEqu2 r = calcula_raiz_equ_2(a, b, c);

    printf("x1 = ");
    complex_print(r.x1);
    printf("x2 = ");
    complex_print(r.x2);

    return 0;
}