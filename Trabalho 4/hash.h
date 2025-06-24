#ifndef TABELA_HASH_H
#define TABELA_HASH_H
#include <stdbool.h>
#define TAMANHO_MAX_CHAVE 100
#define TAMANHO_TABELA 101  // Número primo para o tamanho da tabela
typedef struct ParChaveValor {
    char chave[TAMANHO_MAX_CHAVE];
    int valor;
    struct ParChaveValor* proximo;
} ParChaveValor;
typedef struct {
    ParChaveValor** buckets;
} TabelaHash;
// Declarações das funções
unsigned int funcao_hash(const char* chave); // Adicionada a declaração da função
TabelaHash* criar_tabela_hash(void);
bool inserir(TabelaHash* tabela, const char* chave, int valor);
int* buscar(TabelaHash* tabela, const char* chave);
bool remover(TabelaHash* tabela, const char* chave);
void imprimir_tabela(TabelaHash* tabela);
void liberar_tabela(TabelaHash* tabela);
#endif