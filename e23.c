#include <stdio.h>
 
int main() {
    unsigned long int code, codeMaisLucro = 0, codeMaisVendas = 0;
    float pCompra, pVenda;
    int nVendas;
    
    int qtdMenor = 0, qtdMeio = 0, qtdMaior = 0;
    float comprasTotal = 0, vendasTotal = 0;
    
    float maiorLucro = -1;
    int maiorNVendas = -1;
    
    while (scanf("%lu %f %f %d", &code, &pCompra, &pVenda, &nVendas) == 4) {
        float lucroPerc = (pVenda - pCompra) / pCompra;
        float lucroAbs = (pVenda - pCompra) * nVendas;
        
        if (lucroPerc < 0.1) {
            qtdMenor++;
        } else if (lucroPerc <= 0.2) {
            qtdMeio++;
        } else {
            qtdMaior++;
        }
        
        if (lucroAbs > maiorLucro) {
            maiorLucro = lucroAbs;
            codeMaisLucro = code;
        }
        
        if (nVendas > maiorNVendas) {
            maiorNVendas = nVendas;
            codeMaisVendas = code;
        }
        
        comprasTotal += pCompra * nVendas;
        vendasTotal += pVenda * nVendas;
    }
    
    float lucroTotal = ((vendasTotal - comprasTotal) / comprasTotal) * 100;
    
    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", qtdMenor);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", qtdMeio);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", qtdMaior);
    printf("Codigo da mercadoria que gerou maior lucro: %lu\n", codeMaisLucro);
    printf("Codigo da mercadoria mais vendida: %lu\n", codeMaisVendas);
    printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n", comprasTotal, vendasTotal, lucroTotal);
 
    return 0;
}
