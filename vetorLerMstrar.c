// Ler um vetor de inteiros e depois mostrá-lo
#include <stdio.h>

void main() {
    // Write C code here
    int v[10];
    
    for(int i=0; i<=9; i++){
        printf("Digite o elemento %d do vetor: ",i);
        scanf("%d", &v[i]);
    }
    
    for(int i=0; i<=9; i++){
        printf("%d, ",v[i]);
    }
}