#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hash.h" 

void gerar_dados_testes(TabelaHash* tabela, int quantidade) {
    const char* alunos[] = {"Maria", "João", "Ana", "Pedro", "Carlos","Claros"};
    int num_alunos = sizeof(alunos) / sizeof(alunos[0]);
    
    srand(time(NULL));
    
    for (int i = 0; i < quantidade; i++) {
        int aluno_idx = rand() % num_alunos;
        char chave[50];
        sprintf(chave, "%s-%d", alunos[aluno_idx], i);
        int valor = 60 + rand() % 40; // Notas entre 60 e 99
        
        inserir(tabela, chave, valor);
    }
}

void mostrar_colisoes(TabelaHash* tabela, const char* prefixo_chave) {
    printf("\nDemonstração de colisões para '%s':\n", prefixo_chave);
    
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ParChaveValor* atual = tabela->buckets[i];
        while (atual) {
            if (strstr(atual->chave, prefixo_chave) != NULL) {
                printf("Bucket %d: %s = %d (hash: %u)\n", 
                      i, atual->chave, atual->valor, funcao_hash(atual->chave));
            }
            atual = atual->proximo;
        }
    }
}

void estatisticas_tabela(TabelaHash* tabela) {
    int total_itens = 0;
    int buckets_ocupados = 0;
    int colisoes = 0;
    int maior_lista = 0;
    
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int itens_no_bucket = 0;
        ParChaveValor* atual = tabela->buckets[i];
        
        while (atual) {
            itens_no_bucket++;
            atual = atual->proximo;
        }
        
        if (itens_no_bucket > 0) {
            buckets_ocupados++;
            total_itens += itens_no_bucket;
            
            if (itens_no_bucket > 1) {
                colisoes += (itens_no_bucket - 1);
            }
            
            if (itens_no_bucket > maior_lista) {
                maior_lista = itens_no_bucket;
            }
        }
    }
    
    printf("\nEstatísticas da Tabela Hash:\n");
    printf("Total de itens: %d\n", total_itens);
    printf("Buckets ocupados: %d (de %d)\n", buckets_ocupados, TAMANHO_TABELA);
    printf("Total de colisões: %d\n", colisoes);
    printf("Maior lista encadeada: %d itens\n", maior_lista);
    printf("Taxa de ocupação: %.2f%%\n", (float)buckets_ocupados/TAMANHO_TABELA*100);
    printf("Taxa de colisão: %.2f%%\n", (float)colisoes/total_itens*100);
}

int main() {
    TabelaHash* tabela = criar_tabela_hash();
    const int NUM_INSERCOES = 50;
    
    printf("Inserindo %d valores aleatórios na tabela hash...\n", NUM_INSERCOES);
    gerar_dados_testes(tabela, NUM_INSERCOES);
    
    // Demonstração específica para colisões
    mostrar_colisoes(tabela, "Maria");
    mostrar_colisoes(tabela, "João");
    
    // Estatísticas completas
    estatisticas_tabela(tabela);
    
    // Liberar memória
    liberar_tabela(tabela);
    
    return 0;
}
