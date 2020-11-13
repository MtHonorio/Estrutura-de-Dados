#include <stdio.h>
#include <math.h>

float Delta(int a, int b, int c){

  return ((b*b)-(4*a*c));
}

void Raizes(int a, int b, float d){
  printf("----Raizes----\n");
  float x;
  x = (-b + sqrt(d))/(2*a);
  printf("x1 = %.2f\n", x);
  x = (-b - sqrt(d))/(2*a);
  printf("x2 = %.2f\n", x);

}

int main (){
  int a, b, c;
  float d, x;

  printf("Digite o a: \n");
  scanf("%d", &a);
  printf("Digite o b: \n");
  scanf("%d", &b);
  printf("Digite o c: \n");
  scanf("%d", &c);

  x = Delta(a, b, c);
  Raizes(a,b,x);

  return 0;
}