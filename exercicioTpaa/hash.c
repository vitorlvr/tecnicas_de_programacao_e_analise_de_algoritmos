#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

unsigned int hash(char *chave) {
  unsigned int valor = 0;
  for (int i = 0; i < strlen(chave); i++) {
    valor += (int)chave[i];
  }
  return valor % TAMANHO_TABELA;
}

void imprimir_tabela(Node *tabela[]) {
  for (int i = 0; i < TAMANHO_TABELA; i++) {
    if (tabela[i] == NULL) {
      printf("[%d]: NULL\n", i);
    } else {
      printf("[%d]: ", i);
      Node *atual = tabela[i];
      while (atual != NULL) {
        printf("(%s, %d) -> ", atual->chave, atual->valor);
        atual = atual->prox;
      }
      printf("NULL\n");
    }
  }
}

void buscar(Node *tabela[], char *chave) {
  unsigned int indice = hash(chave);
  printf("Busca pela chave %s (hash: %d)\n", chave, indice);
  Node *atual = tabela[indice];
  while (atual != NULL) {
    if (strcmp(atual->chave, chave) == 0) {
      printf("Chave encontrada: (%s, %d)\n", atual->chave, atual->valor);
      return;
    }
    atual = atual->prox;
  }
  printf("Chave não encontrada\n");
}