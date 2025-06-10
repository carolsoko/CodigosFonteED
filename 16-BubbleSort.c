//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// 
void bubbleSort(int tam, int v[]){
    int aux;
    for(int j=1; j<tam; j++){
        for(int i=1; i<tam; i++){
            if (v[i-1] > v[i]){
               aux=v[i];
               v[i]=v[i-1];
               v[i-1]=aux;
            }
        }
    } 
}

void bubbleSortFlag(int tam, int v[]){
    int aux,flag=1;
    do{
        flag=0;
        for(int i=1; i<tam; i++){
            if (v[i-1] > v[i]){
               aux=v[i];
               v[i]=v[i-1];
               v[i-1]=aux;
               flag=1;
            }
        }
    }while(flag); 
}



int main (void){
int i,j,aux,tam;
int v[]={16,8,0,3,4,7,13,22,6,5,1,24,12,9,77,34,120,56};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor Original:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  bubbleSortFlag(tam, v);
  
  printf("Vetor Ordenado:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}