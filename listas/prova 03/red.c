#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int likes, rt, menc;
} Interacao;

int main() {
    int n, m, i, j, qtd_vazios = 0;
    // Totais GERAIS (para a média final continuar correta, dividindo por N)
    int total_likes = 0, total_rt = 0, total_menc = 0;
    
    int u1, u2, li, rt, men;
    double media_likes = 0.0, media_rt = 0.0, media_menc = 0.0;
    
    scanf("%d", &n);
    scanf("%d", &m);

    Interacao ***re = NULL;

    // Alocação da matriz principal
    re = (Interacao***)malloc(n * sizeof(Interacao**));

    for(i=0; i<n; i++){
        re[i] = (Interacao**)malloc(n*sizeof(Interacao*));
    }

    // Inicializa tudo com NULL
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            re[i][j] = NULL;
        }
    }
    
    // Leitura
    for(i=0; i<m; i++){
        scanf("%d %d %d %d %d", &u1, &u2, &li, &rt, &men);

        if (re[u1][u2] == NULL) {
             re[u1][u2] = (Interacao*)malloc(sizeof(Interacao));
        }

        re[u1][u2]->likes = li;
        re[u1][u2]->rt = rt;
        re[u1][u2]->menc = men;
    }

    // Conta vazios
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(re[i][j] == NULL) qtd_vazios++;
        }
    }

    // Loop de Impressão e Somas
    int u_likes, u_rt, u_menc;
    
    for(i=0; i<n; i++) {
        u_likes = 0; u_rt = 0; u_menc = 0; 
        int tem_interacao = 0; // FLAG: Vamos assumir que ele não existe

        for(j=0; j<n; j++){
            if(re[i][j] != NULL) {
                tem_interacao = 1; // Opa, achamos algo! Ele existe.
                u_likes += re[i][j]->likes;
                u_rt += re[i][j]->rt;
                u_menc += re[i][j]->menc;
            }
        }
        
        // Acumula nos totais GERAIS (importante fazer isso mesmo se não imprimir)
        total_likes += u_likes;
        total_rt += u_rt;
        total_menc += u_menc;

        // A MÁGICA TÁ AQUI: Só imprime se a flag for verdadeira
        if(tem_interacao == 1) {
            printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, u_likes, u_rt, u_menc);
        }
    }

    printf("Slots vazios: %d\n", qtd_vazios);

    if(n > 0) {
        media_likes = (double)total_likes / n;
        media_rt = (double)total_rt / n;
        media_menc = (double)total_menc / n;
    }

    printf("Media de likes por usuario: %.2lf\n", media_likes);
    printf("Media de retweets por usuario: %.2lf\n", media_rt);
    printf("Media de mencoes por usuario: %.2lf\n", media_menc);

    // Free
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(re[i][j] != NULL) free(re[i][j]);
        }
        free(re[i]);
    }
    free(re);

    return 0;
}