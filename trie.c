#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

/*Inicializa uma nova trie alocando memória para 
o nodo raiz e definindo um filho para cada letra 
inicial possível das palavras.*/
nodo *inicializaTrie() { 
    nodo *raiz = (nodo *) malloc(sizeof(nodo)); 
    raiz->caractere = -1; 
    raiz->fimPalavra = 0;

    for (int i = 0; i < 26; i++) 
        raiz->filhos[i] = NULL; 
    
    return raiz;
}

/*Insere uma palavra na trie.*/
void insereChave(nodo *raiz, char *chave) {
    nodo* atual = raiz;
    int letra;

    for (int i = 0; chave[i] != '\0'; i++) {
        char c = chave[i];
        
        if (c >= 'a' && c <= 'z')
            letra = c - 'a';   
        else if (c >= 'A' && c <= 'Z')
            letra = c - 'A';
        else
            continue;

        /*Se não houver correspondência para a letra
        em questão, cria um novo nodo, se houver, 
        procura a próxima letra correspondente.*/
        if (!atual->filhos[letra])
            atual->filhos[letra] = inicializaTrie();

        atual->caractere = letra;
        atual = atual->filhos[letra];
    }
    atual->fimPalavra = 1;
}

/*Busca uma palavra na trie e verifica se está 
nela, se encontrar, retorna 1, se não, retorna 0.*/
int procuraChave(nodo *raiz, char *chave) {
    nodo* atual = raiz;

    for (int i = 0; i < strlen(chave); i++) {
        int letra = chave[i] - 'a';
        
        if (!atual->filhos[letra])
            return 0; //Não encontrou a palavra

        atual = atual->filhos[letra];
    }

    return (atual != NULL && atual->fimPalavra);
}

/*Remove uma palavra da trie, se encontrá-la.*/
void removeChave(nodo *raiz, char *chave) {
    nodo* atual = raiz;
    
    //Se a palavra a ser removida não está na trie, retorna    
    if (!procuraChave(raiz, chave)) return;

    for (int i = 0; chave[i] != '\0'; i++) {
        int letra;
        char c = chave[i];

        if (c >= 'a' && c <= 'z')
            letra = c - 'a';
        
        else if (c >= 'A' && c <= 'Z')
            letra = c - 'A';
        
        else
            continue;

        //Continua se houver correspondência para a letra
        atual = atual->filhos[letra];
    }

    atual->fimPalavra = 0;
}

/*Libera a memória alocada para a trie.*/
void destroiTrie(nodo *raiz) {
    if (raiz) {
        for (int i = 0; i < 26; i++)
            destroi_trie(raiz->filhos[i]);

        free(raiz);
    }
}