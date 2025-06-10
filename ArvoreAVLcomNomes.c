//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	char nome[100];
	struct no *esquerda;
	struct no *direita;
	int fatorBalanceamento;
}No;

//aloca um novo nó
No *novoNo(char x[]){
	No *novo = malloc(sizeof(No));
	strcpy(novo->nome, x);
	novo->direita = NULL;
	novo->esquerda = NULL;
	novo->fatorBalanceamento = 0;
	return novo;
}

int maiorAltura(int a, int b){
	return (a>b)?a :b;
}

//verifica a altura da árvore
int altura(No *no){
	if(no == NULL){
		return -1;
	}else{
		return no->fatorBalanceamento;
	}
}


//verifica o fator de balanceamento
int fatorDeBanlanceamento(No *no){
	if(no){
		return (altura(no->esquerda) - altura(no->direita));
	}else{
		return 0;
	}
}

//realiza a rotação a esquerda
No *rotacaoEsquerda(No *r){
	No *y, *f;
	
	y = r->direita;
	f = y->esquerda;
	
	y->esquerda = r;
	r->direita = f;
	
	r->fatorBalanceamento = maiorAltura(altura(r->esquerda), altura(r->direita)) + 1;
	y->fatorBalanceamento = maiorAltura(altura(y->esquerda), altura(y->direita)) + 1;
	
	return y;	
}

//realiza a rotação a direita
No *rotacaoDireita(No *r){
	No *y, *f;
	
	y = r->esquerda;
	f = y->direita;
	
	y->direita = r;
	r->esquerda = f;
	
	r->fatorBalanceamento = maiorAltura(altura(r->esquerda), altura(r->direita)) + 1;
	y->fatorBalanceamento = maiorAltura(altura(y->esquerda), altura(y->direita)) + 1;
	
	return y;	
}

//realiza dupla rotação esquerda-direita
No *rotacaoEsquerdaDireita(No *r){
	r->esquerda = rotacaoEsquerda(r->esquerda);
	return rotacaoDireita(r);
}

//realiza dupla rotação direita-esquerda
No *rotacaoDireitaEsquerda(No *r){
	r->direita = rotacaoDireita(r->direita);
	return rotacaoEsquerda(r);
}

//verifica o fator de balanceamento e rebalancea a árvore se necessário
No *balancear(No *raiz){
    //verifica fator de balçanceamento
    //caso a árvore esteja desbalanceada, rebalancea a árvore
	int fb = fatorDeBanlanceamento(raiz);
	
	if(fb < -1 && fatorDeBanlanceamento(raiz->direita) <=0){
		raiz = rotacaoEsquerda(raiz);
	}else if(fb < -1 && fatorDeBanlanceamento(raiz->direita) > 0){
		raiz = rotacaoDireitaEsquerda(raiz);
	}else if(fb > 1 && fatorDeBanlanceamento(raiz->esquerda) >= 0){
		raiz = rotacaoDireita(raiz);
	}else if(fb > 1 && fatorDeBanlanceamento(raiz->esquerda) < 0){
		raiz = rotacaoEsquerdaDireita(raiz);
	}  	
	
	return raiz;
}

//insere na árvore e rebalancea a árvore se necessário
No *inserir(No *raiz, char nome[]){
	if(raiz == NULL){
		return novoNo(nome);
	}else if(strcmp(raiz->nome, nome) > 0) {
		raiz->esquerda = inserir(raiz->esquerda, nome);
	}else if(strcmp(raiz->nome, nome) < 0){
		raiz->direita = inserir(raiz->direita, nome);	
	}else{
		printf("O nome já está cadastrado!\n");
	}
	
	raiz->fatorBalanceamento = maiorAltura(altura(raiz->esquerda), altura(raiz->direita)) + 1;
	
	//após inserir elemento na árvore, precisa balancear ela.
	raiz = balancear(raiz);
	
	return raiz;
		
}

No *menor(No *raiz){
	while(raiz->esquerda != NULL)
		raiz = raiz->esquerda;
	return raiz;
}

//remove o elemento da árvore AVL
No *remover(No *raiz, char nome[]){
	if(raiz == NULL)
		return raiz;
	if(strcmp(nome, raiz->nome) < 0){
		raiz->esquerda = remover(raiz->esquerda, nome);
	}else if(strcmp(nome, raiz->nome) > 0){
		raiz->direita = remover(raiz->direita, nome);
	}else{
		if((raiz->esquerda == NULL) || (raiz->direita == NULL)){
			No *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
			
			if(temp == NULL){
				temp = raiz;
				raiz = NULL;
			}else{
				*raiz = *temp;
			}
			free(temp);
		}else {
			No *temp = menor(raiz->direita);
			strcpy(raiz->nome, temp->nome);
			raiz->direita = remover(raiz->direita, temp->nome);
		}
	}
	
	if(raiz == NULL){
		return raiz;
	}
	
	raiz->fatorBalanceamento = maiorAltura(altura(raiz->esquerda), altura(raiz->direita)) + 1;

	//após remover um elemento da árvore, precisa rebalancear ela.
	raiz = balancear(raiz);

	return raiz;
}

//limpa a árvore AVL
void limparArvore(No *raiz){
	if(raiz != NULL){
		limparArvore(raiz->esquerda);
		limparArvore(raiz->direita);
		free(raiz);
	}
}

//desenha a árvore da raiz às folhas deitada
void desenhar(No *raiz, int nivel){
	int i;
	if(raiz){
		desenhar(raiz->direita, nivel + 1);
		printf("\n\n");
		for(i = 0; i< nivel; i++){
			printf("\t");
		}
		printf("%s", raiz->nome);
		desenhar(raiz->esquerda, nivel + 1);
	}

}


void imprimirEmOrdem(No *raiz){
	if(raiz){
		imprimirEmOrdem(raiz->esquerda);
		printf("%s\n", raiz->nome);
		imprimirEmOrdem(raiz->direita);
	}
}


void imprimirPreOrdem(No *raiz){
	if(raiz){
		printf("%s\n", raiz->nome);
		imprimirPreOrdem(raiz->esquerda);
		imprimirPreOrdem(raiz->direita);
	}
}


void imprimirPosOrdem(No *raiz){
	if(raiz){
		imprimirPosOrdem(raiz->esquerda);
		imprimirPosOrdem(raiz->direita);
		printf("%s\n", raiz->nome);
	}
}

//busca um elemento da árvore
No *busca(No *no, char nome[]){
	if(no == NULL){
		printf("Nome não encontrado!\n");
	}else{
		if(strcmp(no->nome, nome) < 0){
			no = busca(no->esquerda, nome);
		}else if(strcmp(no->nome, nome) > 0)
			no = busca(no->direita, nome);
		else
			printf("Nome encontrado!\n");
		
	}
	return no;
}

int main(){
	No *raiz = NULL, *no;

	int escolha;
	char nome[100];

	
	while(1){
		printf("\n------- MENU -------\n");
        printf("1. Inserir um nome\n");
        printf("2. Remover um nome\n");
		printf("3. Mostra a árvore binaria Ordenada em Pre-ordem\n");
  		printf("4. Mostra a árvore binaria Ordenada em Pós-ordem\n");
  		printf("5. Mostra a árvore binaria Ordenada Em Ordem\n");
        printf("6. Desenhar árvore\n");
        printf("7. Buscar um nome\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
		scanf("%d", &escolha);

		switch (escolha)
		{
		case 1:
			printf("Digite um nome para inserí-lo na árvore:\n");
			scanf("%s", nome);
			raiz = inserir(raiz, nome);
			printf("Nome inserido com sucesso!\n");
			break;

		case 2:
			printf("Digite o nome que deseja remover:\n");
			scanf("%s", nome);
			raiz = remover(raiz, nome);
			printf("Nome removido com sucesso!\n");
			break;

		case 3:
			printf("Árvore em pré-ordem:\n");
			imprimirPreOrdem(raiz);
			break;

		case 4:
			printf("Árvore em pós-ordem:\n");
			imprimirPosOrdem(raiz);
			break;

		case 5:
			printf("Árvore em  ordem:\n");
			imprimirEmOrdem(raiz);
			break;

		case 6:
			printf("Desenho da árvore:\n");
			desenhar(raiz,0);
			break;
		
		case 7:
			printf("Digite um nome para buscá-lo na árvore:\n");
			scanf("%s", nome);
			
			no = busca(raiz, nome);
			break;

		case 8:
			limparArvore(raiz);
			break;

		default:
			printf("Opção inválida! Tente novamente!\n");
			return 0;
		}
	}
	return 0;
}