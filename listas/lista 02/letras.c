#include <stdio.h>
#include <string.h>
#define TAMANHO_MAXIMO 10001
int main() {
    int n;
    scanf("%d", &n);
    getchar(); // limpa o buffer de entrada

    int i, j, k, l, m;
    for(i = 0; i < n; i++) {
        int letras = 0, vogais = 0, consoantes = 0;

        char frase[TAMANHO_MAXIMO];
        scanf("%[^\n]%*c", frase);

        int tamanhoFrase = strlen(frase);

        int j;
        for(j = 0; j < tamanhoFrase; j++) {
            char charAtual = frase[j];


            if((charAtual >= 'a' && charAtual <= 'z') || (charAtual >= 'A' && charAtual <= 'Z')) { // verifica se é letra
                letras++;
                if(charAtual == 'a' || charAtual == 'e' || charAtual == 'i' || charAtual == 'o' || charAtual == 'u' || 
                    charAtual == 'A' || charAtual == 'E' || charAtual == 'I' || charAtual == 'O' || charAtual == 'U') { // verifica se é vogal
                    vogais++;
                } else { // se não for vogal, então é consoante
                    consoantes++;
                    }
            }
                
            
        }

        printf("Letras = %d\n", letras);
        printf("Vogais = %d\n", vogais);
        printf("Consoantes = %d\n", consoantes);
    }

    return 0;
}