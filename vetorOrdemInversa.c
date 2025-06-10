/** Faça um algoritmo em C que receba do usuário um vetor com 10 posições. Em seguida, o 
algoritmo deve imprimir o vetor na ordem inversa.
**/

#include <stdio.h>

void main() {
    int vetor[10];
    printf("Informe os valores do vetor:\n");
    for(int i=0;i<=9;i++){
        printf("Vetor[%d] = ",i);
        scanf("%d",&vetor[i]);
    }
   
    printf("\nElementos do vetor na ordem inversa= ");
    for(int i=9;i>=0;i--)
        printf("%d, ",vetor[i]);
}