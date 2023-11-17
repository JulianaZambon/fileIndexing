#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "aplicacoes.h"

/*Função que insere um texto em uma
base de dados em formato de trie.*/
void insereTextoNaTrie(FILE *base, FILE *texto, char *nomeArqTexto, nodo *raiz) {
    char linha[1024];    
    char *palavra;

    /*Se arquivo texto vazio, retorna*/
    if (texto == NULL || feof(texto)) return;

    while (fgets(linha, sizeof(linha), texto) != NULL) {
        palavra = strtok(linha, " \t\n"); 

        while (palavra) {
            insereChave(raiz, palavra, nomeArqTexto);
            palavra = strtok(NULL, " \t\n");
        }
    }

    escreveTrieNaBase(base, raiz);
}

/*Função auxiliar para escrever trie no 
arquivo base de maneira recursiva.*/
void escreveTrieNaBase(FILE *base, nodo *atual) {
    if (atual == NULL)
        return;

    if (atual->nomeArquivo != NULL) {
        char *arquivoOrigem = malloc(strlen(atual->nomeArquivo) + 1);
        strcpy(arquivoOrigem, atual->nomeArquivo);
        char *nomesArquivos = strtok(arquivoOrigem, ",");

        while (nomesArquivos != NULL) {
            fprintf(base, "[%s]", nomesArquivos);
            nomesArquivos = strtok(NULL, ",");
        }
        fprintf(base, "\n");
        free(arquivoOrigem);
    }

    for (int i = 0; i < 52; i++) {
        if (atual->filhos[i] != NULL) {
            fprintf(base, "%c", (char)(atual->filhos[i]->caractere + 'A'));
            escreveTrieNaBase(base, atual->filhos[i]);
        }
    }
}

/*Procura o caractere fornecido em uma base de dados que 
contém a estrutura trie (procura caractere entre simbolo e 
faz um contador para verificar cada palavra encontrada)*/
void procuraPalavrasPorPrefixo(FILE *base, char *caractere) {
    char linha[1024];
    char nomeArquivo[512];
    nomeArquivo[0] = '\0';

    while (fgets(linha, sizeof(linha), base) != NULL) {

        if (linha[0] == '[')
            sscanf(linha, "[%[^]]]", nomeArquivo);

        else if (strstr(linha, caractere) != NULL) {
            char palavra[512];
            char arquivo[512];

            if (sscanf(linha, "%[^(](%[^)])", palavra, arquivo) == 2) {
                if (strncmp(palavra, caractere, strlen(caractere)) == 0)
                    fprintf(stdout, "%s %s\n", palavra, arquivo);
            
            }
        }
    }

    if (nomeArquivo[0] == '\0')
        fprintf(stderr, "Arquivo base não possui parâmetros necessários.\n");
}