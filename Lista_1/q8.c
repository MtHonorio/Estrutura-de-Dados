#include <stdio.h>

int main (){
  int x, z=1;
  printf("Digite x: ");
  scanf("%d", &x);
  printf("---Fatorial---\n");
  while (x>=1)
  {
    z *= x;
    x--;
  }
  printf("%d\n", z);

  return 0;
}