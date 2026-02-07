#include <stdio.h>
#include <string.h> // Ainda precisamos para strlen

#define MAX_WORDS 200
#define MAX_WORD_LEN 64 + 1

int ehSeparador(char c, char *sep) {
    int i, tam = strlen(sep), ehSeparador = 0;
    for (i = 0; i < tam; i++) {
        if (c == sep[i]) {
            ehSeparador = 1;
        }
    }
    return ehSeparador;
}

int str_split(char *str, char m[][MAX_WORD_LEN], char *sep) {
    int i, str_tam = strlen(str), nl = 0, nc = 0;
    for (i = 0; i < str_tam; i++) {
        if (ehSeparador(str[i], sep) == 0) {
            m[nl][nc] = str[i];
            nc++;
        } else {
            if (nc > 0) {
                m[nl][nc] = '\0';
                nl++;
                nc = 0;
            }
        }
    }

    if (nc > 0) {
        m[nl][nc] = '\0';
        nl++;
    }

    return nl;
}

int verificar_iguais(char *a, char *b) {
    int i = 0;
    
    while (a[i] != '\0' || b[i] != '\0') {
        
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

void contagem_iguais(int num_palavras, char m[][MAX_WORD_LEN]) {
    int i, j;

    for (i = 0; i < num_palavras; i++) {
        if (i > 0 && verificar_iguais(m[i], m[i - 1]) == 1) {
            continue;
        }

        int contagem = 0;
        
        for (j = 0; j < num_palavras; j++) {
            
            if (verificar_iguais(m[i], m[j]) == 1) {
                contagem++;
            }
        }

        printf("(%s)%d\n", m[i], contagem);
    }
}

int main() {
    char str[2048];
    char sep[] = " .,!?()[]{}*";
    char m[MAX_WORDS][MAX_WORD_LEN];
    int num_palavras;

    scanf("%[^\n]%*c", str);

    num_palavras = str_split(str, m, sep);

    contagem_iguais(num_palavras, m);

    return 0;
}