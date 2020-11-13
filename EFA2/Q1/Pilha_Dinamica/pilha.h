#pragma once

typedef float Chave;
typedef struct pilha Pilha;
//Cria uma pilha vazia
Pilha* new_pilha (void);
//Empilha no topo
void pilha_push (Pilha* p, Chave v);
//Desempilha do topo
Chave pilha_pop (Pilha* p);
//Verifica se a pilha eh vazia
int pilha_vazia (Pilha* p);
//Libera a memoria
void pilha_libera (Pilha* p);
//Printa os elementos da pilha
void pilha_imprime(Pilha* p);
//Retorna o tamanho da pilha
int pilha_tamanho(Pilha* p);