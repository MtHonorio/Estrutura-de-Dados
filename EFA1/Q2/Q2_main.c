#include <stdio.h>
#include <stdlib.h>
#include "Q2_Struct.h"


int main (){

  //conjunto X//
  No* x = conjunto_cria_vazio();
  conjunto_insere(&x, 4);
  conjunto_insere(&x, (-7));
  conjunto_insere(&x, 20);
  
  
  //conjunto Y//
  No* y = conjunto_cria(100);
  conjunto_insere(&y, -20);
  conjunto_insere(&y, 20);
  conjunto_insere(&y, 20);
  conjunto_insere(&y, 20);
  

  //conjunto Z//
  No* z = conjunto_cria(-20);
  conjunto_insere(&z, 15000);
  conjunto_insere(&z, 0);
  conjunto_insere(&z, 20);
  conjunto_insere(&z, 100);
  conjunto_insere(&z, 152);
  conjunto_insere(&z, 70);

  
  printf("-------Printando os conjuntos-------\n");
  printf("-----Lista X-----\n");
  conjunto_print(x);

  printf("-----Lista Y-----\n");
  conjunto_print(y);

  printf("-----Lista Z-----\n");
  conjunto_print(z);


  //Tamanho dos Conjuntos//
  int tamanho;
  printf("\n-----Printando os Tamanhos dos Conjuntos-----\n");
  tamanho = conjunto_tamanho(x);
  printf("Tamanho do conjunto: %d \n", tamanho);
  
  tamanho = conjunto_tamanho(y);
  printf("Tamanho do conjunto: %d \n", tamanho);

  tamanho = conjunto_tamanho(z);
  printf("Tamanho do conjunto: %d \n", tamanho);


  //Teste qual o maior numero//
  printf("\n-----Printando o Maior Numero dos Conjuntos-----\n");
  printf("maior numero do conjunto x: %d.\n", conjunto_maior_valor(x));
  printf("maior numero do conjunto y: %d.\n", conjunto_maior_valor(y));
  printf("maior numero do conjunto z: %d.\n", conjunto_maior_valor(z));


  //Teste qual o menor numero//
  printf("\n-----Printando o Menor Numero dos Conjuntos-----\n");
  printf("menor numero do conjunto x: %d.\n", conjunto_menor_valor(x));
  printf("menor numero do conjunto y: %d.\n", conjunto_menor_valor(y));
  printf("menor numero do conjunto z: %d.\n", conjunto_menor_valor(z));


  //Teste se existe o numero//
  printf("\n-----Printando se Existe os Valores nos Conjuntos-----\n");
  if(conjunto_existe_valor(x, 15)){
    printf("existe.\n");
  }else{
    printf("nao existe.\n");
  }
  
  if(conjunto_existe_valor(y, 0)){
    printf("existe.\n");
  }else{
    printf("nao existe.\n");
  }
  
  if(conjunto_existe_valor(z, 100)){
    printf("existe.\n");
  }else{
    printf("nao existe.\n");
  }
  

  //Teste se os conjuntos sao iguais//
  printf("\n-----Printando se os Conjuntos sao Iguais-----\n");
  if (conjunto_iguais(x, y)){
    printf("conjuntos iguais.\n");
  }else{
    printf("conjuntos diferentes.\n");
  }
  
  if (conjunto_iguais(z, y)){
    printf("conjuntos iguais.\n");
  }else{
    printf("conjuntos diferentes.\n");
  }
  
  if (conjunto_iguais(y, y)){
    printf("conjuntos iguais.\n");
  }else{
    printf("conjuntos diferentes.\n");
  }


  //Criando os conjuntos de teste para serem atribuidos os conjuntos abaixo//
  No* t1 = conjunto_cria_vazio();
  No *t2 = conjunto_cria_vazio();
  No *t3 = conjunto_cria_vazio();
  No *t4 = conjunto_cria_vazio();
  No *t5 = conjunto_cria_vazio();
  No *t6 = conjunto_cria_vazio();
  No *t7 = conjunto_cria_vazio();
  No *t8 = conjunto_cria_vazio();
  No *t9 = conjunto_cria_vazio();


  //Teste se o conjunto eh vazio//
  printf("\n-----Printando se tem Conteudo no Conjunto-----\n");
  if (conjunto_eh_vazio(t1)){
    printf("conjunto vazio.\n");
  }else{
    printf("conjunto cheio.\n");
  }
  
  if (conjunto_eh_vazio(x)){
    printf("conjunto vazio.\n");
  }else{
    printf("conjunto cheio.\n");
  }


  //Retorna o conjunto de Interseccao//
  printf("\n-----Printando a Interseccao dos Conjuntos-----\n");
  printf("\n--elementos (y, z):\n");
  t1 = conjunto_interseccao(&y, &z);
  conjunto_print(t1);
  
  printf("\n--elementos (z, x):\n");
  t2 = conjunto_interseccao(&z, &x);
  conjunto_print(t2);

  printf("\n--elementos (x, y):\n");
  t3 = conjunto_interseccao(&x, &y);
  conjunto_print(t3);


  //Retorna o conjunto de Diferenca//
  printf("\n-----Printando a Diferenca dos Conjuntos-----\n");
  printf("\n--elementos (z, y):\n");
  t4 = conjunto_diferenca(&z, &y);
  conjunto_print(t4);

  printf("\n--elementos (x, y):\n");
  t5 = conjunto_diferenca(&x, &y);
  conjunto_print(t5);

  printf("\n--elementos (x, z):\n");
  t6 = conjunto_diferenca(&x, &z);
  conjunto_print(t6);


  //Retorna a Uniao dos Conjuntos//
  printf("\n-----Printando a Uniao dos Conjuntos-----\n");
  printf("\n--elementos (z, y):\n");
  t7 = conjunto_uniao(&z, &y);
  conjunto_print(t7);

  printf("\n--elementos (x, y):\n");
  t8 = conjunto_uniao(&y, &x);
  conjunto_print(t8);

  printf("\n--elementos (z, x):\n");
  t9 = conjunto_uniao(&z, &x);
  conjunto_print(t9);


  //Remove o elemento do conjunto//
  conjunto_remove(&x, -7);
  conjunto_remove(&y, 20);
  conjunto_remove(&z, 0);
  conjunto_remove(&z, 15000);
  conjunto_remove(&z, 152);
  
  printf("\n-----Printando os Conjuntos depois do Remover-----\n");
  printf("\n-----Lista X-----\n");
  conjunto_print(x);

  printf("\n-----Lista Y-----\n");
  conjunto_print(y);

  printf("\n-----Lista Z-----\n");
  conjunto_print(z);
  

  //Libera os Conjuntos Criados//
  free(x); free(y); free(z);
  free(t1); free(t2); free(t3);
  free(t4); free(t5); free(t6);
  free(t7); free(t8); free(t9);  

  return 0;
}