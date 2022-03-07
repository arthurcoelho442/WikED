#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.

compile:
	gcc WikED.c Pagina.c Link.c Contribuicao.c	
	
run:
	./a.out entrada.txt
	
compile-run:
	gcc WikED.c Pagina.c Link.c Contribuicao.c
	./a.out entrada.txt
	
valgrind:
	gcc WikED.c Pagina.c Link.c Contribuicao.c
	valgrind ./a.out entrada.txt

#Finalizado