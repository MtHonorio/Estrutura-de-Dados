#pragma once

typedef struct MATRIZ MATRIZ;
typedef struct NO NO;

//(a) Criar a matriz esparsa
MATRIZ* cria_matriz(int n_linhas, int n_colunas);
//(b) Remover a matriz esparsa
void remover_matriz(MATRIZ* matriz);
//(c) Inserir um valor na posição (i,j)
int inserir_no(MATRIZ* matriz, int linha, int coluna, float valor);
//(d) Remover um valor na posição (i,j)
int remover_no(MATRIZ* matriz, int linha, int coluna);
//(e) Exibir na tela a matriz (com todos os seus 0s não armazenados)
void print_matriz(MATRIZ * matriz);
float acessar_no(MATRIZ * matriz, int linha, int coluna);