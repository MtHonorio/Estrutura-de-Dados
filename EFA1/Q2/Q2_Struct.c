#include <stdio.h>
#include <stdlib.h>
#include "Q2_Struct.h"

struct no
{
  int numero;      //inteiro que eh o conteudo do elemento do conjunto.
  struct no *prox; //cria um tipo noh que aponta para o proximo elemento do conjunto.
};

No *conjunto_cria_vazio()
{
  No *no = (No *)malloc(sizeof(No)); //aloca memoria necessaria para o noh e converte para No*.
  if (no)
  {
    no = NULL;    //noh igual a NULL
  }
  return no; //retorna o noh vazio criado.
}

No *conjunto_cria(int numero)
{
  No *novo = (No *)malloc(sizeof(No)); //cria um novo conjunto vazio
  if (novo)
  {
    novo->numero = numero; //seta o numero do cojunto novo como o numero passado como parametro
    novo->prox = NULL;    //seta o proximo elemento do conjunto como nulo
  }
  return novo; //retorna o novo elemento da lista
}

void conjunto_print(No *cabeca)
{
  int contador = 0;      //contador comeca em 0, contador feito para setar o numero do elemento no conjunto.
  while (cabeca != NULL) //enquanto a cabeca for diferente de NULL o programa entra em loop
  {
    printf("Elemento %d: ", contador); //print com o numero do contador
    printf("%d \n", cabeca->numero);   // mais o numero do setado no conjunto
    contador++;                        //contador acrescenta mais 1.
    cabeca = cabeca->prox;             //cabeca aponta para o proximo indice.
  }
}

int conjunto_eh_vazio(No *cabeca)
{
  return (cabeca == NULL); //se o No* tiver os elementos 0 e NULO, retorna 1 se verdadeiro e 0 para falso.
}

int conjunto_tamanho(No *cabeca)
{
  int contador = 0;      //contador do tamanho do conjunto.
  while (cabeca != NULL) //enquanto cabeca do conjunto diferente de NULL.
  {
    contador++;            //contador +1 a cada verificacao.
    cabeca = cabeca->prox; //cabeca igual ao proximo elemento do conjunto.
  }

  return contador; //retorna resultado do contador que e igual o numero de elementos do conjunto.
}

int conjunto_menor_valor(No *cabeca)
{
  int menor = cabeca->numero; //verificar amanha se ele pega o valor do primeiro termo da lista.
  while (cabeca != NULL)      //enquanto cabeca do conjunto diferente de NULL.
  {
    if (cabeca->numero < menor)   //se o numero da cabeca for menor que o menor numero encontrado ate o momento
    {
      menor = cabeca->numero; //Se o elemento numero atual da tabela for menor que o menor setado anteriormente, atribui o numero atual como menor
    }
    cabeca = cabeca->prox; //cabeca igual ao proximo elemento do conjunto.
  }

  return menor; //retorna o menor.
}

int conjunto_maior_valor(No *cabeca)
{
  int maior = cabeca->numero; //verificar amanha se ele pega o valor do primeiro termo da lista.
  while (cabeca != NULL)      //enquanto cabeca do conjunto diferente de NULL.
  {
    if (cabeca->numero > maior)     //se o numero da cabeca for maior que o maior numero encontrado ate o momento
    {
      maior = cabeca->numero; //Se o elemento numero atual da tabela for maior que o maior setado anteriormente, atribui o numero atual como maior
    }
    cabeca = cabeca->prox; //cabeca igual ao proximo elemento do conjunto.
  }

  return maior; //retorna o maior.
}

int conjunto_existe_valor(No *cabeca, int numero)
{
  if (conjunto_eh_vazio(cabeca)) //se cabeca diferente de NULO
  { 
    return 0;
  }
  while (cabeca != NULL) //enquanto cabeca for diferente de NULL
  {
    if (cabeca->numero == numero) //se o numero do elemento for igual ao numero setado como parametro.
    {
      return 1; //retorna verdadeiro
    }
    cabeca = cabeca->prox; //avanca para o proximo elemento da lista
  }
  return 0;
}

int conjunto_insere(No **cabeca, int numero)
{
  No *aux = conjunto_cria(numero);        //cria um conjunto auxiliar com o numero do parametro como elemento
  if (conjunto_existe_valor(*cabeca, numero))     //se ja existir o valor do parametro no conjunto
  {
    return 0;       //retorna 0 porque nao precisa ser setado, pois ja tem no conjunto
  }
  if (aux)    //se aux tiver sido criado sem problemas
  {
    aux->prox = *cabeca;    //o proximo elemento de auxiliar vai ser a cabeca da lista, fazendo com o que aux seja o primeiro elemento do conjunto
    *cabeca = aux;    //cabeca do conjunto igual aux
    return 1;  
  }
}

int conjunto_iguais(No *cabeca1, No *cabeca2)
{
  if (cabeca1) //cabeca diferente de 0;
  {
    while (cabeca1 != NULL)
    {
      if (cabeca1->numero != cabeca2->numero)
      {           //se o elemento do conjunto 1 diferente do elemento do conjunto 2
        return 0; //sao diferentes e retorna 0 = falso
      }
      cabeca1 = cabeca1->prox; //aponta o proximo para percorrer o conjunto 1
      cabeca2 = cabeca2->prox; //aponta o proximo para percorrer o conjunto 2
    }
    return 1;
  }
  else    //falso para se o conjunto nao existir ou estiver NULL
  {
    printf("conjunto 1 vazio.\n");
    return 0;
  }
}

int conjunto_remove(No **cabeca, int numero)
{ 
  //cria os noh auxiliares e um validador
  No *ante = NULL;      
  No *aux = *cabeca;
  int found = 0;    //encontrado igual a 0
  while (aux != NULL)   //percorre o conjunto enquanto aux for diferente de NULO
  {
    if (aux->numero == numero)    //se o numero de aux for igual ao numero do parametro setado
    {
      found = 1;    //encontrado igual a verdadeiro e sai do loop
      break;
    }
    ante = aux;   //anterior igual ao elemento atual
    aux = aux->prox;    //aux igual ao proximo elemento
  }

  if (found)    //Se o numero for encontrado
  {
    if (ante == NULL)   //se anterior for NULL
    {
      *cabeca = aux->prox;    //seta cabeca como o proximo elemento de aux
      free(aux);    //libera aux
      return 1;   //retorna 1
    }

    ante->prox = aux->prox;   //proximo elemento do anterior eh igual ao proximo elemento do aux
    free(aux);    //libera aux
    return 1;   //retorna verdadeiro
  }

  return 0;     //retorna falso
}

No *conjunto_interseccao(No **cabeca1, No **cabeca2)
{
  //cria o conjunto que ira retornar e o aux para percorrer o conjunto
  No *resultante = conjunto_cria_vazio();
  No *aux = *cabeca1;
  No *aux_2 = *cabeca2;

  if (conjunto_tamanho(*cabeca1) <= conjunto_tamanho(*cabeca2))   //Se o tamanho do primeiro conjunto menor que o do segundo
  {
    while (aux != NULL)       //enquanto aux diferente de NULL
    {
      if (conjunto_existe_valor(*cabeca2, aux->numero))   //Se o numero de aux existir na cabeca2
      {
        conjunto_insere(&resultante, aux->numero);    //insere o numero no conjunto
      }

      aux = aux->prox;    //pula para o proximo elemento do conjunto
    }
    return resultante;    //retorna o conjunto resultante
  }
  else
  {
    while (aux_2 != NULL)     //enquanto aux diferente de NULL
    {
      if (conjunto_existe_valor(*cabeca1, aux_2->numero))     //se o numero de aux2 existir na cabeca1
      {
        conjunto_insere(&resultante, aux_2->numero);      //insere o numero de aux_2 no resultante
      }

      aux_2 = aux_2->prox;    //pula para o proximo elemento do conjunto
    }
    return resultante;
  }
}

No *conjunto_diferenca(No **cabeca1, No **cabeca2)
{
  No *res_diferenca = conjunto_cria_vazio();  //cria o conjunto resultado
  No *aux = *cabeca1;       //serve para percorrer o conjunto cabeca1 sem altera-lo
  No *aux_2 = *cabeca2;     //serve para percorrer o conjunto cabeca2 sem altera-lo

  while (aux != NULL)       //enquanto aux nao for NULL percorre o loop
  {
    if (!conjunto_existe_valor(aux_2, aux->numero))   //Se nao existir o valor passado em aux_2
    {
      conjunto_insere(&res_diferenca, aux->numero);   //insere no conjunto diferenca
    }
    aux = aux->prox;        //pula para o proximo termo do conjunto
  }
  return res_diferenca;     //retorna o conjunto diferenca
}

No *conjunto_uniao(No **cabeca_1, No **cabeca_2)
{
  No *aux = *cabeca_1;        //serve para percorrer o conjunto cabeca_1 sem altera-lo
  No *aux_2 = *cabeca_2;      //serve para percorrer o conjunto cabeca_2 sem altera-lo
  No *result = conjunto_cria_vazio();    //cria o conjunto resultado

  while (aux != NULL)       //enquanto aux nao for NULL percorre o loop
  {
    conjunto_insere(&result, aux->numero);    //insere o elemento no conjunto
    aux = aux->prox;                    //pula para o proximo termo do conjunto
  }

  while (aux_2 != NULL)     //enquanto aux_2 nao for NULL percorre o loop
  {
    conjunto_insere(&result, aux_2->numero);    //insere o elemento no conjunto
    aux_2 = aux_2->prox;    //pula para o proximo termo do conjunto
  }

  return result;        //retorna o conjunto uniao
}
