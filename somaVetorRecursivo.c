// Faça um algoritmo recursivo que soma todos os valores de um vetor
#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int somar(int qtde, int v[]){
    if(qtde == 0) return 0;
    return v[qtde-1] + somar(qtde-1,v);
}

void main(){
    int vetor[TAM];
    int soma;
   
    printf("Elementos do vetor: \n");
    for(int i=0; i<TAM;i++){
        vetor[i] = rand()%100;
        printf("%d, ",vetor[i]);
    }
       
    printf("Soma dos elementos = %d\n",somar(TAM,vetor));
   
}