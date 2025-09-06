#include <stdio.h>
 
int main() {
 
    int data;
    scanf("%d", &data);
 
    int dJaneiro = 31;
    int janeiro = 1;
 
    int dFevereiro = 28;
    int fevereiro  = 2;
 
    int dMarco = 31;
    int marco = 3;
 
    int dAbril = 30;
    int abril = 4;
 
    int dMaio = 31;
    int maio = 5;
 
    int dJunho = 30;
    int junho = 6;
 
    int dJulho = 31;
    int julho = 7;
 
    int dAgosto = 31;
    int agosto = 8;
 
    int dSetembro = 30;
    int setembro = 9;
 
    int dOutubro = 31;
    int outubro = 10;
 
    int dNovembro = 30;
    int novembro = 11;
 
    int dDezembro = 31;
    int dezembro = 12;
 
    int dia = data / 1000000;
    
    int resto = data % 1000000;
    int mes = resto / 10000;
 
    int ano = resto % 10000;
 
    if(dia == 0) {
        printf("Data invalida!\n");;
    } else if (mes == 0 || mes > 12) {
        printf("Data invalida!\n");
    }
 
 
 
    if(mes == 1) {
        if(dia > dJaneiro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de janeiro de %d", dia, ano);
        }
    } else if(mes == 2) {
            if(dia > dFevereiro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de fevereiro de %d", dia, ano);
        }
    } else if(mes == 3) {
            if(dia > dMarco) {
            printf("Data invalida!\n");
        } else {
            printf("%d de marco de %d", dia, ano);
        }
    } else if(mes == 4) {
            if(dia > dAbril) {
            printf("Data invalida!\n");
        } else {
            printf("%d de abril de %d", dia, ano);
        }
    } else if(mes == 5) {
            if(dia > dMaio) {
            printf("Data invalida!\n");
        } else {
            printf("%d de maio de %d", dia, ano);
        }
    } else if(mes == 6) {
            if(dia > dJunho) {
            printf("Data invalida!\n");
        } else {
            printf("%d de junho de %d", dia, ano);
        }
    } else if(mes == 7) {
            if(dia > dJulho) {
            printf("Data invalida!\n");
        } else {
            printf("%d de julho de %d", dia, ano);
        }
    } else if(mes == 8) {
            if(dia > dAgosto) {
            printf("Data invalida!\n");
        } else {
            printf("%d de agosto de %d", dia, ano);
        }
    } else if(mes == 9) {
            if(dia > dSetembro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de setembro de %d", dia, ano);
        }
    } else if(mes == 10) {
            if(dia > dOutubro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de outubro de %d", dia, ano);
        }
    } else if(mes == 11) {
            if(dia > dNovembro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de novembro de %d", dia, ano);
        }
    } else if(mes == 12) {
            if(dia > dDezembro) {
            printf("Data invalida!\n");
        } else {
            printf("%d de dezembro de %d", dia, ano);
        }
    }
 
    return 0;
}
