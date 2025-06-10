/**Em um banco, há apenas um caixa e todos devem ser atendidos por
ordem de chegada. No entanto, pessoas idosas têm prioridade e passam para
o início da fila. Considerando que, em vários dias, o número de idosos é muito
grande, foram estipuladas as seguintes regras:
1. uma pessoa é atendida na ordem de chegada.
2. no máximo 2 idosos podem passar na frente de uma pessoa que não é
idosa.
Escreva um programa que leia uma sequência de informação da ordem de
chegada e categoria do cliente e imprima a ordem de atendimento (considere
que todos chegaram antes de começar o atendimento, na ordem em que são
apresentados).
Ex. de entrada:
geral, geral, idoso, idoso, idoso, geral, idoso
ou pode ser lido tb: 1,1,2,2,2,1,2 (considerando que 1 é geral e 2 é idoso) Ex.
saída: 3 4 1 2 5 7 6
OBS.: Crie e use as funções enfileirar, desenfileirar, imprimir fila, etc, faça o 
algoritmo para funcionar com qualquer entrada fornecida. Pode usar números no lugar 
das palavras geral e idoso.**/

#include <stdio.h>
#include <stdlib.h>

typedef struct usuario {
    int categoria; // 1 - geral, 2 - idoso
    int ordemChegada;
    int ordemAtendimento;
    struct usuario *prox;
} cliente;

// Cria novo cliente
cliente* criarCliente(int categoria, int ordem) {
    cliente* novo = (cliente*)malloc(sizeof(cliente));
    novo->categoria = categoria;
    novo->ordemChegada = ordem;
    novo->ordemAtendimento = ordem;
    novo->prox = NULL;
    return novo;
}

// Atualiza a ordem de atendimento de acordo com a posição na fila
void atualizarOrdemAtendimento(cliente* fila) {
    int ordem = 1;
    while (fila != NULL) {
        fila->ordemAtendimento = ordem++;
        fila = fila->prox;
    }
}

// desenfileira o primeira da fila
cliente* desenfileirar(cliente* fila) {
    
    if(!fila) printf("Fila Vazia!\n");
    
    else{
        cliente* aux = fila;
        fila = fila->prox;

        printf("Removendo o elemento: %d\n",aux->categoria);
        aux->prox = NULL;
        free(aux);
    }

    return(fila);
}

// Enfileira cliente com regra dos idosos
cliente* enfileirar(cliente* topo, int categoria, int ordem) {
    cliente* novo = criarCliente(categoria, ordem);

    // Fila vazia
    if (!topo) return novo;

    // Cliente geral (categoria 1) vai sempre pro final da fila
    if (categoria == 1) {
        cliente* aux = topo;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        atualizarOrdemAtendimento(topo);
        return topo;
    }

    // Cliente idoso (categoria 2) pode furar até 2 clientes gerais
    cliente *atual = topo, *anterior = NULL;

    while (atual != NULL) {
        // Pode furar até dois clientes gerais seguidos
        if ((atual->categoria == 1) && ((atual->ordemAtendimento-atual->ordemChegada) < 2)) {
            if (anterior == NULL) {
                // Insere no início
                novo->prox = topo;
                atualizarOrdemAtendimento(novo);
                return novo;
            } else {
                anterior->prox = novo;
                novo->prox = atual;
                atualizarOrdemAtendimento(topo);
                return topo;
            }
        }

        atualizarOrdemAtendimento(topo);
        anterior = atual;
        atual = atual->prox;
    }

    // Se não furou ninguém, insere no final
    anterior->prox = novo;
    atualizarOrdemAtendimento(topo);
    return topo;
}

// Imprime ordem de atendimento
void imprimir(cliente* fila) {
    cliente* aux = fila;
    printf("\n--- Ordem de Atendimento ---\n");
    while (aux != NULL) {
        printf("Categoria: %d\nOrdem Chegada: %d\nOrdem Atendimento: %d\n\n",
               aux->categoria, aux->ordemChegada, aux->ordemAtendimento);
        aux = aux->prox;
    }
}

// Função principal
int main() {
    cliente* fila = NULL;
    int categoria, ordem = 0;
    char resp;

    do {
        printf("Informe a categoria do cliente (1 - geral, 2 - idoso): ");
        scanf("%d%*c", &categoria);
        ordem++;
        fila = enfileirar(fila, categoria, ordem);

        printf("Deseja inserir outro cliente? (S/N): ");
        scanf("%c%*c", &resp);
    } while (resp == 'S' || resp == 's');

    imprimir(fila);
    
    do {
        printf("Deseja desenfileirar cliente?: (S/N): ");
        scanf("%c%*c", &resp);
        
        if (resp == 'S' || resp == 's') fila = desenfileirar(fila);
        
        imprimir(fila);
        
    } while (resp == 'S' || resp == 's');
    
    return 0;
}