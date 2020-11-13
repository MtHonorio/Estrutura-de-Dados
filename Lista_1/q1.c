#include <stdio.h>
#define fatia 3
#define refrigerante 1.5
#define taxa 0.10

void Conta(int x, int y, int z){
  float w;
  w = (x*refrigerante)+(y*fatia);
  printf("Sua conta deu o total de: %0.2f \n", w);

  w = w+(w*taxa);
  printf("Sua conta total + taxa do garçom: %0.2f \n", w);

  w = w/z;
  printf("Sua conta total dividido para cada cliente da ao todo: %0.2f pra cada. \n", w);

}

int main (){
  int x, y, z;

  printf("----Gerencia de Pizzaria----\n");
  printf("Quantos refrigerantes foram consumidos? \n");
  scanf( "%d", &x);

  printf("Quantas fatias de pizza?\n");
  scanf("%d", &y);

  printf("Quantas pessoas estão presentes?\n");
  scanf("%d", &z);

  Conta(x, y, z);


  return 0;
}