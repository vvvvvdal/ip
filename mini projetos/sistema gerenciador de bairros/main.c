#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Iniciando modo aplicativo... (Aguarde a janela abrir)\n");
        return IniciarGUI();
    }

    if (argc != 2) {
        printf("=== Bairros App ===\n");
        printf("Modo Terminal: %s <arquivo_dados>\n", argv[0]);
        printf("Modo Aplicativo:   Execute sem argumentos.\n");
        return 1;
    }
    
    const char *nomeArquivo = argv[1];
    Terreno **vetorTerrenos;
    
    inicializarVetor(&vetorTerrenos); 
    carregarTerrenos(vetorTerrenos, nomeArquivo);

    int opcao = -1;
    int id_digitado;
    
    while (opcao != 0) {
        exibirMenu();
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = -1;
            printf("Entrada invalida!\n");
            continue;
        }
        limparBuffer();
        
        switch (opcao) {
            case 1:
                criarTerreno(vetorTerrenos);
                break;
            case 2:
                printf("Digite o ID do terreno a deletar: ");
                scanf("%d", &id_digitado);
                deletarTerreno(vetorTerrenos, id_digitado);
                break;
            case 3:
                printf("Digite o ID do terreno a mostrar: ");
                scanf("%d", &id_digitado);
                mostrarTerreno(vetorTerrenos, id_digitado);
                break;
            case 4:
                printf("Digite o ID do terreno a editar: ");
                scanf("%d", &id_digitado);
                editarTerreno(vetorTerrenos, id_digitado);
                break;
            case 5:
                printf("Digite o ID do terreno para calcular o valor: ");
                scanf("%d", &id_digitado);
                double valor = calcularValorTerreno(vetorTerrenos, id_digitado);
                if (valor > 0) {
                    printf("Valor do terreno ID %d: R$ %.2f\n", id_digitado, valor);
                } else {
                    printf("Terreno não encontrado ou valor zero.\n");
                }
                break;
            case 6:
                printf("Terrenos ocupados: %d\n", contarTerrenosOcupados(vetorTerrenos));
                break;
            case 7:
                printf("Terrenos livres: %d\n", contarTerrenosLivres(vetorTerrenos));
                break;
            case 8:
                printf("Valor total: R$ %.2f\n", calcularValorTotal(vetorTerrenos));
                break;
            case 9:
                salvarTerrenos(vetorTerrenos, nomeArquivo);
                break;
            case 0:
                printf("Salvando e saindo...\n");
                salvarTerrenos(vetorTerrenos, nomeArquivo);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } 
    
    return 0;
}