#ifndef ABB_H
#define ABB_H

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

// --- ADICIONAR ISSO:
No* novoNo(int valor);

// --- Funções principais:
No* inserirABB(No* raiz, int valor);
void emOrdem(No* raiz);
void preOrdem(No* raiz);
void posOrdem(No* raiz);
int busca(No* raiz, int valor, int* contador);

#endif
