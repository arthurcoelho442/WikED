#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"
#include "Link.h"
#include "Contribuicao.h"

struct pagina{
    char* nome;//Nome da pagina
    char* Arq;//Nome do arquivo da pagina
    Links* L;//Lista de liks da pagina
    Historico* H;//Historico de comtribuição da pagina
    Pagina* Prox;//Ponteiro para a proxima pagina
};

struct paginas{
    Pagina* Primeiro;//Primeira pagina da lista
    Pagina* Ultimo;//Ultima pagina da lista
};

Pagina* InicializaPagina(){
    //Aloca dinamicamente a pagina
    Pagina* P = (Pagina*) malloc(sizeof(Pagina));
    
    //Aloca dinamicamente um espaco para o nome da pagina
    P->nome = (char*) malloc(sizeof(char)*100);
    
    //Aloca dinamicamente um espaco para o nome do arquivo da pagina
    P->Arq = (char*) malloc(sizeof(char)*100);
    
    //Recebe a inicializacao de uma lista de links
    P->L = InicializaListaLinks();
    
    //Recebe a inicializacao da lista de historico
    P->H = InicializaHistorico();
    
    //Defini inicialmente o ponteiro para a proxima pagina como NULL
    P->Prox = NULL;
}

Paginas* InicializaPaginas(){
    //Aloca Dinamicamente a lista de paginas
    Paginas* lista = (Paginas*)malloc(sizeof(Paginas));
    
    //Define inicialmete a lista como vazia
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
    
    return lista;
}

int InserePagina(char* nome, char* nome_arq, Paginas* WikED){    
    //Inicializa a pagina
    Pagina* P = InicializaPagina();
    
    //Insere o nome da pagina
    InsereNomeDaPagina(nome, P);
    
    //Insere nome do arquivo na pagina
    InsereArquivoNaPagina(nome_arq, P);
    
    if(RetornaPagina(P->nome, WikED) != NULL)//Verifica se a pagina ja é existente
        return 0;//retorna NULL para não alterado
    
    //Caso a lista esteja vazia 
    if(WikED->Primeiro == NULL){
        WikED->Primeiro = P;
        WikED->Ultimo = P;
    }else{//Caso a lista possua pelomenos 1 elemento
        WikED->Ultimo->Prox = P;
        WikED->Ultimo = P;
    }
    
    return 1;
}

Pagina* InsereNomeDaPagina(char* nome, Pagina* P){
    //Copia o nome da entrada para o P
    strcpy(P->nome, nome);
    
    return P;
}

Pagina* InsereArquivoNaPagina(char* nome_arq, Pagina* P){
    //Copia o nome da entrada para o P
    strcpy(P->Arq, nome_arq);
    
    return P;
}


int InsereContribuicao(char* nome_pagina, char* nome_editor, char* nome_arq, Paginas* Lista){
    Pagina* P;
    
    //Percore a lista de paginas ate achar a pagina correta
    for(P = Lista->Primeiro; P != NULL; P = P->Prox)
        if(!(strcmp(P->nome, nome_pagina))){
            //Insere o nome do editor e o nome do arquivo com a contribuicao caso ele não exista
            if(!InsereContribuicaoNoHistorico(nome_editor, nome_arq, P->H))
                return 0;
        }
    return 1;
}

Pagina* RetornaPagina(char* nome, Paginas* Lista){
    Pagina* P;
    //Percorre a lista de paginas
    for(P = Lista->Primeiro; P != NULL; P = P->Prox)
        if(!(strcmp(P->nome, nome)))//retorna a pagina
            return P;
    return NULL;
}

int InsereLink(char* nome_origem, char* nome_destino, Paginas* Lista){
    //Pega duas paginas da lista, uma pagina de oringem e uma com a de destino
    Pagina* P1 = RetornaPagina(nome_origem, Lista);
    Pagina* P2 = RetornaPagina(nome_destino, Lista);
    
    //Retorna 0 se o link já existir
    if((VerificaSeExisteLink(P1->L, P2->nome)))
        return 0;
    
    //Pega a lista de links da pagina de origem e coloca o link e nome da de destino
    ColocaNaListaDeLinks(P1->L, P2->nome, P2->Arq);
    
    return 1;
}

int VerificaCaminho(char* nome_origem, char* nome_destino, Paginas* Lista){
    //Pega a pagiana na lista
    Pagina* P = RetornaPagina(nome_origem, Lista);
    
    if(VerificaSeExisteLink(P->L, nome_destino))
        return 1;
    
    //for(;Link != NULL; Link = Link->Prox){
      //  if(VerificaSeExisteLink(Link, nome_destino))
      //      return 1;
        //else if(VerificaCaminho(Link->Nome, nome_destino));            
    //}
    
    //retorna 1 caso exista um link na pagina de origem para a de destino
    return 0;
}

int RemoveLink(char* nome_origem, char* nome_destino, Paginas* Lista){
    //Pega a pagiana na lista
    Pagina* P1 = RetornaPagina(nome_origem, Lista);
    Pagina* P2 = RetornaPagina(nome_destino, Lista);
    
    if(P1 == NULL && P2 == NULL)//Verifica se os dois existem
        return -3;
    else if(P2 == NULL)//Verifica se o destino existe
        return -2;
    else if(P1 == NULL)//Verifica se a origem existe
        return -1;
    
    //Pega a lista de liks e remove o link para a pasgina de destino
    return(RetiraDaListaDeLinks(P1->L, nome_destino));
}

int RetiraContribuicao(char* nome_pagina, char* nome_editor, char* nome_arq, Paginas* Lista){ 
    Pagina* P = RetornaPagina(nome_pagina, Lista);
    if(P == NULL)//Verifica se a pagina existe
        return -2;
    
    return (DesativaContribuicao(nome_editor, nome_arq, P->H));
}

int ExcluiPagina(char* nome, Paginas* Lista){
    Pagina* Ant;
    Pagina* P;
    
    //Anda pela lista de paginas preocurando a pagina correspomdente
    for(P = Lista->Primeiro; P != NULL; P = P->Prox){
        //Entra no if quando enconta a pagina correspondente
        if(!(strcmp(P->nome, nome))){
            //Olha se a pagina é a unica na lista
            if(P == Lista->Primeiro && P == Lista->Ultimo){
                Lista->Primeiro = NULL;
                Lista->Ultimo = NULL;
            }
            //Olha se a pagina e a primeira da lista
            else if(P == Lista->Primeiro)
                Lista->Primeiro = P->Prox;
            //Olha se a pagina e a ultima da lista
            else if(P == Lista->Ultimo){
                Lista->Ultimo = Ant;
                Ant->Prox = NULL;
            }else
                Ant->Prox = P->Prox;
            
            //Libera a Pagina
            LiberaPagina(P);
            return 1;
        }
        Ant = P;
    }
    return 0;
}

void ImprimePagina(char* nome, Paginas* Lista){
    Pagina* P = RetornaPagina(nome, Lista);
    
    //Cria arquivo com o nome da pagina
    FILE* Pag; 
    Pag = fopen(P->Arq, "w+");
    
    //Imprime o nome do arquivo
    fprintf(Pag, "%s", P->nome);
    
    fprintf(Pag, "\n\n--> Historico de contribuicoes");
    
    //Imprime o historico da pagina
    ImprimeHistorico(P->H, Pag);
    
    
    fprintf(Pag, "\n\n--> Links");
    //Imprime o links da pagina
    ImprimeLinks(P->L, Pag);
    
    //Imprime os textos de contribuicoes
    fprintf(Pag, "\n\n--> Textos\n\n");
    ImprimeComtribuicoes(P->H, Pag);
    
    
    fclose(Pag);
}

void ImprimeWikED(Paginas* WikED){
    Pagina* P;
    
    //Anda pela lista de paginas e imprime pagina por pagina
    for(P = WikED->Primeiro; P != NULL; P = P->Prox){
        ImprimePagina(P->nome, WikED);
    }
}

void LiberaPagina(Pagina* P){
    //Libera Historico
    LiberaHistorico(P->H);
    
    //Libera Links
    LiberaLinks(P->L);
    
    //Libera nome
    free(P->nome);
    
    //Libera nome do arquivo da pagina
    free(P->Arq);
    
    //Libera pagina
    free(P);
    
}

void LiberaListaDePaginas(Paginas* WikED){
    Pagina* Atual;
    Pagina* Prox;
    
    //Percore as paginas
    for(Atual = WikED->Primeiro; Atual != NULL; Atual = Prox){
        //Pega o proximo
        Prox = Atual->Prox;
        //Libera pagina
        LiberaPagina(Atual);
    }
    free(WikED);
}