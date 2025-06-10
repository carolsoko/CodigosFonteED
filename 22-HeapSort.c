//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

int main() {
	int vetor[]={16,8,0,3,4,7,13,22,123,675,111,576,97,15,6,5,1,24,14,9,77,11,12,87,33,59,89,56,32,90,34};
    int max = sizeof(vetor)/ sizeof(vetor[0]);

	printf("Vetor Original:\n");
  	for (int i = 0; i < max; ++i)
    printf("Vetor v[%d] = %d\n", i, vetor[i]);

	heapsort(vetor,max);
	
	printf("Vetor Ordenado:\n");
	for (int i = 0; i < max; ++i)
    printf("Vetor v[%d] = %d\n", i, vetor[i]);
    
	return(0);
}