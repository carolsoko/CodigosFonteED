/***    2. Sistema de Notas e Estatísticas da Turma (Valor: 6,0pts):  Faça um algoritmo 
que gerencie os dados de alunos de uma disciplina. Para isso, você deve: 
        a) Definir uma struct chamada Aluno, com os seguintes campos: (nome (até 50 
        caracteres), matricula (inteiro), notas (vetor com 3 notas reais), media (real)).
        b) Faça funcões que:
            1. Leia os dados de até 100 alunos (permitir que o usuário informe quantos 
            alunos ele deseja cadastrar, entre 1 e 100).
            2. Calcule a média de cada aluno (com base nas 3 notas) e armazene no campo 
            media.
            3. Encontre e exiba: O aluno com maior média, O aluno com menor média, A média 
            geral da turma, Quantos alunos foram aprovados, considerando média maior ou 
            igual a 7.0 como critério de aprovação.
            ***/
            
#include <stdio.h>

#define TAM 100

typedef struct Aluno{
    char nome[50];
    int matricula;
    float nota[3];
    float media;
}aluno;

void lerDados(aluno lista[], int qtde){
    for(int i=0; i<qtde; i++){
        printf("Informe o nome do %dº aluno: ",i+1);
        scanf("%s",lista[i].nome);
        printf("Informe a matrícula do %dº aluno: ",i+1);
        scanf("%d",&lista[i].matricula);
        printf("Informe a primeira nota do %dº aluno: ",i+1);
        scanf("%f",&lista[i].nota[1]);
        printf("Informe a segunda nota do %dº aluno: ",i+1);
        scanf("%f",&lista[i].nota[2]);
        printf("Informe a terceira nota do %dº aluno: ",i+1);
        scanf("%f",&lista[i].nota[3]);
    }
}

void calculaMedia(aluno lista[], int qtde){
    for(int i=0; i<qtde; i++)
        lista[i].media = (lista[i].nota[1]+lista[i].nota[2]+lista[i].nota[3])/3;
}

void encontrar(aluno lista[], int qtde){
    float maior=lista[0].media;
    float menor=lista[0].media;
    float media=0;
    int aprovados=0;
    
    for(int i=0; i<qtde; i++){
        media += lista[i].media;
        if(lista[i].media>=7) aprovados++;
        if(lista[i].media>maior) maior = lista[i].media;
        if(lista[i].media<menor) menor = lista[i].media;
    }
    media = media/(float)qtde;
    printf("Menor = %.1f\nMaior = %.1f\nMédia da turma = %.1f\nQtde de aprovados = %d\n",menor,maior,media,aprovados);
}

void main(){
    aluno lista[TAM];
    int qtde, sair;
    
    do{
        printf("Cadastro de alunos\n");
        printf("Informe quantos alunos deseja cadastrar:\n");
        scanf("%d%*c",&qtde);
        lerDados(lista,qtde);
        calculaMedia(lista,qtde);
        encontrar(lista,qtde);
        
        printf("Deseja repetir? 1-Sim 2-Não");
        scanf("%d",&sair);
    }while(sair==1);    
}
            