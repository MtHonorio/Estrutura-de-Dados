#pragma once

typedef float Chave;
typedef struct pilha Pilha;
typedef struct elemento Elemento;

Pilha* newVazio(void);
void empilhar(Pilha* p, Chave Chave);
Chave desempilhar(Pilha* p);
int tamanho(Pilha* p);
int ehVazio(Pilha* p);
void liberar(Pilha* p);
void printar(Pilha* p);