##Descrição do trabalho
# 🌳 Comparativo: Árvore Binária de Busca (BST) vs Árvore AVL

Este projeto tem como objetivo demonstrar as diferenças práticas entre **Árvores Binárias de Busca (BST)** e **Árvores AVL**, com foco em como os dados são inseridos, percorridos e buscados, além de contabilizar a eficiência da busca em cada tipo de árvore.

## 📌 Objetivos

✅ Implementar:
- Árvore Binária de Busca (BST)  
- Árvore AVL (com balanceamento automático)

✅ Verificar:
- Como os dados são inseridos separadamente em cada estrutura  
- Como as árvores crescem com base na ordem de inserção

✅ Implementar e demonstrar:
- Percursos: Em ordem, Pré-ordem e Pós-ordem  
- Algoritmo de busca com contador de acessos para análise de desempenho

---

## 🧠 Conceitos

### 🔹 BST (Binary Search Tree)
- Estrutura onde a inserção é feita com base em comparações, mas sem controle de balanceamento.
- Pode gerar árvores degeneradas (como listas encadeadas) em casos extremos.

### 🔹 AVL (Adelson-Velsky and Landis)
- Variante da BST que aplica rotações após cada inserção para manter a árvore balanceada.
- Garante altura logarítmica: busca, inserção e remoção sempre eficientes.

---

## 📁 Estrutura do Projeto
-main.c // Código principal que realiza testes comparativos
-abb.c / abb.h // Implementação da Árvore Binária de Busca
-avl.c / avl.h // Implementação da Árvore AVL
 Funcionalidades

### 🔸 Inserção
- Inserção individual em cada árvore
- AVL realiza balanceamentos automaticamente

### 🔸 Percursos
Implementados nos dois tipos de árvore:
- Em Ordem (In-Order)
- Pré-Ordem (Pre-Order)
- Pós-Ordem (Post-Order)

> Isso permite observar a estrutura interna das árvores e a ordem lógica dos elementos.

### 🔸 Busca com contador
- A função de busca retorna o número de vezes que foi chamada até encontrar o elemento
- Usado para comparar a eficiência de busca entre BST e AVL

---

## 🧪 Exemplo de Saída

-Inserindo os elementos: 30 20 40 10 25 35 50

-Percurso em ordem (BST): 10 20 25 30 35 40 50
-Percurso em ordem (AVL): 10 20 25 30 35 40 50

-Busca pelo elemento 50:
-Acessos na BST: 3
-Acessos na AVL: 2
-Busca pelo elemento 25:
-Acessos na BST: 3
-Acessos na AVL: 2

> Em árvores grandes e desbalanceadas, a AVL se destaca por manter desempenho constante.


## 🚀 Como Compilar
gcc main.c bst.c avl.c -o arvores
./arvores

##👨‍🏫 Considerações
A AVL é ideal quando há muitas operações de busca em conjuntos grandes de dados.

A BST pode ser suficiente em casos simples, mas seu desempenho depende da ordem de inserção.

A contagem de acessos fornece uma métrica direta da eficiência de cada estrutura.
