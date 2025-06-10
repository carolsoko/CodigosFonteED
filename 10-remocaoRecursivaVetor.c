//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int remove_r (int k, int n, int v[]) {
   int x = v[k];
   if (k < n-1) {
      int y = remove_r (k+1, n, v); 
      v[k] = y;
   } return x;
}

int main (void){
int i,j,aux;
int v1[10],v[]={8,3,4,7,6,5,1,2,9,0};


  for (i = 0; i < 10; ++i)
    printf("Vetor original v[%d] = %d\n", i, v[i]);
  
  printf("Informe a posição do item que você deseja remover no vetor original:");  
  scanf("%d",&aux);
  
  i = remove_r(aux,10,v);
  printf("Item removido = %d\n", i);
  
  for (i = 0; i < 9; ++i)
    printf("Vetor original v[%d] = %d\n", i, v[i]);
}