#include <stdio.h>
#include <string.h>
#include "calculadora.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void q1_soma(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "+") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '+'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a + *b;
}

void q2_subtracao(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "-") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '-'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a - *b;
}

void q3_multiplicacao(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "*") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '*'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a * *b;
}

void q4_divisao(double *a, double *b, double *resultado, char *simbolo){
    scanf("%lf %s %lf", a, simbolo, b);
    if(strcmp(simbolo, "/") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '/'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = 1.0 * (*a) / (*b);
}

void q5_resto(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "%") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '%%'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = (*a) % (*b);
}

void q6_potencia(int *a, int *b, long long int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "~") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '~'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = 1;
    if(*b>=0){
        int expoente = *b;
        while(expoente--) *resultado *= *a;
    }
}

void q7_fatorial(long long int *a, long long int *resultado, char *simbolo) {
    scanf("%lld %s", a, simbolo);
    if(strcmp(simbolo, "!") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '!'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    int i;
    long long int fatorial = 1;
    for(i = *a; i > 0; i--) fatorial *= i;
    *resultado = fatorial;
}

void q8_and_bit_a_bit(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "&") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '&'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado= *a & *b;
}

void q9_or(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "|") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '|'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a | *b;
}

void q10_XOR(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "^") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '^'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a ^ *b;
}

void q11_shift_direita(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, ">>") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '>>'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a >> *b;
}

void q12_shift_esquerda(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "<<") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '<<'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = *a << *b;
}

void q13_media(int *a, int *b, double *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "M") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'M'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    *resultado = ((long long int)*a + (long long int)*b)/2.0;
}

void q14_somatorio_invervalo(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "S") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'S'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    int i;
    long long int soma = 0;
    for(i = *a; i <= *b; i++) soma += i;
    *resultado = soma;
}

void q15_produtorio_de_um_intervalo(int *a, int *b, long long int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "P") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'P'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    int i;
    long long int aux = 1;
    for(i = *a; i <= *b; i++){
        aux*= i;
        *resultado = aux;
    }
}

void q16_minimo(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "min") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'min'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if (*a < *b) *resultado = *a;
    else *resultado = *b;
}

void q17_max(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "max") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'max'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a > *b) *resultado = *a;
    else *resultado = *b;
}

void q18_abs(int *a, int *resultado, char *simbolo) {
    scanf("%d %s", a, simbolo);
    if(strcmp(simbolo, "abs") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: 'abs'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a < 0) *a *= -1;
    *resultado = *a;
}

void q19_igualdade(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "==") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '=='.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a == *b) *resultado = 1;
    else *resultado = 0;
}

void q20_diferenca(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "!=") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '!='.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a != *b) *resultado = 1;
    else *resultado = 0;
}

void q21_maior_que(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, ">") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '>'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a > *b) *resultado = 1;
    else *resultado = 0;
}

void q22_menor_que(int *a, int *b, int *resultado, char *simbolo){
    scanf ("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "<") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '<'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a < *b) *resultado = 1;
    else *resultado = 0;
}

void q23_maior_igual(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, ">=") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '>='.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if (*a >= *b) *resultado = 1;
    else *resultado = 0;
}

void q24_menor_igual(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "<=") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '<='.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a <= *b) *resultado = 1;
    else *resultado = 0;
}

void q25_and(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "&&") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '&&'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = -1; return;
    }
    if((*a != 0 && *a != 1) || (*b != 0 && *b != 1)) *resultado = -1;
    else if(*a == 0 || *b == 0) *resultado = 0;
    else *resultado = 1;
}

void q26_nand(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "!&") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '!&'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a == 0 && *b == 0) *resultado = 1;
    else if(*a == 0 && *b == 1) *resultado = 1;
    else if(*a == 1 && *b == 0) *resultado = 1;
    else if(*a == 1 && *b == 1) *resultado = 0;
}

void q27_or(int *a, int *b, int *resultado, char *simbolo){
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "||") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '||'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = -1; return;
    }
    if((*a != 0 && *a != 1) || (*b != 0 && *b != 1)) *resultado = -1;
    else if(*a || *b) *resultado = 1;
    else *resultado = 0;
}

void q28_nor(int *a, int *b, int *resultado, char *simbolo) {
    scanf("%d %s %d", a, simbolo, b);
    if(strcmp(simbolo, "!|") != 0) {
        printf("\n[ERRO] Caracter invalido! Esperado: '!|'.\nVoltando ao menu...\n");
        limpar_buffer(); *resultado = 0; return;
    }
    if(*a == 0 && *b == 0) *resultado = 1;
    else *resultado = 0;
}