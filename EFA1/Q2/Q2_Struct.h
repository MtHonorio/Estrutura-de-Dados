#pragma once

typedef struct no No;
No* conjunto_cria(int numero);

//Pega a cabeca da lista e printa o conjunto.
void conjunto_print(No *cabeca);

//(a) União 
No* conjunto_uniao(No** cabeca1,No** cabeca2);

//(b) Cria um conjunto vazio
No* conjunto_cria_vazio();

//(c) Insere
int conjunto_insere(No** cabeca, int numero);

//(d) Remove
int conjunto_remove(No** cabeca, int numero);

//(e) Intersecção
No* conjunto_interseccao(No** cabeca1,No** cabeca2);

//(f) Diferenca
No* conjunto_diferenca(No** cabeca1,No** cabeca2);

//(g) Testa se um número pertence ao conjunto
int conjunto_existe_valor(No* cabeca, int numero);

//(h) Menor valor
int conjunto_menor_valor(No* cabeca);

//(i) Maior valor
int conjunto_maior_valor(No* cabeca);

//(j) Testa se os conjuntos são iguais
int conjunto_iguais(No* cabeca1, No* cabeca2);

//(k) Retorna o Tamanho do conjunto
int conjunto_tamanho(No* cabeca);

//(l) Testa se o conjunto é vazio
int conjunto_eh_vazio(No* cabeca);