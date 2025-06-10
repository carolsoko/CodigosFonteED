
//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Sistema de Biblioteca


typedef struct LEITOR{
    int cpf;
    char nome[30];
    char endereco[30];
    int qtde;
    char livrosEmprestado[10][30];
    struct LEITOR *prox;
    struct LEITOR *ant;
}pessoa;

typedef struct LIVRO{
    char nome[30];
    int disponibilidade;
    struct LEITOR *filaEspera;
    struct  LIVRO *prox;
    struct  LIVRO *ant;
}exemplar;

pessoa *enfileirar(int cpf, pessoa *fila){
    pessoa *novo, *p;
    p = fila;
    novo = malloc (sizeof (pessoa));
    novo->cpf = cpf;
    novo->prox = NULL;
    novo->ant = NULL;
    if (p!=NULL){
        for(p;p->prox!= NULL;p=p->prox);
        p->prox=novo;
        novo->ant=p;
    }else fila = novo;
    return fila;
}

pessoa *buscar(char x[], pessoa *fila){
    pessoa *aux = fila;
    while(aux!=NULL && aux->nome!=x)
       aux=aux->prox;
    return aux;   
}

pessoa *desenfileirar(pessoa *fila){
   pessoa *p, *q;
   if (fila!=NULL){  
        q = fila;
        p=q->prox;
        p->ant = NULL;
        free(q);
        return p;
   }else return fila;
}


void imprimirFila(pessoa *fila) {
   pessoa *p;
   if (fila!=NULL)
        for (p=fila; p!=NULL; p=p->prox)
             printf ("%d\n", p->cpf);
}

void imprimirLeitores(pessoa *lista) {
   pessoa *p;
   if (lista!=NULL)
        for (p=lista; p!=NULL; p=p->prox)
             printf ("Nome: %s - CPF: %d\n", p->nome,p->cpf);
}

void imprimirLivros(exemplar *lista) {
   exemplar *p;
   if (lista!=NULL)
        for (p=lista; p!=NULL; p=p->prox)
             printf ("%s\n", p->nome);
}

exemplar *cadastraLivro(exemplar *lista){
    int i, resp=1;
    exemplar *aux, *novo;
    while(resp){
        printf("Informe o nome do livro a ser cadastrado:\n");
        novo = malloc (sizeof (exemplar));
        novo->prox = NULL;
        novo->ant = NULL;
        novo->disponibilidade = 1;
        novo->filaEspera = NULL;
        printf("Nome:");scanf("%s",novo->nome);
        
        if (lista == NULL) 
            lista = novo;
        else{
            for(aux=lista;aux->prox!=NULL;aux=aux->prox);
            aux->prox = novo;
            novo->ant = aux;
        }  
        
        printf("Deseja cadastrar novo livro? 1-Sim/0-Não:\n");
        scanf("%d",&resp);
    }
    return lista;
}

pessoa *cadastraLeitor(pessoa *lista){
    int i, resp=1;
    pessoa *aux, *novo;
    while(resp){
        printf("Informe os dados do leitor a ser cadastrado:\n");
        novo = malloc (sizeof(pessoa));
        novo->prox = NULL;
        novo->ant = NULL;
        printf("Nome:");scanf("%s",novo->nome);
        printf("CPF:");scanf("%d",&novo->cpf);
        printf("Endereço:");scanf("%s",novo->endereco);
        if (lista == NULL) 
            lista = novo;
        else{
            for(aux=lista;aux->prox!=NULL;aux=aux->prox);
            aux->prox = novo;
            novo->ant = aux;
        }
        printf("Deseja cadastrar novo leitor? 1-Sim/0-Não:\n");
        scanf("%d",&resp);
    }
    return lista;
}

void emprestarLivro(pessoa *leitor, exemplar *livro){
    
   if(livro->disponibilidade){
        leitor->qtde++;
        if (leitor->qtde <= 9){
            livro->disponibilidade = 0;
            strcpy(leitor->livrosEmprestado[leitor->qtde],livro->nome);
        }else{
            leitor->qtde--;
            printf("Leitor atingiu quantidade máxima de livros emprestados");
        }
    }else{
        livro->filaEspera = enfileirar(leitor->cpf, livro->filaEspera);
    }
}

void devolverLivro(pessoa *leitor, exemplar *livro){
    livro->disponibilidade = 1;
    leitor->qtde--;
}

pessoa *buscarLeitor(pessoa *lista, int cpf){
    pessoa *aux;
    for (aux=lista; aux!=NULL; aux=aux->prox)
        if (aux->cpf == cpf) break;
    return aux;
}

exemplar *buscarLivro(exemplar *lista, char nome[30]){
    exemplar *aux;
    
    for (aux = lista; aux!=NULL; aux=aux->prox)
        if(strcmp(aux->nome,nome) == 0) break;
    return aux;
}


int main(){
    int resp = 1, cpf;
    char nome[30];
    pessoa *listaLeitores, *Leitor;
    exemplar *listaLivros, *Livro;
    
    while(resp != 0){
    
        printf("Sistema de Biblioteca \n");
        printf("+++++++++++++++++++++ \n");
        printf("Informe a ação desejada:\n");
        printf("1 - Cadastro de Livro Novo \n");
        printf("2 - Cadastro de Leitor \n");
        printf("3 - Empréstimo de Livro\n");
        printf("4 - Devolução de Livro\n");
        printf("5 - Verificar se Leitor tem cadastro\n");
        printf("6 - Mostrar Leitores Cadastrados\n");
        printf("7 - Mostrar Livros Cadastrados\n");
        scanf("%d", &resp);
        
        switch (resp){
        case 1://1 - Cadastro de Livro Novo
            listaLivros = cadastraLivro(listaLivros);
        break;

        case 2://2 - Cadastro de Leitor Novo
            listaLeitores = cadastraLeitor(listaLeitores);
        break;

        case 3:// 3 - Empréstimo de Livro
            printf("Informe o nome do livro que deseja empréstimo:\n");
            scanf("%s",nome);
            Livro = buscarLivro(listaLivros, nome);
            if(Livro == NULL){
                printf("Livro não cadastrado!\n");
                break;
            }
            
            printf("Informe o cpf do leitor cadastrado:\n");
            scanf("%d",&cpf);
            Leitor = buscarLeitor(listaLeitores, cpf);
            
            if(Leitor == NULL){
                printf("Leitor não cadastrado!\n");
                break;
            }
            emprestarLivro(Leitor, Livro);
        break;
        
        case 4://4 - Devolução de Livro
            printf("Informe o nome do livro que deseja empréstimo:\n");
            scanf("%s",nome);
            Livro = buscarLivro(listaLivros, nome);
            if(Livro == NULL){
                printf("Livro não cadastrado!\n");
                break;
            }
            
            printf("Informe o cpf do leitor cadastrado:\n");
            scanf("%d",&cpf);
            Leitor = buscarLeitor(listaLeitores, cpf);
            
            if(Leitor == NULL){
                printf("Leitor não cadastrado!\n");
                break;
            }
            devolverLivro(Leitor, Livro);
        break;
        
        case 5://5 - Verificar se Leitor tem cadastro
            printf("Informe o cpf do leitor cadastrado:\n");
            scanf("%d",&cpf);
            Leitor = buscarLeitor(listaLeitores, cpf);
            
            if(Leitor == NULL)
                printf("Leitor não Cadastrado!\n");
            else
                printf("Leitor Cadastrado!\n");
        break;
        
        case 6://6 -Listar Leitores
            imprimirLeitores(listaLeitores);
        break;
        
        case 7:// 7 - Listar Livros
           imprimirLivros(listaLivros);
        break;
        default:
            printf("Opção Inválida");
        }
    }
}