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

#typedef struct btreePagina{
  int item[2*MAX];
  int qtde;
  struct btreePagina *ponteiro[2*MAX + 1];
}PAGINA;



// Cria página
PAGINA *criarPagina(int item, PAGINA *filho, PAGINA *raiz) {
  PAGINA *novaPagina;
  novaPagina = (PAGINA *)malloc(sizeof(PAGINA));
  novaPagina->item[1] = item;
  novaPagina->qtde = 1;
  novaPagina->ponteiro[0] = raiz;
  novaPagina->ponteiro[1] = filho;
  return novaPagina;
}

// Adiciona valor na Página
void adicionaValorPagina(int item, int pos, PAGINA *pagina,
          PAGINA *filho) {
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

// Split the pagina
void dividePagina(int item, int *valor, int pos, PAGINA *pagina,
         PAGINA *filho, PAGINA **novaPagina) {
  int media, j;

  if (pos > MIN)
    media = MIN + 1;
  else
    media = MIN;

  *novaPagina = (PAGINA *)malloc(sizeof(PAGINA));
  j = media + 1;
  while (j <= MAX) {
    (*novaPagina)->item[j - media] = pagina->item[j];
    (*novaPagina)->ponteiro[j - media] = pagina->ponteiro[j];
    j++;
  }
  pagina->qtde = media;
  (*novaPagina)->qtde = MAX - media;

  if (pos <= MIN) {
    adicionaValorPagina(item, pos, pagina, filho);
  } else {
    adicionaValorPagina(item, pos - media, *novaPagina, filho);
  }
  *valor = pagina->item[pagina->qtde];
  (*novaPagina)->ponteiro[0] = pagina->ponteiro[pagina->qtde];
  pagina->qtde--;
}

// Determina valor na Pagina
int copiaValorNaPagina(int item, int *valor,
           PAGINA *pagina, PAGINA **filho) {
  int pos;
  if (!pagina) {
    *valor = item;
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
  if (copiaValorNaPagina(item, valor, pagina->ponteiro[pos], filho)) {
    if (pagina->qtde < MAX) {
      adicionaValorPagina(*valor, pos, pagina, *filho);
    } else {
      dividePagina(*valor, valor, pos, pagina, *filho, filho);
      return 1;
    }
  }
  return 0;
}

// Insertion operation
PAGINA *insere(int item, PAGINA *raiz) {
  int flag, i;
  PAGINA *filho;

  flag = copiaValorNaPagina(item, &i, raiz, &filho);
  if (flag)
    raiz = criarPagina(i, filho, raiz);
   
  return raiz;  
}

// Copia o successor
void copiaSuccessor(PAGINA *paginaAtual, int pos) {
  PAGINA *sucessor;
  sucessor = paginaAtual->ponteiro[pos];

  for (; sucessor->ponteiro[0] != NULL;)
    sucessor = sucessor->ponteiro[0];
  paginaAtual->item[pos] = sucessor->item[1];
}

// remove o valor
void removeValor(PAGINA *paginaAtual, int pos) {
  int i = pos + 1;
  while (i <= paginaAtual->qtde) {
    paginaAtual->item[i - 1] = paginaAtual->item[i];
    paginaAtual->ponteiro[i - 1] = paginaAtual->ponteiro[i];
    i++;
  }
  paginaAtual->qtde--;
}

// faz o shift na direita
void shiftDireita(PAGINA *paginaAtual, int pos) {
  PAGINA *x = paginaAtual->ponteiro[pos];
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

// faz o shift na esquerda
void shiftEsquerda(PAGINA *paginaAtual, int pos) {
  int j = 1;
  PAGINA *x = paginaAtual->ponteiro[pos - 1];

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

// Junta páginas
void juntaPaginas(PAGINA *paginaAtual, int pos) {
  int j = 1;
  PAGINA *x1 = paginaAtual->ponteiro[pos], *x2 = paginaAtual->ponteiro[pos - 1];

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

// Ajusta pagina
void ajustaPagina(PAGINA *paginaAtual, int pos) {
  if (!pos) {
    if (paginaAtual->ponteiro[1]->qtde > MIN) {
      shiftEsquerda(paginaAtual, 1);
    } else {
      juntaPaginas(paginaAtual, 1);
    }
  } else {
    if (paginaAtual->qtde != pos) {
      if (paginaAtual->ponteiro[pos - 1]->qtde > MIN) {
        shiftDireita(paginaAtual, pos);
      } else {
        if (paginaAtual->ponteiro[pos + 1]->qtde > MIN) {
          shiftEsquerda(paginaAtual, pos + 1);
        } else {
          juntaPaginas(paginaAtual, pos);
        }
      }
    } else {
      if (paginaAtual->ponteiro[pos - 1]->qtde > MIN)
        shiftDireita(paginaAtual, pos);
      else
        juntaPaginas(paginaAtual, pos);
    }
  }
}

// deleta o valor da página
int deletaDaPagina(int item, PAGINA *paginaAtual) {
  int pos, flag = 0;
  if (paginaAtual) {
    if (item < paginaAtual->item[1]) {
      pos = 0;
      flag = 0;
    } else {
      for (pos = paginaAtual->qtde; (item < paginaAtual->item[pos] && pos > 1); pos--)
        ;
      if (item == paginaAtual->item[pos]) {
        flag = 1;
      } else {
        flag = 0;
      }
    }
    if (flag) {
      if (paginaAtual->ponteiro[pos - 1]) {
        copiaSuccessor(paginaAtual, pos);
        flag = deletaDaPagina(paginaAtual->item[pos], paginaAtual->ponteiro[pos]);
        if (flag == 0) {
          printf("Chave não existe na árvore B-Tree\n");
        }
      } else {
        removeValor(paginaAtual, pos);
      }
    } else {
      flag = deletaDaPagina(item, paginaAtual->ponteiro[pos]);
    }
    if (paginaAtual->ponteiro[pos]) {
      if (paginaAtual->ponteiro[pos]->qtde < MIN)
        ajustaPagina(paginaAtual, pos);
    }
  }
  return flag;
}

// Operação de exclusão
PAGINA *excluir(int item, PAGINA *paginaAtual) {
  PAGINA *tmp;
  if (!deletaDaPagina(item, paginaAtual)) {
    printf("Chave não existe na árvore!\n");
    return paginaAtual;
  } else {
    if (paginaAtual->qtde == 0) {
      tmp = paginaAtual;
      paginaAtual = paginaAtual->ponteiro[0];
      free(tmp);
    }
  }
  return paginaAtual;
}

//procura determinada chave
void procurar(int item, int *pos, PAGINA *paginaAtual) {
  if (!paginaAtual) {
    return;
  }

  if (item < paginaAtual->item[1]) {
    *pos = 0;
  } else {
    for (*pos = paginaAtual->qtde;
       (item < paginaAtual->item[*pos] && *pos > 1); (*pos)--)
      ;
    if (item == paginaAtual->item[*pos]) {
      printf("%d existe na B-tree", item);
      return;
    }
  }
  procurar(item, pos, paginaAtual->ponteiro[*pos]);
  return;
}

// Desenha a árvore B
void desenhar(PAGINA *paginaAtual) {
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
    
  PAGINA *raiz=NULL;
    
  do{
      printf("Informe uma chave inteira positiva a ser inserida na árvore ou -1 para sair: ");
      scanf("%d",&ch); 
      if(ch>=0)
        raiz = insere(ch, raiz);
      printf("Páginas folha da árvore B:\n");    
      desenhar(raiz);  
      printf("\n");
  }while(ch>=0);

  printf("Informe uma chave inteira positiva que deseja excluir ou -1 para sair: ");
  scanf("%d",&ch); 	
  raiz = excluir(ch, raiz);
  printf("\n");
  //desenhar(raiz);
}