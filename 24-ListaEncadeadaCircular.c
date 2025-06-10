//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int         conteudo;
    struct      reg *prox;
}celula;

void imprimir(celula *topo) {
   celula *p;
   for (p = topo; p != NULL; p = p->prox){
      if (p == NULL) printf("Lista Vazia");  
      else printf ("%d\n", p->conteudo);
      if (p->prox == topo) break;
   }
}

celula *buscar(int x, celula *topo){
   celula *aux;
   aux = topo->prox;
   while ((aux->conteudo != x) && (aux!=topo))
      	aux = aux->prox;
   return aux;
}

celula *inserir(int x, celula *topo){
   celula *nova, *aux;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
   if (topo != NULL){
       aux = topo;
       while(aux->prox != topo)
            aux = aux->prox;
       nova->prox = topo;
       aux->prox = nova;
   } else {
       nova->prox = nova;
   }    
   topo = nova;
   return topo;
}

void remover(celula *p){
   celula *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

celula *buscar_e_remover(int x, celula *listaCircular){
   celula *p, *q;
   p = listaCircular;
   if(listaCircular->conteudo==x){
       for(q=listaCircular;q->prox!=listaCircular;q=q->prox);
       q->prox=listaCircular->prox;
       q=listaCircular;
       p=listaCircular->prox;
       free(q);
       return p;
   }else{
       q = listaCircular->prox;
       while (q != NULL && q->conteudo != x) {
            p = q;
            q = q->prox;
        }
        if (q != NULL) {
            p->prox = q->prox;
            free (q);
        }
        return listaCircular;
   }    
}

int main(){
    int resp, resp2=1;
    printf("Lista Circular Encadeada \n");
    celula *topo=NULL, *buscado=NULL;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserir(resp, topo);
        imprimir(topo);
    }
    printf("Fim da Inserção \n");
   
    while (resp2){
        printf("Digite o elemento que deseja encontrar na lista: ");
        scanf("%d", &resp);
   
        topo = buscar_e_remover(resp, topo);
       
        imprimir(topo);
       
       printf("Deseja repetir a busca? 1 - Sim, 0 - Não\n");
       scanf("%d", &resp2);
    }
}