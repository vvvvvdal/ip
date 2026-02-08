#include <stdio.h>
#include <string.h>
#define N 2048

int ehDeli(char c) {
    if(c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == '(' || c == ')' || c == '{' || c == '}') {
        return 1;
    } else {
        return 0;
    }
}

int comparar(char *str1, char *str2) {
    int i, j, tam1 = strlen(str1), tam2 = strlen(str2);
    if(tam1 != tam2) return 0;

    for(i = 0; i < tam1; i++) {
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}

int main() {
    char str[N], m[20][20];
    scanf("%[^\n]%*c", str);
    int i, j = 0, tam = strlen(str), l = 0, c = 0, contagem[25], co = 0, ctg = 0;;

    for(i = 0; i <tam; i++) {
        if(ehDeli(str[i]) == 0) {
            m[l][c] = str[i];
            c++;
        } else {
            if(c > 0) {
                m[l][c] = '\0';
                l++;
                c = 0;
            }
        }
    }
    
    if(c > 0) {
        m[l][c] = '\0';
        l++;
        c = 0;
    }

    for(i = 0; i < l; i++) {
        ctg = 0;
        for(j = 1; j < l; j++) {
            if(comparar(m[i],m[j]) == 1) {
                ctg++;
            }
        }
        contagem[co] = ctg;
        co++;
    }

    for(i = 0; i < l; i++) {
        printf("(%s)%d\n", m[i], contagem[i]);
    }

    return 0;
}