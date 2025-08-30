#include <stdio.h>

int main() {

    float nota;
    char conceito;

    scanf("%f", &nota);

    if(9.0 <= nota && nota <= 10) conceito = 'A';
    else if(7.5 <= nota && nota < 9.0) conceito = 'B';
    else if(6.0 <= nota && nota < 7.5) conceito = 'C';
    else if(0 <= nota && nota < 6.0) conceito = 'D';

    printf("NOTA = %.1f CONCEITO = %c\n", nota, conceito);

    return 0;
}
