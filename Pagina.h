#ifndef PAGINA_H
#define PAGINA_H

#include "Contribuicao.h"


typedef struct pagina Pagina;
typedef struct paginas Paginas;

/*
* Função InicializaPagina :Alocadinamicamente e inicializa uma
pagina.
* Inputs: Nenhuma.
* Outputs: Ponteiro para Pagina.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Pagina retornada existe, porem esta vazia, ou sem
endereco de uma pagina existente.
*/
Pagina* InicializaPagina();

/*
* Função InicializaPaginas :Alocadinamicamente e inicializa uma lista
de paginas.
* Inputs: Nenhuma.
* Outputs: Ponteiro para lista de Paginas.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Lista retornada existe, porem esta vazia, ou sem
endereco de uma outra lista anexado.
*/
Paginas* InicializaPaginas();

/*
* Função InserePagina: Cria a pagina, alocada dinamicamente ela
inicializapagina, e a insere na lista de paginas.
* Inputs: Nome da pagina, nome do arquivo da pagina e a lista de
paginas.
* Outputs: 1 para lista inserida 0 para lista ja existente
* Pre-Condicao: Lista de paginas deve ser existente e esta alocada.
* Pos-Condicao: Lista retornada existe.
*/
int InserePagina(char* nome, char* nome_arq, Paginas* WikED);

/*
* Função InsereNomeDaPagina: Insere o nome da pagina.
* Inputs: Nome da pagina e a pagina.
* Outputs: Paginas.
* Pre-Condicao: Pagina deve ser existente e esta alocada.
* Pos-Condicao: Nenhuma
*/
Pagina* InsereNomeDaPagina(char* nome, Pagina* P);

/*
* Função InsereArquivoNaPagina: .
* Inputs: Nome do arquivo da pagina, Pagina.
* Outputs: Pagina.
* Pre-Condicao: Pagina deve ser existente e esta alocada.

* Pos-Condicao: Nenhuma.
*/
Pagina* InsereArquivoNaPagina(char* nome_arq, Pagina* P);

/*
* Função InsereContribuicao: .
* Inputs: Nome da pagina, nome do editor da pagina, nome do arquivo
da pagina, lista de paginas. .
* Outputs: retorna 1 para contribuição inserida e 0 para contribuição existente.
* Pre-Condicao: Lista de Paginas deve ser existente e esta alocada.
* Pos-Condicao: Nenhuma.
*/
int InsereContribuicao(char* nome_pagina, char* nome_editor, char* nome_arq, Paginas* Lista);

/*
* Função RetornaPagina: .
* Inputs: Nome da pagina e a lista de paginas. .
* Outputs: Pagina.
* Pre-Condicao: Lista de Paginas deve ser existente e esta alocada.
* Pos-Condicao: Nenhuma.
*/
Pagina* RetornaPagina(char* nome, Paginas* Lista);

/*
* Função VerificaCaminho: .
* Inputs: Nome da pagina de origem, nome da pagina de destino e a
lista de paginas. .
* Outputs: 1 para Ha caminho e 0 para não a caminho.
* Pre-Condicao: Lista de Paginas, Pagina de origem e Pagina de
destino deve ser existente.
* Pos-Condicao: Nenhuma.
*/
int VerificaCaminho(char* nome_origem, char* nome_destino, Paginas* Lista);

/*
* Função RetiraContribuicao: .
* Inputs: Nome da pagina, nome do editor, nome do arquivo da e a
lista de paginas. .
* Outputs: 1 para contribuicao retirada 0 para editor nao tem permissao =1 caso a contribuição não exista e -2 caso a pagina não exista.
* Pre-Condicao: Lista de Paginas deve ser existente.
* Pos-Condicao: Nenhuma.
*/
int RetiraContribuicao(char* nome_pagina, char* nome_editor, char* nome_arq, Paginas* Lista);

/*
* Função ExcluiPagina: .
* Inputs: Nome da pagina e a lista de paginas. .
* Outputs: 1 para excluida com sucesso 0 não excluida.
* Pre-Condicao: Lista de Paginas deve ser existente e esta alocada.
* Pos-Condicao: Nenhuma.
*/
int ExcluiPagina(char* nome, Paginas* Lista);

/*
* Função InsereLink: .
* Inputs: Nome da pagina de origem, nome da pagina de desino e a
lista de paginas. .
* Outputs: 1 para link inserido e 0 para link ja existente.
* Pre-Condicao: Pagina de destino, pagina de origem e lista de
paginas devem ser existentes.
* Pos-Condicao: Nenhuma.
*/
int InsereLink(char* nome_origem, char* nome_destino, Paginas* Lista);

/*
* Função RemoveLink: .
* Inputs: Nome da pagina de origem, nome da pagina de desino e a
lista de paginas. .
* Outputs: 1 para removido com sucessor, 0 para link não existente, -1 se a pagina de origem não existem, -2 se a pagina de destino não existem e -3 se as duas não existem.
* Pre-Condicao: Pagina de destino, pagina de origem e lista de
paginas devem ser existentes.
* Pos-Condicao: Nenhuma.
*/
int RemoveLink(char* nome_origem, char* nome_destino, Paginas* Lista);

/*
* Função ImprimePagina:
* Inputs: Nome da pagina e a lista de paginas. .
* Outputs: Nenhum.
* Pre-Condicao: Lista de paginas deve ser existente.
* Pos-Condicao: Nenhuma.
*/
void ImprimePagina(char* nome, Paginas* Lista);

/*
* Função ImprimeWikED: .
* Inputs: Lista de paginas. .
* Outputs: Nenhum.
* Pre-Condicao: Lista de paginas deve ser existentes
* Pos-Condicao: Nenhuma.
*/
void ImprimeWikED(Paginas* WikED);

/*
* Função LiberaPagina: .
* Inputs: Pagina.
* Outputs: Nenhum.
* Pre-Condicao: Pagina deve ser existente.
* Pos-Condicao: Pagina é liberada.
*/
void LiberaPagina(Pagina* P);

/*
* Função LiberaListaDePaginas: .
* Inputs: Lista de Pagina.
* Outputs: Nenhum.
* Pre-Condicao: Pagina deve ser existente.
* Pos-Condicao: Pagina a lista de Paginas.
*/
void LiberaListaDePaginas(Paginas* WikED);

#endif /* PAGINA_H */
//Finalizado