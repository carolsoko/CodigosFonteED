#include <stdio.h>
#define tamanho 5

void main(){
    double notaAluno[tamanho][4];
    for (int i = 0; i <= (tamanho-1); i++){
        for (int j = 0; j <= 3; j++){
            printf ("Informe Prova %d da %dª pessoa: ",j+1,i+1);
            scanf ("%lf", &notaAluno[i][j]);
        }
    }
    
    printf("Segue listagem de notas por aluno: \n");
    for (int i = 0; i <= (tamanho-1); i++){
        printf ("%dº aluno: ",i+1);
        for (int j = 0; j <= 3; j++){
            printf("%2.2f ",notaAluno[i][j]);
        }
        printf ("\n");
    }
}
