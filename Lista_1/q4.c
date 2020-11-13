#include <stdio.h>

int aluno(float a, float b, float c){
  float z;
  if (((a+b+c)/3)>=7.0){
    printf("aprovado\n");
    return 0;
  }else if(((a+b+c)/3)<7.0 && ((a+b+c)/3)>=5.0){
    printf("recuperacao\n");
    return 1;
  }else{
    printf("reprovado\n");
    return 2;
  }
}


int main (){
  float a, b, c, y;
  int x;

  printf("Digite a nota 1: ");
  scanf("%f", &a);
  printf("Digite a nota 2: ");
  scanf("%f", &b);
  printf("Digite a nota 3: ");
  scanf("%f", &c);

  x = aluno(a,b,c);
  if (x == 1){
    y = ((a+b+c)/3) - 7.0;
    y = y*-1;
    y = y*3;
    printf("Voce precisa de %.2f para passar \n", y);
  } 

  return 0;
}