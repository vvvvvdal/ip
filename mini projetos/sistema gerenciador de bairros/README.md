# Sistema Gerenciador de Bairros

Este projeto é um sistema de gerenciamento de terrenos que permite criar, listar, editar e excluir registros de terrenos. O sistema foi desenvolvido em linguagem C e possui duas interfaces de operação: via Terminal (CLI) e via Interface Gráfica (GUI, nativa Windows API).

## Link do Repositório
[https://github.com/vvvvvdal/grupo-a-mini-projeto](https://github.com/vvvvvdal/grupo-a-mini-projeto)

## Integrantes do Grupo
*   Felipe Gonçalves Vidal
*   Rafael José de Souza Marques
*   Robert Francisco Taveira

## Vídeo de Apresentação
https://www.youtube.com/watch?v=Y4vdSPOW27Q

---

## Como Compilar e Rodar

Para compilar o projeto, certifique-se de ter o GCC instalado e configurado. Como o projeto utiliza a API do Windows (`windows.h`), é necessário linkar as bibliotecas `gdi32` e `user32`.

**Comando de Compilação:**
```bash
gcc main.c gui.c terrenos.c -o sistema.exe -lgdi32 -luser32
```

### Modos de Uso

O programa detecta automaticamente qual modo iniciar baseando-se nos argumentos passados:

1.  **Modo Aplicativo:**
    Execute o programa sem nenhum argumento.
    ```bash
    ./sistema.exe
    ```
    *Uma janela será aberta com opções de Criar, Listar e Estatísticas.*

2.  **Modo Terminal:**
    Execute o programa passando o nome do arquivo de dados como argumento.
    ```bash
    ./sistema.exe dados.dat
    ```
    *O menu interativo aparecerá no terminal.*

---

## Funcionalidades Implementadas

O sistema atende a todos os requisitos propostos, gerenciando um vetor de ponteiros para estruturas `Terreno` (com limite de 100 posições).

### Estruturas de Dados
*   **Data:** Armazena dia, mês e ano.
*   **Pessoa:** Armazena nome, CPF, data de nascimento e telefone.
*   **Terreno:** Armazena ID (único), dono (struct Pessoa), data de compra (struct Data), dimensões (largura, comprimento), área e preço/m².

### Funções Principais
1.  **Inicializar Vetor:** Prepara o vetor de ponteiros inicializando com NULL.
2.  **Criar Terreno:** Aloca memória dinamicamente, valida e insere os dados.
3.  **Deletar Terreno:** Remove o terreno e libera a memória.
4.  **Mostrar Detalhes:** Exibe todas as informações de um terreno específico.
5.  **Editar Terreno:** Permite alterar largura, comprimento e preço de um terreno existente.
6.  **Calcular Valor:** Retorna o valor do terreno (Área * Preço/m²).
7.  **Contar Ocupados:** Retorna quantos terrenos estão cadastrados.
8.  **Contar Livres:** Retorna quantas vagas ainda existem no vetor.
9.  **Valor Total do Patrimônio:** Soma o valor de todos os terrenos cadastrados.
10. **Salvar/Carregar:** Persistência de dados binária em arquivo (ex: `dados.dat`).
11. **Validação de Dados:** O sistema valida Nomes (apenas letras), CPFs/Telefones (11 dígitos), Datas (calendário válido) e Valores (positivos).

---

## Exemplo de Uso (Terminal)

```text
============== SISTEMA GERENCIADOR DE BAIRROS ==============
1. Criar novo terreno
2. Deletar terreno
3. Mostrar detalhes do terreno
4. Editar terreno
5. Calcular valor de um terreno
6. Contar terrenos ocupados
7. Contar terrenos livres
8. Calcular valor total dos terrenos
9. Salvar dados agora
0. Sair e salvar
===============================================================
Escolha uma opcao:
```
