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

void imprimir(celula *pilha) {
   celula *p;
   for (p = pilha; p != NULL; p = p->prox){
      printf ("%d\n", p->conteudo);
   }
}

celula *buscar(int x, celula *pilha){
   celula *p;
   p = pilha;
   while (p!=NULL && p->conteudo != x)
      p = p->prox;
   return p;
}

celula *empilhar(int x, celula *p){
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

celula *desempilhar(celula *pilha){
   celula *p, *q;
   p = pilha;
   q = pilha;
   if(p != NULL){
        q = p->prox;
        if (q != NULL) q->ant = NULL;
   }
   free (p);
   return q;
}

int main(){
    int resp;
    printf("Pilha\n");
    celula *pilha,*p;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da Pilha: ");
        scanf("%d", &resp);
        pilha = empilhar(resp, pilha);
        imprimir(pilha);
    }
    printf("Fim do empilhamento \n");
   
    resp=1;
    while(resp){
        printf("Deseja desempilhar um elemento? 1 - Sim / 0 - Não");
        scanf("%d", &resp);
       
        if(resp) pilha = desempilhar(pilha);
        if(pilha != NULL) imprimir(pilha);
    }
    return 0;
}