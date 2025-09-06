#include <stdio.h>
 
int main() {
 
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
 
    double maiorN, meioN, menorN;
 
    if(a >= b && a >= c) {
        maiorN = a;
    } else if(b >= a && b >= c) {
        maiorN = b;
    } else if(c >= a && c >= b) {
        maiorN = c;
    }
 
    if(a <= b && a <= c) {
        menorN = a;
    } else if(b <= a && b <= c){
        menorN = b;
    } else if(c <= a && c <= b) {
        menorN = c;
    }
 
    meioN = (a+b+c) - (maiorN+menorN);
 
 
    printf("%.2lf, %.2lf, %.2lf", menorN, meioN, maiorN);
 
    return 0;
}
