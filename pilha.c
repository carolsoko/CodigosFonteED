
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// Pilha
typedef struct NODO{
    int     conteudo;
    struct  NODO *prox;
    struct  NODO *ant;
}celula;

celula *empilhar(int x, celula *pilha){
    celula *novo;
    novo = malloc (sizeof (celula));
    novo->conteudo = x;
    novo->prox = NULL;
    novo->ant = NULL;
    if (pilha!=NULL){
       novo->prox = pilha;
       pilha->ant = novo;
       pilha = novo;
    }else pilha = novo;
    return pilha;
}

celula *buscar(int x, celula *pilha){
    celula *aux = pilha;
    while(aux!=NULL && aux->conteudo!=x)
       aux=aux->prox;
    return aux;   
}

celula *buscarRecursivo(int x, celula *pilha){
    if (pilha == NULL) return NULL;
    if (pilha->conteudo!=x) return buscarRecursivo(x,pilha->prox);
    else return pilha;
}

celula *desempilhar(celula *pilha){
   celula *p, *q;
   if (pilha!=NULL){  
        q = pilha;
        p=q->prox;
        p->ant = NULL;
        free(q);
        return p;
   }else return pilha;
}


void imprimir(celula *pilha) {
   celula *p;
   if (pilha !=NULL)
        for (p = pilha; p != NULL; p = p->prox)
             printf ("%d\n", p->conteudo);
}


int main(){
    int resp;
    printf("Pilhas \n");
    celula *pilha;
    
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da pilha: ");
        scanf("%d", &resp);
        pilha = empilhar(resp, pilha);
        imprimir(pilha);
    }
    printf("Fim da Inserção \n");
    
   while(1){
        printf("Deseja tirar um elemento da pilha? 1-Sim/2-Não ");
        scanf("%d", &resp);
        if (resp==1){
            pilha = desempilhar(pilha);
            imprimir(pilha);
        }
    }
}