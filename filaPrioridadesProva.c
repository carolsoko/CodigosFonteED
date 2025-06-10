//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct tarefa{
    int prioridade;
    int idTarefa;
    struct tarefa *prox;
}Job;

Job *enfileirar(Job *fila, int idTarefa,int prioridade){
    Job *novo = (Job *)malloc(sizeof(Job));
    novo->idTarefa = idTarefa;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (!fila) {
       return novo;
    }else if(prioridade < fila->prioridade){
    		novo->prox = fila;
    		return novo;
    }else if(!fila->prox){
    	fila->prox = novo;
    	return fila;
    }else{
    	Job *aux1 = fila;
    	Job *aux;
    	for(aux = fila->prox; aux!=NULL; aux=aux->prox){
    		if(prioridade < aux->prioridade){
    			aux1->prox = novo;
    			novo->prox = aux;
    			return fila;
    		}
    		aux1 = aux;
    	}
    	aux1->prox = novo;
    	return fila;
    }
}

Job *desenfileirar(Job *fila){
    Job *lixo = NULL;
    
    if(!fila) {
    	printf("\nFila vazia!!");
        return NULL;
    }else{
    	lixo = fila;
    	fila = fila->prox;
    	printf("\nDesenfileirada a tarefa %d!\n",lixo->idTarefa);
    	free(lixo);
    	return fila;
    }
}


void imprimir(Job *fila){
    printf("\n+-------+------------------+------------+\n");
    printf("| Ordem |     Elemento     | Prioridade |\n");
    printf("+-------+------------------+------------+\n");
    
    Job *aux = fila;
    
    int ordem = 1;
    
    while (aux != NULL) {
        printf("| %5d | %5d | %5d |\n", ordem, aux->idTarefa,aux->prioridade);
        aux = aux->prox;
        ordem++;
    }
    
    printf("+-------+------------------+------------+\n");
}

int main(){
    Job *fila = NULL;
    int opcao, id, prioridade;

    do {
        printf("======= Lista de prioridade =======\n\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Imprimir fila\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
            	printf("\nInforme o id da tarefa: ");
        		scanf("%d", &id);
        		printf("Informe a prioridade da tarefa: ");
        		scanf("%d", &prioridade);
                fila = enfileirar(fila, id, prioridade); 
                break;
            case 2:
                fila = desenfileirar(fila); 
                break;
            case 3:
                imprimir(fila); 
                break;
            case 0:
            	printf("Saindo...");
                break;
            default:
                printf("Opção invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}