#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

int buscaLinear(No *lista, int valor) {
    No *p = lista;
    while (p != NULL) {
        if (p->valor == valor) {
            return 1;
        }
        p = p->prox;
    }
    return 0;
}
