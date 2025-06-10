//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#define max 10
#define troca(A,B) {int t = A; A = B; B = t;}

static void 
constroiHeap (int m, int v[])
{
   for (int k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.
static void
peneira (int m, int v[])
{ 
   int p = 1, f = 2, x = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = x;
}

// Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente.

void
heapsort (int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}

int main() {
	int vetor[max], i;
	
	for(i = 0; i < max; i++){
	    printf("Digite o %dº elemento: ",i+1);
	    scanf("%d",&vetor[i]);
	}

	heapsort(max, vetor);
	for (i = 0; i < max; i++) {
		printf("%d ", vetor[i]);
	}
	return(0);
}