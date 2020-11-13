#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "pilha.h"

struct elemento
{
  Chave info;
  Elemento *prox;
};

struct pilha
{
  Elemento *topo;
};

Pilha *newVazio(void)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

int tamanho(Pilha *p)
{
  Elemento *fim = p->topo;
  int tam = 0;
  while (fim != NULL)
  {
    tam++;
    fim = fim->prox;
  }
  return tam;
}

int ehVazio(Pilha *p)
{
  return (p->topo == NULL);
}

void printar(Pilha *p)
{
  for (Elemento *q = p->topo; q != NULL; q = q->prox)
    printf("Elemento: %.f \n", q->info);
}

void empilhar(Pilha *p, Chave x)
{
  Elemento *n = (Elemento *)malloc(sizeof(Elemento));
  n->info = x;
  n->prox = p->topo;
  p->topo = n;
}

Chave desempilhar(Pilha *p)
{
  Elemento *t = p->topo;
  Chave v = t->info;
  p->topo = t->prox;
  free(t);
  return v;
}

void liberar(Pilha *p)
{
  Elemento *q = p->topo;
  while (q != NULL)
  {
    Elemento *t = q->prox;
    free(q);
    q = t;
  }
  free(p);
}
