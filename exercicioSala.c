
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

celula *inserirNoInicio(int x, celula *p){
   celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->prox = NULL;
   if (p != NULL)
        nova->prox = p;
   p = nova;
   return p;
}

void imprimir(celula *listaEncadeada) {
   celula *p;
   for (p = listaEncadeada; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}

celula *extraiPar(celula *topo){
    celula *aux, *par, *aux1;
    par = NULL;
    
    for(aux = topo; aux!=NULL; aux=aux->prox){
        if(aux->conteudo%2 == 0){
            celula *novo;
            novo = malloc (sizeof (celula));
            novo->conteudo = aux->conteudo;
            novo->prox=NULL;
            if (par == NULL){ 
                par = novo;
            }else{
               for(aux1 = par; aux1->prox!=NULL; aux1=aux1->prox);
               aux1->prox = novo;
            }
        }    
    }
    return par;
}

celula *extraiImpar(celula *topo){
    celula *aux, *impar, *aux1;
    impar = NULL;
    
    for(aux = topo; aux!=NULL; aux=aux->prox){
        if(aux->conteudo%2 != 0){
            celula *novo;
            novo = malloc (sizeof (celula));
            novo->conteudo = aux->conteudo;
            novo->prox=NULL;
            if (impar == NULL){ 
                impar = novo;
            }else{
               for(aux1 = impar; aux1->prox!=NULL; aux1=aux1->prox);
               aux1->prox = novo;
            }
        }    
    }
    return impar;
}

void contaQtde(celula *topo){
    celula *aux;
    int qtde;
    
    for(aux=topo, qtde=0; aux!=NULL; aux=aux->prox,qtde++);
    
    printf("Quantidade de elementos = %d\n", qtde);
}

void contaQtdeElementoRepetido(int x,celula *topo){
    celula *aux;
    int qtde;
    
    for(aux=topo, qtde=0; aux!=NULL; aux=aux->prox)
          if (aux->conteudo == x) qtde++;
    
    printf("Quantidade de repetições do elemento %d = %d\n", x, qtde);
}

int main(){
    int resp, resp2=1;
    printf("Lista Simplesmente Encadeada \n");
    celula *topo, *buscado, *par, *impar;
    
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserirNoFinal(resp, topo);
        imprimir(topo);
    }
    contaQtde(topo);
    printf("Fim da Inserção \n");
    
    printf("Par: \n");
    par = extraiPar(topo);
    imprimir(par);
    contaQtde(par);
    printf("Impar: \n");
    impar = extraiImpar(topo);
    imprimir(impar);
    contaQtde(impar);
    
    contaQtdeElementoRepetido(4,topo);
    
}