#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000

int main() {
    char frase[N], letras[N];

    while (scanf("%[^\n]%*c", frase) != EOF) {
        int contador = 0, tam = strlen(frase), i, j = 0;

        for (i = 0; frase[i] != '\0'; i++) {
            frase[i] = tolower(frase[i]);
        }

        for(i = 0; i < tam; i++) {  
            if(i == 0) {
                letras[0] = frase[0];
            }
            if(frase[i] == ' ') {
                j++;
                letras[j] = frase[i+1];
            }
        }

        char letraAtual = 'z';

        for (i = 0; i < j; i++) {
            if (letras[i] == letras[i+1]) {
                if (letras[i] != letraAtual) {
                    contador++;
                    letraAtual = letras[i];
                }
            } else {
                letraAtual = 'z';
            }
        }

        printf("%d\n", contador);
    }

    return 0;
}