#include <stdio.h>
#include <string.h>

int ehDel(char c) {
    int i;
    char del[11] = " .,!?()[]{}";

    for(i=0;i<11;i++) {
        if(c == del[i]) return 1;
    }

    return 0;
}

int comp_str(char *str1, char *str2) {
    int tam1 = strlen(str1), tam2 = strlen(str2), i;
    if(tam1 != tam2) return 0;

    for(i=0;i<tam1;i++){
        if(str1[i]!=str2[i]) return 0;
    }
    return 1;
}

int main() {
    char str[2048], m[200][65];
    scanf("%[^\n]%*c", str);
    int tamstr = strlen(str), i,j,l = 0,c = 0;

    for(i=0;i<tamstr;i++) {
        if(ehDel(str[i]) == 0) {
            m[l][c] = str[i];
            c++;
        } else {
            if(c>0){
                m[l][c] = '\0';
                l++;
                c = 0;
            }
        }
    }

    if(c>0){
        m[l][c] = '\0';
        l++;
        c = 0;
    }

    int qtd[l];

    for(i=0;i<l;i++){
        qtd[i] = 0;
    }

    for(i=0;i<l;i++){
        for(j=0;j<l;j++) {
            if(comp_str(m[i], m[j]) == 1) {
                qtd[i]++;
            }
        }
    }

    for(i=0;i<l;i++){
        printf("(%s)%d\n", m[i], qtd[i]);
    }

    return 0;
}