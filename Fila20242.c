//Fila
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct NODO {
    int conteudo;
    struct NODO *prox;
} celula;

celula *inserirFila(celula *topo, int elemento) {
    celula *novo, *aux;
    novo = (celula*)malloc(sizeof(celula));
    novo->conteudo = elemento;
    novo->prox = NULL;

    if(topo == NULL) {
        topo = novo;
    } else {
        for(aux = topo; aux->prox!=NULL; aux=aux->prox);
        aux->prox = novo;
    }
    return topo;
}

celula *removerFila(celula *topo) {
    celula *aux;
    if(topo == NULL) {
        printf("Fila Vazia!\n");
    } else {
        aux = topo;
        topo = topo->prox;

        printf("Removendo o elemento: %d\n",aux->conteudo);
        aux->prox = NULL;
        free(aux);
    }

    return(topo);
}

void imprimirFila(celula *topo) {
    celula *aux;
    int cont;

    for(cont=1, aux = topo; aux != NULL; aux = aux->prox, cont++)
        printf("%dº elemento da fila: %d\n",cont,aux->conteudo);

}


int main() {
    celula *topo = NULL;
    int elemento;

    for(int i=1; i<=TAM; i++) {
        printf("Digite o elemento %d da fila: ",i);
        scanf("%d",&elemento);
        topo = inserirFila(topo, elemento);
    }

    printf("Fila:\n");
    imprimirFila(topo);

    topo = removerFila(topo);
    topo = removerFila(topo);
    topo = removerFila(topo);

    printf("\n\n\n");
    printf("Fila após remoções:\n");
    imprimirFila(topo);

    return 0;
}