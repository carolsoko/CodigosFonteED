//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim){
    int pivo, pivoIndice, i;
   
    pivo = vet[fim]; // o pivô é sempre o último elemento
    pivoIndice = inicio;
   
    for(i = inicio; i < fim; i++){
        // verifica se o elemento é <= ao pivô
        if(vet[i] <= pivo){
            // realiza a troca
            troca(vet, i, pivoIndice);
            // incrementa o pivo_indice
            pivoIndice++;
        }
    }
    // troca o pivô
    troca(vet, pivoIndice, fim);
    // retorna o índice do pivô
    return pivoIndice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particionaRandom(int vet[], int inicio, int fim){
    // seleciona um número entre fim (inclusive) e inicio (inclusive) aleatoriamente
    int pivoIndice = (rand() % (fim - inicio + 1)) + inicio;
    // faz a troca para colocar o pivô no fim
    troca(vet, pivoIndice, fim);
    // chama a particiona
    return particiona(vet, inicio, fim);
}

void quickSort(int vet[], int inicio, int fim){
    if(inicio < fim){
        // função particionar retorna o índice do pivô
        int pivoIndice = particionaRandom(vet, inicio, fim);
       
        // chamadas recursivas quick_sort
        quickSort(vet, inicio, pivoIndice - 1);
        quickSort(vet, pivoIndice + 1, fim);
    }
}

void printVetor(int A[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    // vetor que será ordenado
    int vet[] = {25,4,6,7,9,0,1,2,5,8,40,55,20,44,35,38,99,10,65,50};
    int tamVet = sizeof(vet) / sizeof(int);
    int i;
   
    //Mostra vetor original
    printf("Vetor Original: \n");
    printVetor(vet, tamVet);
     
    // chamada do quicksort
    quickSort(vet, 0, tamVet - 1);

    // mostra o vetor ordenado
    printf("\nVetor Ordenado:  \n");
    printVetor(vet, tamVet);
   
    return 0;
}