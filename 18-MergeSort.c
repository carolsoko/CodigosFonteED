
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>

void merge(int V[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; //pegando a quantidade da metade
    int n2 = r - m;     //pegando a quantidade da metade
  
    /* vetores temporários */
    int L[n1], R[n2]; 
  
    /* Copia os dados para os vetores temporários L e R */
    for (i = 0; i < n1; i++) L[i] = V[l + i]; 
    for (j = 0; j < n2; j++) R[j] = V[m + 1+ j]; 
  
    /* Merge (junta) os vetores temporários novamente dentro do V[l..r]*/
    i = 0; // Índice inicial do primeiro Subvetor 
    j = 0; // Índice inicial do segundo Subvetor 
    k = l; // Índice inicial do Subvetor juntado 
    while ((i < n1) && (j < n2)) { 
        if (L[i] <= R[j])  { 
            V[k] = L[i]; 
            i++; 
        } else { 
            V[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copia os elementos remanescentes de esquerdo, se existir algum */
    while (i < n1) { 
        V[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia os elementos remanescentes de direito, se existir algum */
    while (j < n2) { 
        V[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l é para o índice esquerdo e r para o índice direito do Subvetor de vetor que será ordenado */
void mergeSort(int V[], int l, int r){ 
    if (l < r) { 
        int m = (l+r)/2; 
  
        // Ordena as outras metades
        mergeSort(V, l, m); //chama a divisão para o lado esquerdo
        mergeSort(V, m+1, r); //chama a divisão para o lado direito
  
        //junta novamente
        merge(V, l, m, r); 
    } 
} 

void printVetor(int A[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() { 
    int V[] = {70, 11, 34, 23, 4, 5, 87, 2, 50, 30, 10, 89, 45, 20, 40, 60, 110, 1, 3}; 
    //Descobre o tamanho do vetor
    int V_size = sizeof(V)/sizeof(V[0]);   
  
    printf("Vetor Original: \n"); 
    printVetor(V, V_size); 
  
    mergeSort(V, 0, V_size - 1); 
  
    printf("\nVetor Ordenado:  \n"); 
    printVetor(V, V_size); 
    return 0; 
} 