#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "pilha.h"
#define DIMENSAO_INICIAL 2

struct pilha
{
  int n_elementos;
  int dimensao;
  Chave *vetorElementos;
};

Pilha *new_pilha(void)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->dimensao = DIMENSAO_INICIAL;
  p->vetorElementos = (Chave *)malloc(p->dimensao * sizeof(Chave));
  p->n_elementos = 0;

  return p;
}

void pilha_push(Pilha *p, Chave v)
{
  if (p->n_elementos == p->dimensao)
  {
    p->dimensao *= 2;
    p->vetorElementos = (Chave *)realloc(p->vetorElementos, p->dimensao * sizeof(Chave));
  }
  p->vetorElementos[p->n_elementos++] = v;
}

Chave pilha_pop(Pilha *p)
{
  Chave v = p->vetorElementos[--p->n_elementos];
  return v;
}

int pilha_vazia(Pilha *p)
{
  return (p->n_elementos == 0);
}

void pilha_libera(Pilha *p)
{
  free(p->vetorElementos);
  free(p);
}

void pilha_imprime(Pilha *p)
{
  if(!pilha_vazia(p)){
    for (int i = p->n_elementos - 1; i >= 0; i--)
      printf("Quantidade de Elementos: %d Elemento: %f \n", i, p->vetorElementos[i]);
  }else{
    printf("Pilha eh vazia\n");
  }
}

int pilha_tamanho(Pilha* p){
  return p->n_elementos;
}