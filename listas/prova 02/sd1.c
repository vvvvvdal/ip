#include <stdio.h>
#include <string.h>

/**
* Converte a string str para o valor real correspondente.
* @param str string contendo um número real
* @return o número inteiro correspondente
*/
double string2double( const char * str ) {
    int tam = strlen(str), i, a = 1, ehNeg = 0, ctg = 0;
    double n = 0;

    if(str[0] == '-') ehNeg = 1;

    if(ehNeg == 1) {
        for(i=0;i<tam;i++){
            if(str[i] != '.'){
                ctg++;
            } else {
                break;
            }
        }

        for(i=1;i<ctg;i++) a*=10;

        for(i=1;i<tam;i++){
            if(str[i] == '.'){
                continue;
            }

            n += (str[i]-'0') *a;
            a /= 10;
        }
        n/=10;


        printf("-%.3lf -%.3lf\n", n, n+n);
    } else {
        for(i=0;i<tam;i++){
            if(str[i] != '.'){
                ctg++;
            } else {
                break;
            }
        }

        for(i=0;i<ctg;i++) a*=10;

        for(i=0;i<tam;i++){
            if(str[i] == '.'){
                continue;
            }

            n += (str[i]-'0') *a;
            a /= 10;
        }
        n/=10;
        printf("%.3lf %.3lf\n", n, n+n);
    }

}

int main() {
    char str[128];
    while( scanf("%s", str) != EOF ) {
        string2double(str);
    }

    return 0;
}