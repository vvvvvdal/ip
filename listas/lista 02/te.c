#include <stdio.h>
#include <stdlib.h>

void le_vet(int **v, int nl) {
    int i;
    *v = (int*)malloc(nl*sizeof(int));

    if(*v == NULL) exit(1);

    for(i = 0; i < nl; i++) {
        scanf("%d", (*v+i));
    }
}

void pri_vet(int *v, int nl) {
    int i;
    printf("vetor:\n");
    for(i = 0; i < nl; i++) {
        printf("%d ", *(v+i));
    }
    printf("\n");
}

void fre_vet(int **v) {
    free(*v);
    *v = NULL;
}

void le_mat(int ***m, int nl, int nc) {
    int i, j;

    *m = (int**)malloc(nl*sizeof(int*));

    if(*m == NULL) exit(1);

    for(i = 0; i < nl; i++) {
        (*m)[i] = (int*)malloc(nc*sizeof(int));

        if((*m)[i] == NULL) exit(1);
    }

    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            scanf("%d", &(*m)[i][j]);
        }
    }
}

void pr_mat(int **m, int nl, int nc) {
    int i, j;

    printf("matriz:\n");

    for(i = 0; i < nl; i++) {
        for(j = 0; j < nc; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void free_mat(int ***m, int nl, int nc) {
    int i;

    for(i = 0; i < nl; i++) {
        free((*m)[i]);
    }
    free(*m);
    *m = NULL;
}

int main() {
    int nl, nc;
    int *v = NULL;
    int **m = NULL;
    scanf("%d%d", &nl, &nc);

    le_mat(&m, nl, nc);
    pr_mat(m, nl, nc);
    free_mat(&m, nl, nc);

    le_vet(&v, nl);
    pri_vet(v, nl);
    fre_vet(&v);

    return 0;
}