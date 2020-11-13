#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main()
{
  //----Criando Pilhas Vazias----//
  Pilha *Carregada = new_pilha();
  Pilha *Metade = new_pilha();
  Pilha *Descarregada = new_pilha();


  //--Carregadando pilhas--//
  pilha_push(Carregada, 5.0);
  pilha_push(Carregada, 10.0);
  pilha_push(Carregada, 20.0);
  pilha_push(Carregada, 30.0);
  pilha_push(Carregada, 40.0);
  pilha_push(Carregada, 50.0);
  pilha_push(Carregada, 60.0);
  pilha_push(Carregada, 70.0);
  pilha_push(Carregada, 80.0);
  pilha_push(Carregada, 90.0);
  pilha_push(Carregada, 100.0);

  pilha_push(Metade, 5.0);
  pilha_push(Metade, 10.0);
  pilha_push(Metade, 20.0);
  pilha_push(Metade, 30.0);
  pilha_push(Metade, 40.0);
  pilha_push(Metade, 50.0);


  printf("--Testando se estao vazias-- \n");
  if (pilha_vazia(Descarregada))
  {
    printf("Pilha vazia\n");
  }
  else
  {
    printf("Pilha nao esta vazia\n");
  }

  if (pilha_vazia(Metade))
  {
    printf("Pilha vazia\n");
  }
  else
  {
    printf("Pilha nao esta vazia\n");
  }

  if (pilha_vazia(Carregada))
  {
    printf("Pilha vazia\n");
  }
  else
  {
    printf("Pilha nao esta vazia\n");
  }

  printf("\nO tamanho da pilha Carregada eh: %d \n", pilha_tamanho(Carregada));
  printf("O tamanho da pilha Metade eh: %d \n", pilha_tamanho(Metade));
  printf("O tamanho da pilha Descarregada eh: %d \n", pilha_tamanho(Descarregada));

  printf("\n--Printando as pilhas: \n");
  pilha_imprime(Carregada);
  printf("\n");
  
  pilha_imprime(Metade);
  printf("\n");

  pilha_imprime(Descarregada);
  printf("\n");


  printf("\n--Desempilhando as pilhas: \n");
  while (!pilha_vazia(Carregada))
    printf("Bateria atual: %.f \n", pilha_pop(Carregada));

  while (!pilha_vazia(Metade))
    printf("Bateria atual: %.f \n", pilha_pop(Metade));

  pilha_libera(Carregada);
  pilha_libera(Metade);
  pilha_libera(Descarregada);

  return 0;
}