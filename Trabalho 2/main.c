#include <stdio.h>
#include "abb.h"
#include "avl.h"

int main() {
    int dados[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(dados) / sizeof(dados[0]);
    No* abb = NULL;
    No* avl = NULL;

    for (int i = 0; i < n; i++) {
        abb = inserirABB(abb, dados[i]);
        avl = inserirAVL(avl, dados[i]);
    }

    printf("=== ARVORE BINARIA DE BUSCA ===\n");
    printf("Em ordem: ");
    emOrdem(abb);
    printf("\nPre ordem: ");
    preOrdem(abb);
    printf("\nPos ordem: ");
    posOrdem(abb);
    printf("\n");

    printf("\n=== ARVORE AVL ===\n");
    printf("Em ordem: ");
    emOrdem(avl);
    printf("\nPre ordem: ");
    preOrdem(avl);
    printf("\nPos ordem: ");
    posOrdem(avl);
    printf("\n");

    int contadorABB = 0;
    int contadorAVL = 0;
    int elementoBusca = 35;

    printf("\nBuscando o elemento %d:\n", elementoBusca);
    printf("Resultado na ABB: %s\n", busca(abb, elementoBusca, &contadorABB) ? "Encontrado" : "Nao encontrado");
    printf("Resultado na AVL: %s\n", busca(avl, elementoBusca, &contadorAVL) ? "Encontrado" : "Nao encontrado");

    printf("Buscas realizadas (ABB): %d vezes\n", contadorABB);
    printf("Buscas realizadas (AVL): %d vezes\n", contadorAVL);

    return 0;
}
