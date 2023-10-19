#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "aplicacoes.h"

/* 
 * Função que insere um texto em uma base de dados.
 * base: arquivo de base de dados.
 * texto: texto a ser inserido na base de dados.*/
void insere(FILE *base, char *texto) {
    char *linha = NULL;
    size_t tam = 0;
    ssize_t lidos;
    while ((lidos = getline(&linha, &tam, base)) != -1) {
        if (strstr(linha, texto) != NULL) {
            printf("%s", linha);
        }
    }
    free(linha);
}

/* 
 * Função que procura um texto em uma base de dados.
 * base: arquivo de base de dados.
 * texto: texto a ser procurado na base de dados.*/
void procura(FILE *base, char *texto) {
    char *linha = NULL;
    size_t tam = 0;
    ssize_t lidos;
    while ((lidos = getline(&linha, &tam, base)) != -1) {
        if (strstr(linha, texto) != NULL) {
            printf("%s", linha);
        }
    }
    free(linha);
}

/* 
 * Função que remove um texto em uma base de dados.
 * base: arquivo de base de dados.
 * texto: texto a ser removido na base de dados.*/
void remove(FILE *base, char *texto) {
    char *linha = NULL;
    size_t tam = 0;
    ssize_t lidos;
    while ((lidos = getline(&linha, &tam, base)) != -1) {
        if (strstr(linha, texto) != NULL) {
            printf("%s", linha);
        }
    }
    free(linha);
}

/* 
 * Função que imprime uma base de dados.
 * base: arquivo de base de dados.
 * texto: texto a ser procurado na base de dados.*/
void imprime_trie(FILE *base, char *texto) {
    char *linha = NULL;
    size_t tam = 0;
    ssize_t lidos;
    while ((lidos = getline(&linha, &tam, base)) != -1) {
        if (strstr(linha, texto) != NULL) {
            printf("%s", linha);
        }
    }
    free(linha);
}





