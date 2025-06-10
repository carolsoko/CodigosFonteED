//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int buscaRetira2_r (int n, int v[]) {
   if (n == 0) return 0;
   int m = buscaRetira2_r (n - 1, v);
   if (v[n-1] == 2) return m;
   v[m] = v[n-1];
   return m + 1;
}

int main (void){
int i,j,aux,tam;
int v[]={2,8,2,3,4,7,2,6,5,1,0,2,9,7,0};
int tam = sizeof(v)/ sizeof(v[0]);


  printf("Vetor com zeros:\n");
  for (i = 0; i < tam; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  tam = buscaRetira2_r(tam,v);
  
  printf("Vetor sem zeros:\n");
  for (i = 0; i < j; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}