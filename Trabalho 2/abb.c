#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

No* novoNo(int valor) {
    No* n = (No*)malloc(sizeof(No));
    n->valor = valor;
    n->esq = n->dir = NULL;
    n->altura = 1;
    return n;
}

No* inserirABB(No* raiz, int valor) {
    if (raiz == NULL) return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserirABB(raiz->esq, valor);
    else
        raiz->dir = inserirABB(raiz->dir, valor);
    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void preOrdem(No* raiz) {
    if (raiz) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int busca(No* raiz, int valor, int* contador) {
    (*contador)++;
    if (raiz == NULL) return 0;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor)
        return busca(raiz->esq, valor, contador);
    else
        return busca(raiz->dir, valor, contador);
}
