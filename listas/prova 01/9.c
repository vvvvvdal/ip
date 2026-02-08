#include <stdio.h>

double resultado(double porcentagem, int qtdPessoas, double valorTotalMensalidade) {

    double resposta = (porcentagem * qtdPessoas) * valorTotalMensalidade;

    return resposta;
}

int calcularDesconto (double salBruto, double resposta, double salLiquido) {
    int desconto;
    salLiquido = salBruto - resposta;
    double salBrutoParte = 0.3 * salBruto;

    if(salBrutoParte > salLiquido) {
        desconto = 1;
    } else {
        desconto = 0;
    }

    return desconto;
}


int main() {
    double salBruto, valorTotalMensalidade, resposta, salLiquido;
    int qtdPessoas, desconto;
    char tipoPlano;

    scanf("%lf %d %c %lf", &salBruto, &qtdPessoas, &tipoPlano, &valorTotalMensalidade);

    if(tipoPlano != 'A' && tipoPlano != 'E') {
        printf("TIPO DE PLANO INVALIDO\n");
        return 0;
    }

    // resposta /valortotalmensalidade = porcentagem.
    // mensalidade/100 * quantidade pessoas = porcentagem
    // resposta = (mensalidade/100 * quantidade pessoas) * valortotalmensalidade

    if(salBruto <= 1800.00) {
        if(tipoPlano == 'E') {
            resposta = resultado(0.25, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("ENFERMARIA %.2lf", resposta);
            }
        } else if(tipoPlano == 'A') {
            resposta = resultado(0.30, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("APARTAMENTO %.2lf", resposta);
            }
        }
    } else if(1800.00 < salBruto && salBruto <= 5000.00) {
        if(tipoPlano == 'E') {
            resposta = resultado(0.28, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("ENFERMARIA %.2lf", resposta);
            }
        } else if(tipoPlano == 'A') {
            resposta = resultado(0.35, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("APARTAMENTO %.2lf", resposta);
            }
        }
    } else if(salBruto > 5000.00) {
        if(tipoPlano == 'E') {
            resposta = resultado(0.31, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("ENFERMARIA %.2lf", resposta);
            }
        } else if(tipoPlano == 'A') {
            resposta = resultado(0.40, qtdPessoas, valorTotalMensalidade);
            salLiquido = salBruto - resposta;
            desconto = calcularDesconto(salBruto, resposta, salLiquido);
            if(desconto == 1) {
                printf("DESCONTO NAO AUTORIZADO\n");
                return 0;
            } else {
                printf("APARTAMENTO %.2lf", resposta);
            }
        }
    }

    return 0;
}