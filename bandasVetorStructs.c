/** Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda, o tipo de música que ela toca, o número de integrantes e em que posição do ranking essa banda está dentre as suas 5 bandas favoritas. Em seguida, preencha as 5 estruturas de bandas criadas. Após criar e preencher, exiba todas as informações das bandas/estruturas.
(a) Faça um MENU para controlar as interações com o usuário.
(b) Solicite ao usuário um número de 1 até 5. Em seguida, exiba informações da banda cuja posição no seu ranking é a que foi solicitada pelo usuário
(c) Solicite ao usuário um tipo de música (forneça opções para escolha) e exiba as bandas com esse tipo de música no seu ranking.
(d) Solicite ao usuário o nome de uma banda ao usuário e diga se ela está entre suas bandas favoritas ou não.**/

#include <stdio.h>
#include <string.h>


typedef struct bandaStruct{
    char nome[30];
    char tipoMusica[10];
    int qtdeIntegrantes;
    int ranking;
}banda;

void main() {
    banda Vbandas[5];
    int resp, posicao;
    char tipo[10];
    
    do{
        printf("----------------------------------\n");
        printf("    Escolha uma das opções abaixo:\n");
        printf("1 - Preencher Ranking de Bandas   \n");
        printf("2 - Buscar pela posição no Ranking\n");
        printf("3 - Buscar pelo tipo de música    \n");
        printf("4 - Buscar pelo nome da banda     \n");
        printf("5 - Sair do programa              \n");
        printf("----------------------------------\n");
        scanf("%d",&resp);
        getchar();
        
        switch (resp){
            case 1: 
                printf("Informe os dados das bandas:\n");
                for(int i=0;i<=4;i++){
                    printf("Nome da Banda %d: ",i+1);
                    scanf("%s",Vbandas[i].nome);
                    getchar();
                    printf("Tipo de Música: ");
                    scanf("%s",Vbandas[i].tipoMusica);
                    getchar();
                    printf("Qtde de integrantes: ");
                    scanf("%d",&Vbandas[i].qtdeIntegrantes);
                    printf("Ranking: ");
                    scanf("%d",&Vbandas[i].ranking);
                }
                break;
            case 2:
                printf("Informe a posição do ranking desejada:\n");
                scanf("%d",&posicao);
                
                if((posicao < 1)|| (posicao > 5)){
                    printf("Posição informada inválida");
                }else{
                    for(int i=0;i<=4;i++)
                        if(Vbandas[i].ranking == posicao){
                            printf("Nome da Banda: %s\n",Vbandas[i].nome);
                            printf("Tipo de Música: %s\n",Vbandas[i].tipoMusica);
                            printf("Qtde de integrantes: %d\n",Vbandas[i].qtdeIntegrantes);
                        }
                }break;
            case 3:
            	getchar();
                printf("Informe o tipo da música desejada:\n");
                scanf("%s",tipo);
                getchar();
                for(int i=0;i<=4;i++)
                    if(strcmp(Vbandas[i].tipoMusica,tipo)==0){
                            printf("Nome da Banda: %s\n",Vbandas[i].nome);
                            printf("Qtde de integrantes: %d\n",Vbandas[i].qtdeIntegrantes);
                            printf("Posição Ranking: %d\n",Vbandas[i].ranking);
                        }
                break;    
            case 4: 
                int i;
                getchar();
                printf("Informe o nome da banda desejada:\n");
                scanf("%s",tipo);
                getchar();
                for(i=0;i<=4;i++)
                    if(strcmp(Vbandas[i].nome,tipo)==0){
                            printf("Nome da Banda: %s\n",Vbandas[i].nome);
                            printf("Qtde de integrantes: %d\n",Vbandas[i].qtdeIntegrantes);
                            printf("Posição Ranking: %d\n",Vbandas[i].ranking);
                            break;
                        }
                if(i==5){
                    printf("Banda não encontrada!\n");
                }     
                break; 
        }
        
    }while(resp!=5);
}