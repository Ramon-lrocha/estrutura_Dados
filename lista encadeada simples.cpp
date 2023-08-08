//programa de lista encadeada simples

#include <stdio.h>
#include <stdlib.h>


//definir estrutura

struct no{
	int numero;
	struct no *proximo;
};
//decalrar variavel

struct no *cabeca;

//para endereçar o conteudo apontado pelo ponteiro eu uso " -> "

//funcao para inserir elemento na lista

void inserir(int parametronumero){
	//novo no
	struct no *novoNo = NULL;
	novoNo = (struct no*) malloc(sizeof(struct no*));
	novoNo -> numero = parametronumero;
    novoNo -> proximo = NULL;
	    
	if (cabeca	==	NULL){
		cabeca = novoNo;
	}else{
		//procurar o ultimo elemento da lista
		struct no *ponteiro = cabeca;
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo ; 
		}
		ponteiro -> proximo = novoNo;
	}
}
//funcao q imprime elementos da lista

void imprimir(){
	struct no *ponteiro = cabeca;
	
	while(ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}
//funcao que remove um elemento da lista

void remover (int parametronumero) {

	struct no *ponteiroAnterior;
	struct no *ponteiroExcluir;
	
	if (cabeca != NULL) {
		if (cabeca -> numero == parametronumero) {
			ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
		}else{
			ponteiroAnterior = cabeca;
			while ((ponteiroAnterior != NULL) && (ponteiroAnterior -> numero != parametronumero)){
			
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			if (ponteiroAnterior != NULL){
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);			
				}
		}
	}
}
//funcao principal

int main(){
	int i = 0;
	for (i = 0 ; i < 10; i++){
		inserir(i);
	}
	imprimir();
	printf("===================\n");
	remover(19);
	
	imprimir();

}



