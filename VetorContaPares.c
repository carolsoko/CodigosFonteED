/** Faça um algoritmo em C que leia um vetor de 10 posições, Conte e escreva quantos valores pares ele possui.
**/

#include <stdio.h>

void main() {
    int vetor[10];
    int pares = 0;
   
    printf("Informe os valores do vetor:");
    for(int i=0;i<=9;i++){
        printf("\nVetor[%d] = ",i);
        scanf("%d",&vetor[i]);
    }
   
     for(int i=0;i<=9;i++)
        if(vetor[i]%2 == 0) pares++;
   
    printf("\nElementos do vetor = ");
    for(int i=0;i<=9;i++)
        printf("%d, ",vetor[i]);
   
    printf("\n Quantidade de elementos pares = %d",pares);
}