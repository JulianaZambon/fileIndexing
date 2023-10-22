#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "aplicacoes.h"

/*Função que insere um texto em uma 
base de dados em formato de trie.*/
void insere(FILE *base, FILE *texto) {
    nodo *raiz = inicializaTrie();
    char palavra[128];

    //Se arquivo texto vazio, retorna
    if (texto == NULL) return;

    //Insere as palavras na trie
    while (fscanf(texto, "%s", palavra) != EOF)
        insereChave(raiz, palavra);

    //Insere a trie no arquivo base
    escreveTrie(base, raiz, "", 0);
}

/*Função auxiliar para escrever trie no 
arquivo base de maneira recursiva.*/
void escreveTrie(FILE *base, nodo *atual, char *palavra, int nivel) {
    if (atual) {
        palavra[nivel] = (atual->caractere < 26) ? (atual->caractere + 'a') : (atual->caractere - 26 + 'A');

        if (atual->fimPalavra) {
            palavra[nivel + 1] = '\0';
            fprintf(base, "%s\n", palavra);
        }

        for (int i = 0; i < 52; i++)
            escreveTrie(base, atual->filhos[i], palavra, nivel + 1);
    }
}

/*Procura a palavra fornecida em uma base de dados que 
contém uma ou mais estruturas de dados trie.*/
void procura(FILE *base, char *prefixo) {
    char linha[1024];
    char nomeArquivo[512];
    nomeArquivo[0] = -1;

    while (fgets(linha, sizeof(linha), base) != NULL) {
        
        //Se identificar um nome de arquivo, armazena no array
        if (linha[0] == '[') {

            /*Se foi encontrado um novo nome de arquivo mas já
            havia outro nome armazenado, anula a string.*/
            if (nomeArquivo[0] != '\0') {
                for (int i = strlen(nomeArquivo); i >= 0; i--)
                    nomeArquivo[i] = '\0'; 
            }

            //Atribui novo nome de arquivo para a variavel
            for (int i = 0; linha[i + 1] != ']'; i++)
                nomeArquivo[i] = linha[i + 1];
            nomeArquivo[strlen(nomeArquivo) - 1] = '\0';
        }
        
        if (strstr(linha, prefixo) != NULL)
            fprintf(stdout, "%s %s\n", nomeArquivo, prefixo);
    }
    
    if (nomeArquivo[0] == -1)
        fprintf(stderr, "Arquivo base não possuí parâmetros necessários.\n");
}
