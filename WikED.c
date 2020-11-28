/* 
 * File:   main.c
 * Author: arthur
 *
 * Created on 7 de Novembro de 2020, 16:05
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"


int main(int argc, char** argv) {
    //limpar a tela de saída de programa
    system("clear"); 
    
    FILE* Entrada;//Arquivo de entrada para o sistema
    FILE* Log;//Arquivo de relato dos erros ocorridos
    
    //Abre o arquivo de Entrada e o Log
    Entrada = fopen(argv[1], "r+");
    Log = fopen("log.txt", "w+");
    
    //Verifica se o arquivo de Entrada é existente
    if (Entrada == NULL)
        printf ("\n\tErro Arquivo de entrada não encontrado\n\n");
    
    //Inicializa strings alocadas dinamicamente para ler as palavras do arquivo
    char* Aux = (char*) malloc (sizeof(char)*100);
    char* Aux_2 = (char*) malloc (sizeof(char)*100);
    char* Aux_3 = (char*) malloc (sizeof(char)*100);
    int Aux_int;//varial auxiliar inteira
    
    //Inicializa Paginas da WikED
    Paginas* WikED = InicializaPaginas();
    
    while (1) {
        //Pega os primeiros caracteres ate o whitespace
        fscanf(Entrada, "%s", Aux);
        
        
        //Cria uma pagina inicialmente com nome e endereco de arquivo e a insere na WikED 
        if (!(strcmp(Aux, "INSEREPAGINA"))) {
            //Pega o nome da Pagina
            fscanf(Entrada, "%s", Aux);
            //Pega o nome do arquivo da pagina
            fscanf(Entrada, "%s", Aux_2);
            
            //retorna 1 para pagina inserida e 0 para pagina já existente
            if(!(InserePagina(Aux, Aux_2, WikED)))
                fprintf(Log, "ERRO: Pagina %s já existente\n", Aux);//printa mensagem de erro
        }else if (!(strcmp(Aux, "RETIRAPAGINA"))) {
            //Pega nome da pagina
            fscanf(Entrada, "%s", Aux);
            
            //Verifica se esta pagina existe caso nao exista entra no if
            if(!(ExcluiPagina(Aux, WikED)))
                fprintf(Log, "ERRO: não existe a pagina %s\n", Aux);
        }else if (!(strcmp(Aux, "INSEREEDITOR"))) {
////////////////////// nao feito
        }else if (!(strcmp(Aux, "RETIRAEDITOR"))) {//Opcional
/////////////////////// nao feito
        }else if (!(strcmp(Aux, "INSERECONTRIBUICAO"))) {
            //Pega o nome da Pagina
            fscanf(Entrada, "%s", Aux);
            //Pega o nome do editor
            fscanf(Entrada, "%s", Aux_2);
            //Pega o nome do arquivo da pagina
            fscanf(Entrada, "%s", Aux_3);
            if(!(InsereContribuicao(Aux, Aux_2, Aux_3, WikED)))
                fprintf(Log, "ERRO: contribuicao de %s referente a %s já existente em %s\n", Aux_2, Aux_3, Aux);//printa mensagem de erro
        }else if (!(strcmp(Aux, "RETIRACONTRIBUICAO"))) {
            //Pega o nome da Pagina
            fscanf(Entrada, "%s", Aux);
            //Pega o nome do editor
            fscanf(Entrada, "%s", Aux_2);
            //Pega o nome do arquivo da pagina
            fscanf(Entrada, "%s", Aux_3);
            printf("\n%s %s %s\n", Aux, Aux_2, Aux_3);
            
            Aux_int = RetiraContribuicao(Aux, Aux_2, Aux_3, WikED);//Variavel resebe o valor da função          
            if(!Aux_int)//Entra se editor não possue permisão
                fprintf(Log, "ERRO: editor nao tem direito de excluir esta contribuicao.\n");
            else if(Aux_int == -1)//Entra se a contribuição não existe
                fprintf(Log, "ERRO: A contribuicao de %s referente a %s não existe.\n", Aux_2, Aux_3);
            else if(Aux_int == -2)//Entra se a pagina não existe
                fprintf(Log, "ERRO: Esta pagina %s não existe.\n", Aux);
        }else if (!(strcmp(Aux, "INSERELINK"))) {
            //Pega pagina origem
            fscanf(Entrada, "%s", Aux);
            //Pega pagina destino
            fscanf(Entrada, "%s", Aux_2);
            
            //retorna 1 para link inserido e 0 para Link já existente
            if(!(InsereLink(Aux, Aux_2, WikED)))
                fprintf(Log, "ERRO: Link de %s para %s já existente\n", Aux, Aux_2);//printa mensagem de erro
            
        }else if (!(strcmp(Aux, "RETIRALINK"))) {
            //Pega pagina origem
            fscanf(Entrada, "%s", Aux);
            //Pega pagina destino
            fscanf(Entrada, "%s", Aux_2);
            if(!(RemoveLink(Aux, Aux_2, WikED)))
                fprintf(Log, "ERRO: Não existe link de %s para %s.\n", Aux, Aux_2);
            else if(RemoveLink(Aux, Aux_2, WikED) == -1)
                fprintf(Log, "ERRO: Pagina %s não existe.\n", Aux);
            else if(RemoveLink(Aux, Aux_2, WikED) == -2)
                fprintf(Log, "ERRO: Pagina %s não existe.\n", Aux_2);
            else if(RemoveLink(Aux, Aux_2, WikED) == -3)
                fprintf(Log, "ERRO: As duas paginas não existem\n");
        }else if (!(strcmp(Aux, "CAMINHO"))) {
            //Pega pagina origem
            fscanf(Entrada, "%s", Aux);
            //Pega pagina destino
            fscanf(Entrada, "%s", Aux_2);
            
            //Se a caminho entra no if
            if(VerificaCaminho(Aux, Aux_2, WikED))
                fprintf(Log, "HA CAMINHO DA PAGINA %s PARA %s\n", Aux, Aux_2);
            else
                fprintf(Log, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", Aux, Aux_2);
        }else if (!(strcmp(Aux, "IMPRIMEPAGINA"))) {
            //Pega nome da pagina
            fscanf(Entrada, "%s", Aux);
            //Imprime a pagina do arquivo
            ImprimePagina(Aux, WikED);
        }else if (!(strcmp(Aux, "IMPRIMEWIKED"))) {
            //imprime todas as paginas da lista
            ImprimeWikED(WikED);
        }else if (!(strcmp(Aux, "FIM")))
            break;
    }
    
    //Fecha os arquivos
    fclose(Entrada);
    fclose(Log);
    
    //Libera as strings auxiliares
    free(Aux);
    free(Aux_2);
    free(Aux_3);
    
    //Libera Paginas
    LiberaListaDePaginas(WikED);
    
    return (EXIT_SUCCESS);
}