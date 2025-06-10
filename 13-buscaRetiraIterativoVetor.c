//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Esta função elimina todos os elementos 2 de v[0..n-1].
// Supõe apenas que n >= 0. A função deixa o resultado em 
// v[0..i-1]  e devolve i.
int buscaRetira2 (int n, int v[]) {
   int i = 0;
   for (int j = 0; j < n; ++j)  
      if (v[j] != 2) 
         v[i++] = v[j];
   return i;
}

int main (void){
int i,j,aux,tam;
int v[]={2,8,0,3,4,7,2,2,6,5,1,0,2,9,2,};
tam = sizeof(v)/ sizeof(v[0]);

  printf("Vetor com números 2:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  
  j = buscaRetira2(tam,v);
  
  printf("Vetor sem números 2:\n");
  for (i = 0; i < j; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}