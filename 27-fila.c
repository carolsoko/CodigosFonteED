//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int         conteudo;
    struct      reg *prox;
    struct      reg *ant;
}celula;

void imprimir(celula *fila) {
   celula *p;
   for (p = fila; p != NULL; p = p->prox){
      printf ("%d\n", p->conteudo);
   }
}

celula *buscar(int x, celula *fila){
   celula *p;
   p = fila;
   while (p!=NULL && p->conteudo != x)
      p = p->prox;
   return p;
}

celula *enfileirar(int x, celula *p){
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
    nova->ant = NULL;
   if (p != NULL){
       nova->prox = p;
       p->ant = nova;
   }
   return nova;
}

celula *desenfileirar(celula *fila){
   celula *p, *q;
   p = fila;
   while (p->prox != NULL)
      p = p->prox;
   q = p->ant;
   if (q != NULL) q->prox = NULL;
   else fila = NULL;
   free (p);
   return fila;
}

int main(){
    int resp, resp1;
    printf("Fila\n");
    celula *fila,*p;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da fila: ");
        scanf("%d", &resp);
        fila = enfileirar(resp, fila);
        imprimir(fila);
    }
    printf("Fim do enfileiramento \n");
   
    resp=1;
    while(resp){
        printf("Deseja desenfileirar um elemento? 1 - Sim / 0 - Não");
        scanf("%d", &resp);
       
        if(resp) fila = desenfileirar(fila);
        if(fila != NULL) imprimir(fila);
    }
    return 0;
}