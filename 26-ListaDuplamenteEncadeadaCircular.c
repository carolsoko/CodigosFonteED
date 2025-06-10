//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    int conteudo;
    struct registro *ant;
    struct registro *prox;
}celula;

celula *inserir(int x, celula *topo){
    celula *novo, *aux;
    novo = malloc(sizeof(celula));
    novo->conteudo = x;
    novo->ant = novo;
    novo->prox = novo;
   
    if (topo==NULL){
        novo->ant = novo->prox = novo;
    }else if(topo->prox == topo){
        novo->prox = topo;
        novo->ant = topo;
        topo->prox = novo;
        topo->ant = novo;
    }else{
        for(aux = topo; aux->prox!=topo; aux=aux->prox);
        aux->prox = novo;
        topo->ant = novo;
        novo->prox = topo;
        novo->ant = aux;
    }
    topo = novo;
}

celula *buscar(int x, celula *topo){
    celula *aux;
    for(aux = topo; ; aux=aux->prox){
        if(aux->conteudo == x)
            return aux;
        if(aux->prox == topo) break;
    }
   
    return NULL;        
}

celula *remover(int x, celula *lixo, celula *topo){
    celula *aux;
    if (lixo == topo) topo = lixo->prox;
    for(aux = lixo; aux->prox!=lixo; aux=aux->prox);
    aux->prox = lixo->prox;
    lixo->prox->ant = aux;
    free(lixo);
    return topo;
}

void imprimir(celula * topo){
   celula *p;
   printf("Lista: "); 
   for (p = topo; p != NULL; p = p->prox){
      if (p == NULL) printf("Vazia!");  
      else printf ("%d, ", p->conteudo);
      if (p->prox == topo) { printf ("\n");break;}
   }
}

void main(){
    celula *lista=NULL, *aux=NULL;
    int resp,x;
   
   
    do{
        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Mostrar Lista\n");
        printf("4 - Remover elemento\n");
        printf("5 - Sair do programa\n");
        scanf("%d",&resp);
       
        switch(resp){
            case 1:
                printf("Informe o elemento a ser inserido: ");
                scanf("%d",&x);
                lista = inserir(x,lista);
                imprimir(lista);
                break;
            case 2:
                printf("Informe o elemento a ser buscado: ");
                scanf("%d",&x);
                aux = buscar(x,lista);
                if (aux == NULL) printf("Elemento não encontrado\n");
                else printf("Elemento encontrado na lista\n");
                break;
            case 3:
                imprimir(lista);
                break;    
            case 4:
                printf("Informe o elemento a ser removido: ");
                scanf("%d",&x);
                aux = buscar(x,lista);
                if (aux == NULL) printf("Elemento não encontrado\n");
                else lista = remover(x,aux,lista);
                imprimir(lista);
                break;
            case 5:
                printf("Saindo do pragrama..."); break;
            default:
                printf("Opção Inválida!");
        }
    }while(resp != 4);
}
