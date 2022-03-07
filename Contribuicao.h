#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

typedef struct contribuicao Contribuicao;
typedef struct historico Historico;

/*
* Função InicializaContribuicao .
* Inputs: Nenhum.
* Outputs: Ponteiro para Contribuição.
* Pre-Condicao: Nenhum.
* Pos-Condicao: Contribuição alocada dinamicamente é retornada.
*/
Contribuicao* InicializaContribuicao();

/*
* Função InicializaHistorico.
* Inputs: Nenhum.
* Outputs: Ponteiro para historico.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: lista de contribuições alocada dinamicamente é retornada.
*/
Historico* InicializaHistorico();

/*
* Função RetornaContribuicao.
* Inputs: Lista de contribuições, nome do editor e nome do arquivo de contribuição.
* Outputs: Ponteiro para o arquivo de contribuição.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Arquivo de contribuição ou nulo é retornado.
*/
Contribuicao* RetornaContribuicao(Historico* H, char* nome_editor, char* nome_arq);

/*
* Função VerificaSeExisteContribuicao: .
* Inputs: Lista de contribuiçoes , nome do editor, nome do arquivo de contribuição
* Outputs: 1 para contribuição existente e 0 para para contribuição inesistente.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Nenhuma.
*/
int VerificaSeExisteContribuicaoDoEditor(Historico* H, char* nome_editor, char* nome_arq);

/*
* Função InsereContribuicaoNoHistorico .
* Inputs: nome do editor, nome do arquivo e o historico de comtribuiçoes.
* Outputs: 1 para contribuição inserida e 0 para contribuição já existente.
* Pre-Condicao: contribuição de existir.
* Pos-Condicao: Contribuição é colocada no historico.
*/
int InsereContribuicaoNoHistorico(char* editor, char* nome_arq, Historico* H);

/*
* Função InsereEditor .
* Inputs: nome do editor e a contribuição.
* Outputs: Ponteiro da comtribuição.
* Pre-Condicao: Ponteiro de contribuição da entrada esta alocado.
* Pos-Condicao: Nenhuma.
*/
Contribuicao* InsereEditor(char* editor, Contribuicao* C);

/*
* Função InsereArquivoDoComtribuinte .
* Inputs: nome do arquivo e ponteiro da contribuição.
* Outputs: Ponteiro da contribuição.
* Pre-Condicao: Ponteiro de contribuição da entrada esta alocado.
* Pos-Condicao: Ponteiro de contribuição é alterado.
*/
Contribuicao* InsereArquivoDoComtribuinte(char* nome, Contribuicao* C);

/*
* Função InsereEditor .
* Inputs: nome do editor e a contribuição.
* Outputs: Ponteiro da comtribuição.
* Pre-Condicao: Ponteiro de contribuição da entrada esta alocado.
* Pos-Condicao: Nenhuma.
*/
int DesativaContribuicao(char* editor, char* nome_arq, Historico* H);

/*
* Função ImprimeHistorico .
* Inputs: Ponteiro do historico e arquivo destino.
* Outputs: Nenhum.
* Pre-Condicao: Arquivo de destino esta previamente aberto.
* Pos-Condicao: historico foi devidamente impresso no arquivo destino.
*/
void ImprimeHistorico(Historico* H, FILE* Pag);

/*
* Função ImprimeContribuições.
* Inputs: Ponteiro do historico e arquivo destino.
* Outputs: Nenhum.
* Pre-Condicao: Arquivo de destino esta previamente aberto.
* Pos-Condicao: Contribuição foi devidamente impresso no arquivo destino.
*/
void ImprimeComtribuicoes(Historico* H , FILE* Pag);

/*
* Função CopiaTexto .
* Inputs: nome do arquivo atual e arquivo destino.
* Outputs: Nenhum.
* Pre-Condicao: Arquivo de destino esta previamente aberto.
* Pos-Condicao: Arquivo de contribuição é impresso no arquivo destino.
*/
void CopiaTexto(char* Arq_contribuicao, FILE* Pag);

/*
* Função LiberaHistorico .
* Inputs: Ponteiro do historico.
* Outputs: Nenhum.
* Pre-Condicao: Nenhum.
* Pos-Condicao: Lista de historicos é liberada.
*/
void LiberaHistorico(Historico* H);

/*
* Função LiberaContribuicao .
* Inputs: Ponteiro de contribuição.
* Outputs: Nenhum.
* Pre-Condicao: Nenhum.
* Pos-Condicao: Contribuição é liberada.
*/
void LiberaContribuicao(Contribuicao* C);

#endif /* CONTRIBUICAO_H */
//Finalizado