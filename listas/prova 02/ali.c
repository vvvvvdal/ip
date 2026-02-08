#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100], ali[100];
    while(scanf("%[^\n]%*c", str) == 1) {
        int i, j, tam = strlen(str);
        for(i = 0; i < tam; i++) {
            if(str[i] != tolower(str[i])) str[i] = tolower(str[i]);
        }

        ali[0] = str[0];
        int a = 1, ctg = 0, achou = 0;

        for(i = 1; i < tam; i++) {
            if(str[i] == ' ') {
                ali[a] = str[i+1];
                a++;
            }
        }
        ali[a] = '\0';
        char letra_atual = 'z';

        for(i = 0; i < a; i++) {
            if(ali[i] == ali[i+1]) {
                if(ali[i] != letra_atual) {
                    ctg++;
                    letra_atual = ali[i];
                }
            } else {
                letra_atual = 'z';
            }
        }
        
        printf("%d\n", ctg);
    }

    return 0;
}