/**Crie um programa que leia até 100 idades (inteiras), armazene-as e 
depois mostre-as. Crie funções e procedimentos para realizar as 
tarefas. **/

#include <stdio.h>

#define tam 100

void inserir(int id, int qtde, int idades[]){
    idades[qtde] = id;
}

int buscarRemover(int id, int qtde, int idades[]){
    
    for(int i=0; i<qtde; i++){
        if(idades[i]==id){
            for(int j=i; j<(qtde-1);j++)
                idades[j]=idades[j+1];
            printf("Elemento removido!\n");    
            return 1;
        }
    }
    printf("Elemento não encontrado!\n");
    return 0;
}

void mostrar(int qtde, int idades[]){
    for(int i=0; i< qtde; i++)
        printf("%d, ",idades[i]);
    printf("\n");    
    
}

void main(void){
    int idades[tam], id, qtde=0;
    int removeu;
    
    do{
        printf("Informe uma idade a ser inserida ou -1 para sair: ");
        scanf("%d",&id);
        
        if(id>=0){
            inserir(id,qtde,idades);
            qtde++;
            
            mostrar(qtde,idades);   
        }
    }while(id>=0);
    
    
    do{
        printf("Informe uma idade a ser removida ou -1 para sair: ");
        scanf("%d",&id);
        
        if(id>=0)
            if(buscarRemover(id,qtde,idades)) 
                qtde--;
        
        mostrar(qtde,idades);        
        
    }while(id>=0);
    
}

