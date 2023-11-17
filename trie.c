#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/*Inicializa uma nova trie alocando memória para 
o nodo raiz e definindo um filho para cada letra 
inicial possível das palavras.*/
nodo *inicializaTrie() { 
    nodo *raiz = (nodo *)malloc(sizeof(nodo)); 
    raiz->caractere = '\0';
    raiz->nomeArquivo = NULL;

    for (int i = 0; i < 52; i++) 
        raiz->filhos[i] = NULL; 
    
    return raiz;
}

void insereChave(nodo *raiz, char *chave, char *nomeArqTexto) {
    nodo* atual = raiz;
    int tam = strlen(chave);
    int letra;

    /* Faz a inserção de caracteres e (se 
    necessário) a criação de novos nodos */
    for (int i = 0; i < tam; i++) {
        letra = (chave[i] >= 'A' && chave[i] <= 'Z')
                    ? chave[i] - 'A'
                    : (chave[i] >= 'a' && chave[i] <= 'z')
                        ? chave[i] - 'a'
                        : -1;

        if (letra >= 0) {
            if (atual && !atual->filhos[letra]) {
                atual->filhos[letra] = inicializaTrie();
                atual->filhos[letra]->caractere = letra + 'A'; //Ajusta o valor do caractere
                atual = atual->filhos[letra];
            }
        }
    }

    /* Atribui nome do arquivo em que está localizada a 
    palavra ao seu último caractere e, se outra palavra 
    que foi adicionada de outro arquivo for igual à essa 
    palavra em questão, concatena o nome de seus arquivos */
    if (atual) {
        if (atual->nomeArquivo == NULL) {
            atual->nomeArquivo = (char *)malloc(strlen(nomeArqTexto) + 1);
            strcpy(atual->nomeArquivo, nomeArqTexto);
        
        } else {
            
            /*Se já tiver sido adicionada a mesma palavra
            mais de uma vez proveniente de um mesmo arquivo*/
            if (!strstr(atual->nomeArquivo, nomeArqTexto)) {
                size_t tam = strlen(atual->nomeArquivo);
                size_t novoTam = tam + strlen(nomeArqTexto) + 2;
            
                atual->nomeArquivo = (char *)realloc(atual->nomeArquivo, novoTam);
                strcat(atual->nomeArquivo, ",");
                strcat(atual->nomeArquivo, nomeArqTexto);
            }
        }
    }
}

/*Libera a memória alocada para a trie.*/
void destroiTrie(nodo *raiz) {
    if (raiz == NULL) return;
    
    for (int i = 0; i < 52; i++)
        destroiTrie(raiz->filhos[i]);

    free(raiz->nomeArquivo);
    free(raiz);
}