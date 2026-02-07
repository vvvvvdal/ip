#include <stdio.h>
#include <string.h>
#define N 2048

int main() {
    char string[N];
    scanf("%[^\n]%*c");
    int tam = strlen(string), i, j;


    for(i = 0; i < tam; i++) {
        int ctg = 0;
        for(j = 0; j < tam; j++) {
            if(string[j] == string[i]) {
                printf("%c", string[j]);
                ctg++;
            }
        }

        printf(" %d\n", ctg);
    }










    return 0;
}