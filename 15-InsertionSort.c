//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// 
void insertionSort(int tam, int v[]){
    int j,aux;
    for(int i=1; i<tam; i++){
        j = i;
        while((j>0) && (v[j]<v[j-1])){
            aux=v[j];
            v[j]=v[j-1];
            v[j-1]=aux;
            j--;
        }
    } 
}

int main (void){
int i,j,aux,tam;
int v[]={2,8,0,3,4,7,2,2,6,5,1,0,2,9,2,};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor Original:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  insertionSort(tam, v);
  
  printf("Vetor Ordenado:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}