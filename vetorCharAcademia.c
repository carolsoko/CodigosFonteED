#include <stdio.h>
#define tamanho 100

typedef struct alunoAcademia{
    int idade; 
    float altura;
    float peso;
    char nome[30];
    char endereco[50];
    char telefone[11];
} aluno;

void main(){
aluno classe[tamanho];
for (int i = 0; i <= (tamanho-1); i++){
printf ("Informe o nome da %dª pessoa: ",i+1);
scanf ("%s", classe[0].nome); getchar();
printf ("Informe a idade da %dª pessoa: ",i+1);
scanf ("%d", &classe[0].idade);
printf ("Informe a altura da %dª pessoa: ",i+1);
scanf ("%f", &classe[0].altura);
printf ("Informe o peso da %dª pessoa: ",i+1);
scanf ("%f", &classe[0].peso);
printf ("Informe o endereço da %dª pessoa: ",i+1);
scanf ("%s", classe[0].endereco); getchar();
printf ("Informe o telefone da %dª pessoa: ",i+1);
scanf ("%s", classe[0].telefone);getchar();
}}