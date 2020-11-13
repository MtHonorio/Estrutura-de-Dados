#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"
#define DIM_INICIAL 3

struct fila
{
  int n_elementos;
  int inicio;
  int dimensao;
  float *vetorElementos;
};

Fila *newFila(void)
{
  Fila *f = (Fila *)malloc(sizeof(Fila));

  f->dimensao = DIM_INICIAL;
  f->vetorElementos = (Chave *)malloc(f->dimensao * sizeof(Chave));
  f->n_elementos = 0;
  f->inicio = 0;

  return f;
}

void insere(Fila *f, Chave valor)
{
  int fim;
  //se capacidade esgotada//
  if (f->n_elementos == f->dimensao)
  {
    //realoca, dobrando o tamanho//
    f->dimensao *= 2;

    f->vetorElementos = (Chave *)realloc(f->vetorElementos, f->dimensao * sizeof(Chave));

    if (f->inicio != 0)
    {
      /*Esta função recebe três parâmetros: o endereço de memória destino da cópia,
       o endereço de memória origem e o número de bytes a ser movido (copiado). */
      memmove(
          &f->vetorElementos[f->dimensao - f->inicio],
          &f->vetorElementos[f->inicio],
          (f->n_elementos - f->inicio) * sizeof(Chave));
    }
  }
  //insere elemento na próxima posicao livre//
  fim = (f->inicio + f->n_elementos) % f->dimensao;
  f->vetorElementos[fim] = valor;
  f->n_elementos++;
}

Chave retira(Fila *f)
{
  if(vazia(f)){
    printf("Nao tem mais elementos na fila. \n");
    return 0;
  }
  Chave v;
  v = f->vetorElementos[f->inicio];
  // retira elemento do inicio
  f->inicio = (f->inicio + 1) % f->dimensao;
  // diminui o numero de elementos da fila
  f->n_elementos--;

  return v;
}

int vazia(Fila *f)
{
  return (f->n_elementos == 0);
}

void printar(Fila *f)
{
  if (!vazia(f))
  {
    for (int i = 0; i < f->n_elementos; i++)
      printf("Posicao: %d Chave: %.f \n", i, f->vetorElementos[(f->inicio + i) % f->dimensao]);
  }else{
    printf("Fila vazia.\n");
  }
}

void libera(Fila *f)
{
  free(f->vetorElementos);
  free(f);
}