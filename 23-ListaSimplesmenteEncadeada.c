//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
    int     conteudo;
    struct  NODO *prox;
}celula;

celula *inserirNoFinal(int x, celula *p){
    celula *novo, *topo;
    topo = p;
    novo = malloc (sizeof (celula));
    novo->conteudo = x;
    novo->prox = NULL;
    if (p!=NULL){
        for(p;p->prox!= NULL;p=p->prox);
        p->prox=novo;
    }else topo = novo;
    return topo;
}

celula *buscar(int x, celula *lista){
    celula *aux = lista;
    while(aux!=NULL && aux->conteudo!=x)
       aux=aux->prox;
    return aux;  
}

celula *buscarRecursivo(int x, celula *lista){
    if (lista == NULL) return NULL;
    if (lista->conteudo!=x) return buscarRecursivo(x,lista->prox);
    else return lista;
}

void remover(celula *p){
   celula *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

celula *buscar_e_remover(int x, celula *listaEncadeada){
   celula *p, *q;
   p = listaEncadeada;
   if(p->conteudo==x){
       q=listaEncadeada;
       p=listaEncadeada->prox;
       free(q);
       return p;
   }else{
       q = listaEncadeada->prox;
       while (q != NULL && q->conteudo != x) {
            p = q;
            q = q->prox;
        }
        if (q != NULL) {
            p->prox = q->prox;
            free (q);
        }
        return listaEncadeada;
   }    
}


celula *inserirNoInicio(int x, celula *topo){
   celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
   if (topo != NULL)
        nova->prox = topo;
   topo = nova;
   return topo;
}

void imprimir(celula *listaEncadeada) {
   celula *p;
   for (p = listaEncadeada; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}

int main(){
    int resp, resp2=1;
    printf("Lista Simplesmente Encadeada \n");
    celula *topo=NULL, *buscado=NULL;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserirNoInicio(resp, topo);
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