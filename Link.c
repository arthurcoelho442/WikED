#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"
#include "Pagina.h"

struct link{
    char* Nome;//Nome da pagina
    char* Arq;//Nome do arquivo da pagina 
    Link* Prox;//Ponteiro para o proximo link
};
struct links{
    Link* Primeiro;//Ponteiro para o primeiro link
    Link* Ultimo;//Ponteiro para o ultimo link
};

Link* InicializaLink(){
    //Aloca L dinamicamente como link
    Link* L = (Link*) malloc(sizeof(Link));
    
    //Aloca espaco para o nome do arquivo no link dinamicamente
    L->Arq = (char*) malloc(sizeof(char)*100);
    
    //Aloca dinamicamente o nome do link
    L->Nome = (char*) malloc(sizeof(char)*100);
    
    //Predefine o proximo link como null
    L->Prox = NULL;
    
    return L;
}


Links* InicializaListaLinks(){
    //Aloca dinamicamente a lista de links
    Links* L =  (Links*) malloc(sizeof(Links));
    
    //Defini inicialmente a lista como vazia
    L->Primeiro = NULL;
    L->Ultimo = NULL;
    
    return L;
}

int VerificaSeExisteLink(Links* L, char* nome){
    Link* C = L->Primeiro;
    /*char* Aux = (char*) malloc(sizeof(char)*100);
    Links* Lista_Aux = NULL;
    Links* Lista_Aux_2 = L;
    int cont=0;
    int cont_2=0;
    
    while (1) {
        if(Lista_Aux == L){
            cont++;
            continue;
        }
        //Percorre a lista de links atual           
        for (; C != NULL; C = C->Prox) {
            //Entra caso ache o link dentro da pagina e retorn 1
            if (!(strcmp(C->Nome, nome)))
                return 1;
        }
        
        C = Lista_Aux_2->Primeiro;
        for(int i=0;i <= cont;i++, C = C->Prox)
            Aux = C->Nome;
        
        if(C == NULL)
            break;
        
        Lista_Aux = RetornaListaDeLinks(Aux, paginas);
        C = Lista_Aux->Primeiro;
                
        cont++;
    }
    
    //Retorna 0 caso nao ache o link
    return 0;*/
    
    for (; C != NULL; C = C->Prox) {
            //Entra caso ache o link dentro da pagina e retorn 1
            if (!(strcmp(C->Nome, nome)))
                return 1;
    }
    return 0; 
}

/*Links* RetornaListaDeLinks(char* nome, Paginas* Lista){
    Pagina* P = Lista->Primeiro;
    for(int i=0; P != NULL; i++, P = P->Prox)
        if(!(strcpy(P->nome, nome)))
            return P->L;
}*/

void ColocaNaListaDeLinks(Links* L, char* nome, char* Arq){
    Link* C = InicializaLink();
    
    //Copia o nome da entrada para o link
    strcpy(C->Nome, nome);
    
    //Copia o nome do arquivo para o link
    strcpy(C->Arq, Arq);
    
    //Se a lista for vazia coloca o link no primeiro e ultimo lugar
    if(L->Primeiro == NULL && L->Ultimo == NULL){
        L->Primeiro = C;
        L->Ultimo = C;
    }else{//Coloca na ultima posicao da lista
        L->Ultimo->Prox = C;
        L->Ultimo = C;
    }
}

int RetiraDaListaDeLinks(Links* L, char* nome){
    Link* C;
    Link* Ant;
    
    //Percorre a lista de links
    for(C = L->Primeiro; C != NULL; C = C->Prox){
        //entra no if se o nome do link e o mesmo que o da entrada
        if(!(strcmp(C->Nome, nome))){
            //Entra se a lista for vazia
            if(C == L->Primeiro && C == L->Ultimo){
                L->Primeiro = NULL;
                L->Ultimo = NULL;
            }else if(C == L->Primeiro){//entra caso o link seja o primeiro da lista
                L->Primeiro = L->Primeiro->Prox;
            }else if(C == L->Ultimo){//entra caso o link seja o ultimo da lista
                Ant->Prox = NULL;
                L->Ultimo= Ant;
            }else{
                Ant->Prox = C->Prox;
            }
            //Libera o link
            LiberaLink(C);
            return 1;
        }
        Ant = C;
    }
    return 0;
}

void ImprimeLinks(Links* L, FILE* Pag){
        Link* C;
    
    //Anda pela lista de contribuintes e os imprime no arquivo
    for(C = L->Primeiro; C != NULL; C = C->Prox)
        fprintf(Pag, "\n%s %s", C->Nome, C->Arq);
}

void LiberaLink(Link* C){
    free(C->Arq);//Libera nome do arquivo
    free(C->Nome);//Libera o nome do link
    free(C);//Libera o link
}

void LiberaLinks(Links* Lista){
    Link* Atual;
    Link* Prox;
    
    //Percorre todos os links da lista e os exclue
    for(Atual = Lista->Primeiro; Atual != NULL; Atual = Prox){
        //Pega o proximo link
        Prox = Atual->Prox;
        //Libera o link
        LiberaLink(Atual);
    }
    free(Lista);
}
//Finalizado