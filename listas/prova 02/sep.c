#include <stdio.h>
#include <string.h>

#define MAX_WORDS 200
#define MAX_WORD_LEN 64+1

int ehSep(char c, char *sep) {
    int tamsep = strlen(sep), i;
    for(i=0;i<tamsep;i++) {
        if(c == sep[i]) {
            return 1;
        }
    }
    return 0;
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
* @return int quantidade de palavras detectadas
*/
int str_split(char * str, char m[][MAX_WORD_LEN], char * sep) {
    int tamstr = strlen(str), i,j,l = 0,c = 0,ctg = 0, maior;

    for(i=0;i<tamstr;i++) {
        if(ehSep(str[i],sep) == 0) {
            m[l][c] = str[i];
            c++;
        } else {
            if(c > 0) {
                m[l][c] = '\0';
                l++;
                c = 0;
            }
        }
    }

    if(c > 0) {
        m[l][c] = '\0';
        l++;
        c = 0;
    }

    int tamfrase[l];

    for(i=0;i<l;i++){
        tamfrase[i]=strlen(m[i]);
    }
    
    maior = tamfrase[0];

    for(i=0;i<l;i++){
        if(tamfrase[i] == maior) ctg++;
    }

    for(i=0;i<l;i++){
        printf("(%d)%s\n", tamfrase[i],m[i]);
    }
    printf("%d\n",ctg);

}

int main() {
    char str[1000], m[MAX_WORDS][MAX_WORD_LEN], sep[20];
    scanf("%[^\n]%*c",str);
    scanf("%[^\n]%*c",sep);
    str_split(str, m, sep);


    return 0;
}