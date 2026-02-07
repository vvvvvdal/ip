#include <stdio.h>
#include <string.h>
#define N 10000

int main() {
    int t;
    scanf("%d%*c", &t);
    if(t < 0 || t > 100) return 0;

    while(t--) {
        char astring[N], bstring[N], letra;
        scanf("%s %s", astring, bstring);
        
        int ctg = 0, tam = strlen(astring), i;

        for(i = 0; i < tam; i++) {
            letra = astring[i];
            while(letra != bstring[i]) {
                letra++;

                if (letra > 'z') {
                    letra = 'a';
                }

                ctg++;
            }
        }

        printf("%d\n", ctg);
    }

    return 0;
}