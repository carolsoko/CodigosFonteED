//---------------------------------------------------------------------
//
// Algoritmo desenvolvido pela professora Ana Carolina Sokolonski Anton
// na disciplina de Estruturas de Dados no IFBA Campus Feira de Santana
//
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct btreePagina {
  int item[2*MAX];
  int qtde;
  struct btreePagina *ponteiro[2*MAX + 1];
};


// Criando uma página na árvore B
struct btreePagina *criarPagina(int item, struct btreePagina *filho, struct btreePagina *raiz) {
  struct btreePagina *novaPagina;
  novaPagina = (struct btreePagina *)malloc(sizeof(struct btreePagina));
  novaPagina->item[1] = item;
  novaPagina->qtde = 1;
  novaPagina->ponteiro[0] = raiz;
  novaPagina->ponteiro[1] = filho;
  return novaPagina;
}

// Insere um valor na árvore
void insereValor(int item, int pos, struct btreePagina *pagina,
          struct btreePagina *filho) {
  int j = pagina->qtde;
  while (j > pos) {
    pagina->item[j + 1] = pagina->item[j];
    pagina->ponteiro[j + 1] = pagina->ponteiro[j];
    j--;
  }
  pagina->item[j + 1] = item;
  pagina->ponteiro[j + 1] = filho;
  pagina->qtde++;
}

// Divide uma pagina
void dividePagina(int item, int *paginaValor, int pos, struct btreePagina *pagina,
         struct btreePagina *filho, struct btreePagina **novaPagina) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *novaPagina = (struct btreePagina *)malloc(sizeof(struct btreePagina));
  j = median + 1;
  while (j <= MAX) {
    (*novaPagina)->item[j - median] = pagina->item[j];
    (*novaPagina)->ponteiro[j - median] = pagina->ponteiro[j];
    j++;
  }
  pagina->qtde = median;
  (*novaPagina)->qtde = MAX - median;

  if (pos <= MIN) {
    insereValor(item, pos, pagina, filho);
  } else {
    insereValor(item, pos - median, *novaPagina, filho);
  }
  *paginaValor = pagina->item[pagina->qtde];
  (*novaPagina)->ponteiro[0] = pagina->ponteiro[pagina->qtde];
  pagina->qtde--;
}

//determina o valor da pagina
int setPaginaValor(int item, int *paginaValor,
           struct btreePagina *pagina, struct btreePagina **filho) {
  int pos;
  if (!pagina) {
    *paginaValor = item;
    *filho = NULL;
    return 1;
  }

  if (item < pagina->item[1]) {
    pos = 0;
  } else {
    for (pos = pagina->qtde;
       (item < pagina->item[pos] && pos > 1); pos--)
      ;
    if (item == pagina->item[pos]) {
      printf("Chaves duplicadas não são permitidas\n");
      return 0;
    }
  }
  if (setPaginaValor(item, paginaValor, pagina->ponteiro[pos], filho)) {
    if (pagina->qtde < MAX) {
      insereValor(*paginaValor, pos, pagina, *filho);
    } else {
      dividePagina(*paginaValor, paginaValor, pos, pagina, *filho, filho);
      return 1;
    }
  }
  return 0;
}

// Insere o valor
struct btreePagina *insere(int item, struct btreePagina *raiz) {
  int flag, i;
  struct btreePagina *filho;

  flag = setPaginaValor(item, &i, raiz, &filho);
  if (flag)
    raiz = criarPagina(i, filho, raiz);
  return raiz;    
}

// Copia o sucessor
void copiaSuccessor(struct btreePagina *paginaAtual, int pos) {
  struct btreePagina *sucessor;
  sucessor = paginaAtual->ponteiro[pos];

  for (; sucessor->ponteiro[0] != NULL;)
    sucessor = sucessor->ponteiro[0];
  paginaAtual->item[pos] = sucessor->item[1];
}

// Faz o shift da página da direita
void direitaShift(struct btreePagina *paginaAtual, int pos) {
  struct btreePagina *x = paginaAtual->ponteiro[pos];
  int j = x->qtde;

  while (j > 0) {
    x->item[j + 1] = x->item[j];
    x->ponteiro[j + 1] = x->ponteiro[j];
  }
  x->item[1] = paginaAtual->item[pos];
  x->ponteiro[1] = x->ponteiro[0];
  x->qtde++;

  x = paginaAtual->ponteiro[pos - 1];
  paginaAtual->item[pos] = x->item[x->qtde];
  paginaAtual->ponteiro[pos] = x->ponteiro[x->qtde];
  x->qtde--;
  return;
}

// faz o  shift na página da esquerda
void esquerdaShift(struct btreePagina *paginaAtual, int pos) {
  int j = 1;
  struct btreePagina *x = paginaAtual->ponteiro[pos - 1];

  x->qtde++;
  x->item[x->qtde] = paginaAtual->item[pos];
  x->ponteiro[x->qtde] = paginaAtual->ponteiro[pos]->ponteiro[0];

  x = paginaAtual->ponteiro[pos];
  paginaAtual->item[pos] = x->item[1];
  x->ponteiro[0] = x->ponteiro[1];
  x->qtde--;

  while (j <= x->qtde) {
    x->item[j] = x->item[j + 1];
    x->ponteiro[j] = x->ponteiro[j + 1];
    j++;
  }
  return;
}

// Junta as paginas
void juntaPaginas(struct btreePagina *paginaAtual, int pos) {
  int j = 1;
  struct btreePagina *x1 = paginaAtual->ponteiro[pos], *x2 = paginaAtual->ponteiro[pos - 1];

  x2->qtde++;
  x2->item[x2->qtde] = paginaAtual->item[pos];
  x2->ponteiro[x2->qtde] = paginaAtual->ponteiro[0];

  while (j <= x1->qtde) {
    x2->qtde++;
    x2->item[x2->qtde] = x1->item[j];
    x2->ponteiro[x2->qtde] = x1->ponteiro[j];
    j++;
  }

  j = pos;
  while (j < paginaAtual->qtde) {
    paginaAtual->item[j] = paginaAtual->item[j + 1];
    paginaAtual->ponteiro[j] = paginaAtual->ponteiro[j + 1];
    j++;
  }
  paginaAtual->qtde--;
  free(x1);
}

// Ajusta a pagina
void ajustaPagina(struct btreePagina *paginaAtual, int pos) {
  if (!pos) {
    if (paginaAtual->ponteiro[1]->qtde > MIN) {
      esquerdaShift(paginaAtual, 1);
    } else {
      juntaPaginas(paginaAtual, 1);
    }
  } else {
    if (paginaAtual->qtde != pos) {
      if (paginaAtual->ponteiro[pos - 1]->qtde > MIN) {
        direitaShift(paginaAtual, pos);
      } else {
        if (paginaAtual->ponteiro[pos + 1]->qtde > MIN) {
          esquerdaShift(paginaAtual, pos + 1);
        } else {
          juntaPaginas(paginaAtual, pos);
        }
      }
    } else {
      if (paginaAtual->ponteiro[pos - 1]->qtde > MIN)
        direitaShift(paginaAtual, pos);
      else
        juntaPaginas(paginaAtual, pos);
    }
  }
}

// Desenha a árvore B
void desenhar(struct btreePagina *paginaAtual) {
  int i;
  if (paginaAtual) {
    for (i = 0; i < paginaAtual->qtde; i++) {
      desenhar(paginaAtual->ponteiro[i]);
      printf("%d ", paginaAtual->item[i + 1]);
    }
    desenhar(paginaAtual->ponteiro[i]);
  }
}

int main() {
  int item, ch;
    
  struct btreePagina *raiz=NULL;
    
  do{
      printf("Informe uma chave inteira positiva a ser inserida na árvore ou -1 para sair: ");
      scanf("%d",&ch); 
      if(ch>=0)
        raiz = insere(ch, raiz);
      printf("Páginas folha da árvore B:\n");    
      desenhar(raiz);  
      printf("\n");
  }while(ch>=0);
}
