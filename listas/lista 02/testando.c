#include <stdio.h>
#include <stdlib.h>

// --- Protótipos das Funções ---
void le_vect(int **v, int n);
void print_vect(int *v, int n);
void limpa_vect(int **v);

void le_matriz(int ***m, int n, int k);
void print_matriz(int **m, int n, int k);
void limpa_matriz(int ***m, int n);

// --- Função Principal ---
int main() {
    int n;
    int *v = NULL;
    int **m = NULL;

    printf("Digite o tamanho N (para o vetor e matriz N x N): ");
    
    // --- Verificação de Entrada Segura ---
    if (scanf("%d", &n) != 1) {
        printf("Erro: Entrada invalida. Por favor, digite um numero.\n");
        return 1;
    }
    if (n <= 0) {
        printf("Erro: O tamanho N deve ser um numero positivo (maior que 0).\n");
        return 1;
    }
    // --- Fim da Verificação ---


    // --- Seção do Vetor ---
    printf("\n--- Lendo Vetor (tamanho %d) ---\n", n);
    le_vect(&v, n);
    
    printf("Vetor lido: ");
    print_vect(v, n);
    
    limpa_vect(&v); // Libera 'v' e aponta para NULL

    // --- Seção da Matriz ---
    printf("\n--- Lendo Matriz %dx%d ---\n", n, n);
    le_matriz(&m, n, n); // Passando 'n' para linhas (n) e 'n' para colunas (k)
    
    printf("Matriz lida:\n");
    print_matriz(m, n, n);
    
    limpa_matriz(&m, n); // Libera 'm' e aponta para NULL
    
    printf("\nPrograma finalizado com sucesso.\n");
    return 0;
}

// --- Funções do Vetor ---

void le_vect(int **v, int n) {
    *v = (int*)malloc(n * sizeof(int));
    
    if (*v == NULL) {
        printf("Erro: Falha na alocacao de memoria para o vetor!\n");
        exit(1); 
    }
    
    printf("Digite os %d elementos do vetor:\n", n);
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", (*v + i)); 
    }
}

void print_vect(int *v, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", *(v+i)); 
    }
    printf("\n");
}

void limpa_vect(int **v) {
    free(*v);
    *v = NULL; 
}


// --- Funções da Matriz ---

void le_matriz(int ***m, int n, int k) {

    *m = (int**)malloc(n * sizeof(int*));
    
    if (*m == NULL) {
        printf("Erro: Falha na alocacao das linhas da matriz!\n");
        exit(1);
    }
    
    int i, j;
    
    for(i = 0; i < n; i++) { 
        (*m)[i] = (int*)malloc(k * sizeof(int)); 
        
        if ((*m)[i] == NULL) {
            printf("Erro: Falha na alocacao da coluna %d da matriz!\n", i);
            exit(1);
        }
    }

    printf("Digite os %d elementos da matriz (%dx%d):\n", n*k, n, k);
    for(i = 0; i < n; i++) {
        for(j = 0; j < k; j++) {
            scanf("%d", &(*m)[i][j]);
        }
    }
}

void print_matriz(int **m, int n, int k) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < k; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void limpa_matriz(int ***m, int n) {
    int i;
    
    // 1. Libera cada vetor de coluna (as 'n' linhas)
    for(i = 0; i < n; i++) {
        free((*m)[i]);
    }
    
    // 2. Libera o vetor de ponteiros (o "armário")
    free(*m);
    
    // 3. Aponta o ponteiro da main para NULL
    *m = NULL;
}