#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
    int     conteudo;
    struct  NODO *ant;
    struct  NODO *prox;
}celula;

celula *inserirNoFinal(int x, celula *topo){
    celula *novo,*p;
    p = topo;
    novo = malloc (sizeof (celula));
    novo->conteudo = x;
    novo->ant = NULL;
    novo->prox = NULL;
    if(topo==NULL)
        topo = novo;
    else{
        while(p->prox!=NULL) p=p->prox;
        novo->ant = p;
        p->prox = novo;
    }
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

celula *buscar_e_remover(int x, celula *topo){
   celula *p, *lixo;
   
   for(p=topo; p->prox!=NULL; p=p->prox)
        if(p->conteudo == x){
            lixo = p;
            break;
        }
   if(lixo!=NULL){
       if(lixo->prox!=NULL)
            lixo->prox->ant = lixo->ant;
       if(lixo->ant!=NULL)  
            lixo->ant->prox = lixo->prox;
       else topo = topo->prox;
       free(lixo);
   }else{
      printf("Elemento não encontrado");
   } 
   return(topo);
}

celula *removerElementosNegativos(celula *topo){
   celula *p, *aux;
   p=topo;
   while(p!=NULL){
        if(p->conteudo <= 0){
            if(p->ant != NULL) 
                p->ant->prox = p->prox;
            else 
                topo = topo->prox;
            
            if(p->prox!=NULL) 
                p->prox->ant = p->ant;
        
            aux = p;
            p=p->prox;
            
            free(aux);
        }else p=p->prox;
   }
   return(topo);
}


celula *inserirNoInicio(int x, celula *topo){
   celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = x;
    nova->ant = NULL;
    nova->prox = NULL;
   if (topo != NULL){
        topo->ant = nova;
        nova->prox = topo;
   }
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
    printf("Lista Duplamente Encadeada \n");
    celula *topo, *buscado;
   
    for(int j=0; j<10;j++){
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserirNoInicio(resp, topo);
        imprimir(topo);
    }
    printf("Fim da Inserção \n");
   
    while (resp2){
        printf("Excluindo números negativos...\n");
        
        topo = removerElementosNegativos(topo);
       
        imprimir(topo);
       
       printf("Deseja repetir a busca? 1 - Sim, 0 - Não\n");
       scanf("%d", &resp2);
    }
}