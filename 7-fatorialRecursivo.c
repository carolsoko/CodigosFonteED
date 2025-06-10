//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int fat (int n){
    if (n == 1){
        printf("1 = ");
        return 1;
    }
    else{
        printf("%d*",n);
        return (n * fat(n-1));
    }
}

int main (void){
int n;

  printf("Informe o número que você deseja saber o fatorial:");  
  scanf("%d",&n);
  printf("%d! = ",n);
  printf("%d\n", fat(n));
}