#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "aplicacoes.h"

/*Função que insere um texto em uma
base de dados em formato de trie.*/
void insereTextoNaTrie(FILE *base, FILE *texto, char *nomeArqTexto, nodo *raiz) {
    char palavra[128];

    /*Se arquivo texto vazio, retorna*/
    if (texto == NULL) return;

    /*Insere as palavras na trie*/
    while (fscanf(texto, "%s", palavra) != EOF)
        insereChave(raiz, palavra, nomeArqTexto);

    escreveTrieNaBase(base, raiz, "");
}

/*Função auxiliar para escrever trie no 
arquivo base de maneira recursiva.*/
void escreveTrieNaBase(FILE *base, nodo *atual, char *prefixo) {
    
    if (atual) {
        char *arquivoOrigem = atual->nomeArquivo;
        char *indiceVirgula = strchr(arquivoOrigem, ',');

        /*Enquanto houverem vírgulas na string, ou seja, 
        palavras iguais vindas de diferentes arquivos*/
        while (indiceVirgula) {
            int tamanho = indiceVirgula - arquivoOrigem;

            /*Cria uma cópia do conteúdo que 
            precede a vírgula e o escreve*/
            char palavra[100];
            strncpy(palavra, arquivoOrigem, tamanho);
            palavra[tamanho] = '\0';
            fprintf(base, "%s[%s]\n", prefixo, palavra);
                
            arquivoOrigem = indiceVirgula + 1;
            indiceVirgula = strchr(arquivoOrigem, ',');
        }
        
        /*Se não houverem mais vírgulas, escreve 
        a última e encerra o loop*/
        if (*arquivoOrigem != '\0')
            fprintf(base, "%s[%s]\n", prefixo, arquivoOrigem);        

        for (int i = 0; i < 52; i++) {
            char proximo = (i < 26) ? (i + 'a') : (i - 26 + 'A');
            char novoPrefixo[100];
            sprintf(novoPrefixo, "%s%c", prefixo, proximo);
            escreveTrieNaBase(base, atual->filhos[i], novoPrefixo);
        }
    }
}

/*Procura o prefixo fornecido em uma base de dados que 
contém a estrutura trie (procura prefixo entre simbolo e 
faz um contador para verificar cada palavra encontrada)*/
void procuraPalavrasPorPrefixo(FILE *base, char *prefixo) {
    char linha[1024];
    char nomeArquivo[512];
    nomeArquivo[0] = '\0';

    while (fgets(linha, sizeof(linha), base) != NULL) {

        if (linha[0] == '[')
            sscanf(linha, "[%[^]]]", nomeArquivo);

        else if (strstr(linha, prefixo) != NULL) {
            char palavra[512];
            char arquivo[512];

            if (sscanf(linha, "%[^(](%[^)])", palavra, arquivo) == 2) {
                if (strncmp(palavra, prefixo, strlen(prefixo)) == 0)
                    fprintf(stdout, "%s %s\n", palavra, arquivo);
            
            }
        }
    }

    if (nomeArquivo[0] == '\0')
        fprintf(stderr, "Arquivo base não possui parâmetros necessários.\n");
}

/*
SAÍDA ESPERADA NO ARQUIVO BASE

palavraA[arquivodapalavraA]
palavraB[arquivodapalavraB]
...
*/