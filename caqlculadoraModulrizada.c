/**Faça um algoritmo que implemente um calculadora modularizada **/

#include <stdio.h>

void soma(float a, float b){
    printf("%.1f + %.1f = %.1f\n", a, b, a+b);
}

void subtracao(float a, float b){
    printf("%.1f - %.1f = %.1f\n", a, b, a-b);
}

void divisao(float a, float b){
    if(b==0){
        printf("Não é permitido realizar divisão por zero!\n");
    }else printf("%.1f/%.1f = %.1f\n", a, b, a/b);
}

void multiplicacao(float a, float b){
    printf("%.1f x %.1f = %.1f\n", a, b, a*b);
}

void main(){
    int x,y,resp;
    char op;
    do{
        printf("-----------Calculadora------------\n");
        printf("Digite a operação desejada:\n");
        printf("Número operador Número\n");
        scanf("%d%*c", &x);
        scanf("%c", &op);
        scanf("%d%*c", &y);
        switch (op){
            case '+': soma(x,y); break;
            case '-': subtracao(x,y); break;
            case '/': divisao(x,y); break;
            case '*': multiplicacao(x,y); break;
            default: printf("Operação Inválida!\n"); break;
        }
        printf("Deseja repetir a operação? 1-Sim 2-Não\n");
        scanf("%d%*c", &resp);
        
    }while(resp==1);
}