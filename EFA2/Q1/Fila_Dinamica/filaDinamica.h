#pragma once

typedef struct fila Fila;
typedef float Chave;

Fila* newFila(void);
void insere(Fila* f, Chave v);
Chave retira(Fila* f);
int vazia(Fila* f);
void printar(Fila *f);
void libera(Fila* f);