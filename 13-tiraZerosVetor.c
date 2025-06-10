//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Esta função elimina todos os elementos nulos de v[0..n-1].
// Supõe apenas que n >= 0. A função deixa o resultado em 
// v[0..i-1]  e devolve i.
int tirazeros (int n, int v[]) {
   int i = 0;
   for (int j = 0; j < n; ++j)  
      if (v[j] != 0) 
         v[i++] = v[j];
   return i;
}

int main (void){
int i,j,aux;
int v[]={0,8,0,3,4,7,0,6,5,1,0,2,9,0};
int tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor com zeros:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  
  tam = tirazeros(12,v);
  
  printf("Vetor sem zeros:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}