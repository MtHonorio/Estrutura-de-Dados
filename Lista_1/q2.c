/*Para compilar o codigo a biblioteca nao esta linkada por padrao
tem que ser referenciar na linha do compilador:
gcc <nome_do_prog.c> -lm
  Para rodar: ./<nome_do_executavel>
*/ 

#include <stdio.h>
#include <math.h>
#define pi 3.14159

float area(float x){
  float A;
  A = pi*(pow(x,2));
  return A;
}

int main ()
{
  float x;
  printf("Digite o raio da circunferencia: \n");
  scanf("%f", &x);
  while(1){
    if (x>=0){
      x = area(x);
      printf("A area da circunferencia e: %.2f \n", x);
      break;
    }else{
      printf("Numero negativo, por favor não tente bugar o programa\n");
    }
    return 0;
  }
}