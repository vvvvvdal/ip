#include <stdio.h>
#include <string.h>
#define N 1000

int main() {
    int n, qtdDigitos, leds;
    char valorN[102];
    int numerosLeds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d", &n);
    if(n < 0 || n > 1000) {
        return 0;
    }

    int i, j;
    for(i = 0; i < n; i++) {
        leds = 0;
        scanf("%s", valorN);
        
        qtdDigitos = strlen(valorN);

        for(j = 0; j < qtdDigitos; j++) {
            char digitoCaractere = valorN[j];
            int digitoReal = digitoCaractere - '0';

            leds += numerosLeds[digitoReal];
        }

        printf("%d leds\n", leds);
    }

    return 0;
}