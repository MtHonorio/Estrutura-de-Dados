#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main (){
  Fila* cheia = newFila();
  Fila* meioAMeio = newFila();
  Fila* vazio = newFila();
  
  insere(cheia, 101.0);
  insere(cheia, 202.0);
  insere(cheia, 303.0);
  insere(cheia, 404.0);
  insere(cheia, 505.0);
  insere(cheia, 606.0);
  insere(cheia, 707.0);
  insere(cheia, 808.0);
  insere(cheia, 909.0);
  insere(cheia, 1010.0);

  insere(meioAMeio, 105.0);
  insere(meioAMeio, 115.0);
  insere(meioAMeio, 125.0);
  insere(meioAMeio, 135.0);
  insere(meioAMeio, 145.0);
  insere(meioAMeio, 155.0);
  insere(meioAMeio, 165.0);

  printf("---Printando as Filas---\n");
  printf("Fila cheia:\n");
  printar(cheia);

  printf("Fila cheia:\n");
  printar(cheia);
  
  printf("Fila meio a meio:\n");
  printar(meioAMeio);

  printf("Fila vazio\n");
  printar(vazio);
  
  printf("\n---Retirando elementos da fila---\n");
  printf("--Fila cheia--\n");
  printf("Elemento retirado da fila: %.f \n", retira(cheia));
  printf("Elemento retirado da fila: %.f \n", retira(cheia));
  printf("Elemento retirado da fila: %.f \n", retira(cheia));
  printf("Elemento retirado da fila: %.f \n", retira(cheia));
  printf("Elemento retirado da fila: %.f \n", retira(cheia));


  printf("--Fila meio a meio--\n");
  printf("Elemento retirado da fila: %.f \n", retira(meioAMeio));
  printf("Elemento retirado da fila: %.f \n", retira(meioAMeio));
  printf("Elemento retirado da fila: %.f \n", retira(meioAMeio));
  printf("Elemento retirado da fila: %.f \n", retira(meioAMeio));
  printf("Elemento retirado da fila: %.f \n", retira(meioAMeio));

  printf("Fila vazia\n");
  printf("Elemento retirado da fila: %.f \n", retira(vazio));

  
  printf("\n---Verificando se a fila eh vazia---\n");
  if(vazia(cheia)){
    printf("eh vazia. \n");
  }else{
    printf("nao eh vazia. \n");
  }

  if(vazia(meioAMeio)){
    printf("eh vazia. \n");
  }else{
    printf("nao eh vazia. \n");
  }

  if(vazia(vazio)){
    printf("eh vazia. \n");
  }else{
    printf("nao eh vazia. \n");
  }

  
  printf("\n---Liberando as filas da memoria---\n");
  libera(cheia);
  libera(meioAMeio);
  libera(vazio);
  
  return 0;
}