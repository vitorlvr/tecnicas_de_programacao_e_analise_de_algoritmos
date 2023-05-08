#define TAMANHO_TABELA 3

typedef struct Node {
  char *chave;
  int valor;
  struct Node *prox;
} Node;

unsigned int hash(char *chave);
void imprimir_tabela(Node *tabela[]);
void buscar(Node *tabela[], char *chave);