#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* n) {
    return (n == NULL) ? 0 : n->altura;
}

int fatorBalanceamento(No* n) {
    if (n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}

No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

No* inserirAVL(No* raiz, int valor) {
    if (raiz == NULL) return novoNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserirAVL(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserirAVL(raiz->dir, valor);
    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    int fb = fatorBalanceamento(raiz);

    if (fb > 1 && valor < raiz->esq->valor)
        return rotacaoDireita(raiz);
    if (fb < -1 && valor > raiz->dir->valor)
        return rotacaoEsquerda(raiz);
    if (fb > 1 && valor > raiz->esq->valor) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
    if (fb < -1 && valor < raiz->dir->valor) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}
