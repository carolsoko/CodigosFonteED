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

celula *buscar(int x, celula *listaCircular){
   celula *p;
   p = listaCircular->prox;
   while (p->conteudo != x){
      p = p->prox;
      if (p == listaCircular) break;
   }
   return p;
}

celula *inserir(int x, celula *p){
   celula *nova, *aux;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
   if (p != NULL){
       aux = p;
       while(aux->prox != p)
            aux = aux->prox;
       nova->prox = aux->prox;
       aux->prox = nova;
   } else {
       nova->prox = nova;
   }    
   p = nova;
   return p;
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
    celula *topo, *buscado;
   
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
       
        topo = 0(resp, topo);
       
        imprimir(topo);
       
       printf("Deseja repetir a busca? 1 - Sim, 0 - Não\n");
       scanf("%d", &resp2);
    }
}