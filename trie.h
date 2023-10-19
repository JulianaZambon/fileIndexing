#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRIE_H
#define TRIE_H

/*A base de dados conterá as palavras existentes nos arquivos organizadas
 usando árvores digitais (tries) possivelmente implementadas com remoção 
 de nós com filho único. Cada registro (palavra) indicará a lista de 
 arquivos onde a palavra acontece. A base deve ser guardada em arquivo 
 para poder ser usada posteriormente. */

// struct para representar um nó da trie
typedef struct no_trie {
    int valor; // valor do nó
    struct no_trie *filhos[26]; // ponteiros para os filhos
    int fimDaPalavra; // flag para indicar o fim da palavra
} no_trie;

// Cria uma nova trie
no_trie *cria_trie();

// Insere uma chave na trie
void insere_chave(no_trie *raiz, char *chave, int valor);

// Busca uma chave na trie
int procura_chave(no_trie *raiz, char *chave);

// Remove uma chave da trie
void remove_chave(no_trie *raiz, char *chave);

// Libera a memória alocada pela trie
void destroi_trie(no_trie *raiz);

#endif
