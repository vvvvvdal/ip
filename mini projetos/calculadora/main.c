#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main() {
    int questao = -1;
    int a_int, b_int, resultado_int;
    double a_double, b_double, resultado_double;
    long long int a_lli, b_lli, resultado_lli;
    char simbolo[5];

    while(questao != 0) {
        questao = -1;
        resultado_int = 0; resultado_double = 0.0; resultado_lli = 0;
        
        printf("\n======================================================================\n");
        printf("                   CALCULADORA MULTIFUNCIONAL EM C                    \n");
        printf("======================================================================\n");
        printf(" ARITMETICA BASICA:                BITWISE (BIT A BIT):\n");
        printf(" [1] Soma (+)                      [8] AND (&)\n");
        printf(" [2] Subtracao (-)                 [9] OR (|)\n");
        printf(" [3] Multiplicacao (*)             [10] XOR (^)\n");
        printf(" [4] Divisao (/)                   [11] Shift Right (>>)\n");
        printf(" [5] Resto (%%)                     [12] Shift Left (<<)\n");
        printf(" [6] Potencia (~)\n");
        printf(" [7] Fatorial (!)\n");
        printf("----------------------------------------------------------------------\n");
        printf(" ESTATISTICA E INTERVALOS:          COMPARACAO:\n");
        printf(" [13] Media (M)                     [16] Minimo (min)\n");
        printf(" [14] Somatorio Intervalo (S)       [17] Maximo (max)\n");
        printf(" [15] Produtorio Intervalo (P)      [18] Valor Absoluto (abs)\n");
        printf("----------------------------------------------------------------------\n");
        printf(" TESTES LOGICOS (SIM/NAO):          OPERACOES BOOLEANAS:\n");
        printf(" [19] Igualdade (==)                [25] AND Logico (&&)\n");
        printf(" [20] Diferenca (!=)                [26] NAND Logico (!&)\n");
        printf(" [21] Maior que (>)                 [27] OR Logico (||)\n");
        printf(" [22] Menor que (<)                 [28] NOR Logico (!|)\n");
        printf(" [23] Maior ou Igual (>=)\n");
        printf(" [24] Menor ou Igual (<=)\n");
        printf("======================================================================\n");
        printf(" [0] SAIR DO PROGRAMA\n");
        printf("======================================================================\n");
        printf("Digite a opcao desejada: ");
        
        scanf("%d", &questao);
        printf("\n");
        
        //system("clear"); //linux
        system("cls"); //windows

        switch (questao) {
            case 0:
                printf("encerrando o programa...\n");
                break;
            case 1:
                printf("executando a questao 1...\n");
                printf("soma (Ex: 1 + 2)\n");
                q1_soma(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 2:
                printf("executando a questao 2...\n");
                printf("subtracao (Ex: 5 - 9)\n");
                q2_subtracao(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 3:
                printf("executando a questao 3...\n");
                printf("multiplicacao (Ex: 9 * 5)\n");
                q3_multiplicacao(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 4:
                printf("executando a questao 4...\n");
                printf("divisao (Ex: 9 / 4)\n");
                q4_divisao(&a_double, &b_double, &resultado_double, simbolo);
                printf("%.3lf\n", resultado_double);
                break;
            case 5:
                printf("executando a questao 5...\n");
                printf("resto (Ex: 5 %% 8)\n");
                q5_resto(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 6:
                printf("executando a questao 6...\n");
                printf("potencia (Ex: 9 ~ 2)\n");
                q6_potencia(&a_int, &b_int, &resultado_lli, simbolo);
                if(b_int < 0) printf("Expoente Invalido\n");
                else printf("%lld\n", resultado_lli);
                break;
            case 7:
                printf("executando a questao 7...\n");
                printf("fatoracao (Ex: 6 !)\n");
                q7_fatorial(&a_lli, &resultado_lli, simbolo);
                printf("%lld\n", resultado_lli);
                break;
            case 8:
                printf("executando a questao 8...\n");
                printf("AND bit a bit (Ex: 13 & 7)\n");
                q8_and_bit_a_bit(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 9:
                printf("executando a questao 9...\n");
                printf("OR bit a bit (Ex: 13 | 7)\n");
                q9_or(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 10:
                printf("executando a questao 10...\n");
                printf("XOR bit a bit (Ex: 13 ^ 7)\n");
                q10_XOR(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 11:
                printf("executando a questao 11...\n");
                printf("shift a direita (Ex: 8 >> 2)\n");
                q11_shift_direita(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 12:
                printf("executando a questao 12...\n");
                printf("shift a esquerda (Ex: 2 << 3)\n");
                q12_shift_esquerda(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 13:
                printf("executando a questao 13...\n");
                printf("media de dois numeros (Ex: 5 M 9)\n");
                q13_media(&a_int, &b_int, &resultado_double, simbolo);
                printf("%.3lf\n", resultado_double);
                break;
            case 14:
                printf("executando a questao 14...\n");
                printf("somatorio de um intervalo (Ex: 8 S 10)\n");
                q14_somatorio_invervalo(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 15:
                printf("executando a questao 15...\n");
                printf("produtorio de um intervalo (Ex: 4 P 7)\n");
                q15_produtorio_de_um_intervalo(&a_int, &b_int, &resultado_lli, simbolo);
                printf("%lld\n", resultado_lli);
                break;
            case 16:
                printf("executando a questao 16...\n");
                printf("minimo entre dois numeros (Ex: 512 min 940)\n");
                q16_minimo(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 17:
                printf("executando a questao 17...\n");
                printf("maximo entre dois numeros (Ex: 512 max 940)\n");
                q17_max(&a_int, &b_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);   
                break;
            case 18:
                printf("executando a questao 18...\n");
                printf("valor absoluto de um numero (Ex: -9502 abs)\n");
                q18_abs(&a_int, &resultado_int, simbolo);
                printf("%d\n", resultado_int);
                break;
            case 19:
                printf("executando a questao 19...\n");
                printf("igualdade (Ex: 9 == 5)\n");
                q19_igualdade(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 20:
                printf("executando a questao 20...\n");
                printf("diferenca (Ex: 9 != 5)\n");
                q20_diferenca(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 21:
                printf("executando a questao 21...\n");
                printf("maior que (Ex: 5 > 4)\n");
                q21_maior_que(&a_int, &b_int, &resultado_int, simbolo);
                if (resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 22:
                printf("executando a questao 22...\n");
                printf("menor que (Ex: 5 < 4)\n");
                q22_menor_que(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 23:
                printf("executando a questao 23...\n");
                printf("maior ou igual (Ex: 5 >= 5)\n");
                q23_maior_igual(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 24:
                printf("executando a questao 24...\n");
                printf("menor ou igual (Ex: 5 <= 6)\n");
                q24_menor_igual(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 25:
                printf("executando a questao 25...\n");
                printf("AND Logico (Ex: 1 && 0)\n");
                q25_and(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == -1) printf("Entrada Invalida\n");
                else if (resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 26:
                printf("executando a questao 26...\n");
                printf("NAND Logico (Ex: 1 !& 0)\n");
                q26_nand(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 27:
                printf("executando a questao 27...\n");
                printf("OR Logico (Ex: 1 || 0)\n");
                q27_or(&a_int, &b_int, &resultado_int, simbolo);
                if(resultado_int == -1) printf("Entrada Invalida\n");
                else if(resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            case 28:
                printf("executando a questao 28...\n");
                printf("NOR Logico (Ex: 1 !| 0)\n");
                q28_nor(&a_int, &b_int, &resultado_int, simbolo);
                if (resultado_int == 1) printf("SIM\n");
                else printf("NAO\n");
                break;
            default:
                printf("valor invalido\n");
                break;
        }

    }

    return 0;
}