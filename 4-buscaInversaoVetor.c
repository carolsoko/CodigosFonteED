//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
/**Inversão.  
 * Suponha que um vetor v[1..n] contém uma permutação de 1..n. 
 * Escreva uma função que inverta essa permutação:  
 * se v[i] == j no vetor original, queremos ter v[j] == i 
 * no fim da execução da função.
**/
#include <stdio.h>
#include <stdlib.h>

int busca (int x, int n, int v[]){
   int i;
   /**i = n-1;
   while (i >= 0 && v[i] != x) 
      i -= 1;**/
   for(i = (n - 1); ((i >= 0) && (v[i] != x)); --i);  
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
  printf("Posição do item no original= %d\n", i);
  i = busca(aux, 10, v1);
  printf("Posição do item no permutado= %d\n", i);
}