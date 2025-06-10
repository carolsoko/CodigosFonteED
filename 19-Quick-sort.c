//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }

int main(){
	// vetor que será ordenado
	int vet[] = {25,4,6,7,9,0,1,2,5,8,40,55,20,44,35,38,99,10,65,50};
	int tamVet = sizeof(vet) / sizeof(int);
	int i;
	
	// inicializa random seed
	srand(time(NULL));
	 
	// chamada do quicksort
	quick(vet, 0, tamVet - 1);

	// mostra o vetor ordenado
	for(i = 0; i < tamVet; i++)
		printf("%d ", vet[i]);
	
	return 0; 
}