#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

// Cria uma nova trie
no_trie *cria_trie(no_trie *raiz) 
{ 
    no_trie *raiz = (no_trie *) malloc(sizeof(no_trie)); 
    raiz->valor = -1; 
    for (int i = 0; i < 26; i++) 
        raiz->filhos[i] = NULL; 
    return raiz;
}

// Insere uma chave na trie
void insere_chave(no_trie *raiz, char *chave, int valor)
{
    no_trie* atual = raiz;
    for (int i = 0; i < strlen(chave); i++) {
        int indice = chave[i] - 'a';
        if (!atual->filhos[indice]) {
            atual->filhos[indice] = cria_trie();
        }
        atual = atual->filhos[indice];
    }
    atual->fimDaPalavra = 1;
}

// Busca uma chave na trie e verifica se está nela
int procura_chave(no_trie *raiz, char *chave)
{
    no_trie* atual = raiz;
    for (int i = 0; i < strlen(chave); i++) {
        int indice = chave[i] - 'a';
        if (!atual->filhos[indice]) {
            return 0; // a palavra não está na trie
        }
        atual = atual->filhos[indice];
    }
    return (atual != NULL && atual->fimDaPalavra);
}

// Remove uma chave da trie
void remove_chave(no_trie *raiz, char *chave)
{
    no_trie* atual = raiz;
    for (int i = 0; i < strlen(chave); i++) {
        int indice = chave[i] - 'a';
        if (!atual->filhos[indice]) {
            return; // a palavra não está na trie
        }
        atual = atual->filhos[indice];
    }
    atual->fimDaPalavra = 0;
}

// Libera a memória alocada pela trie
void destroi_trie(no_trie *raiz)
{
    if (raiz) {
        for (int i = 0; i < 26; i++) {
            destroi_trie(raiz->filhos[i]);
        }
        free(raiz);
    }
}