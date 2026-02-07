#include <stdio.h>
#include <string.h>
#define N 256

void str_clean(char *str, char *clr) {
    int i, j, k = 0, stam = strlen(str), ctam = strlen(clr);

    for(i = 0; i < stam; i++) {
        for(j = 0; j < ctam; j++) {
            if(clr[j] == str[i]) {
                break;
            }
        }

        if(j == ctam) {
            str[k] = str[i];
            k++;
        }
    }

    str[k] = '\0';
}

int main() {
    char str[N]; // string original
    char clr[N]; // lista de caracteres indesejados
    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);
    str_clean(str, clr) ;
    printf("%s\n", str);
    return 0;
}