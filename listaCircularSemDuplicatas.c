/***Você foi contratado para melhorar a eficiência de um sistema que armazena
dados de clientes em uma lista encadeada circular. No entanto, percebeu-se que
alguns registros foram inseridos de forma duplicada. Faça uma função que
receba um ponteiro para o início da lista, e retorne a própria lista mantendo
apenas a primeira ocorrência de cada valor. Exemplo: (Valor:4,0pts)
Lista de Entrada: → 1 → 3 → 2→ 10 → 3 → 4 → 2 → 5→ 4 → início
Lista após remoção de duplicatas: → 1 → 3 → 2 → 10 → 4 → 5→ início***/

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

celula *removerDuplicatas(celula *listaCircular){
   celula *p, *ant,*atual, *lixo;
   p = listaCircular;
   int flag, apagar;
   
   while(p->prox!=listaCircular){
      flag = 0;
      ant = p;
      apagar = (int)ant->conteudo;
      atual = p->prox;
      while(atual!=listaCircular){
          if(atual->conteudo == apagar){
              lixo = atual;
              ant->prox = atual->prox;
              atual = atual->prox;
              free(lixo);
          }else{
              ant = atual;
              atual = atual->prox;
          }
      }
      p = p->prox;
   }
   return listaCircular;
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
    
    topo = removerDuplicatas(topo);
   
   printf("Fim da Remoção \n");
    imprimir(topo);
}