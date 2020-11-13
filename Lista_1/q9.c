#include <stdio.h>
#include <math.h>

int main (){
  int x, z;
  printf("Digite o numero que queria saber se e primo: ");
  scanf("%d", &x);
  z=(int) sqrt(x);
  for (int i = 2; i<=z; i++)
  {
    if (x%i==0){
      printf("numero nao eh primo.\n");
      return 1;
    } 
  }
  printf("numero eh primo\n");
  return 0;
}