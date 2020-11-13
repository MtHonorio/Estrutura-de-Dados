#include <stdio.h>

void par(int a){
  if(a%2==0){
    printf("par\n");
  }else{
    printf("impar\n");
  }
}

int main (){
  int x;
  printf("digite o numero: \n");
  scanf("%d", &x);

  par(x);
  return 0;
}