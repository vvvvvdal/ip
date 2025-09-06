#include <stdio.h>
 
int main() {
 
    int carbono, rock, tracao;
    scanf("%d %d %d", &carbono, &rock, &tracao);
 
    int teste1 = carbono < 7;
    int teste2 = rock > 50;
    int teste3 = tracao > 80000;
 
    int grau;
 
    if(teste1 && teste2 && teste3) {
        grau = 10;
    } else if(teste1 && teste2) {
        grau = 9;
    } else if(teste1) {
        grau = 8;
    } else {
        grau = 7;
    }
 
    printf("ACO DE GRAU = %d\n", grau);
 
    return 0;
}
