#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main (){
  Pilha* pListaX = newVazio();
  Pilha* pListaY = newVazio();
  
  empilhar(pListaX, 4.0);
  empilhar(pListaX, 14.0);
  empilhar(pListaX, 24.0);
  empilhar(pListaX, 34.0);
  empilhar(pListaX, 44.0);
  empilhar(pListaX, 54.0);
  empilhar(pListaX, 64.0);
  empilhar(pListaX, 74.0);
  empilhar(pListaX, 84.0);
  empilhar(pListaX, 94.0);
  
  empilhar(pListaY, 14.0);
  empilhar(pListaY, 25.0);
  empilhar(pListaY, 36.0);
  empilhar(pListaY, 47.0);
  empilhar(pListaY, 58.0);
  empilhar(pListaY, 69.0);
  
  printf("-------Printando as listas-------\n");
  printf("-----Lista X-----\n");
  printar(pListaX);

  printf("-----Lista Y-----\n");
  printar(pListaY);


  //Tamanho das pilhas//
  int i = 0;
  printf("\n-----Printando os Tamanhos das pilhas-----\n");
  printf("Tamanho da pilha X: %d \n", tamanho(pListaX));
  printf("Tamanho da pilha Y: %d \n", tamanho(pListaY));


  //Teste se existe elemento//
  printf("\n-----Printando se esta vazia-----\n");
  if(ehVazio(pListaX)){
    printf("Lista X esta vazia.\n");
  }else{
    printf("Lista X nao esta vazia.\n");
  }
  
  if(ehVazio(pListaY)){
    printf("Lista Y esta vazia.\n");
  }else{
    printf("Lista Y nao esta vazia.\n");
  }
  

  //Desempilhando//
  printf("\n-----Desempilhando as pilhas-----\n");
  printf("-----Pilha X-----\n");
  printf("Elemento: %.f \n", desempilhar(pListaX));
  printf("Elemento: %.f \n", desempilhar(pListaX));
  printf("Elemento: %.f \n", desempilhar(pListaX));
  printf("Elemento: %.f \n", desempilhar(pListaX));
  printf("Elemento: %.f \n", desempilhar(pListaX));

  printf("\n-----Pilha Y-----\n");
  printf("Elemento: %.f \n", desempilhar(pListaY));
  printf("Elemento: %.f \n", desempilhar(pListaY));
  printf("Elemento: %.f \n", desempilhar(pListaY));
  printf("Elemento: %.f \n", desempilhar(pListaY));
  printf("Elemento: %.f \n", desempilhar(pListaY));


  printf("\n-----Printando se esta vazia-----\n");
  if(ehVazio(pListaX)){
    printf("Lista X esta vazia.\n");
  }else{
    printf("Lista X nao esta vazia.\n");
  }
  
  if(ehVazio(pListaY)){
    printf("Lista Y esta vazia.\n");
  }else{
    printf("Lista Y nao esta vazia.\n");
  }
  
  
  printf("\n-----Printando as pilhas depois de desempilhar-----\n");
  printf("\n-----Pilha X-----\n");
  printar(pListaX);

  printf("\n-----Pilha Y-----\n");
  printar(pListaY);
  

  //Libera as pilhas criadas//
  liberar(pListaX);
  liberar(pListaY); 

  return 0;
}