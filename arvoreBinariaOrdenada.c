//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
   
typedef struct noArvore{
  int chave;
  struct noArvore *filhoDir;
  struct noArvore *filhoEsq;
}NO;
 
int menu(void){
  int opcao;
  printf("Opções:\n");
  printf("-------\n");
  printf("0. Insere elementos na Árvore Binária Ordenada\n");
  printf("1. Mostra Árvore Binária Ordenada em Pré-ordem\n");
  printf("2. Mostra Árvore Binária Ordenada em Pós-ordem\n");
  printf("3. Mostra Árvore Binária Ordenada Em Ordem\n");
  printf("4. Desenha a Árvore Binária Ordenada da raiz às folhas\n");
  printf("5. Remove elementos da Árvore Binária Ordenada\n");
  printf("6. Busca elementos na Árvore Binária Ordenada\n");
  printf("7. Fechar\n\n");
   
  do{
    printf("Escolha [0,1,2,3,4,5,6 ou 7]: ");
    scanf("%d",&opcao);
    printf("\n\n");
  }
  while((opcao < 0) && (opcao > 7));
  return opcao;
}
 
NO *insereNaArvore(NO *nodo, int chave){
  if (nodo == NULL){
      nodo = malloc (sizeof(NO));
      nodo->filhoEsq = NULL;
      nodo->filhoDir = NULL;
      nodo->chave = chave;
  }else{
    if(nodo->chave > chave)
      nodo->filhoEsq = insereNaArvore(nodo->filhoEsq, chave);
    else
      nodo->filhoDir = insereNaArvore(nodo->filhoDir, chave);
  }
  return nodo;
}

NO *buscaMaisADireita(NO *nodo){
    NO *aux = nodo;
    for(aux = nodo; aux->filhoDir!=NULL;aux=aux->filhoDir);
    return aux;
}

NO *buscaPaiDoDir(NO *nodo, NO *Dir){
    NO *aux;
    if (nodo != Dir){
        for(aux=nodo; aux->filhoDir != Dir; aux=aux->filhoDir);
        return aux;
    } else return nodo;    
}

NO *buscaNaArvore(NO *nodo, int chave){
  if (nodo == NULL){
      printf("Chave não Encontrada!\n");
  }else{
    if(nodo->chave > chave)
      nodo = buscaNaArvore(nodo->filhoEsq, chave);
    else if (nodo->chave < chave)
      nodo = buscaNaArvore(nodo->filhoDir, chave);
    else printf("Chave Encontrada!\n");
  }
  return nodo;
}

NO* removeDaArvore(NO *nodo, int chave){
  NO *maisDir, *pai;
 
  if (nodo == NULL){
        printf("Árvore vazia!");
        return NULL;
  }else if (nodo->chave == chave){ //encontrou a chave a remover
      if ((nodo->filhoEsq == NULL) && (nodo->filhoDir == NULL)){
        //o Nó a ser removido é folha
        free(nodo);
        nodo=NULL;
        printf("Removido o Nó folha de chave %d\n",chave);
        return NULL;
      }else if(nodo->filhoDir == NULL){
        //o Nó a ser removido tem apenas um filho da esquerda
        nodo = nodo->filhoEsq;
        printf("Removido o Nó com 1 filho à esquerda de chave %d\n",chave);
      }else if(nodo->filhoEsq == NULL){
         //o Nó a ser removido tem apenas um filho da direita
        nodo = nodo->filhoDir;
        printf("Removido o Nó com 1 filho à direita de chave %d\n",chave);
      }else{
        //Neste caso, o Nó tem dois filhos. Devemos escolher se vamos
        //substituir pelo filho da subárvore da esquerda ou da direita.
        //Escolhi sempre substituir pelo filha da subárvore da esquerda.
        //Então busco o mais à direita da subárvore à esquerda.
        maisDir = buscaMaisADireita(nodo->filhoEsq); //busco o elemento mais à direita da subárvore da esquerda
        nodo->chave = maisDir->chave;
        pai = buscaPaiDoDir(nodo->filhoEsq, maisDir); //busco o pai do mais à direita para reposicionar o ponteiro
       
        if (pai == maisDir){
            nodo->filhoEsq = maisDir->filhoEsq;
        }
       
        if (pai->filhoDir == maisDir){
            pai->filhoDir = maisDir->filhoEsq;
            printf("Removido o Nó com dois filhos de chave %d\n",chave);
        }
        return nodo;
      }
  }else if (nodo->chave > chave)
      nodo->filhoEsq = removeDaArvore(nodo->filhoEsq, chave);
      //procura Nó na subárvore da esquerda
  else
      nodo->filhoDir = removeDaArvore(nodo->filhoDir, chave);
      //procura Nó na subárvore da direita
     
  return nodo;      
}

 
void preOrdem(NO *nodo){
  if(nodo){
    printf("%d\n",nodo->chave);
    preOrdem(nodo->filhoEsq);
    preOrdem(nodo->filhoDir);
  }
}
 
void posOrdem(NO *nodo){
  if(nodo){
    posOrdem(nodo->filhoEsq);
    posOrdem(nodo->filhoDir);
    printf("%d\n",nodo->chave);
  }
}
 
void emOrdem(NO *nodo){
  if(nodo){
    emOrdem(nodo->filhoEsq);
    printf("%d\n",nodo->chave);
    emOrdem(nodo->filhoDir);
  }
}
 
void destroi(NO *nodo) {
  if(nodo) {
    destroi(nodo->filhoEsq);
    destroi(nodo->filhoDir);
    free(nodo);
    nodo = NULL;
  }
}
 
void imprimir(NO *nodo, int nivel){
  int i;
  if(nodo != NULL) {
    imprimir(nodo->filhoDir, nivel + 1);
    for(i = 0; i <= nivel-1; i++) printf("  ");
    printf("+--");
    printf("%d\n",nodo->chave);
    imprimir(nodo->filhoEsq, nivel + 1);
  }
  return;
}

void main() {
  NO *raiz = NULL, *nodo;
  int escolha, chave;
  do{
    escolha = menu();
    switch(escolha){
        case 0:
            printf("Insere elementos na Árvore Binária Ordenada \n\r");
            while(escolha == 0){
                printf("Digite o elemento que deseja inserir ou -1 para sair: ");
                scanf("%d",&chave);
                if (chave != -1)
                    raiz = insereNaArvore(raiz,chave);
                else break;
            }
            break;
        case 1:
            printf("Percorre a Árvore Binária Ordenada e mostra no modo Pré-ordem\n\r");
            preOrdem(raiz);
            break;
        case 2:
            printf("Percorre a Árvore Binária Ordenada e mostra no modo Pós-ordem\n\r");
            posOrdem(raiz);
            break;
        case 3:
            printf("Percorre a Árvore Binária Ordenada e mostra no modo Em Ordem\n\r");
            emOrdem(raiz);
            break;
        case 4:
            printf("Mostra Árvore Binária Ordenada (raiz à esquerda e folhas à direita)\n\r");
            imprimir(raiz, 0);
            break;
        case 5:
            printf("Remove elementos da Árvore Binária Ordenada \n\r");
            while(escolha == 5){
                printf("Digite o elemento que deseja remover ou -1 para sair: ");
                scanf("%d",&chave);
                if (chave != -1)
                    raiz = removeDaArvore(raiz, chave);
                else break;
            }
            break;
        case 6:
            printf("Busca elemento na Árvore Binária Ordenada \n\r");
            while(escolha == 6){
                printf("Digite o elemento que deseja buscar ou -1 para sair: ");
                scanf("%d",&chave);
                if (chave != -1)
                    nodo = buscaNaArvore(raiz,chave);
                else break;
            }
            break;    
        }
        printf("\n\nDigite qualquer tecla...");
        getchar();
    }
  while(escolha != 7);
  destroi(raiz);
}