
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
/*
Altere o Algoritmo Bubble Sort para que ele pare assim que for possível
perceber que o vetor está ordenado. Qual o custo deste novo algoritmo
em termos do número de comparações entre elementos do vetor (tanto
no melhor, quanto no pior caso)?
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int tam, int v[]){
    int aux,flag = 1;
    while (flag){
        flag = 0;
        for(int i=1; i<tam; i++){
            if (v[i-1] > v[i]){
               flag = 1;
               aux=v[i];
               v[i]=v[i-1];
               v[i-1]=aux;
            }
        }
    } 
}

int main (void){
int i,j,aux,tam;
int v[]={16,8,0,3,4,7,13,22,6,5,1,24,12,9,77,11,12,87,33,56,89,56,32,90,34};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor Original:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  bubbleSort(tam, v);
  
  printf("Vetor Ordenado:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}