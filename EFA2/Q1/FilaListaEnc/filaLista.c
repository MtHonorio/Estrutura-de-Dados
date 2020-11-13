#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "filaLista.h"

struct elemento
{
  float info;
  Elemento *prox;
};

struct fila
{
  Elemento *inicio;
  Elemento *fim;
};

Fila *newFila(void)
{
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->inicio = f->fim = NULL;
  return f;
}

void insere(Fila *f, float v)
{
  Elemento *noh = (Elemento *)malloc(sizeof(Elemento));

  noh->info = v;
  noh->prox = NULL;

  if (f->fim != NULL)
    f->fim->prox = noh;
  else
    f->inicio = noh;

  //Fim da fila aponta para o novo elemento
  f->fim = noh;
}

Chave retira(Fila *f)
{
  Elemento *noh = f->inicio;
  Chave valor = noh->info;

  f->inicio = noh->prox;

  //Verifica se a fila ficou vazia
  if (f->inicio == NULL)
  {
    f->fim = NULL;
  }
  free(noh);

  return valor;
}

void printar(Fila *f)
{
  for (Elemento *noh = f->inicio; noh != NULL; noh = noh->prox)
    printf("Posicao: %d Elemento: %.f \n", noh->info);
}

int vazia(Fila *f)
{
  return (f->inicio == NULL);
}

void libera(Fila *f)
{
  Elemento *noh = f->inicio;

  while (noh != NULL)
  {
    Elemento *aux = noh->prox;
    
    free(noh);
    
    noh = aux;
  }
  free(f);
}