
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct CELULA{
    int     num;
    struct  CELULA *prox;
}nodo;

nodo *inserirNoFinal(int x, nodo *lista){
    nodo *novo, *topo;
    novo = malloc (sizeof (nodo));
    novo->num = x;
    novo->prox = NULL;
    if (lista!=NULL){
        for(topo=lista;topo->prox!=NULL;topo=topo->prox);
        topo->prox=novo;
    }else lista = novo;
    return lista;
}

nodo *buscar(int x, nodo *lista){
    nodo *aux = lista;
    while(aux!=NULL && aux->num!=x)
       aux=aux->prox;
    return aux;   
}

nodo *buscarRecursivo(int x, nodo *lista){
    if (lista == NULL) return NULL;
    if (lista->num!=x) return buscarRecursivo(x,lista->prox);
    else return lista;
}

nodo *buscar_e_remover(int x, nodo *lista){
   nodo *p, *q;
   
   if(lista->num==x){
       q=lista;
       lista=lista->prox;
       free(q);
   }else{
       q = lista->prox;
       while (q != NULL && q->num != x) {
            p = q;
            q = q->prox;
        }
        if (q != NULL) {
            p->prox = q->prox;
            free (q);
        }
   } 
   
   return lista;   
}

nodo *inserirNoInicio(int x, nodo *lista){
    nodo *nova;
    nova = malloc (sizeof (nodo));
    nova->num = x;
    nova->prox = NULL;
   if (lista != NULL)
        nova->prox = lista;
   lista = nova;
   return lista;
}

nodo *criarL3(nodo *lista1, nodo *lista2){
    nodo *lista3, *aux;
    lista3 = lista1;
    for(aux=lista3;aux->prox!=NULL;aux=aux->prox);
    aux->prox = lista2;
    return lista3;
}

//BubbleSort
nodo *ordenarLista(nodo *lista){
    nodo *aux, *p = lista, *aux2;
    int flag = 1;
    
    while(flag){
        flag = 0;
        for(aux=lista;(aux!=NULL && aux->prox!=NULL);aux=aux->prox){
            aux2=aux->prox;
            if (aux->num > aux2->num){
                if(aux==lista){
                    lista=aux2;
                }else {
                    for(p=lista;p->prox!=aux;p=p->prox);
                    p->prox = aux2;
                }    
                aux->prox = aux2->prox;
                aux2->prox = aux;
                flag = 1;
                aux = aux2;
            }
        }
    }
    return lista;
}

void imprimir(nodo *lista) {
   nodo *p;
   for (p = lista; p != NULL; p = p->prox)
      printf ("%d\n", p->num);
}

int main(){
    int resp, j;
    printf("Algoritmo que recebe L1 e L2 e gera L3 \n");
    nodo *topo1, *topo2, *topo3;
    
    printf("Digite os elementos de L1: \n");
    for(j=0; j<10;j++){
        printf("Digite o %dº elemento da lista: ",j+1);
        scanf("%d", &resp);
        topo1 = inserirNoFinal(resp, topo1);
    }
    imprimir(topo1);
    printf("Fim da Inserção de L1\n");
    
    for(j=0; j<10;j++){
        printf("Digite o %dº elemento da lista: ",j+1);
        scanf("%d", &resp);
        topo2 = inserirNoFinal(resp, topo2);
    }
    imprimir(topo2);
    printf("Fim da Inserção de L2\n");
    
     printf("Elementos de ambos as listas:\n");
    topo3 = criarL3(topo1,topo2);
    topo3 = ordenarLista(topo3);
    imprimir(topo3);
}
