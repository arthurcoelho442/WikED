#ifndef LINK_H
#define LINK_H


typedef struct link Link;
typedef struct links Links;

/*
* Função InicializaLink: .
* Inputs: Nenhum.
* Outputs: Ponteiro para link.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro alocado dinamicamente.
*/
Link* InicializaLink();

/*
* Função InicializaListaLinks: .
* Inputs: Nenhum.
* Outputs: Ponteiro para uma lista de links.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro para lista alocado dinamicamente.
*/
Links* InicializaListaLinks();

/*
* Função ColocaNaListaDeLinks: .
* Inputs: Lista de links, nome do link, nome do arquivo do link.
* Outputs: Nenhum.
* Pre-Condicao: Lista deve existir.
* Pos-Condicao: Não retorna nada porem o link e colocado na lista.
*/
void ColocaNaListaDeLinks(Links* L, char* nome, char* Arq);

/*
* Função VerificaSeExisteLink: .
* Inputs: Lista de links, o nome do link e a lista de paginas.
* Outputs: 1 para existe link na lista e 0 para não existe link na lista.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Nenhuma.
*/
int VerificaSeExisteLink(Links* L, char* nome);

//Links* RetornaListaDeLinks(char* nome, Paginas* Lista);

/*
* Função RetiraDaListaDeLinks .
* Inputs: Lista de links, nome do link a ser retirado.
* Outputs: 1 para link retirado e 0 para link não existente.
* Pre-Condicao: Link deve existir.
* Pos-Condicao: Link é retirado.
*/
int RetiraDaListaDeLinks(Links* L, char* nome);

/*
* Função ImprimeLinks.
* Inputs: Lista de links e arquivo destino.
* Outputs: Nenhum.
* Pre-Condicao: Arquido deve esta previamente aberto.
* Pos-Condicao: Lista de links e printada no arquivo.
*/
void ImprimeLinks(Links* L, FILE* Pag);

/*
* Função LiberaLink .
* Inputs: Link.
* Outputs: Nenhum.
* Pre-Condicao: Link deve existir.
* Pos-Condicao: Link é liberado.
*/
void LiberaLink(Link* C);

/*
* Função LiberaLinks.
* Inputs: Lista de links.
* Outputs: Nenhum.
* Pre-Condicao: Lista de Links deve existir.
* Pos-Condicao: Linsta de Links é liberada.
*/
void LiberaLinks(Links* L);

#endif /* LINK_H */