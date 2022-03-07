#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "Pagina.h"

struct contribuicao{
    char* Editor;//Nome do editor da contribuicao
    char* Arq_contribuicao;//Nome do arquivo da contribuicao
    Contribuicao* Prox;//Ponteiro para a proxima contribuicao
    int chave;//Diz se esta contribuicao esta ativa ou nao
};

struct historico{
    Contribuicao* Primeiro;//Ponteiro para a primeira contribuicao
    Contribuicao* Ultimo;//Ponteiro para a ultima contribuicao
};
Contribuicao* InicializaContribuicao(){
    //Aloca uma contribuicao dinamicamente
    Contribuicao* C = (Contribuicao*) malloc(sizeof(Contribuicao));
    
    //Aloca espaco dinamicamente para o nome do editor
    C->Editor = (char*) malloc(sizeof(char));
    
    //Aloca espaco dinamicamente para o nome do arquivo contribuido pelo editor
    C->Arq_contribuicao = (char*) malloc(sizeof(char));
    
    //Define inicialmente o ponteiro para a proxima contribuicao como NULL
    C->Prox = NULL;
    
    //Define a chave como  ativa pois no momento de insercao ela e ativa
    C->chave = 1;
    
    return C;
}

Historico* InicializaHistorico(){
    //Aloca dinamicamente uma lista do Historico
    Historico* H = (Historico*) malloc(sizeof(Historico));
    
    //Define primordialmete a lista como vazia
    H->Primeiro = NULL;
    H->Ultimo = NULL;
    
    return H;
}

Contribuicao* RetornaContribuicao(Historico* H, char* nome_editor, char* nome_arq){
    Contribuicao* C = H->Primeiro; 
    
    //Percorre o historico e retorna a contribuição caso ela exista
    for(;C != NULL; C = C->Prox)
        if(!strcpy(C->Editor, nome_editor) && !strcpy(C->Arq_contribuicao, nome_arq))
            return C;
    //Retorna NULL caso não ache
    return NULL;
}

int VerificaSeExisteContribuicaoDoEditor(Historico* H, char* nome_editor, char* nome_arq){
    //Resgata a contribuição do historico
    //Contribuicao* C = RetornaContribuicao(H, nome_editor, nome_arq);
    
    Contribuicao* C = H->Primeiro;
    //Percorre o historico e retorna a contribuição caso ela exista
    for(;C != NULL; C = C->Prox)
        if(!strcpy(C->Editor, nome_editor) && !strcpy(C->Arq_contribuicao, nome_arq))
            return 1;
    
    
    //if(C == NULL)//Verifica se não é nulo
        return 0;
    
    //return 1;
}

int InsereContribuicaoNoHistorico(char* editor, char* nome_arq, Historico* H){
    Contribuicao* C = InicializaContribuicao();
    
    //Insere o nome do editor na estrutura
    C = InsereEditor(editor, C);
    //Insere o nome do arquivo do comtribuinte
    C = InsereArquivoDoComtribuinte(nome_arq, C);
    
    //Ativa a chave se a contribuição ja estiver no historico
    for(Contribuicao* Aux = H->Primeiro; Aux != NULL; Aux = Aux->Prox)
        if(!strcmp(Aux->Editor, editor) && !strcmp(Aux->Arq_contribuicao, nome_arq)){
            if(Aux->chave)//Retorna 0 se a Contribuiao já existir
                return 0;
            Aux->chave = 1;//Ativa a chave
            return 1;
        }
    //Se o historico for vazio adiciona a contribuicao na primeira e ultima posicao
    if(H->Primeiro == NULL && H->Ultimo == NULL){
        H->Primeiro = C;
        H->Ultimo = C;
    }else{//adiciona na ultima posicao
        H->Ultimo->Prox = C;
        H->Ultimo = C;
    }
    return 1;
}

Contribuicao* InsereEditor(char* editor, Contribuicao* C){
    //Copia o nome do editor para o C
    strcpy(C->Editor, editor);
    return C;
}

Contribuicao* InsereArquivoDoComtribuinte(char* nome, Contribuicao* C){
    //Copia o nome do arquivo para o C
    strcpy(C->Arq_contribuicao, nome);
    
    return C;
}

int DesativaContribuicao(char* editor, char* nome_arq, Historico* H){
    Contribuicao* C;
    int aux = 0;//Varial auxilia para verificação de permisão do editor
    
    //Percorre o historico
    for(C = H->Primeiro; C != NULL; C = C->Prox)
        //Entra caso o nome do arquivo seja o mesmo
        if(!(strcmp(C->Arq_contribuicao, nome_arq))){
            if(!(strcmp(C->Editor, editor))){//Entra caso o editor seja o mesmo
                if(!C->chave)//verifica se a contribuição esta ativa
                    return -1;
                //Desativa a chave de contribuicao com o texto
                C->chave = 0;
                
                //Retorna 1 para desativado com sucesso
                return 1;
            }
            aux++;
        }
    if(aux!=0)
        return 0;
    return -1;
}

void ImprimeHistorico(Historico* H, FILE* Pag){
    Contribuicao* C;
    
    //Anda pela lista de contribuintes e os imprime no arquivo
    for(C = H->Primeiro; C != NULL; C = C->Prox){
        fprintf(Pag, "\n%s %s", C->Editor, C->Arq_contribuicao);
        if(!C->chave)//Se a chave for 0 imprime retirada no arquivo
            fprintf(Pag, " <<retirada>>\n");
    }
}

void ImprimeComtribuicoes(Historico* H , FILE* Pag){
    Contribuicao* C;
    
    //Anda pela lista de contribuintes e os imprime no arquivo as contribuicoes ativas
    for(C = H->Primeiro; C != NULL; C = C->Prox)
        if(C->chave){
            fprintf(Pag, "-------- %s (%s) --------\n\n", C->Arq_contribuicao, C->Editor);
            //Abre o arquivo com o texto do comtribinte
            CopiaTexto(C->Arq_contribuicao, Pag);
        }

}

void CopiaTexto(char* Arq_contribuicao, FILE* Pag){
    FILE* Cont;
    //Abre o arquivo de contribuicao
    Cont = fopen(Arq_contribuicao, "r");
    
    //Incializa um char para andar letra por letra
    char Palavra;
    
    //fica no loop ate o arquivo de contribuicao acabar
    while(!feof(Cont)){
        //Pera uma letra no arquivo de contribuicao
        fscanf(Cont, "%c", &Palavra);
        //Coloca a letra no arquivo final
        fprintf(Pag, "%c", Palavra);
    }
    
    fclose(Cont);
}

void LiberaContribuicao(Contribuicao* C){
    //Libera editor
    free(C->Editor);
    //Libera nome do arquivo
    free(C->Arq_contribuicao);
    //Libera Contribuinte
    free(C);
}

void LiberaHistorico(Historico* H){
    Contribuicao* Atual;
    Contribuicao* Prox;
    
    //Percorre todo o historico
    for(Atual = H->Primeiro; Atual != NULL; Atual = Prox){
        //Salva um ponteiro para a proxima contribuicao
        Prox = Atual->Prox;
        
        //Libera a Contribuicao
        LiberaContribuicao(Atual);
    }
    free(H);
}
//Finalizado