#include <stdio.h>

int main() {
    int dia, mes, ano, anoBissexto = 1;
    int dJan = 31, dFev = 28, dMarc = 31, dAbr = 30, dMai = 31, dJun = 30, dJul = 31, dAgo = 31, dSet = 30, dOct = 31, dNov = 30, dDez = 31;
    int mJan = 1, mFev = 2, mMarc = 3, mAbr = 4, mMai = 5, mJun = 6, mJul = 7, mAgo = 8, mSet = 9, mOct = 10, mNov = 11, mDez = 12;

    scanf("%d %d %d", &dia, &mes, &ano);

    if(ano < 1900) {
        printf("DATA FORA DO INTERVALO ESTIPULADO\n");
        return 0;
    } else if(ano > 2036) {
        printf("DATA FORA DO INTERVALO ESTIPULADO\n");
        return 0;
    }

    if(ano%4 == 0 && ano%100 == 0) {
        anoBissexto = 0;
    } else if(ano%4 == 0 && ano%100 != 0) {
        anoBissexto = 1;
        dFev = 29;
    } else if(ano%400 == 0 && ano%100 == 0) {
        anoBissexto = 1;
        dFev = 29;
    } else {
        anoBissexto = 0;
    }

    if(mes == 1 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 2 && anoBissexto == 1 && dia > 29) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 2 && anoBissexto == 0 && dia > 28) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 3 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 4 && dia > 30) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 5 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 6 && dia > 30) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 7 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 8 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 9 && dia > 30) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 10 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 11 && dia > 30) {
        printf("DATA INVALIDA\n");
        return 0;
    } else if(mes == 12 && dia > 31) {
        printf("DATA INVALIDA\n");
        return 0;
    }

    printf("%02d/%02d/%d\n", dia, mes, ano);

    return 0;
}