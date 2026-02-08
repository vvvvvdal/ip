#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehVogal(char c) {
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    } else {
        return 0;
    }
}

/**
* Função que remove vogais e calcula a quantidade de vogais removidas
* @param str string de entrada
* @param vogais vetor de 5 posições que contabiliza a quantidade
* de vogais removidas
* @return A função atualiza os vetores str e vogais.
*/
void remove_vogais(char * str, int * vogais) {
    int i, tam = strlen(str), ctg = 0;

    char nova[256];
    int no = 0;

    for(i = 0; i < tam; i++) {
        if(ehVogal(str[i]) == 0) {
            nova[no] = str[i];
            no++;
        }
    }
    nova[no] = '\0';

    for(i = 0; i < tam; i++) {
        str[i] = tolower(str[i]);
    }

    for(i = 0; i < tam; i++) {
        if(ehVogal(str[i]) == 1) {
            if(str[i] == 'a') vogais[0]++;
            else if(str[i] == 'a') vogais[0]++;
            else if(str[i] == 'e') vogais[1]++;
            else if(str[i] == 'i') vogais[2]++;
            else if(str[i] == 'o') vogais[3]++;
            else if(str[i] == 'u') vogais[4]++;
        }
    }

    for(i = 0; i < tam; i++) {
        if(i >= no) {
            str[i] = '\0';
        }
    }

    for(i = 0; i < no; i++) {
        str[i] = nova[i];
    }
}

int main() {
    char str[256];
    int vogais[5];
    vogais[0] = 0;
    vogais[1] = 0;
    vogais[2] = 0;
    vogais[3] = 0;
    vogais[4] = 0;

    scanf("%[^\n]%*c", str);
    remove_vogais(str, vogais);

    printf("%s\n", str);
    printf("a: %d\n", vogais[0]);
    printf("e: %d\n", vogais[1]);
    printf("i: %d\n", vogais[2]);
    printf("o: %d\n", vogais[3]);
    printf("u: %d\n", vogais[4]);


    return 0;
}