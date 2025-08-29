#include <stdio.h>

int main() {

    int contaCliente;
    float metroCubico;
    char tipoConsumidor;

    float calcConta;

    scanf("%d %f %c", &contaCliente, &metroCubico, &tipoConsumidor);

    if(tipoConsumidor == 'R') {
        calcConta = 5.00 + (metroCubico*0.05);
    } else if(tipoConsumidor == 'C') {
        calcConta = 500 + (0.25 * (metroCubico - 80));
    } else if(tipoConsumidor == 'I') {
        calcConta = 800 + (0.04 * (metroCubico - 100));
    }

    printf("CONTA = %d\n", contaCliente);
    printf("VALOR DA CONTA = %.2f\n", calcConta);

    return 0;
}