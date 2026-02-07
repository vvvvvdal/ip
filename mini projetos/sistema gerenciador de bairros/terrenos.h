#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TERRENO 100
#define TAMANHO_NUMEROS 20

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[TAMANHO_TERRENO];
    char cpf[TAMANHO_NUMEROS];
    Data data_nascimento;
    char telefone[TAMANHO_NUMEROS];
} Pessoa;

typedef struct {
    int id;
    Pessoa dono;
    Data data_compra;
    float largura;
    float comprimento;
    float area;
    float preco_m2;
} Terreno;

// funcoes auxiliares
int encontrarPosicaoPorID(Terreno **terrenos, int id);
void limparBuffer();
int verificaNome(const char *str);
int verificaCPF(const char *str);
int verificaData(int d, int m, int a);

// funcoes obrigatorias
void exibirMenu();
void inicializarVetor(Terreno ***terrenos);
void criarTerreno(Terreno **terrenos);
int adicionarTerreno(Terreno **terrenos, Pessoa dono, Data data_compra, float largura, float comprimento, float preco_m2);
void deletarTerreno(Terreno **terrenos, int id);
void mostrarTerreno(Terreno **terrenos, int id);
void editarTerreno(Terreno **terrenos, int id);
double calcularValorTerreno(Terreno **terrenos, int id);
int contarTerrenosOcupados(Terreno **terrenos);
int contarTerrenosLivres(Terreno **terrenos);
double calcularValorTotal(Terreno **terrenos);
void salvarTerrenos(Terreno **terrenos, const char *nomeArquivo);
void carregarTerrenos(Terreno **terrenos, const char *nomeArquivo);