//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int busca_r (int x, int n, int v[]) {
   if (n == 0) return -1;
   if (x == v[n-1]) return n-1;
   return busca_r (x, n-1, v);
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
  
  i = busca_r(aux, 10, v);
  printf("Posição do item no original= %d\n", i);
  i = busca_r(aux, 10, v1);
  printf("Posição do item no permutado= %d\n", i);
}
