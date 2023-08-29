//Matrizes Esparsas

////////////////////////

//programa que implementa matriz esparsa

#include <stdio.h>
#include <stdlib.h>

//declarar constantes

const int MODULO = 5;

//declaração de estruturas

struct diretor {
	int resto;
	struct no * proxNo;
	struct diretor *proxDiretor;
};
struct no{
	int numero;
	struct no *proxNo;
};

//declaração de variaveis

struct diretor * cabeca = NULL;


//funcao que cria um diretor

struct diretor * procurarDiretor(int restoProcurado) {
	struct diretor *pont = cabeca;
	
	while ((pont != NULL) && 
	(pont -> resto != restoProcurado)) {
		pont = pont -> proxDiretor; 
	}
	if (pont == NULL){
		pont = (struct diretor *) malloc(sizeof(struct diretor)); //criou um diretor
		pont -> resto = restoProcurado;
		pont -> proxDiretor = cabeca;
		pont -> proxNo = NULL;
		cabeca = pont;
	}
	
	return pont;
		
	}
//funcao que insere um no na matriz espasa

void inserir(int numero){
	struct diretor *MelbyLaw = procurarDiretor(numero % MODULO); //melby = diretor certo
	
	struct no *novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proxNo = MelbyLaw -> proxNo;
	MelbyLaw -> proxNo = novoNo;
}

//funcao que imprime a matriz espasa

void imprimir(){
	struct diretor *pontDiretor = cabeca;
	printf("===================\n");
	printf("Resto\n");
	while(pontDiretor != NULL){
		printf("%d -> \t", pontDiretor -> resto);
		
		struct no *pontNo = pontDiretor -> proxNo;
		
		while (pontNo != NULL){
			printf("%d\t", pontNo -> numero);
			pontNo = pontNo -> proxNo;
			
		}
		printf("\n");
		pontDiretor = pontDiretor -> proxDiretor;
	}
}
//funcao principal

int main(){
	int i = 0;
	
	for (i = 0; i< 20000000 ; i++){
		inserir (i);	
	}
	imprimir();

}














