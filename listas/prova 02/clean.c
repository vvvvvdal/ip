#include <stdio.h>
#include <string.h>
#define N 256

void str_clean(char *str, char *clr) {
    int tamstr = strlen(str), tamclr = strlen(clr), i, j, s = 0, achou = 0;
    char string[N];

    for(i = 0; i < tamstr; i++) {
        achou = 0;
        for(j = 0; j < tamclr; j++) {
            if(str[i] == clr[j]) {
                achou = 1;
            }
        }

        if(achou == 0) {
            string[s] = str[i];
            s++;
        }
    }

    string[s] = '\0';

    for(i = 0; i < s; i++) {
        str[i] = string[i];
    }

    for(i = 0; i < tamstr; i++) {
        if(i >= s) {
            str[i] = '\0';
        }
    }
}

int main() {
    char str[N]; // string original
    char clr[N]; // lista de caracteres indesejados
    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);
    str_clean(str, clr);
    printf("%s\n", str);

    return 0;
}