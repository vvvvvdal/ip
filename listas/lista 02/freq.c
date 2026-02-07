#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 202

int main() {
    int n;
    scanf("%d%*c", &n);

    while(n--) {
        char frase[N], letras[N], alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int contagem[26] = {0}, maiores[26] = {0};
        scanf("%[^\n]%*c", frase);

        int i, j = 0, k = 0;
        int tam = strlen(frase);
        for(i = 0; i < tam; i++) { // deixa tudo minúsculo
            if(frase[i] != tolower(frase[i])) {
                frase[i] = tolower(frase[i]);
            }
        }

        for(i = 0; i < tam; i++) { // tira tudo e deixa só letras
            if(frase[i] >= 'a' && frase[i] <= 'z') {
                letras[j] = frase[i]; 
                j++;
            }
        }

        letras[j] = '\0';
        
        for(i = 0; i < j; i++) {
            for(k = 0; k < 26; k++) {  // contagem de cada letra do alfabeto
                if(alfabeto[k] == letras[i]) {
                    contagem[k]++;
                }
            }
        }

        int maiorFreq = 0;
        for(i = 0; i < 26; i++) { // define a maior frequência
            if(contagem[i] > maiorFreq) {
                maiorFreq = contagem[i];
            }
        }

        for(i = 0; i < 26; i++) { // imprime a(s) letra(s) com maior frequência
            if(contagem[i] == maiorFreq) {
                printf("%c", alfabeto[i]);
            }
        }
        printf("\n");
    }

    return 0;
}