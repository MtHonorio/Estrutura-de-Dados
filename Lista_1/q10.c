#include <stdio.h>

int main (){
  int x;
  printf("Qual o tamanho do vetor: ");
  scanf("%d", &x);
  int y[x];
  for (int i=0; i<=x; i++){
    scanf("%d", &y[i]);
  }
  for (size_t i = 0; i <= x; i++)
  {
    printf("%d, ", y[i]);
  }
  
  return 0;
}