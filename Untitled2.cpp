//programa que implementa uma fila FIFO
//fila emplementada na CABECA

#include <stdio.h>
#include <stdlib.h>

//estrutura
struct no {
	int numero;
	struct no *prox;
};
//variavel

struct no *cabeca = NULL;

//inserir 

void inserir(int numero){
	//instaciação
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> prox = cabeca;
	cabeca = novoNo;
}
//remover
int remover(){
	struct no *pont = cabeca;
	int retorno = 0;
	if (cabeca != NULL){
		if (cabeca -> prox == NULL){
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		}else{
			
		}
	}
	//navegação da fila ate o ultimo
	
	while (pont -> prox != NULL){
		pont = pont -> prox;
	}
	
	retorno = pont -> prox -> numero;
	struct no *temp = pont -> prox -> prox;
	pont -> prox = NULL;
	free(temp);

return retorno;
}
//funcao pricipal
int main(){
	printf("%d\n", remover());
	printf("===================");
	
	inserir(1);
	printf("%d\n", remover());
	printf("===================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	inserir(7);
	
printf("%d\n", remover());
printf("%d\n", remover());
printf("%d\n", remover());
printf("%d\n", remover());

}
