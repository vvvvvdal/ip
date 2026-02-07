#include <stdio.h>
#include <string.h>
#define B 12221

int main() {
    int b, numeros[B], final;
    char string[B];

    scanf("%d%*c", &b);

    while(b--) {
        scanf("%d %d", &numeros[0], &final);

        int i, j, tam = (final - numeros[0]), temp = numeros[0];
        for(i = 1; i <= tam; i++) {
            numeros[i] = temp + 1;
            temp = numeros[i];
        }

        string[0] = '\0';

        for(i = tam; i >= 0; i--) {
            char orig[B], invert[B];

            sprintf(orig, "%d", numeros[i]);
            int tamo = strlen(orig), tams = strlen(string);

            for(j = 0; j < tamo; j++) {
                invert[j] = orig[tamo-1-j];
            }
            
            invert[tamo] = '\0';

            sprintf(&string[tams], "%s", invert);
        }

        for(i = 0; i <= tam; i++) {
            printf("%d", numeros[i]);
        }
        printf("%s", string);
        printf("\n");
    }

    return 0;
}