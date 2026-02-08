#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;

int main() {
    int n, i, qtdm = 0, qtdh = 0, saida_a = 0, saida_b = 0, saida_c = 0, saida_d = 0;
    scanf("%d", &n);

    FUNCIONARIO *fun = (FUNCIONARIO*)malloc(n*sizeof(FUNCIONARIO));
    double media_idades = 0.0, salmin = 1200.00, media_filhos = 0.0;

    for(i=0;i<n;i++){
        scanf("%d %d %d %c %lf", &(fun[i].matricula), &(fun[i].idade), &(fun[i].numFilhos), &(fun[i].sexo), &(fun[i].salario)); 
    }

    for(i=0;i<n;i++){
        if(fun[i].sexo == 'F') qtdm++;
        else qtdh++;
    }

    FUNCIONARIO *mul = (FUNCIONARIO*)malloc(qtdm*sizeof(FUNCIONARIO));
    FUNCIONARIO *hom = (FUNCIONARIO*)malloc(qtdh*sizeof(FUNCIONARIO));

    qtdm = 0, qtdh = 0;
    for(i=0;i<n;i++){
        if(fun[i].sexo == 'F') {
            mul[qtdm] = fun[i];
            qtdm++;
        } else {
            hom[qtdh] = fun[i];
            qtdh++;
        }
    }

    for(i=0;i<n;i++){
        media_idades += fun[i].idade;
        media_filhos += fun[i].numFilhos;
    }
    media_idades /= n;
    media_filhos /= n;

    for(i=0;i<n;i++){
        if(fun[i].idade > media_idades && fun[i].salario > 3*salmin) saida_a++;
    }

    for(i=0;i<qtdm;i++){
        if(mul[i].numFilhos > media_filhos) saida_b++;
    }

    for(i=0;i<qtdh;i++){
        if(hom[i].numFilhos > media_filhos) saida_c++;
    }

    for(i=0;i<n;i++){
        if(fun[i].idade > 47 && (fun[i].salario/(fun[i].numFilhos + 1) < 2*salmin)) saida_d++;
    }

    printf("%d %d %d %d\n", saida_a, saida_b, saida_c, saida_d);

    free(fun);
    free(mul);
    free(hom);

    return 0;
}