//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void shellSort(int vet[], int tam) {
    int i , j , valor;
    int salto = 1;
    while(salto < tam) {
        salto = 3*salto+1;
    }
    while (salto > 1) {
        salto /= 3;
        for(i = salto; i < tam; i++) {
            valor = vet[i];
            j = i - salto;
            while ((j >= 0) && (valor < vet[j])) {
                vet [j + salto] = vet[j];
                j -= salto;
            }
            vet [j + salto] = valor;
        }
    }
}

int main(){
	// vetor que será ordenado
	int vet[] = {25,4,6,7,9,0,1,2,5,8,40,55,20,44,35,38,99,10,65,50,100,120,11,13};
	int tamVet = sizeof(vet) / sizeof(int);
	int i;
	
	// chamada do shellSort
	shellSort(vet, tamVet);

	// mostra o vetor ordenado
	for(i = 0; i < tamVet; i++)
		printf("%d ", vet[i]);
	
	return 0; 
}