/******************************************************************************
Faça um algoritmo que leia um vetor com n elementos desordenado
e implemente o BubbleSort para ordenar os seus elementos
*******************************************************************************/
#include <stdio.h>
#define tam 10

void BubbleSort(int qtde, int vetor[]){
    int aux;
    for(int i=0;i<qtde;i++)
        for(int j=0;j<(qtde-1);j++)
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
}

void BubbleSortOtimo(int qtde, int vetor[]){
    int aux, flag = 0;
    while(!flag){
        flag = 1;
        for(int j=0;j<(qtde-1);j++)
            if(vetor[j]>vetor[j+1]){
                flag = 0;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
    }        
}

void insereVetor(int qtde, int vetor[]){
    int x;
    printf("Informe o elemento a ser inserido: ");
    scanf("%d",&x);
    vetor[qtde] = x;
}


void imprimeVetor(int qtde, int vetor[]){
    printf("Elementos do vetor:\n");
    for(int i=0;i<qtde;i++)
        if(i==(qtde-1)) printf("%d",vetor[i]);
        else printf("%d, ",vetor[i]);
    printf("\n");    
}

void main(){
    int qtde = 0, resp, vetor[tam];
    
    do{
        printf("---------------------------------\n");
        printf("Informe a ação desejada:\n");
        printf("1 - Inserir elemento no vetor\n");
        printf("2 - Imprimir vetor\n");
        printf("3 - Ordenar vetor pelo BubbleSort Simples\n");
        printf("4 - Ordenar vetor pelo BubbleSort Otimizado\n");
        printf("5 - Sair\n");
        printf("---------------------------------\n");
        scanf("%d",&resp);
        
        switch(resp){
            case 1:
                insereVetor(qtde,vetor);
                qtde++;
                break;
            case 2:
                imprimeVetor(qtde,vetor);
                break;
            case 3:
                BubbleSort(qtde,vetor);
                break;
            case 4:
                BubbleSortOtimo(qtde,vetor);
                break;
            case 5:
                printf("Saindo...");
                break;
            default:break;   
        }
    }while(resp!=5);    
}