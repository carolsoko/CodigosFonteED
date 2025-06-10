#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 200

typedef struct{
    int prioridade;
    char conteudo[MAX_CARACTERES];
} Elemento;

typedef struct No{
    Elemento elemento;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

Fila *criarFila(){
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void adicionarElemento(Fila *fila, Elemento elemento){
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->elemento = elemento;
    novoNo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }

    fila->fim = novoNo;
    fila->tamanho++;
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

int verificarListaVazia(Fila *fila) {
    return (fila->inicio == NULL) ? -1 : 1;
}

void adicionarElementos(Fila *fila){
    
    char conteudo[MAX_CARACTERES];
    int prioridade;
    
    int tamanhoFilaAnterior = fila->tamanho;

    while (1){
        printf("Digite o conteudo do %do elemento ou 0 para parar: ", fila->tamanho + 1);
        fgets(conteudo, MAX_CARACTERES, stdin);
        conteudo[strcspn(conteudo, "\n")] = '\0';

        if (strcmp(conteudo, "0") == 0) {
            break;
        }
        
        int prioridade;
        do{
            printf("Digite a prioridade do %do elemento: ", fila->tamanho + 1);
            scanf("%d", &prioridade);
            limparBuffer();
            if(prioridade < 0){
                printf("Prioridade invalida. A prioridade deve ser igual ou maior que 0. ");
            }
        }while(prioridade < 0);

        Elemento novoElemento;
        strcpy(novoElemento.conteudo, conteudo);
        novoElemento.prioridade = prioridade;

        adicionarElemento(fila, novoElemento);
        
        quebraDeLinhaSimples();
    }
    
    quebraDeLinhaSimples();
    
    int tamanhoFilaPosterior = fila->tamanho;
    
    if(tamanhoFilaPosterior == tamanhoFilaAnterior){
        printf("Nenhum novo elemento foi adicionado. Nada foi feito.\n");
    }else{
        printf("Elemento(s) adicionado(s) com sucesso\n");
        printf("OBS: A função de adicionar nao enfileira os novos elementos na lista. Chame a funcao de enfileirar (segunda opcao do swith-case) para isso.\n");
    }
}

void trocarElementos(Elemento *elemento1, Elemento *elemento2){
    
    Elemento temp = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temp;
}

void selectionSort(Fila *fila){
    
    No *i, *j, *min;

    for (i = fila->inicio; i != NULL; i = i->proximo){
        min = i;

        for (j = i->proximo; j != NULL; j = j->proximo){
            if (j->elemento.prioridade < min->elemento.prioridade){
                min = j;
            }
        }

        if (min != i) {
            trocarElementos(&(i->elemento), &(min->elemento));
        }
    }
}

void enfileirar(Fila *fila){
    
    if (verificarListaVazia(fila) != 1) {
        printf("A fila esta vazia. Nao ha necessidade de enfileirar.\n");
        return;
    } else {
        selectionSort(fila);
        printf("A fila foi enfileirada com sucesso!\n");
    }
}

void desenfileirar(Fila *fila){
    
    if (verificarListaVazia(fila) != 1) {
        printf("A fila esta vazia. Nao possui elemento para desenfileirar.\n");
        return;
    } else {
        No *noRemovido = fila->inicio;
        fila->inicio = noRemovido->proximo;
        free(noRemovido);
        fila->tamanho--;

        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        printf("Lista desenfileirada com sucesso.\n");
    }
}

void buscarElementoFila(Fila *fila){
    
    char conteudo[MAX_CARACTERES];
    printf("Digite o conteudo do elemento a ser buscado: ");
    fgets(conteudo, MAX_CARACTERES, stdin);
    conteudo[strcspn(conteudo, "\n")] = '\0';

    No *noAtual = fila->inicio;
    int ordem = 1;
    int encontrado = 0;

    while (noAtual != NULL){
        if (strcmp(noAtual->elemento.conteudo, conteudo) == 0) {
            printf("Elemento %s encontrado. [Ocupa a %da posicao da fila. Possui prioridade %d.]\n", conteudo, ordem, noAtual->elemento.prioridade);
            encontrado = 1;
            break;
        }
        noAtual = noAtual->proximo;
        ordem++;
    }

    if (!encontrado){
        printf("O elemento nao foi encontrado na fila.\n");
        printf("Deseja adicionar o elemento a fila? (1 - Sim, 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao == 1) {
            int prioridade;
            do{
                printf("Digite a prioridade do elemento: ");
                scanf("%d", &prioridade);
                limparBuffer();
                if(prioridade < 0){
                    printf("Prioridade invalida. A prioridade deve ser igual ou maior que 0. ");
                }
            }while(prioridade < 0);

            Elemento novoElemento;
            strcpy(novoElemento.conteudo, conteudo);
            novoElemento.prioridade = prioridade;

            adicionarElemento(fila, novoElemento);
            // enfileirar(fila);
            // printf("O elemento foi adicionado a fila e a fila foi enfileirada com o novo elemento.\n");
            printf("Elemento adicionado com sucesso!\n");
            printf("OBS: A funcao de insercao da busca nao enfileira os novos elementos na lista. Chame a funcao de enfileirar (segunda opcao do swith-case) para isso.\n");
        } else {
            printf("Nada foi feito.\n");
        }
    }
}

void imprimir(Fila *fila){
    printf("\n+-------+--------------------------+------------+\n");
    printf("| Ordem |         Elemento         | Prioridade |\n");
    printf("+-------+--------------------------+------------+\n");
    
    No *noAtual = fila->inicio;
    int ordem = 1;
    
    while (noAtual != NULL) {
        printf("| %5d | %-24s | %10d |\n", ordem, noAtual->elemento.conteudo, noAtual->elemento.prioridade);
        noAtual = noAtual->proximo;
        ordem++;
    }
    
    printf("+-------+--------------------------+------------+\n");
}

void limparTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(){
    printf("Pressione a tecla ENTER para continuar...");
    getchar();
}

void quebraDeLinhaSimples(){
    printf("\n");
}

int main(){
    Fila *fila = criarFila();
    int opcao;

    do {
        limparTela();
        printf("======= Lista de prioridade =======\n\n");
        printf("1 - Adicionar elementos\n");
        printf("2 - Enfileirar\n");
        printf("3 - Desenfileirar\n");
        printf("4 - Buscar elemento\n");
        printf("5 - Imprimir fila\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        limparBuffer();
        
        quebraDeLinhaSimples();
        
        switch (opcao) {
            case 1:
                adicionarElementos(fila);
                quebraDeLinhaSimples();
                pause();
                break;
            case 2:
                enfileirar(fila);
                quebraDeLinhaSimples();
                pause();
                break;
            case 3:
                desenfileirar(fila);
                quebraDeLinhaSimples();
                pause();
                break;
            case 4:
                buscarElementoFila(fila);
                quebraDeLinhaSimples();
                pause();
                break;
            case 5:
                imprimir(fila);
                quebraDeLinhaSimples();
                pause();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                pause();
                break;
        }
    } while (opcao != 0);
    
    printf("Saindo...");

    return 0;
}