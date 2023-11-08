#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/*Inicializa uma nova trie alocando memória para 
o nodo raiz e definindo um filho para cada letra 
inicial possível das palavras.*/
nodo *inicializaTrie() { 
    nodo *raiz = (nodo *) malloc(sizeof(nodo)); 
    raiz->caractere = -1; 

    for (int i = 0; i < 26; i++) 
        raiz->filhos[i] = NULL; 
    
    return raiz;
}

/*Insere uma palavra na trie.*/
void insereChave(nodo *raiz, char *chave, char *nomeArqTexto) {
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
        if (!(atual->filhos[letra]))
            atual->filhos[letra] = inicializaTrie();

        atual->caractere = letra;
        atual = atual->filhos[letra];
    }

    /*Atribui nome do arquivo em que está localizada a 
    palavra ao seu último caractere e, se outra palavra 
    que foi adicionada de outro arquivo for igual à essa 
    palavra em questão, concatena o nome de seus arquivos*/
    char nomeArqAux[strlen(nomeArqTexto) + 1];    
    if (atual->nomeArquivo[0] == '\0') {
        strncpy(atual->nomeArquivo, nomeArqTexto, strlen(nomeArqTexto));
        atual->nomeArquivo[strlen(nomeArqTexto)] = '\0';
    
    } else {
        sprintf(nomeArqAux, ",%s", nomeArqTexto);
        strcat(atual->nomeArquivo, nomeArqAux);
    }
}

/*Libera a memória alocada para a trie.*/
void destroiTrie(nodo *raiz) {
    if (raiz) {
        for (int i = 0; i < 26; i++)
            destroiTrie(raiz->filhos[i]);

        free(raiz);
    }
}