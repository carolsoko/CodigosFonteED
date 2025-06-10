//Busca em vetor de inteiros e depois mostrá-lo
#include <stdio.h>

void main() {
    int v[10], resp, i;
    
    for(i=0; i<=9; i++){
        printf("Digite o elemento %d do vetor: ",i);
        scanf("%d", &v[i]);
    }
    
    printf("Qual elemento você deseja buscar?\n");
    scanf("%d",&resp);
    
    for(i=0; i<=9; i++){
        if(v[i]==resp){ 
            printf("Elemento encontrado na posição %d", i);
            break;
        }    
    }
    if(i==10) printf("Elemento não encontrado");
}