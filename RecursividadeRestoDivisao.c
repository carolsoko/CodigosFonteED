// Faça um algoritmo que calcula o reto da divisão de forma recursiva
#include <stdio.h>

int MOD(int x, int y){
   if (x == y) return 0;
   if (x < y) return x;
   return MOD(x-y, y);
}

int main() {
    int x,y;
    printf("Digite um dois números para o cálculo do resto da divisão: ");
    scanf("%d %d",x,y);
    printf("MOD(%d,%d) = %d",x,y,MOD(x,y));
    return 0;
}