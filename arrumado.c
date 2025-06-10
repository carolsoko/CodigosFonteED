/***
  1. Um vetor ARRUMADO é um vetor v[p .. r] onde existe ao menos um j ∈ [p, r] tal 
que v[p..j − 1] ≤  v[j] ≤ v[j + 1..r] (ou seja, existe ao menos um j pertencente ao 
vetor v, cujos elementos da esquerda são menores que j e os elementos da direita são 
maiores que j). Escreva uma função que receba um vetor v[p..r] e informe se o vetor 
está ARRUMADO. Em caso afirmativo, o seu algoritmo deve devolver o valor de j, que é
o índice da posição em que está o elemento do MEIO que caracteriza o vetor como ARRUMADO. 
OBS.: Os vetores arrumados NÃO se resumem aos vetores ORDENADOS, ou vetores com todos 
os números iguais!! (valor: 4,0 pts) 
***/


#include <stdio.h>
#include <stdbool.h>

int encontrarJ(int v[], int tamanho) {
    for (int j = 1; j < tamanho - 1; j++) {
        bool esquerdaMenor = true;
        bool direitaMaior = true;

        // Verifica se todos os números à esquerda de 'J' são menores do que ele
        for (int i = 0; i < j; i++) {
            if (v[i] >= v[j]) {
                esquerdaMenor = false;
                break;
            }
        }

        // Verifica se todos os números à direita de 'J' são maiores do que ele
        for (int i = j + 1; i < tamanho; i++) {
            if (v[i] <= v[j]) {
                direitaMaior = false;
                break;
            }
        }

        if (esquerdaMenor && direitaMaior) {
            return v[j];
        }
    }

    return -1; // Retorna -1 se não existir um número J com as propriedades desejadas
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int v[tamanho];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v[i]);
    }

    int j = encontrarJ(v, tamanho);

    if (j != -1) {
        printf("Existe um numero J no vetor onde todos os numeros a esquerda dele sao menores e todos os numeros a direita dele sao maiores.\n");
        printf("Valor de J: %d\n", j);
    } else {
        printf("Nao existe um numero J no vetor com essa propriedade.\n");
    }

    return 0;
}
