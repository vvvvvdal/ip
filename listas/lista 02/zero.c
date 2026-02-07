#include <stdio.h>
#include <string.h>
#define S 1000000

int main() {
    int mInt, nInt, somaInt;
    char somaChar[S];


    while(scanf("%d %d", &mInt, &nInt) == 2 && mInt != 0 && nInt != 0) {
        somaInt = mInt + nInt;
        sprintf(somaChar, "%d" , somaInt);

        int tam = strlen(somaChar);

        int i, j;

        for(i = 0; i < tam; i++) {
            if(somaChar[i] == '0') {
                for(j = i; j < (tam-1); j++) {
                    somaChar[j] = somaChar[j+1];
                }
                tam--;
                i--;
            }
        }

        somaChar[tam] = '\0';

        printf("%s\n", somaChar);
    }

    return 0;
}