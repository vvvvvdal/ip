#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Curso {
    int code;
    double val;
    char curso_nome[100];
};


struct Aluno {
    char nome[500];
    int code;
    int qtd;
};

int main() {
    int n, i, m, j;
    scanf("%d", &n);
    
    struct Curso *curso;
    curso = (struct Curso*)malloc(n*sizeof(struct Curso));

    for(i=0;i<n;i++) {
        scanf("%d", &(curso[i].code));
        scanf("%lf%*c", &(curso[i].val));
        scanf("%[^\n]%*c", curso[i].curso_nome);
    }

    scanf("%d%*c", &m);

    struct Aluno *aluno;
    aluno = (struct Aluno*)malloc(m*sizeof(struct Aluno));

    for(i=0;i<m;i++){
        scanf("%[^\n]%*c", aluno[i].nome);
        scanf("%d", &(aluno[i].code));
        scanf("%d%*c", &(aluno[i].qtd));
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(aluno[i].code == curso[j].code) {
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", aluno[i].nome, curso[j].curso_nome, aluno[i].qtd,
                curso[j].val, curso[j].val * aluno[i].qtd);
            }
        }
    }

    free(curso);
    free(aluno);

    return 0;
}