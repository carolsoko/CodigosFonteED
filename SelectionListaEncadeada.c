/***Faça um algoritmo que implemente uma função que realiza o SelectionSort numa
lista simplesmente encadeada. A função deverá receber um ponteiro para uma
lista desordenada e retornar um ponteiro para a lista ordenada resultante. Utilize o
struct abaixo como nodo da lista, ordene a lista por id, em ordem crescente.
(Valor:3,0pts)
typedef struct no{
int id;
struct no *prox;
}No;***/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id;
    struct no *prox;
}No;

void imprimir(No *topo) {
   No *p;
   for (p = topo; p != NULL; p = p->prox){
      if (p == NULL) printf("Lista Vazia");  
      else printf ("%d\n", p->id);
   }
}

No *buscar(int x, No *topo){
   No *aux;
   aux = topo;
   while ((aux->id != x) && (aux!=NULL))
      	aux = aux->prox;
   return aux;
}

No *inserir(int x, No *topo){
   No *nova, *aux;
    nova = malloc (sizeof (No));
    nova->id = x;
    nova->prox = NULL;
   if (topo != NULL){
       aux = topo;
       while(aux->prox != NULL)
            aux = aux->prox;
       aux->prox = nova;
   }else topo = nova;
   
   return topo;
}

No *remove_minimo(No *ini) {
    No *p, *q, *ant;
    
    if (!ini->prox) return NULL;
    p = ant = ini; 
    q = ini->prox;
    
    while (q) {
        if (q->id < ant->id) ant = p;
        p = q; 
        q = q->prox;
    }
    
    q = ant->prox;
    ant->prox = q->prox;
    return q;
}


void *selectionSort(No *ini){
    No *t = malloc(sizeof(No)), *last, *min;
    t->prox = ini->prox;
    ini->prox = NULL;
    last = ini;
    
    while (t->prox != NULL) {
        min = remove_minimo(t);
        last->prox = min;
        last = min;
        last->prox = NULL;
    }
    free(t);
}


int main(){
    int resp, resp2=1;
    printf("Lista Simplesmente Encadeada \n");
    No *topo=NULL, *buscado=NULL;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserir(resp, topo);
        imprimir(topo);
    }
    printf("Fim da Inserção \n");
    
    printf("Ordenando... \n");
    selectionSort(topo);
    
    printf("Fim da Remoção \n");
    imprimir(topo);
}