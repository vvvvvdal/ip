#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "terrenos.h"

// === IDs ===
#define ID_BTN_MENU_CRIAR 10
#define ID_BTN_MENU_LISTAR 11
#define ID_BTN_MENU_STATS 12
#define ID_BTN_MENU_SAIR 13

// IDs Criar
#define ID_EDIT_NOME 101
#define ID_EDIT_CPF 102
#define ID_EDIT_LARG 103
#define ID_EDIT_COMP 104
#define ID_EDIT_PRECO 105
#define ID_BTN_SALVAR_CRIAR 106
#define ID_LBL_CRIAR_TITLE 107
#define ID_LBL_NOME 108
#define ID_LBL_CPF 109
#define ID_LBL_LARG 110
#define ID_LBL_COMP 111
#define ID_LBL_PRECO 112
#define ID_LBL_DNASC 113
#define ID_EDIT_DNASC 114
#define ID_LBL_TEL 115
#define ID_EDIT_TEL 116
#define ID_LBL_DATACOMPRA 117
#define ID_EDIT_DATACOMPRA 118

// IDs Listar
#define ID_LISTBOX 201
#define ID_BTN_ATUALIZAR_LISTA 202

#define ID_BTN_DELETAR 203
#define ID_LBL_LISTA_TITLE 204
#define ID_BTN_DETALHES 205
#define ID_BTN_EDITAR_LISTA 206

// IDs Stats
#define ID_LBL_STATS_TITLE 300
#define ID_LBL_OCUPADOS 301
#define ID_LBL_LIVRES 302
#define ID_LBL_VALOR_TOTAL 303

// === Globais ===
Terreno **meusTerrenos; // Vetor global
int idEmEdicao = -1; // -1 = Criando, >0 = Editando ID tal

// Handles dos controles
// Menu
HWND hBtnCriar, hBtnListar, hBtnStats, hBtnSair;

// Tela Criar
HWND hNome, hCpf, hLarg, hComp, hPreco, hBtnSalvar, hLblTitleCriar;
HWND hLblNome, hLblCpf, hLblLarg, hLblComp, hLblPreco;
HWND hLblDNasc, hDNasc;
HWND hLblTel, hTel;
HWND hLblDataCompra, hDataCompra;

// Tela Listar
HWND hList, hBtnAtualizar, hBtnDeletar, hLblTitleListar, hBtnDetalhes, hBtnEditar;

// Tela Stats
HWND hLblTitleStats, hLblOcupados, hLblLivres, hLblTotal;

// === Funções Auxiliares ===

int isValidFloat(const char *str) {
    if (str == NULL || *str == '\0') return 0;
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}


void HideAll() {
    ShowWindow(hNome, SW_HIDE); ShowWindow(hCpf, SW_HIDE);
    ShowWindow(hLarg, SW_HIDE); ShowWindow(hComp, SW_HIDE);
    ShowWindow(hPreco, SW_HIDE); ShowWindow(hBtnSalvar, SW_HIDE);
    ShowWindow(hLblTitleCriar, SW_HIDE);
    ShowWindow(hLblNome, SW_HIDE); ShowWindow(hLblCpf, SW_HIDE);
    ShowWindow(hLblLarg, SW_HIDE); ShowWindow(hLblComp, SW_HIDE);
    ShowWindow(hLblPreco, SW_HIDE);
    ShowWindow(hLblDNasc, SW_HIDE); ShowWindow(hDNasc, SW_HIDE);
    ShowWindow(hLblTel, SW_HIDE); ShowWindow(hTel, SW_HIDE);
    ShowWindow(hLblDataCompra, SW_HIDE); ShowWindow(hDataCompra, SW_HIDE);

    ShowWindow(hList, SW_HIDE); ShowWindow(hBtnAtualizar, SW_HIDE);
    ShowWindow(hBtnDeletar, SW_HIDE); ShowWindow(hLblTitleListar, SW_HIDE);
    ShowWindow(hBtnDetalhes, SW_HIDE); ShowWindow(hBtnEditar, SW_HIDE);

    ShowWindow(hLblTitleStats, SW_HIDE); ShowWindow(hLblOcupados, SW_HIDE);
    ShowWindow(hLblLivres, SW_HIDE); ShowWindow(hLblTotal, SW_HIDE);
}

void ShowCriar() {
    HideAll();
    ShowWindow(hNome, SW_SHOW); ShowWindow(hCpf, SW_SHOW);
    ShowWindow(hLarg, SW_SHOW); ShowWindow(hComp, SW_SHOW);
    ShowWindow(hPreco, SW_SHOW); ShowWindow(hBtnSalvar, SW_SHOW);
    ShowWindow(hLblTitleCriar, SW_SHOW);
    ShowWindow(hLblNome, SW_SHOW); ShowWindow(hLblCpf, SW_SHOW);
    ShowWindow(hLblLarg, SW_SHOW); ShowWindow(hLblComp, SW_SHOW);
    ShowWindow(hLblPreco, SW_SHOW);
    ShowWindow(hLblDNasc, SW_SHOW); ShowWindow(hDNasc, SW_SHOW);
    ShowWindow(hLblTel, SW_SHOW); ShowWindow(hTel, SW_SHOW);
    ShowWindow(hLblDataCompra, SW_SHOW); ShowWindow(hDataCompra, SW_SHOW);

    if(idEmEdicao == -1) {
        SetWindowText(hLblTitleCriar, "--- NOVO TERRENO ---");
        SetWindowText(hBtnSalvar, "SALVAR");
        // Limpar campos
        SetWindowText(hNome, ""); SetWindowText(hCpf, "");
        SetWindowText(hLarg, ""); SetWindowText(hComp, "");
        SetWindowText(hPreco, ""); SetWindowText(hDNasc, ""); SetWindowText(hTel, "");
        SetWindowText(hDataCompra, "");
    } else {
        char buf[50];
        sprintf(buf, "--- EDITAR ID %d ---", idEmEdicao);
        SetWindowText(hLblTitleCriar, buf);
        SetWindowText(hBtnSalvar, "SALVAR ALTERACOES");
        
        // Preencher campos
        int pos = encontrarPosicaoPorID(meusTerrenos, idEmEdicao);
        if(pos != -1) {
             Terreno *t = meusTerrenos[pos];
             SetWindowText(hNome, t->dono.nome);
             SetWindowText(hCpf, t->dono.cpf);
             
             char num[50];
             sprintf(num, "%.2f", t->largura); SetWindowText(hLarg, num);
             sprintf(num, "%.2f", t->comprimento); SetWindowText(hComp, num);
             sprintf(num, "%.2f", t->preco_m2); SetWindowText(hPreco, num);
             
             sprintf(num, "%02d/%02d/%04d", t->dono.data_nascimento.dia, t->dono.data_nascimento.mes, t->dono.data_nascimento.ano);
             SetWindowText(hDNasc, num);
             
             SetWindowText(hTel, t->dono.telefone);
             
             sprintf(num, "%02d/%02d/%04d", t->data_compra.dia, t->data_compra.mes, t->data_compra.ano);
             SetWindowText(hDataCompra, num);
        }
    }
}

void AtualizarLista() {
    SendMessage(hList, LB_RESETCONTENT, 0, 0);
    for(int i=0; i<TAMANHO_TERRENO; i++) {
        if(meusTerrenos[i] != NULL) {
            char buffer[300];
            sprintf(buffer, "ID: %d | Dono: %s | %.2fx%.2f m | R$ %.2f/m2", 
                meusTerrenos[i]->id, meusTerrenos[i]->dono.nome, meusTerrenos[i]->largura, meusTerrenos[i]->comprimento, meusTerrenos[i]->preco_m2);
            int pos = SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buffer);
            SendMessage(hList, LB_SETITEMDATA, pos, (LPARAM)meusTerrenos[i]->id);
        }
    }
}

void ShowListar() {
    HideAll();
    ShowWindow(hList, SW_SHOW);
    ShowWindow(hBtnAtualizar, SW_SHOW);
    ShowWindow(hBtnDeletar, SW_SHOW);


    ShowWindow(hBtnEditar, SW_SHOW);
    ShowWindow(hLblTitleListar, SW_SHOW);
    AtualizarLista();
}

void AtualizarStats() {
    char buf[100];
    sprintf(buf, "Terrenos ocupados: %d", contarTerrenosOcupados(meusTerrenos));
    SetWindowText(hLblOcupados, buf);

    sprintf(buf, "Terrenos livres: %d", contarTerrenosLivres(meusTerrenos));
    SetWindowText(hLblLivres, buf);

    sprintf(buf, "Valor total dos terrenos: R$ %.2f", calcularValorTotal(meusTerrenos));
    SetWindowText(hLblTotal, buf);
}

void ShowStats() {
    HideAll();
    ShowWindow(hLblTitleStats, SW_SHOW);
    ShowWindow(hLblOcupados, SW_SHOW);
    ShowWindow(hLblLivres, SW_SHOW);
    ShowWindow(hLblTotal, SW_SHOW);
    AtualizarStats();
}

// === Procedimento da Janela ===
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Carregar dados
            carregarTerrenos(meusTerrenos, "dados.dat");

            // === MENU BAR (Botões no topo) ===
            CreateWindow("STATIC", "MENU:", WS_VISIBLE | WS_CHILD, 10, 10, 50, 20, hwnd, NULL, NULL, NULL);
            hBtnCriar = CreateWindow("BUTTON", "CRIAR", WS_VISIBLE | WS_CHILD, 60, 5, 80, 30, hwnd, (HMENU)ID_BTN_MENU_CRIAR, NULL, NULL);
            hBtnListar = CreateWindow("BUTTON", "LISTAR", WS_VISIBLE | WS_CHILD, 150, 5, 80, 30, hwnd, (HMENU)ID_BTN_MENU_LISTAR, NULL, NULL);
            hBtnStats = CreateWindow("BUTTON", "STATS", WS_VISIBLE | WS_CHILD, 240, 5, 80, 30, hwnd, (HMENU)ID_BTN_MENU_STATS, NULL, NULL);
            hBtnSair = CreateWindow("BUTTON", "SAIR", WS_VISIBLE | WS_CHILD, 330, 5, 80, 30, hwnd, (HMENU)ID_BTN_MENU_SAIR, NULL, NULL);

            // === TELA CRIAR ===
            hLblTitleCriar = CreateWindow("STATIC", "--- NOVO TERRENO ---", WS_CHILD, 50, 50, 200, 20, hwnd, (HMENU)ID_LBL_CRIAR_TITLE, NULL, NULL);
            
            hLblNome = CreateWindow("STATIC", "Nome:", WS_CHILD, 50, 80, 50, 20, hwnd, (HMENU)ID_LBL_NOME, NULL, NULL);
            hNome = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 110, 80, 200, 20, hwnd, (HMENU)ID_EDIT_NOME, NULL, NULL);
            
            hLblCpf = CreateWindow("STATIC", "CPF:", WS_CHILD, 50, 110, 50, 20, hwnd, (HMENU)ID_LBL_CPF, NULL, NULL);
            hCpf = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 110, 110, 150, 20, hwnd, (HMENU)ID_EDIT_CPF, NULL, NULL);
            
            hLblDNasc = CreateWindow("STATIC", "Data nasc:", WS_CHILD, 50, 140, 80, 20, hwnd, (HMENU)ID_LBL_DNASC, NULL, NULL);
            hDNasc = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 130, 140, 100, 20, hwnd, (HMENU)ID_EDIT_DNASC, NULL, NULL);

            hLblDataCompra = CreateWindow("STATIC", "Data compra:", WS_CHILD, 50, 170, 90, 20, hwnd, (HMENU)ID_LBL_DATACOMPRA, NULL, NULL);
            hDataCompra = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 150, 170, 100, 20, hwnd, (HMENU)ID_EDIT_DATACOMPRA, NULL, NULL);

            hLblTel = CreateWindow("STATIC", "Telefone:", WS_CHILD, 50, 200, 70, 20, hwnd, (HMENU)ID_LBL_TEL, NULL, NULL);
            hTel = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 120, 200, 120, 20, hwnd, (HMENU)ID_EDIT_TEL, NULL, NULL);

            hLblLarg = CreateWindow("STATIC", "Larg:", WS_CHILD, 50, 230, 50, 20, hwnd, (HMENU)ID_LBL_LARG, NULL, NULL);
            hLarg = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 110, 230, 80, 20, hwnd, (HMENU)ID_EDIT_LARG, NULL, NULL);
            
            hLblComp = CreateWindow("STATIC", "Comp:", WS_CHILD, 200, 230, 50, 20, hwnd, (HMENU)ID_LBL_COMP, NULL, NULL);
            hComp = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 250, 230, 80, 20, hwnd, (HMENU)ID_EDIT_COMP, NULL, NULL);
            
            hLblPreco = CreateWindow("STATIC", "Preco/m2:", WS_CHILD, 50, 260, 70, 20, hwnd, (HMENU)ID_LBL_PRECO, NULL, NULL);
            hPreco = CreateWindow("EDIT", "", WS_CHILD | WS_BORDER, 120, 260, 100, 20, hwnd, (HMENU)ID_EDIT_PRECO, NULL, NULL); 

            hBtnSalvar = CreateWindow("BUTTON", "SALVAR", WS_CHILD, 50, 300, 100, 30, hwnd, (HMENU)ID_BTN_SALVAR_CRIAR, NULL, NULL);

            // === TELA LISTAR ===
            hLblTitleListar = CreateWindow("STATIC", "--- LISTA DE TERRENOS ---", WS_CHILD, 50, 50, 200, 20, hwnd, (HMENU)ID_LBL_LISTA_TITLE, NULL, NULL);
            hList = CreateWindow("LISTBOX", "", WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY, 50, 80, 400, 200, hwnd, (HMENU)ID_LISTBOX, NULL, NULL);
            hBtnAtualizar = CreateWindow("BUTTON", "Atualizar", WS_CHILD, 50, 290, 80, 30, hwnd, (HMENU)ID_BTN_ATUALIZAR_LISTA, NULL, NULL);
            hBtnDeletar = CreateWindow("BUTTON", "Deletar", WS_CHILD, 140, 290, 80, 30, hwnd, (HMENU)ID_BTN_DELETAR, NULL, NULL);
            hBtnDetalhes = CreateWindow("BUTTON", "Detalhes", WS_CHILD, 230, 290, 80, 30, hwnd, (HMENU)ID_BTN_DETALHES, NULL, NULL);
            hBtnEditar = CreateWindow("BUTTON", "Editar", WS_CHILD, 320, 290, 80, 30, hwnd, (HMENU)ID_BTN_EDITAR_LISTA, NULL, NULL);

            // === TELA STATS ===
            hLblTitleStats = CreateWindow("STATIC", "--- ESTATISTICAS ---", WS_CHILD, 50, 50, 200, 20, hwnd, (HMENU)ID_LBL_STATS_TITLE, NULL, NULL);
            hLblOcupados = CreateWindow("STATIC", "Ocupados: 0", WS_CHILD, 50, 80, 200, 20, hwnd, (HMENU)ID_LBL_OCUPADOS, NULL, NULL);
            hLblLivres = CreateWindow("STATIC", "Livres: 100", WS_CHILD, 50, 110, 200, 20, hwnd, (HMENU)ID_LBL_LIVRES, NULL, NULL);
            hLblTotal = CreateWindow("STATIC", "Total: R$ 0.00", WS_CHILD, 50, 140, 300, 20, hwnd, (HMENU)ID_LBL_VALOR_TOTAL, NULL, NULL);

            // Iniciar na tela de Criar
            ShowCriar();
            break;

        case WM_COMMAND:
            // Navegação
            // Navegação
            if(LOWORD(wParam) == ID_BTN_MENU_CRIAR) {
                idEmEdicao = -1; // Reset modo criação
                ShowCriar();
            }
            if(LOWORD(wParam) == ID_BTN_MENU_LISTAR) ShowListar();
            if(LOWORD(wParam) == ID_BTN_MENU_STATS) ShowStats();
            if(LOWORD(wParam) == ID_BTN_MENU_SAIR) PostMessage(hwnd, WM_CLOSE, 0, 0);


            // Ações Tela Criar
            if(LOWORD(wParam) == ID_BTN_SALVAR_CRIAR) {
                char nome[100], cpf[20], largTxt[20], compTxt[20], precoTxt[20], dnascTxt[20], telTxt[20], dataCompraTxt[20];
                GetWindowText(hNome, nome, 100);
                GetWindowText(hCpf, cpf, 20);
                GetWindowText(hLarg, largTxt, 20);
                GetWindowText(hComp, compTxt, 20);
                GetWindowText(hPreco, precoTxt, 20);
                GetWindowText(hDNasc, dnascTxt, 20);
                GetWindowText(hTel, telTxt, 20);
                GetWindowText(hDataCompra, dataCompraTxt, 20);

                // Validação
                if (!isValidFloat(largTxt) || !isValidFloat(compTxt) || !isValidFloat(precoTxt)) {
                    MessageBox(hwnd, "Por favor, insira apenas numeros validos nos   campos de Largura, Comprimento e Preco (use ponto para decimais).", "Erro de Formatacao", MB_OK | MB_ICONWARNING);
                    return 0;
                }

                if (!verificaNome(nome)) {
                    MessageBox(hwnd, "O nome nao pode conter numeros.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                    return 0;
                }

                if (strlen(cpf) != 11 || !verificaCPF(cpf)) {
                    MessageBox(hwnd, "O CPF deve conter exatamente 11 digitos numericos.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                    return 0;
                }
                
                int d, m, a;
                if (sscanf(dnascTxt, "%d/%d/%d", &d, &m, &a) != 3) {
                     MessageBox(hwnd, "Data de Nascimento invalida. Use o formato dia/mes/ano (ex: 01/01/2000).", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                     return 0;
                }
                
                if (d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 2100) {  // Mantendo a lógica explicita aqui ou poderia usar verificaData
                     if (!verificaData(d, m, a)) {
                         MessageBox(hwnd, "Data de Nascimento invalida.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                         return 0;
                     }
                     MessageBox(hwnd, "Data de Nascimento com valores irreais.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                     return 0;
                }

                if (strlen(telTxt) != 11 || !verificaCPF(telTxt)) { // verificaCPF checa apenas digitos, serve para telefone tb
                     MessageBox(hwnd, "O Telefone deve conter exatamente 11 digitos numericos.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                     return 0;
                }

                int dc, mc, ac;
                if (sscanf(dataCompraTxt, "%d/%d/%d", &dc, &mc, &ac) != 3) {
                     MessageBox(hwnd, "Data de Compra invalida. Use o formato dia/mes/ano (ex: 01/01/2000).", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                     return 0;
                }

                if (!verificaData(dc, mc, ac)) {
                     MessageBox(hwnd, "Data de Compra com valores irreais.", "Erro de Validacao", MB_OK | MB_ICONWARNING);
                     return 0;
                }

                Pessoa p;
                strcpy(p.nome, nome);
                strcpy(p.cpf, cpf);
                strcpy(p.telefone, telTxt); 
                p.data_nascimento.dia = d; p.data_nascimento.mes = m; p.data_nascimento.ano = a;

                float l = atof(largTxt);
                float c = atof(compTxt);
                float pr = atof(precoTxt);

                if (l <= 0 || c <= 0 || pr <= 0) {
                     MessageBox(hwnd, "Os valores devem ser maiores que zero.", "Erro de Valor", MB_OK | MB_ICONWARNING);
                     return 0;
                }

                Data dataCompra = {dc, mc, ac}; 

                if (idEmEdicao == -1) {
                    // MODO CRIAR
                    int id = adicionarTerreno(meusTerrenos, p, dataCompra, l, c, pr);
                    if(id != -1) {
                        MessageBox(hwnd, "Terreno Criado!", "Sucesso", MB_OK);
                        SetWindowText(hNome, ""); SetWindowText(hCpf, "");
                        SetWindowText(hLarg, ""); SetWindowText(hComp, "");
                        SetWindowText(hPreco, ""); SetWindowText(hDNasc, ""); SetWindowText(hTel, "");
                        SetWindowText(hDataCompra, "");
                    } else {
                        MessageBox(hwnd, "Erro ao criar (Memoria Cheia?)", "Erro", MB_OK | MB_ICONERROR);
                    }
                } else {
                    // MODO EDITAR
                    int pos = encontrarPosicaoPorID(meusTerrenos, idEmEdicao);
                    if(pos != -1) {
                        meusTerrenos[pos]->dono = p;
                        meusTerrenos[pos]->largura = l;
                        meusTerrenos[pos]->comprimento = c;
                        meusTerrenos[pos]->preco_m2 = pr;
                        meusTerrenos[pos]->area = l * c;
                        meusTerrenos[pos]->data_compra = dataCompra;
                        MessageBox(hwnd, "Terreno Atualizado com Sucesso!", "Sucesso", MB_OK);
                        // Volta para lista
                        idEmEdicao = -1;
                        ShowListar();
                    } else {
                        MessageBox(hwnd, "Erro fatal: ID de edicao nao encontrado.", "Erro", MB_OK | MB_ICONERROR);
                    }
                }
            }

            // Ações Tela Listar
            if(LOWORD(wParam) == ID_BTN_ATUALIZAR_LISTA) {
                // Força o reset completo e recarregamento da visualização
                // As vezes a ListBox não redesenha só com AddString
                AtualizarLista(); 
                InvalidateRect(hList, NULL, TRUE); 
                UpdateWindow(hList);
            }
            if(LOWORD(wParam) == ID_BTN_DELETAR) {
                int index = SendMessage(hList, LB_GETCURSEL, 0, 0);
                if(index != LB_ERR) {
                    int id = SendMessage(hList, LB_GETITEMDATA, index, 0);
                    deletarTerreno(meusTerrenos, id);
                    AtualizarLista();
                    MessageBox(hwnd, "Terreno Deletado.", "Info", MB_OK);
                } else {
                    MessageBox(hwnd, "Selecione um item na lista.", "Aviso", MB_OK);
                }
            }
            
            if(LOWORD(wParam) == ID_BTN_DETALHES) {
                 int index = SendMessage(hList, LB_GETCURSEL, 0, 0);
                 if(index != LB_ERR) {
                     int id = SendMessage(hList, LB_GETITEMDATA, index, 0);
                     int pos = encontrarPosicaoPorID(meusTerrenos, id);
                     if (pos != -1) {
                         char msg[1000];
                         Terreno *t = meusTerrenos[pos];
                         sprintf(msg, 
                             "--- DADOS DO DONO ---\n"
                             "Nome: %s\n"
                             "CPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n"
                             "Data Nasc: %02d/%02d/%04d\n"
                             "Telefone: (%c%c) %c%c%c%c%c-%c%c%c%c\n\n"
                             "--- DADOS DO TERRENO ---\n"
                             "ID: %d\n"
                             "Dimensoes: %.2f x %.2f m\n"
                             "Area: %.2f m2\n"
                             "Preco por m2: R$ %.2f\n"
                             "Valor Total: R$ %.2f\n"
                             "Data Compra: %02d/%02d/%04d",
                             t->dono.nome, 
                             t->dono.cpf[0], t->dono.cpf[1], t->dono.cpf[2],
                             t->dono.cpf[3], t->dono.cpf[4], t->dono.cpf[5],
                             t->dono.cpf[6], t->dono.cpf[7], t->dono.cpf[8],
                             t->dono.cpf[9], t->dono.cpf[10],
                             t->dono.data_nascimento.dia, t->dono.data_nascimento.mes, t->dono.data_nascimento.ano,
                             t->dono.telefone[0], t->dono.telefone[1],
                             t->dono.telefone[2], t->dono.telefone[3], t->dono.telefone[4], t->dono.telefone[5], t->dono.telefone[6],
                             t->dono.telefone[7], t->dono.telefone[8], t->dono.telefone[9], t->dono.telefone[10],
                             t->id, t->largura, t->comprimento,
                             t->area, t->preco_m2,
                             calcularValorTerreno(meusTerrenos, id),
                             t->data_compra.dia, t->data_compra.mes, t->data_compra.ano
                         );
                         MessageBox(hwnd, msg, "Detalhes Completos", MB_OK | MB_ICONINFORMATION);
                     }
                 } else {
                     MessageBox(hwnd, "Selecione um item na lista.", "Aviso", MB_OK);
                 }
            } // Fechar ID_BTN_DETALHES
            if(LOWORD(wParam) == ID_BTN_EDITAR_LISTA) {
                 int index = SendMessage(hList, LB_GETCURSEL, 0, 0);
                 if(index != LB_ERR) {
                     int id = SendMessage(hList, LB_GETITEMDATA, index, 0);
                     idEmEdicao = id;
                     ShowCriar(); // Vai abrir em modo de edição
                 } else {
                     MessageBox(hwnd, "Selecione um item na lista para editar.", "Aviso", MB_OK);
                 }
            }

            break;

        case WM_CLOSE:
            if(MessageBox(hwnd, "Deseja salvar e sair?", "Sair", MB_YESNO) == IDYES) {
                salvarTerrenos(meusTerrenos, "dados.dat");
                DestroyWindow(hwnd);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int IniciarGUI() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    int nCmdShow = SW_SHOW;

    inicializarVetor(&meusTerrenos);

    const char CLASS_NAME[] = "BairrosAppClass";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Sistema Gerenciador de Bairros",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
