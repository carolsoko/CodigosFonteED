
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
// A função recebe x, n >= 0 e o vetor
// e devolve o índice i em 0..n-1 onde 
// x == v[i].Se i não existir, devolve -1.
#include <stdio.h>
#include <stdlib.h>

int busca (int x, int n, int v[]){
   int i;
   i = n-1;
   while (i >= 0 && v[i] != x) 
      i -= 1;
   return i;
}

int main (void){
int i,j,aux;
int v1[10],v[]={8,3,4,7,6,5,1,2,9,0};


  for (i = 0; i < 10; ++i){
    printf("Vetor original v[%d] = %d\n", i, v[i]);
    v1[v[i]] = i;} //permutando aqui
    
  for (j = 0; j < 10; ++j) printf("Permutado v[%d] = %d\n", j, v1[j]);
  
  printf("Informe qual o item deseja encontrar no vetor original:");  
  scanf("%d",&aux);
  
  i = busca(aux, 10, v);
  printf("Posição do item = %d\n", i);
}