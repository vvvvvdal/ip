#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "terrenos.h"

int proximo_id = 1;

void limparBuffer() {
    while (getchar() != '\n');
}

int verificaNome(const char *str) {
    if (str == NULL || *str == '\0') return 0;
    while (*str) {
        if (!isalpha((unsigned char)*str) && !isspace((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

int verificaCPF(const char *str) {
    if (str == NULL || *str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

int verificaData(int d, int m, int a) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 2100) return 0;

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;

    if (m == 2 && d > 29) return 0;
    return 1;
}

void exibirMenu() {
    printf("\n============== SISTEMA GERENCIADOR DE BAIRROS ==============\n");
    printf("1. Criar novo nerreno\n");
    printf("2. Deletar terreno\n");
    printf("3. Mostrar detalhes do terreno\n");
    printf("4. Editar terreno\n");
    printf("5. Calcular valor de um terreno\n");
    printf("6. Contar terrenos ocupados\n");
    printf("7. Contar terrenos livres\n");
    printf("8. Calcular valor total dos terrenos\n");
    printf("9. Salvar dados agora\n");
    printf("0. Sair e salvar\n");
    printf("===============================================================\n");
}

int encontrarPosicaoPorID(Terreno **terrenos, int id) {
    int i;
    for (i = 0; i < TAMANHO_TERRENO; i++) {
        if (terrenos[i] != NULL && terrenos[i]->id == id) {
            return i;
        }
    }
    return -1;
}

void inicializarVetor(Terreno ***terrenos) {
    *terrenos=(Terreno **) malloc(TAMANHO_TERRENO*sizeof(Terreno*));
    
    for (int i = 0; i<TAMANHO_TERRENO;i++) {
        (*terrenos)[i]=NULL;
    }
    printf("Vetor de ponteiros inicializado com sucesso!\n");
}

void criarTerreno(Terreno **terrenos) {
    Pessoa dono;
    Data data_compra;
    float largura, comprimento, preco_m2;

    // Nome
    do {
        printf("Digite o nome do dono (apenas letras): ");
        fgets(dono.nome, TAMANHO_TERRENO, stdin);
        dono.nome[strcspn(dono.nome, "\n")] = '\0';
        if (!verificaNome(dono.nome)) {
            printf("Nome invalido! Use apenas letras e espacos.\n");
        }
    } while (!verificaNome(dono.nome));

    // CPF
    do {
        printf("Digite o CPF (apenas 11 numeros): ");
        fgets(dono.cpf, TAMANHO_NUMEROS, stdin);
        dono.cpf[strcspn(dono.cpf, "\n")] = '\0';
        if (strlen(dono.cpf) != 11 || !verificaCPF(dono.cpf)) {
            printf("CPF invalido! Deve ter exatamente 11 digitos numericos.\n");
        }
    } while (strlen(dono.cpf) != 11 || !verificaCPF(dono.cpf));

    // Telefone
    do {
        printf("Digite o telefone (apenas 11 numeros): ");
        fgets(dono.telefone, TAMANHO_NUMEROS, stdin);
        dono.telefone[strcspn(dono.telefone, "\n")] = '\0';
        if (strlen(dono.telefone) != 11 || !verificaCPF(dono.telefone)) {
            printf("Telefone invalido! Deve ter exatamente 11 digitos numericos.\n");
        }
    } while (strlen(dono.telefone) != 11 || !verificaCPF(dono.telefone));

    // Data Nascimento
    int dataValida = 0;
    do {
        printf("Digite a data de nascimento (dd/mm/aaaa): ");
        if (scanf("%d/%d/%d", &dono.data_nascimento.dia, &dono.data_nascimento.mes, &dono.data_nascimento.ano) == 3) {
            if (verificaData(dono.data_nascimento.dia, dono.data_nascimento.mes, dono.data_nascimento.ano)) {
                dataValida = 1;
            } else {
                printf("Data inexistente ou invalida!\n");
            }
        } else {
            printf("Formato invalido! Use dd/mm/aaaa.\n");
        }
        limparBuffer();
    } while (!dataValida);

    // Data Compra
    dataValida = 0;
    do {
        printf("Digite a data de compra (dd/mm/aaaa): ");
        if (scanf("%d/%d/%d", &data_compra.dia, &data_compra.mes, &data_compra.ano) == 3) {
            if (verificaData(data_compra.dia, data_compra.mes, data_compra.ano)) {
                dataValida = 1;
            } else {
                printf("Data inexistente ou invalida!\n");
            }
        } else {
            printf("Formato invalido! Use dd/mm/aaaa.\n");
        }
        limparBuffer();
    } while (!dataValida);
    
    // Largura
    do {
        printf("Digite a largura do terreno (m): ");
        if (scanf("%f", &largura) == 1 && largura > 0) break;
        printf("Valor invalido! Digite um numero positivo.\n");
        limparBuffer();
    } while (1);
    limparBuffer();

    // Comprimento
    do {
        printf("Digite o comprimento do terreno (m): ");
        if (scanf("%f", &comprimento) == 1 && comprimento > 0) break;
        printf("Valor invalido! Digite um numero positivo.\n");
        limparBuffer();
    } while (1);
    limparBuffer();

    // Preco
    do {
        printf("Digite o preco por m^2: ");
        if (scanf("%f", &preco_m2) == 1 && preco_m2 > 0) break;
        printf("Valor invalido! Digite um numero positivo.\n");
        limparBuffer();
    } while (1);
    limparBuffer(); 

    int id = adicionarTerreno(terrenos, dono, data_compra, largura, comprimento, preco_m2);

    if (id != -1) {
        printf("Terreno criado com sucesso! ID: %d\n", id);
    } else {
        printf("Erro ao criar terreno: Sem espaco ou falha de memoria.\n");
    }
}

int adicionarTerreno(Terreno **terrenos, Pessoa dono, Data data_compra, float largura, float comprimento, float preco_m2) {
    int posicao = -1;
    for (int i=0;i<TAMANHO_TERRENO;i++) {
        if(terrenos[i]==NULL) {
            posicao=i;
            break;
        }
    }

    if(posicao==-1) {
        return -1;
    }

    Terreno *novo=(Terreno*)malloc(sizeof(Terreno));
    if(novo==NULL) {
        return -1;
    }
    novo->id = proximo_id++;
    novo->dono = dono;
    novo->data_compra = data_compra;
    novo->largura = largura;
    novo->comprimento = comprimento;
    novo->preco_m2 = preco_m2;
    novo->area = largura * comprimento;
    
    terrenos[posicao] = novo;
    return novo->id;
}


void deletarTerreno(Terreno **terrenos, int id) {
    int pos = encontrarPosicaoPorID(terrenos, id);

    if (pos == -1) {
        printf("Erro: Terreno com ID %d nao encontrado.\n", id);
        return;
    }

    free(terrenos[pos]);
    
    terrenos[pos] = NULL;
    
    printf("Terreno com ID %d deletado e memoria liberada.\n", id);
}

void mostrarTerreno(Terreno **terrenos, int id) {
    int pos = encontrarPosicaoPorID(terrenos, id);

    if (pos == -1) {
        printf("Erro: Terreno com ID %d nao encontrado.\n", id);
        return;
    }

    Terreno *t = terrenos[pos];
    
    printf("\n--- Detalhes do Terreno ID %d ---\n", t->id);
    
    printf("Dono(a)\n");
    printf("Nome do dono(a): %s\n", t->dono.nome);
    printf("CPF: %s\n", t->dono.cpf);
    printf("Telefone: %s\n", t->dono.telefone);
    printf("Nascimento: %d/%d/%d\n", t->dono.data_nascimento.dia, t->dono.data_nascimento.mes, t->dono.data_nascimento.ano);
    
    printf("Data de compra: %02d/%02d/%d\n", t->data_compra.dia, t->data_compra.mes, t->data_compra.ano);
    printf("Largura: %.2f m\n", t->largura);
    printf("Comprimento: %.2f m\n", t->comprimento);
    printf("Area total: %.2f m^2\n", t->area);
    printf("Preco/m^2: R$ %.2f\n", t->preco_m2);
    
    printf("Valor total dos terrenos: R$ %.2f\n", calcularValorTerreno(terrenos, id));
    printf("--------------------------------\n");
}

void editarTerreno(Terreno **terrenos, int id) {
    int pos = encontrarPosicaoPorID(terrenos, id);

    if (pos == -1) {
        printf("Erro: Terreno com ID %d nao encontrado para edicao.\n", id);
        return;
    }
    
    Terreno *t = terrenos[pos];
    int opcao;
    float alteracao;
    
    printf("Editando Terreno ID %d (Dono: %s)\n", t->id, t->dono.nome);
    
    do {
        printf("\nO que deseja editar no Terreno ID %d?\n", id);
        printf("1. Largura (atual: %.2f m)\n", t->largura);
        printf("2. Comprimento (atual: %.2f m)\n", t->comprimento);
        printf("3. Preco por m^2 (atual: R$ %.2f)\n", t->preco_m2);
        printf("0. Finalizar edicao\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("Nova largura (m): ");
                if (scanf("%f", &alteracao) == 1 && alteracao > 0) t->largura = alteracao;
                else printf("Valor inválido ou negativo.\n");
                limparBuffer();
                break;
            case 2:
                printf("Novo comprimento (m): ");
                if (scanf("%f", &alteracao) == 1 && alteracao > 0) t->comprimento = alteracao;
                else printf("Valor invalido ou negativo.\n");
                limparBuffer();
                break;
            case 3:
                printf("Novo preco por m^2 (R$): ");
                if (scanf("%f", &alteracao) == 1 && alteracao >= 0) t->preco_m2 = alteracao;
                else printf("Valor invalido ou negativo.\n");
                limparBuffer();
                break;
            case 0:
                printf("Finalizando edicao...\n");
                break;
            default:
                printf("Opcao de edicao invalida.\n");
        }
        
        t->area = t->largura * t->comprimento; 
        
    } while (opcao != 0);

    printf("Edicao do terreno ID %d concluida. Confira novamente os dados caso precise de mais alteracoes.", id);
}

double calcularValorTerreno(Terreno **terrenos, int id) {
    double valor = 0.0;
    int pos = encontrarPosicaoPorID(terrenos, id);

    if(pos == -1) return 0.0;

    valor = terrenos[pos]->area * terrenos[pos]->preco_m2;

    return valor;
}

int contarTerrenosOcupados(Terreno **terrenos) {
    int contador=0;

    for(int i=0;i<TAMANHO_TERRENO;i++) {
        if (terrenos[i]!=NULL) {
            contador++;
        }
    }

    return contador;
}

int contarTerrenosLivres(Terreno **terrenos) {
    int contador=0;

    for (int i=0;i<TAMANHO_TERRENO;i++) {
        if (terrenos[i]==NULL) {
            contador++;
        }
    }

    return contador;
}

double calcularValorTotal(Terreno **terrenos) {
    double valor = 0.0;
    int i;
    for(i=0;i<TAMANHO_TERRENO;i++){
        if(terrenos[i] != NULL) {
            valor += calcularValorTerreno(terrenos, terrenos[i]->id);
        }
    }

    return valor;
}

void salvarTerrenos(Terreno **terrenos, const char *nomeArquivo) {
    FILE *arquivo=fopen(nomeArquivo,"wb"); 
    if (arquivo==NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i=0;i<TAMANHO_TERRENO;i++) {
        if (terrenos[i]!=NULL) {
            fwrite(terrenos[i], sizeof(Terreno), 1, arquivo);
        }
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em '%s' !\n", nomeArquivo);
}


void carregarTerrenos(Terreno **terrenos, const char *nomeArquivo) {
    FILE *arquivo=fopen(nomeArquivo, "rb");
    if (arquivo==NULL) {
        printf("Arquivo '%s' nao encontrado. Nenhum dado carregado.\n", nomeArquivo);
        return;
    }

    for (int i=0;i<TAMANHO_TERRENO;i++) {
        if (terrenos[i]!=NULL) {
            free(terrenos[i]);NULL;
        }
    }

    int posicao=0;
    while (!feof(arquivo)&&posicao<TAMANHO_TERRENO) {
        Terreno *novo=(Terreno*) malloc(sizeof(Terreno));
        if (novo==NULL) {
            printf("Erro ao alocar memoria para carregar terreno.\n");
            break;
        }

        if (fread(novo,sizeof(Terreno),1,arquivo)==1) {
            terrenos[posicao++]=novo;
            
            if(novo->id>=proximo_id) {
                proximo_id=novo->id+1;
            }
        } else {
            free(novo);
        }
    }

    fclose(arquivo);
    printf("Dados carregados com sucesso de '%s'\n", nomeArquivo);
}
