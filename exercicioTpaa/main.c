#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(void) {
  Node *tabela[TAMANHO_TABELA];
  for (int i = 0; i < TAMANHO_TABELA; i++) {
    tabela[i] = NULL;
  }

  // Inserindo as chaves na tabela
  char *chaves[12] = {"D", "Q", "B", "I", "M", "H",
                      "G", "U", "A", "C", "R", "S"};
  int valores[12] = {2, 0, 0, 1, 2, 0, 2, 1, 2, 1, 1, 2};
  for (int i = 0; i < 12; i++) {
    unsigned int indice = hash(chaves[i]);
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->chave = chaves[i];
    novo->valor = valores[i];
    if (tabela[indice] == NULL) {
      novo->prox = NULL;
    } else {
      novo->prox = tabela[indice];
    }
    tabela[indice] = novo;
  }

  // Imprimindo a tabela
  imprimir_tabela(tabela);

  // Buscando a chave J
  buscar(tabela, "J");

  return 0;
}