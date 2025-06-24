#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"


unsigned int funcao_hash(const char* chave) {
    double A = 0.6180339887;
    unsigned long k = 0;
    size_t len = strlen(chave);
    for (size_t i = 0; i < len; i++) {
        k = k * 31 + (unsigned char)chave[i];
    }
    double produto = k * A;
    double frac = produto - floor(produto);
    unsigned int indice = (unsigned int)(TAMANHO_TABELA * frac);
    return indice;
}

TabelaHash* criar_tabela_hash() {
    TabelaHash* tabela = malloc(sizeof(TabelaHash));
    if (!tabela) {
        fprintf(stderr, "Erro: falha na alocação da tabela hash.\n");
        exit(EXIT_FAILURE);
    }
    tabela->buckets = calloc(TAMANHO_TABELA, sizeof(ParChaveValor*));
    if (!tabela->buckets) {
        fprintf(stderr, "Erro: falha na alocação dos buckets.\n");
        free(tabela);
        exit(EXIT_FAILURE);
    }
    return tabela;
}

bool inserir(TabelaHash* tabela, const char* chave, int valor) {
    if (!tabela || !chave) return false;
    unsigned int indice = funcao_hash(chave);
    ParChaveValor* atual = tabela->buckets[indice];
    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            atual->valor = valor;
            return true;
        }
        atual = atual->proximo;
    }
    ParChaveValor* novo_par = malloc(sizeof(ParChaveValor));
    if (!novo_par) {
        fprintf(stderr, "Erro: falha na alocação de novo nó.\n");
        return false;
    }
    strncpy(novo_par->chave, chave, TAMANHO_MAX_CHAVE - 1);
    novo_par->chave[TAMANHO_MAX_CHAVE - 1] = '\0';
    novo_par->valor = valor;
    novo_par->proximo = tabela->buckets[indice];
    tabela->buckets[indice] = novo_par;
    return true;
}

int* buscar(TabelaHash* tabela, const char* chave) {
    if (!tabela || !chave) return NULL;
    unsigned int indice = funcao_hash(chave);
    ParChaveValor* atual = tabela->buckets[indice];
    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            return &atual->valor;
        }
        atual = atual->proximo;
    }
    return NULL;
}

bool remover(TabelaHash* tabela, const char* chave) {
    if (!tabela || !chave) return false;
    unsigned int indice = funcao_hash(chave);
    ParChaveValor* atual = tabela->buckets[indice];
    ParChaveValor* anterior = NULL;
    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela->buckets[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void imprimir_tabela(TabelaHash* tabela) {
    if (!tabela) return;
    printf("Conteúdo da Tabela Hash:\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ParChaveValor* atual = tabela->buckets[i];
        if (atual) {
            printf("Bucket %d:\n", i);
            while (atual) {
                printf("  Chave: '%s' | Valor: %d\n", atual->chave, atual->valor);
                atual = atual->proximo;
            }
        }
    }
}

void liberar_tabela(TabelaHash* tabela) {
    if (!tabela) return;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ParChaveValor* atual = tabela->buckets[i];
        while (atual) {
            ParChaveValor* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(tabela->buckets);
    free(tabela);
}