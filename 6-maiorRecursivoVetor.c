//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int maior_r (int tam, int v[]){
    int maior;
    if (tam == 0) return -1;
    if (tam == 1) return v[0];
    maior = maior_r(tam-1,v);
    if (v[tam-1] > maior)
        return v[tam-1];
    else
        return maior;
}

int main (void){
int v1[]={134,3,234,7,567,5,678,2,899,0};
int v[100];
int tam, d=0;

for(tam=0;d!=-1;tam++){
    printf("Digite os elementos do vetor, digite -1 para sair\n");
    scanf("%d",&d);
    if(d!=-1)
     v[tam] = d;
}

  int i = maior_r(tam,v);
  printf("Maior item do Vetor= %d\n", i);
}