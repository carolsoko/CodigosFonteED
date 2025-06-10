
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
    struct      reg *ant;
}celula;

void imprimir(celula *listaDuplaEncadeada) {
   celula *p;
   for (p = listaDuplaEncadeada; p != NULL; p = p->prox){
      printf ("%d\n", p->conteudo);
   }
}

celula *buscar(int x, celula *listaDuplaEncadeada){
   celula *p;
   p = listaDuplaEncadeada;
   while (p != NULL && p->conteudo != x){
      p = p->prox;
   }
   return p;
}

celula *busca_r(int x, celula *listaDuplaEncadeada){
   if (listaDuplaEncadeada == NULL)  return NULL;
   if (listaDuplaEncadeada->conteudo == x)  return listaDuplaEncadeada;
   return busca_r (x, listaDuplaEncadeada->prox);
}

celula *inserir(int x, celula *p){
   celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
    nova->ant = NULL;
   if (p != NULL){
       p->ant = nova;
       nova->prox = p;
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

celula *buscar_e_remover(int x, celula *listaDuplaEncadeada){
   celula *p, *q;
   p = listaDuplaEncadeada;
   if(listaDuplaEncadeada->conteudo==x){
       q=listaDuplaEncadeada;
       p=listaDuplaEncadeada->prox;
       p->ant=NULL;
       free(q);
       return p;
   }else{
       q = listaDuplaEncadeada->prox;
       while (q != NULL && q->conteudo != x) {
            p = q;
            q = q->prox;
        }
        if (q != NULL) {
            p->prox = q->prox;
            p->prox->ant = p;
            free (q);
        }
        return listaDuplaEncadeada;
   }    
}

void buscar_e_inserir(int x, int y, celula *listaDuplaEncadeada){
   celula *p, *q, *nova, *topo;
   nova = malloc (sizeof (celula));
   nova->conteudo = x;
   p = listaDuplaEncadeada;
   q = listaDuplaEncadeada->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}

int main(){
    int resp, resp2=1;
    printf("Lista Duplamente Encadeada\n");
    celula *topo,*p;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserir(resp, topo);
        imprimir(topo);
    }
    printf("Fim da Insercao \n");
   
    while (resp2){
        printf("Digite o elemento que deseja encontrar na lista: ");
        scanf("%d", &resp);
   
        topo = buscar_e_remover(resp, topo);
       
        imprimir(topo);
       
       printf("Deseja repetir a busca? 1 - Sim, 0 - Não\n");
       scanf("%d", &resp2);
    }
    return 0;
}