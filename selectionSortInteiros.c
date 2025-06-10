//---------------------------------------------------------------------
//
// selectionSort
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define TAM 25

void troca(int i, int j,int v[]){
    int aux;
    
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
 
void selectionSort(int tam, int v[]){
    int split, menor, posMenor;
    
    for(split = 0; split < tam; split++){
        menor = v[split];
        posMenor = split;
        for(int i=split; i < tam; i++)
            if (v[i] < menor){
                menor = v[i];
                posMenor = i;
            }
        troca(posMenor,split,v);    
    }
}

int main (void){
int i,j,aux, v[TAM];

  printf("Vetor Original:\n");
  for (i = 0; i < TAM; ++i){
    v[i] = rand()%50;
    printf("Vetor v[%d] = %d\n", i, v[i]);
  }
 
 selectionSort(TAM,v);
 
  printf("Vetor Ordenado:\n");
  for (i = 0; i < TAM; ++i)https://www.onlinegdb.com/online_c_compiler#tab-stdin
    printf("Vetor v[%d] = %d\n", i, v[i]);
}