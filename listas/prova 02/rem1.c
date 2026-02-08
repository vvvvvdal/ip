#include <stdio.h>
#include <string.h>

/**
* Função que remove vogais e calcula a quantidade de vogais removidas
* @param str string de entrada
* @param vogais vetor de 5 posições que contabiliza a quantidade
* de vogais removidas
* @return A função atualiza os vetores str e vogais.
*/
void remove_vogais( char * str, int * vogais ) {
    char nova[256], i, j, tam = strlen(str), no = 0;


    for(i = 0; i < tam; i++) {
        if(str[i] == 'a' || str[i] == 'A') vogais[0]++;
        else if(str[i] == 'e' || str[i] == 'E') vogais[1]++;
        else if(str[i] == 'i' || str[i] == 'I') vogais[2]++;
        else if(str[i] == 'o' || str[i] == 'O') vogais[3]++;
        else if(str[i] == 'u' || str[i] == 'U') vogais[4]++;
    }

    for(i = 0; i < tam; i++) {
        if(str[i] != 'a' && str[i] != 'A' && str[i] != 'e' && str[i] != 'E' && str[i] != 'i' && str[i] != 'I' && str[i] != 'o' && str[i] != 'O' 
        && str[i] != 'u' && str[i] != 'U') {
            nova[no] = str[i];
            no++;
        }
    }
    nova[no] = '\0';

    for(i = 0; i < tam; i++) {
        if(i > no) str[i] = '\0';
    }

    for(i=0;i<no;i++) str[i]=nova[i];
}

int main() {
    char str[256], vogais_letras[5]="aeiou";
    int vogais[5], i;
    for(i=0;i<5;i++){
        vogais[i]=0;
    }

    scanf("%[^\n]%*c", str);

    remove_vogais(str,vogais);
    printf("%s\n", str);

    for(i = 0; i < 5; i++) {
        printf("%c: %d\n", vogais_letras[i], vogais[i]);
    }

    return 0;
}