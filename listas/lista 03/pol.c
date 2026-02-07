#include <stdio.h>
#include <stdlib.h>

typedef struct pol {
    double termo;
    int coef;
} Pol;

void pol_leitura(Pol *p, int m) {
    int i;
    for(i=0; i<m; i++){
        scanf("%lf %d", &(p[i].termo), &(p[i].coef));
    }
}

void pol_print(Pol *p, int m){
    int i;
    if (m == 0) {
        printf("\n");
        return;
    }

    for(i=0; i<m; i++) {
        if(i > 0) {
            if(p[i].termo >= 0) printf("+");
        }
        
        printf("%.2lf", p[i].termo);

        if(p[i].coef != 0) printf("X∧%d", p[i].coef);
    }
    printf("\n");
}

void pol_soma(Pol *p1, int m1, Pol *p2, int m2, Pol *p3, int *k) {
    int i=0, j=0;
    *k=0;

    while(i<m1 && j<m2){
        if(p1[i].coef > p2[j].coef){
            p3[*k] = p1[i];
            i++; (*k)++;
        } else if(p2[j].coef > p1[i].coef) {
            p3[*k] = p2[j];
            j++; (*k)++;
        } else {
            double soma = p1[i].termo + p2[j].termo;
            if(soma != 0) {
                p3[*k].termo = soma;
                p3[*k].coef = p1[i].coef;
                (*k)++;
            }
            i++; j++;
        }
    }
    while(i < m1) { p3[*k] = p1[i]; i++; (*k)++; }
    while(j < m2) { p3[*k] = p2[j]; j++; (*k)++; }
}

void pol_sub(Pol *p1, int m1, Pol *p2, int m2, Pol *p3, int *k) {
    int i = 0, j = 0;
    *k = 0;

    while(i < m1 && j < m2) {
        if(p1[i].coef > p2[j].coef) {
            p3[*k] = p1[i];
            i++; (*k)++;
        } else if(p2[j].coef > p1[i].coef) {
            p3[*k] = p2[j];
            p3[*k].termo *= -1;
            j++; (*k)++;
        } else {
            double sub = p1[i].termo - p2[j].termo;
            if(sub != 0) {
                p3[*k].termo = sub;
                p3[*k].coef = p1[i].coef;
                (*k)++;
            }
            i++; j++;
        }
    }
    while(i < m1) { p3[*k] = p1[i]; i++; (*k)++; }
    while(j < m2) { 
        p3[*k] = p2[j]; 
        p3[*k].termo *= -1;
        j++; (*k)++; 
    }
}

int main() {
    int n, i, m1, m2, m3;
    char oper;
    
    if(scanf("%d", &n) != 1) return 0;

    for(i=0; i<n; i++){
        scanf(" %c", &oper);

        scanf("%d", &m1);
        Pol *p1 = (Pol*)malloc(m1*sizeof(Pol));
        pol_leitura(p1, m1);

        scanf("%d", &m2);
        Pol *p2 = (Pol*)malloc(m2*sizeof(Pol));
        pol_leitura(p2, m2);

        Pol *p3 = (Pol*)malloc((m1+m2)*sizeof(Pol));

        if(oper == '+') pol_soma(p1, m1, p2, m2, p3, &m3);
        else if(oper == '-') pol_sub(p1, m1, p2, m2, p3, &m3);

        pol_print(p3, m3);

        free(p1);
        free(p2);
        free(p3);
    }

    return 0;
}