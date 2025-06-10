
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
//BubbleSort Modificado - Faça um algoritmo que modifique o BubbleSort para que ele comece 
//sempre do meio e parta para as pontas no sentido decrescente para a esquerda e crescente 
//para direita
 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 
void bubbleSort(int tam, int v[]){
    int aux,flag = 1;
    int meio = ceil(tam/2);
    while (flag){
        flag = 0;
        for(int i=meio; i<tam; i++){
            if (v[i-1] > v[i]){
               flag = 1;
               aux=v[i];
               v[i]=v[i-1];
               v[i-1]=aux;
            }
        }
        for(int i=(meio-1); i>=1; i--){
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
int v[]={16,8,0,3,4,7,13,22,6,5,1,24,12,9,77,34,11,45,76,89,100,2,33};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor Original:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  bubbleSort(tam, v);
  
  printf("Vetor Ordenado:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}
