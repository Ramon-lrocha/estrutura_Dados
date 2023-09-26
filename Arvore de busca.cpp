//aula - Arvore de busca//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declarar estrutura
struct jao_viado{
	int num;
	struct jao_viado *esquerda;
	struct jao_viado *direita;
	
};

//funcao que insere no na arvore//

struct jao_viado *inserir(struct jao_viado *raiz, int num){
	
	if (raiz == NULL){
		raiz = (struct jao_viado *) malloc(sizeof(struct jao_viado));
		raiz -> num = num;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	}else{
		if (num < raiz -> num ){
			raiz -> esquerda = inserir (raiz -> esquerda, num);
		}else if (num > raiz -> num) {
			raiz -> direita = inserir (raiz -> direita, num);
		}
		
	}
	return raiz;
}
 
//funcao de busca um no da arvore//

void buscar (struct jao_viado *raiz, int num) {
	if (raiz != NULL){
		
		printf("NAO ACHEI :(");
		
		}else if(raiz -> num == num){
			
			printf("ACHOOU!!");
			
		}else if (raiz -> num > num){
			buscar (raiz -> esquerda, num);
			
		}else{
			buscar (raiz -> direita, num);
		}
	}
	//funcao que navega a arvore em ordem//
void navegar (struct jao_viado *raiz) {
	if (raiz != NULL){
		navegar (raiz -> esquerda);
		printf("%d\t", raiz -> num);
		navegar(raiz -> direita);
	}
}	
//funçao principal//

int main(){
	//declarar variavel//
	
	struct jao_viado *raiz = NULL;
	int opcao = 0;
	int num = 0;
	int i = 0;
	
	//inicialização de aleatoriedade//
	time_t t;
	srand((unsigned) time(&t));
	
	//menu de opcao
	
	while (opcao != 5){
		printf("\n");
		printf("+================================+\n");
		printf("|     Menu    de    opcao        |\n");
		printf("+================================+\n");
		printf("|  1 - crie uma arvore aleatoria |\n");
		printf("|  2 - inserir NO na arvore.     |\n");
		printf("|  3 - Buscar NO na arvore       |\n");
		printf("|  4 - navegar na arvore         |\n");
		printf("|  5 - dar pro proximo.          |\n");
		printf("+================================+\n");
		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				for (i = 0 ; i < 100 ; i++){
					raiz = inserir(raiz, rand());
				}
				break;
			case 2:
			printf("digite o numero: ");
			scanf("%d", &num);
			raiz = inserir(raiz, num);
			break;
			case 3:
			printf("digite o numero: ");
			scanf("%d", &num);
			raiz = inserir(raiz, num);
			break;
			case 4:
			navegar(raiz);
			break;	
		}

	}

}
		
		
	
	
	

