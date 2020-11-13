#include <stdio.h>
#include <stdlib.h>
#include "Q3.h"

int main (){

  /*Linhas e Colunas foram adaptadas com -1 
  para nao serem um indice a mais */
  
  //Criacao da Matriz
  MATRIZ* m1 = cria_matriz(15, 5);
  MATRIZ* m2 = cria_matriz(45, 15);


  printf("------Atribuindo Elementos------\n");
  if(inserir_no(m1, 10, 3, 72.5)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }
  
  if(inserir_no(m1, 16, 3, 195.59)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }

  if(inserir_no(m1, 2, 3, 3.14156)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }

  if(inserir_no(m1, 9, 3, 72.5)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }
  
  if(inserir_no(m1, 8, 2, 56149.554442)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }

  if(inserir_no(m1, 2, 8, 9.16849)){
    printf("Adicionado com sucesso\n");
  }else{
    printf("Falha ao adicionar, coordenada da matriz invalida\n");
  }
  
  printf("\n------Printando os elementos da Matriz------\n");
  printf("Elemento da posicao: %.2f\n", acessar_no(m1,9,10));
  printf("Elemento da posicao: %.2f\n", acessar_no(m1,2,3));
  printf("Elemento da posicao: %.2f\n", acessar_no(m1,2,8));
  printf("Elemento da posicao: %.2f\n", acessar_no(m1,16,3));
  printf("Elemento da posicao: %.2f\n", acessar_no(m1,8,2));
  
  printf("\n------Printando todos os elementos da Matriz------\n");
  print_matriz(m1);

  printf("\n------Removendo elementos da Matriz------\n");
  if(remover_no(m1, 2, 8)){
    printf("Elemento removido com Sucesso\n");
  }else{
    printf("Erro na remocao, coordenada invalida\n");
  }

  if(remover_no(m1, 2, 3)){
    printf("Elemento removido com Sucesso\n");
  }else{
    printf("Erro na remocao, coordenada invalida\n");
  }


  printf("\n------Printando todos os elementos da Matriz------\n");
  print_matriz(m1);


  printf("\n------Fim do programa e removendo a Matriz da Memoria------\n");
  remover_matriz(m1);
  remover_matriz(m2);

  
  return 0;
}