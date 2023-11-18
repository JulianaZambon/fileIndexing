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
    int índiceCaractere; //Índice do caractere a ser inserido no vetor filhos

    /*Faz a inserção de caracteres e (se 
    necessário) a criação de novos nodos*/
    for (int i = 0; i < tam; i++) {
        
        /*Transforma um caractere ASCII da 
        palavra em índice de vetor filhos*/
        if (chave[i] >= 'A' && chave[i] <= 'Z')
            índiceCaractere = chave[i] - 65;
        else if (chave[i] >= 'a' && chave[i] <= 'z')
            índiceCaractere = chave[i] - 71;
        else
            índiceCaractere = -1;

        /*Se o caractere recebido é uma letra válida, insere-a 
        no nodo correspondente de acordo com seu índice*/
        if (índiceCaractere != -1 && atual) {
            if (!atual->filhos[índiceCaractere]) {
                atual->filhos[índiceCaractere] = inicializaTrie();
                atual->filhos[índiceCaractere]->caractere = chave[i];
            }
            atual = atual->filhos[índiceCaractere];

            /*Se for o último caractere da palavra, adiciona o nome do arquivo*/
            if (i == tam - 1) {
                if (atual->nomeArquivo == NULL) {
                    atual->nomeArquivo = (char *)malloc(strlen(nomeArqTexto) + 1);
                    strcpy(atual->nomeArquivo, nomeArqTexto);
                
                } else {
                    if (!strstr(atual->nomeArquivo, nomeArqTexto)) {
                        size_t tamNomeArquivo = strlen(atual->nomeArquivo);
                        size_t novoTam = tamNomeArquivo + strlen(nomeArqTexto) + 2;
                        atual->nomeArquivo = (char *)realloc(atual->nomeArquivo, novoTam);
                        strcat(atual->nomeArquivo, ",");
                        strcat(atual->nomeArquivo, nomeArqTexto);
                    }
                }
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