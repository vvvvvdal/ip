#include <stdio.h>
#include <string.h>
#define M 1002

int main() {
    int n;
    char linha[M], umPas[M], doisPas[M], tresPas[M];
    scanf("%d%*c", &n);
    
    while(n--) {
        scanf("%[^\n]%*c", linha);

        int tam = strlen(linha), i, ctg = 1;

        if(ctg == 1) {
            for(i = 0; i < tam; i++) {
                if((linha[i] >= 'a' && linha[i] <= 'z') || (linha[i] >= 'A' && linha[i] <= 'Z')) {
                    umPas[i] = linha[i] + 3;
                } else {
                    umPas[i] = linha[i];
                }
            }
            umPas[tam] = '\0';
            ctg++;
        }

        if(ctg == 2) {
            int j = 0;
            for(i = (tam-1); i >= 0; i--, j++) {
                doisPas[j] = umPas[i];
            }
            doisPas[tam] = '\0';
            ctg++;
        }

        if(ctg == 3) {
            int metade = tam/2;
            for(i = 0; i < tam; i++) {
                if(i < metade) {
                    tresPas[i] = doisPas[i];
                } else {
                    tresPas[i] = doisPas[i] - 1;
                }
            }
            tresPas[tam] = '\0';
        }

        for(i = 0; i < tam; i++) {
            printf("%c", tresPas[i]);
        }
        printf("\n");
    }


    return 0;
}