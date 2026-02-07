#include <stdio.h>
#include <string.h>

struct Dicionario {
    char *pais;
    char *frase;
};

int comparar(char *str1, char *str2) {
    int tam1 = strlen(str1), tam2 = strlen(str2), i;
    
    if(tam1 != tam2) return 0;

    for(i=0;i<tam1;i++){
        if(str1[i] != str2[i]) return 0;
    }

    return 1;
}

int main() {
    struct Dicionario dicionario[24];

    dicionario[0].pais = "brasil", dicionario[0].frase = "Feliz Natal!";
    dicionario[1].pais = "alemanha", dicionario[1].frase = "Frohliche Weihnachten!";
    dicionario[2].pais = "austria", dicionario[2].frase = "Frohe Weihnacht!";
    dicionario[3].pais = "coreia", dicionario[3].frase = "Chuk Sung Tan!";
    dicionario[4].pais = "espanha", dicionario[4].frase = "Feliz Navidad!";
    dicionario[5].pais = "grecia", dicionario[5].frase = "Kala Christougena!";
    dicionario[6].pais = "estados-unidos", dicionario[6].frase = "Merry Christmas!";
    dicionario[7].pais = "inglaterra", dicionario[7].frase = "Merry Christmas!";
    dicionario[8].pais = "australia", dicionario[8].frase = "Merry Christmas!";
    dicionario[9].pais = "portugal", dicionario[9].frase = "Feliz Natal!";
    dicionario[10].pais = "suecia", dicionario[10].frase = "God Jul!";
    dicionario[11].pais = "turquia", dicionario[11].frase = "Mutlu Noeller";
    dicionario[12].pais = "argentina", dicionario[12].frase = "Feliz Navidad!";
    dicionario[13].pais = "chile", dicionario[13].frase = "Feliz Navidad!";
    dicionario[14].pais = "mexico", dicionario[14].frase = "Feliz Navidad!";
    dicionario[15].pais = "antardida", dicionario[15].frase = "Merry Christmas!";
    dicionario[16].pais = "canada", dicionario[16].frase = "Merry Christmas!";
    dicionario[17].pais = "irlanda", dicionario[17].frase = "Nollaig Shona Dhuit!";
    dicionario[18].pais = "belgica", dicionario[18].frase = "Zalig Kerstfeest!";
    dicionario[19].pais = "italia", dicionario[19].frase = "Buon Natale!";
    dicionario[20].pais = "libia", dicionario[20].frase = "Buon Natale!";
    dicionario[21].pais = "siria", dicionario[21].frase = "Milad Mubarak!";
    dicionario[22].pais = "marrocos", dicionario[22].frase = "Milad Mubarak!";
    dicionario[23].pais = "japao", dicionario[23].frase = "Merii Kurisumasu!";

    char ppais[30];
    int i, achou;

    while(scanf("%s", ppais) != EOF) {
        achou = 0;
        for(i=0;i<24;i++){
            if(comparar(ppais, dicionario[i].pais)) {
                printf("%s\n", dicionario[i].frase);
                achou = 1;
                break;
            }
        }

        if(achou == 0) {
            printf("-- NOT FOUND --\n");
        }
    }
    
    return 0;
}