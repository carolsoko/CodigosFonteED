/** Faça um algoritmo em C que receba do usuário um vetor com 10 posições. Em seguida, o algoritmo deve imprimir o maior e o menor elemento do vetor, informando a posição (índice) em que se encontram cada um deles.
**/

#include <stdio.h>

void main() {
    int vetor[10];
    int maior, menor, indMaior, indMenor;
   
    printf("Informe os valores do vetor:\n");
    for(int i=0;i<=9;i++){
        printf("Vetor[%d] = ",i);
        scanf("%d",&vetor[i]);
        if(i==0){
            menor = vetor[0];
            maior = vetor[0];
            indMaior = 0;
            indMenor = 0;
        }
       
        if(maior < vetor[i]){
            maior = vetor[i];
            indMaior = i;
        }
       
        if(menor > vetor[i]){
            menor = vetor[i];
            indMenor = i;
        }
    }
   
    printf("\nElementos do vetor = ");
    for(int i=0;i<=9;i++)
        printf("%d, ",vetor[i]);
   
    printf("\nMaior = %d\nÍndice do maior = %d",maior, indMaior);
    printf("\nMenor = %d\nÍndice do menor = %d",menor, indMenor);
}