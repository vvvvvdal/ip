#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
void veVogais(char * str, int *vogais) {
    int i, tam = strlen(str), ctg = 0;

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
    printf("(%d,%d,%d,%d,%d)\n",vogais[0],vogais[1],vogais[2],vogais[3],vogais[4]);
}

void distancia(int *vogais1, int *vogais2) {
    double dist = sqrt((vogais1[0]-vogais2[0]) + (vogais1[1]-vogais2[1]) + (vogais1[2]-vogais2[2]) + (vogais1[3]-vogais2[3]) + (vogais1[4]-vogais2[4]));

    printf("%.2lf", dist);
}

int main() {
    char entrada[1000], str1[1000], str2[1000];
    int i, ctge = 0, j, tamej, tam1 = 0, tam2 = 0, posicao, vogais1[5], vogais2[5];

    for(i = 0; i < 5; i++) {
        vogais1[i] = 0;
        vogais2[i] = 0;
    }

    scanf("%[^\n]%*c", entrada);
    int tame = strlen(entrada);

    for (i = 0; i < tame; i++) {
        if (entrada[i] == ';') {
            ctge++;
            posicao = i;
        } else if (ctge == 0) {
            str1[tam1] = entrada[i];
            tam1++;
        }
    }
    str1[tam1] = '\0';

    if (ctge != 1) {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }

    for (i = posicao + 1; i < tame; i++) {
        str2[tam2] = entrada[i];
        tam2++;
    }
    str2[tam2] = '\0';

    veVogais(str1, vogais1);
    veVogais(str2, vogais2);
    distancia(vogais1, vogais2);

    return 0;
}