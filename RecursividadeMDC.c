// Online C compiler to run C program online
#include <stdio.h>

int MDC(int x, int y){
   if (x == y) return x;
   if (x < y) return MDC(y, x);
   return MDC(x-y, y);
}

int main() {
    int x,y;
    printf("Digite um dois números para o cálculo do MDC: ");
    scanf("%d %d",&x,&y);
    printf("MDC(%d,%d) = %d",x,y,MDC(x,y));
    return 0;
}