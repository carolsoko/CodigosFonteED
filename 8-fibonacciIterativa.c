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
void fibonacci (int n){
    int fib, fib1, fib2, i;
    
    if (n == 0) {
        printf("0\n");
    } else if (n == 1){
        printf("0, 1\n");
    } else{
        printf("0, 1, ");
        fib1 = 1;
        fib2 = 0;
        i = 2;
        while (i <= n){
            fib = fib1+fib2;
            if (i==n) printf("%d\n", fib);
            else printf("%d, ", fib);
            fib2 = fib1;
            fib1 = fib;
            i++;
        }
    } 
    
}
int main (void){
int n,i;

  printf("Informe o número de fatores das sequências de Fibonacci:");  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Sequência de Fibonacci de %d fatores = ", i);
    fibonacci(i);
  }
}
