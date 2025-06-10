//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Esta função insere x entre as posições k-1 e k do vetor v[0..n-1] 
// supondo que 0 <= k <= n.
void inserir_r (int k, int x, int n, int v[]) {
   if (k == n)  v[n] = x;
   else {
      v[n] = v[n-1];
      inserir_r (k, x, n - 1, v);
   }
}

int main (void){
int i,j,aux;
int v[]={8,3,4,7,6,5,1,2,9,0};


  for (i = 0; i < 10; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
  
  printf("Informe o item a ser inserido no vetor:");  
  scanf("%d",&aux);
  
  printf("Informe a posição que deve inserir o item no vetor:");  
  scanf("%d",&j);
  
  inserir_r(j,aux,10, v);
  
  for (i = 0; i < 11; ++i)
    printf("Vetor v[%d] = %d\n", i, v[i]);
}