
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
      printf ("%d\n", p->conteudo);
      if (p->prox == topo) break;
   }
}

celula *buscar(int x, celula *listaCircular){
   celula *p, *topo;
   topo = listaCircular;
   p = listaCircular->prox;
   while (p->conteudo != x){
      p = p->prox;
      if (p == topo) break;
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

celula *buscar_e_remover(int x, celula *topo){
   celula *p, *q,*aux;
   q = topo;
   if(q->conteudo==x){
       for(aux=q; aux->prox!=q;aux=aux->prox);
       aux->prox=q->prox;
       p=q->prox;
       free(q);
       return p;
   }else{
       p = topo;
       q = topo->prox;
       while (q != topo && q->conteudo != x) {
            p = q;
            q = q->prox;
        }
        if (q != topo) {
            p->prox = q->prox;
            free (q);
        }
        return topo;
   }    
}

void buscar_e_inserir(int x, int y, celula *listaCircular){
   celula *p, *q, *nova, *topo;
   nova = malloc (sizeof (celula));
   nova->conteudo = x;
   p = listaCircular;
   q = listaCircular->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}

int main(){
    int resp, resp2;
    printf("Lista Encadeada Circular\n");
    celula *topo,*p;
    
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserir(resp, topo);
        imprimir(topo);
    }
    printf("Fim da Inserção \n");
    resp2=1;
    while (resp2){
        printf("Digite o elemento que deseja remover da lista: ");
        scanf("%d", &resp);
   
        topo = buscar_e_remover(resp, topo);
       
        imprimir(topo);
       
       printf("Deseja repetir a busca? 1 - Sim, 0 - Não\n");
       scanf("%d", &resp2);
    } 
    
}