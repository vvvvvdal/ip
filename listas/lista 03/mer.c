#include <stdio.h>
#include <string.h>

int compara_produtos(char *str1, char *str2) {
    int tam1 = strlen(str1), tam2 = strlen(str2), i;
    
    if(tam1 != tam2) return 0;

    for(i=0;i<tam1;i++){
        if(str1[i] != str2[i]) return 0;
    }

    return 1;
}

struct Produto {
    char nome[50];
    double preco;
};

struct Pedido {
    char nome[50];
    int qtd;
};

int main() {
    int n, m, p, i,j,k;
    double total;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &m);
        struct Produto mercado[100];
        struct Pedido compras[100];

        for(j=0;j<m;j++){
            scanf("%s", mercado[j].nome);
            scanf("%lf", &(mercado[j].preco));
        }

        scanf("%d", &p);
        total = 0.0;
        
        for(j=0;j<p;j++){
            scanf("%s", compras[j].nome);
            scanf("%d", &(compras[j].qtd));
        }

        for(j=0;j<p;j++){
            for(k=0;k<m;k++){
                if(compara_produtos(mercado[k].nome,compras[j].nome)) {
                    total += compras[j].qtd*mercado[k].preco;
                }
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}