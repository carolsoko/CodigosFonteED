//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
 
void selectionSort(int tam, int v[]){
    int aux, menor;
    for (int i = 0; i < tam; i++){
        menor = i;
        for(int j = i; j < tam; j++)
            if (v[j] < v[menor])
                menor = j;
            
        aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
    }
}

int main (void){
int i,j,aux,tam;
int v[]={16,8,0,3,4,7,13,22,6,5,1,24,12,9,77,34};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor Original:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  selectionSort(tam, v);
  
  printf("Vetor Ordenado:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}
