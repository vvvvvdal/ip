#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int li, rt, me;
} Interacao;

int main() {
    int n, m, i, j, qtd_vazios = 0, u_li = 0, total_li = 0, u_rt = 0, total_rt = 0, u_me = 0, total_me = 0, existe = 0, qtd_u = 0;
    int u1, u2, li, rt, me;
    double media_li = 0.0, media_rt = 0.0, media_me = 0.0;

    scanf("%d", &n);
    scanf("%d", &m);

    Interacao ***in = NULL;
    in = (Interacao***)malloc(n*sizeof(Interacao**));

    for(i=0;i<n;i++){
        in[i] = (Interacao**)malloc(n*sizeof(Interacao*));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            in[i][j] = NULL;
        }
    }
    
    for(i=0;i<m;i++){
        scanf("%d %d %d %d %d", &u1, &u2, &li, &rt, &me);

        if(in[u1][u2] == NULL) {
            in[u1][u2] = (Interacao*)malloc(1*sizeof(Interacao));
        }

        in[u1][u2]->li= li;
        in[u1][u2]->rt = rt;
        in[u1][u2]->me = me;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(in[i][j] == NULL) qtd_vazios++;
        }
    }

    for(i=0;i<n;i++){
        u_li = 0, u_rt = 0, u_me = 0, existe = 0;
        for(j=0;j<n;j++){
            if(in[i][j] != NULL) {
                existe = 1;
                u_li += in[i][j]->li;
                u_rt += in[i][j]->rt;
                u_me += in[i][j]->me;
            }
        }

        total_li += u_li;
        total_rt += u_rt;
        total_me += u_me;

        if(existe == 1) {
            qtd_u++;
            printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, u_li, u_rt, u_me);
        }
    }
    media_li = (double)total_li/qtd_u;
    media_rt = (double)total_rt/qtd_u;
    media_me = (double)total_me/qtd_u;

    printf("Slots vazios: %d\n", qtd_vazios);

    printf("Media de likes por usuario: %.2lf\nMedia de retweets por usuario: %.2lf\nMedia de mencoes por usuario: %.2lf\n", media_li, media_rt, media_me);


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(in[i][j] != NULL) free(in[i][j]);
        }
        free(in[i]);
    }

    free(in);

    return 0;
}