#include <stdio.h>
#include <string.h>

int main() {
    char entrada[2000], str1[1000], str2[1000];
    scanf("%[^\n]%*c", entrada);
    int i, j, tame = strlen(entrada), tam1 = 0, tam2 = 0, ctg = 0;

    for(i = 0; i < tame; i++) {
        if(entrada[i] == ';') {
            ctg++;
            j = i;

        } else if(ctg == 0) {
            str1[tam1] = entrada[i];
            tam1++;
        }
    }
    str1[tam1] = '\0';

    if(ctg != 1) {
        printf("formato invalido\n");
        return 0;
    }

    for(i = j+1; i < tame; i++) {
        str2[tam2] = entrada[i];
        tam2++;
    }

    str2[tam2] = '\0';

    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}