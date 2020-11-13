#include <stdio.h>
#include <stdlib.h>
#include "Q3.h"

typedef struct NO
{
  float valor;
  int coluna;
  struct NO *prox;
} NO;

typedef NO *PONT;

typedef struct MATRIZ
{
  PONT *p_line;
  int linhas;
  int colunas;
} MATRIZ;

MATRIZ *cria_matriz(int linhas, int colunas)
{
  // Aloca espaco para a matriz e o ponteiro de linhas
  MATRIZ *matriz = (MATRIZ *)malloc(sizeof(MATRIZ));
  matriz->p_line = (PONT *)malloc(linhas * sizeof(PONT));

  // Se matriz existir
  if (matriz)
  { 
    // Atribui os parametros a matriz criada
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    
    // Percorre todas as linhas para inicializa-las com valor NULL
    for (int i = 0; i < linhas; i++)
    {
      matriz->p_line[i] = NULL;
    }
  }
  return matriz;
}

void remover_matriz(MATRIZ *matriz)
{
  free(matriz); // Libera a matriz
}

void print_matriz(MATRIZ *matriz)
{
  //Pega o total de linhas e colunas
  int total_linhas = matriz->linhas;
  int total_colunas = matriz->colunas;

  // Percorre todas as linhas
  for (int i = 0; i < total_linhas; i++) 
  { 
    // Percorre todas as colunas da linha correspondente
    for (int j = 0; j < total_colunas; j++) 
    {
      // Printa o valor da posicao
      printf("%.1f  ", acessar_no(matriz, i + 1, j + 1)); 
    }
    printf("\n");
  }
}

float acessar_no(MATRIZ *matriz, int linha, int coluna)
{
  // Se os valores passados nao corresponderem a matriz, ou seja, uma coordenada invalida, retorna 0
  if (linha - 1 < 0 || linha - 1 >= matriz->linhas || coluna - 1 < 0 || coluna - 1 >= matriz->colunas)
  {
    return 0;
  }
  // Seleciona a linha correspondente a enviada como parametro
  PONT atual = matriz->p_line[linha - 1];

  // Percorre os elementos ate a coluna ser igual ao do paramento enviado
  while (atual != NULL && atual->coluna < coluna - 1){
    atual = atual->prox;
  }
  
  // Verifica se eh o elemento que quer acessar
  if (atual != NULL && atual->coluna == coluna - 1){
    // Retorna o valor do elemento
    return atual->valor;
  }
  return 0;
}

int inserir_no(MATRIZ *matriz, int linha, int coluna, float valor)
{ 
  // Verifica se a coordenada da matriz eh valida, se for, retorna false
  if (linha - 1 < 0 || linha - 1 >= matriz->linhas || coluna - 1 < 0 || coluna - 1 >= matriz->colunas)
  {
    return 0;
  }
  
  // Seta o ponteiro anterior como NULL
  PONT ant = NULL;
  // Seleciona a linha correspondente a enviada como parametro
  PONT atual = matriz->p_line[linha - 1];

  // Percorre os elementos ate o valor da coluna correspondente ser igual ao do parametro enviado
  while (atual != NULL && atual->coluna < coluna - 1)
  { 
    ant = atual;
    atual = atual->prox;
  }

  // Entra nesse if se o elemento onde quer add for diferente de NULL
  if (atual != NULL && atual->coluna == coluna - 1)
  { 
    // Tratamento para valor igual a 0 que nao precisa ser alocado na memoria
    if (valor == 0)
    {
      if (ant == NULL)
        matriz->p_line[linha - 1] = atual->prox;
      else
        ant->prox = atual->prox;

      free(atual); // Libera o espaco do elemento
    }
    else{ 
      // Se o valor nao for 0, faz a atribuicao
      atual->valor = valor;
    }
  }

  else if (valor != 0)
  { 
    // Armazena espaco pro novo elemento
    PONT novo = (PONT)malloc(sizeof(NO));

    // Atribui os valores
    novo->coluna = coluna - 1;
    novo->valor = valor;
    novo->prox = atual;

    // Adiciona o elemento dependendo do valor do anterior a posicao desejada
    if (ant == NULL)
      matriz->p_line[linha - 1] = novo;

    else
      ant->prox = novo;
  }
  return 1; // Retorna verdadeiro se a operacao for um sucesso
}

int remover_no(MATRIZ *matriz, int linha, int coluna)
{  
  // Verifica se a coordenada da matriz eh valida, se for, retorna false
  if (linha - 1 < 0 || linha - 1 >= matriz->linhas || coluna - 1 < 0 || coluna - 1 >= matriz->colunas)
  {
    return 0;
  }
  // Seleciona a linha correspondente a enviada como parametro
  PONT atual = matriz->p_line[linha - 1]; 

  // Percorre os elementos ate a coluna ser igual ao do paramento enviado
  while (atual != NULL && atual->coluna < coluna - 1){
    atual = atual->prox;
  }

  // Verifica se eh o elemento que quer excluir
  if (atual != NULL && atual->coluna == coluna - 1) 
  {
    free(atual); // Libera o espaco de memoria do mesmo
    return 1;
  }

  return 0;
}