#include <stdio.h>
#include <string.h>
#include <math.h>

void calc_vogais(char *str, int *vogais, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        if(str[i] == 'a' || str[i] == 'A') vogais[0]++;
        else if(str[i] == 'e' || str[i] == 'E') vogais[1]++;
        else if(str[i] == 'i' || str[i] == 'I') vogais[2]++;
        else if(str[i] == 'o' || str[i] == 'O') vogais[3]++;
        else if(str[i] == 'u' || str[i] == 'U') vogais[4]++;
    }
}

int main() {
    char ent[2000], str1[1000], str2[1000];
    scanf("%[^\n]%*c", ent);
    int tame = strlen(ent), tam1 = 0, tam2 = 0, i, j, ctg = 0, vog1[5], vog2[5];
    double dist;

    for(i = 0; i<5;i++) {
        vog1[i] = 0;
        vog2[i] = 0;
    }

    for(i = 0; i < tame;i++) {
        if(ent[i] == ';') {
            ctg++;
            j = i;
        } else if(ctg == 0){
            str1[tam1] = ent[i];
            tam1++;
        }
    }
    str1[tam1] = '\0';

    if(ctg != 1) {
        printf("FORMATO INVALIDO\n");
        return 0;
    }

    for(i = j; i < tame; i++) {
        str2[tam2] = ent[i];
        tam2++;
    }
    str2[tam2] = '\0';

    calc_vogais(str1, vog1, tam1);
    calc_vogais(str2, vog2, tam2);

    printf("(");
    for(i = 0; i< 5;i++) {
        if(i == 0) printf("%d", vog1[i]);
        else printf(",%d", vog1[i]);
    }
    printf(")\n");

    printf("(");
    for(i = 0; i< 5;i++) {
        if(i == 0) printf("%d", vog2[i]);
        else printf(",%d", vog2[i]);
    }
    printf(")\n");

    for(i = 0; i < 5; i++) {
        dist += (vog1[i]-vog2[i]) * (vog1[i]-vog2[i]);
    }
    dist = sqrt(dist);
    printf("%.2lf\n", dist);

    return 0;
}