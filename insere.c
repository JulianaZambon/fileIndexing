#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/* A primeira aplicação será um pequeno programa, chamado insere, 
que recebe como parâmetro (linha de comando) os nomes de dois arquivos. 
O primeiro é o arquivo da base de dados e o segundo, um arquivo texto, 
onde as palavras serão procuradas. A chamada seria algo como:

> insere base arquivo-texto */

int main (int argc, char *argv[]) 
{
    /* As palavras encontradas no arquivo texto são inseridas na base já existente. 
    Caso o arquivo da base não exista, ele é criado. Caso o arquivo de texto não exista, 
    nada acontece (nem mensagem de erro).
    As palavras a serem procuradas e armazenadas na base são definidas como:
    [a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z]+
    Ou seja, seqüencias maximais de letras com 4 ou mais símbolos. Assuma que caracteres 
    acentuados não aparecem. */

    if (argc != 3) {
        fprintf(stderr, "Uso correto: %s <arquivo da base de dados> <arquivo texto>\n", argv[0]);
        return 1;
    }

    const char* base = argv[1];
    const char* arquivo-texto = argv[2];

    // Abre o arquivo da base de dados
    FILE* base = fopen(base, "r+");
    if (base == NULL) {
        base = fopen(base, "w+");
        if (base == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo da base de dados.\n");
            return 1;
        }
    }

    // Abre o arquivo texto
    FILE* arquivo-texto = fopen(arquivo-texto, "r");
    if (arquivo-texto == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo texto.\n");
        return 1;
    }

    // Cria a Trie
    Trie* raiz = criaTrie();

    // Lê o arquivo texto e insere as palavras na base de dados
    char palavra[100];
    while (fscanf(arquivo-texto, "%s", palavra) != EOF) {
        insereTrie(raiz, palavra);
    }

    // Imprime a base de dados
    imprimeTrie(raiz, base);

    // Fecha os arquivos e libera a memória da Trie
    fclose(arquivo-texto);
    fclose(base);
    destroiTrie(raiz);

    return 0;
}
