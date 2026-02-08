#include <stdio.h>

int main() {
    int senha, a = 321456, g = 9510753, u = 78955632;
    char tipo, adm = 'A', ger = 'G', user = 'U';
    scanf("%d %c", &senha, &tipo);

    if(senha <= 99999) { // senha menor que 6 digitos
        printf("SENHA INVALIDA: %d - MINIMO 6 DIGITOS\n", senha);
        return 0;
    }

    if(tipo == adm && senha != a) {
        printf("ACESSO NEGADO\n");
        return 0;
    } else if(tipo == ger && senha != g) {
        printf("ACESSO NEGADO\n");
        return 0;
    } else if(tipo == user && senha != u) {
        printf("ACESSO NEGADO\n");
        return 0;
    }

    if(tipo == adm && senha == a) {
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", adm);
    } else if(tipo == ger && senha == g) {
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", ger);
    } else if (tipo == user && senha == u) {
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", user);
    } else {
        printf("CATEGORIA INVALIDA: %c", tipo);
        return 0;
    }

    return 0;
}