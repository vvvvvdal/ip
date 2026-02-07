#include <stdio.h>
#include <string.h>

#define MAX_WORDS 200
#define MAX_WORD_LEN 64 + 1

int ehSeparador(char c, char *sep) {
    int i, tam = strlen(sep), ehSeparador = 0;

    for(i = 0; i < tam; i++) {
        if(c == sep[i]) {
            ehSeparador = 1;
        }
    }
    return ehSeparador;
}

/**
* @brief Função de separação de palavras de acordo com a uma lista de separadores.
*
Exemplo de chamada da função:
* str_split("Ola mundo! 1,23", m, ", .!?");
*
* O resultado é a separação das strings "Ola", "mundo", "1", "23", cada uma
* ocupando uma linha da matriz m, com base nos caracteres de pontuação fornecidos.
*
* @param str ponteiro para o início da string original
* @param m matriz de caracteres, sendo cada linha uma palavra da string original
* @param sep string com a lista de caracteres separadores
* @r
*/

int str_split(char *str, char m[][MAX_WORD_LEN], char *sep) {
    int i, j, str_tam = strlen(str), sep_tam = strlen(sep), nl = 0, nc = 0;
    for(i = 0; i < str_tam; i++) {
        if(ehSeparador(str[i], sep) == 0) {
            m[nl][nc] = str[i];
            nc++;
        } else {
            if(nc > 0) {
                m[nl][nc] = '\0';
                nl++;
                nc = 0;
            }
        }
    }

    if(nc > 0) {
        m[nl][nc] = '\0';
        nl++;
    }

    return nl;
}

void contagem_letras(int num_palavras, char m[][MAX_WORD_LEN]) {
    int i, j, ctg, quantidade_letras[num_palavras], maior = 0, contador = 0;
    for(i = 0; i < num_palavras; i++) {
        quantidade_letras[i] = strlen(m[i]);
        printf("(%d)", quantidade_letras[i]);
        printf("%s\n", m[i]);
    }

    for(i = 0; i < num_palavras; i++) {
        if(quantidade_letras[i] > maior) {
            maior = quantidade_letras[i];
        }
    }

    for(i = 0; i < num_palavras; i++) {
        if(quantidade_letras[i] >= maior) {
            contador++;
        }
    }
    printf("%d\n", contador);
}

int main() {
    char str[1000], sep[100], m[MAX_WORDS][MAX_WORD_LEN];
    int num_palavras;

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", sep);

    num_palavras = str_split(str, m, sep);

    contagem_letras(num_palavras, m);

    return 0;
}