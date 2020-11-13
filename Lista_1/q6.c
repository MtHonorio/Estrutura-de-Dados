#include <stdio.h>

int main (){
  int x, y;
  printf("Digite x: ");
  scanf("%d", &x);
  printf("Digite y: ");
  scanf("%d", &y);
  printf("---while---\n");
  while (x<=y)
  {
    printf("%d,", x);
    x++;
  }

  printf("\nDigite x: ");
  scanf("%d", &x);
  printf("Digite y: ");
  scanf("%d", &y);
  printf("---do while---\n");
  do{
    printf("%d,", x);
    x++;
  }while (x<=y);

  printf("Digite x: ");
  scanf("%d", &x);
  printf("Digite y: ");
  scanf("%d", &y);
  printf("---for---\n");
  for (x; x<=y; x++){
    printf("%d,", x);
  }
  printf("\nEND\n");
  return 0;
}