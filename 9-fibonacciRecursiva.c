//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/**A função de Fibonacci é definida assim:   F(0) = 0,  F(1) = 1   e   F(n) = F(n-1) + F(n-2)   
para n > 1. Descreva a função F em linguagem C. Faça uma versão recursiva e uma iterativa.**/
int fibonacci (int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
int main (void){
int n, fib, i;

  printf("Informe o número de fatores das sequências de Fibonacci:");  
  scanf("%d",&n);
  for (i = 0; i <= n; i++)
     printf("Parcela %d da sequência = %d\n",i,fibonacci(i));
}