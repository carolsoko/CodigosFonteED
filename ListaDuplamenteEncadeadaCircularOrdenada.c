/******************************************************************************
Faça um algoritmo que implemente uma lista duplamente encadeada circular de 
números inteiros. Nesta lista, a inserção sempre deverá ser feita de forma 
ordenada crescente, inserindo sempre o elemento na sua posição correta 
(a inserção deve ser feita de acordo com com o valor do elemento a ser inserido, 
e não no início ou no fim da lista). Faça a função de inserção e de exibição da 
lista, para que possamos exibir a lista antes e depois da inserção, podendo 
conferir se a inserção foi feita corretamente. (valor: 2,0pts)
*******************************************************************************/

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
    celula *novo=NULL, *aux=topo;
    novo = malloc(sizeof(celula));
    novo->conteudo = x;
    novo->ant = novo;
    novo->prox = novo;
   
    if (topo==NULL){
       topo = novo;
    }else if(topo->prox == topo){
        novo->prox = topo;
        novo->ant = topo;
        topo->prox = novo;
        topo->ant = novo;
        if(topo->conteudo > novo->conteudo){    
            topo = novo;
        }
    }else{
        for(aux = topo;aux!=NULL; aux=aux->prox){
            if(topo->conteudo > novo->conteudo){
                novo->prox = topo;
                novo->ant = topo->ant;
                novo->ant->prox = novo;
                topo->ant = novo;
                topo = novo;
                break;
            }
            if(aux->prox->conteudo > novo->conteudo){
                novo->prox = aux->prox;
                novo->prox->ant = novo;
                aux->prox = novo;
                novo->ant = aux;
                break;
            }
            if(aux->prox==topo){
                novo->prox = topo;
                novo->ant = aux;
                aux->prox = novo;
                topo->ant = novo;
                break;
            }
        }
    }
    
    return topo;
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