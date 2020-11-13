#include <stdio.h>

int main (){
  int x, y, z=0;
  printf("Digite x: ");
  scanf("%d", &x);
  printf("Digite y: ");
  scanf("%d", &y);
  printf("---Somatorio---\n");
  while (x<=y)
  {
    z += x;
    x++;
  }
  printf("%d\n", z);

  return 0;
}