#include <stdio.h>

int main() {
    int matricula, dependentes;
    float salMinimo, salFuncionario, taxaImposto, impostoBruto, impostoLiquido, resultado;
    scanf("%d %f %d %f %f", &matricula, &salMinimo, &dependentes, &salFuncionario, &taxaImposto);

    if(salFuncionario > 12*salMinimo) {
        impostoBruto = 0.2 * salFuncionario;
    } else if(salFuncionario > 5*salMinimo) {
        impostoBruto = 0.08 * salFuncionario;
    } else if(salFuncionario <= 5 * salMinimo) {
        impostoBruto = 0.0;
    }

    impostoLiquido = impostoBruto - (300*dependentes);
    resultado = impostoLiquido - ((taxaImposto * impostoBruto) - salFuncionario);




    printf("MATRICULA = %d\n", matricula);
    printf("IMPOSTO BRUTO = %.2f\n", impostoBruto);
    printf("IMPOSTO LIQUIDO = %.2f\n", impostoLiquido);
    printf("RESULTADO = %.2f\n", resultado);

    if(resultado < 0) {
        printf("IMPOSTO A RECEBER\n");
    } else if(resultado == 0) {
        printf("IMPOSTO QUITADO\n");
    } else if(resultado > 0) {
        printf("IMPOSTO A PAGAR\n");
    }







    return 0;
}