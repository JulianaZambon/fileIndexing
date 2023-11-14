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
    raiz->nomeArquivo[0] = '\0';

    for (int i = 0; i < 52; i++) 
        raiz->filhos[i] = NULL; 
    
    return raiz;
}

/*Insere uma palavra na trie.*/
void insereChave(nodo *raiz, char *chave, char *nomeArqTexto) {
    nodo* atual = raiz;
    int letra;

    /*Faz o tratamento da string para que caracteres que
    não corresponderem à letras sejam desconsiderados*/
    int len = strlen(chave);
    
    for (int i = 0; i < len; i++) {
        if ((chave[i] < 'A' || chave[i] > 'Z') && (chave[i] < 'a' || chave[i] > 'z')) {
            for (int j = i; j < len - 1; j++)
                chave[j] = chave[j + 1];
        
            chave[len - 1] = '\0';
            len--;
            i--;
        }
    }

    /*Faz a inserção de caracteres e (se 
    necessário) a criação de novos nodos*/
    for (int i = 0; chave[i] != '\0'; i++) {
        letra = chave[i];

        if (atual && !atual->filhos[letra]) {
            atual->filhos[letra] = inicializaTrie();
            atual->filhos[letra]->caractere = letra;
        }
        atual = atual->filhos[letra];
    }

    /*Atribui nome do arquivo em que está localizada a 
    palavra ao seu último caractere e, se outra palavra 
    que foi adicionada de outro arquivo for igual à essa 
    palavra em questão, concatena o nome de seus arquivos*/
    char nomeArqAux[1024];

    if (atual) {
        if (atual->nomeArquivo[0] == '\0') {
            strncpy(atual->nomeArquivo, nomeArqTexto, strlen(nomeArqTexto));
            atual->nomeArquivo[strlen(nomeArqTexto)] = '\0';
        
        } else {
            sprintf(nomeArqAux, ",%s", nomeArqTexto);
            strcat(atual->nomeArquivo, nomeArqAux);
        }
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