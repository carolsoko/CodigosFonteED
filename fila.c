
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// Implementando FILAS usando LISTAS DUPLAMENTE ENCADEADAS

typedef struct NODO{
    int     conteudo;
    struct  NODO *prox;
    struct  NODO *ant;
}celula;

celula *enfileirar(int x, celula *fila){
    celula *novo, *p;
    p = fila;
    novo = malloc (sizeof (celula));
    novo->conteudo = x;
    novo->prox = NULL;
    novo->ant = NULL;
    if (p!=NULL){
        for(p;p->prox!= NULL;p=p->prox);
        p->prox=novo;
        novo->ant=p;
    }else fila = novo;
    return fila;
}

celula *buscar(int x, celula *fila){
    celula *aux = fila;
    while(aux!=NULL && aux->conteudo!=x)
       aux=aux->prox;
    return aux;   
}

celula *buscarRecursivo(int x, celula *fila){
    if (fila == NULL) return NULL;
    if (fila->conteudo!=x) return buscarRecursivo(x,fila->prox);
    else return fila;
}

celula *desenfileirar(celula *fila){
   celula *p, *q;
   if (fila!=NULL){  
        q = fila;
        p=q->prox;
        p->ant = NULL;
        free(q);
        return p;
   }else return fila;
}


void imprimir(celula *fila) {
   celula *p;
   if (fila !=NULL)
        for (p = fila; p != NULL; p = p->prox)
             printf ("%d\n", p->conteudo);
}


int main(){
    int resp;
    printf("Filas \n");
    celula *fila;
    
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da fila: ");
        scanf("%d", &resp);
        fila = enfileirar(resp, fila);
        imprimir(fila);
    }
    printf("Fim da Inserção \n");
    
   while(1){
        printf("Deseja tirar um elemento da fila? 1-Sim/2-Não ");
        scanf("%d", &resp);
        if (resp==1){
            fila = desenfileirar(fila);
            imprimir(fila);
        }
    }
}