#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char frase[50];
 
    while(scanf("%[^\n]%*c", frase) != EOF) {
        int tam = strlen(frase);
 
        int i;
        for(i = 0; i < tam; i++) {
            if(i == 0) {
                frase[0] = toupper(frase[0]);
            } else {
                if(frase[i] == '0') {
                    continue;
                }
                
                int charAnterior = i-1;
                while(charAnterior > 0 && frase[charAnterior] == ' ') {
                    charAnterior--;
                }

                int ehMai = (frase[charAnterior] != tolower(frase[charAnterior]));

                if(ehMai) {
                    frase[i] = tolower(frase[i]);
                } else {
                    frase[i] = toupper(frase[i]);
                }
            }
        }
        printf("%s\n", frase);
 
    }
 
    return 0;
}