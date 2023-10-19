#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

    /* A segunda aplicação será uma ferramenta de busca, chamada procura, 
    que recebe como parâmetro (linha de comando) o nome de um arquivo e 
    uma string. O arquivo é o arquivo com a base de dados e a string é um prefixo. 
    A chamada seria algo como:
    > procura base prefixo
    Esta ferramenta executa uma busca na base de dados e escreve na saída padrão 
    (stdout) uma lista de arquivos que contém palavras que iniciem com o prefixo dado, 
    um arquivo por linha. O nome de cada arquivo deve ser precedido do prefixo procurado 
    e um espaço.
    Nenhuma outra mensagem deve ser escrita na saída padrão (stdout). Caso o arquivo da 
    base não exista ou algum parâmetro estiver faltando, uma mensagem apropriada deve ser 
    escrita na saída padrão de erro (stderr). Se não for encontrada nenhuma palavra com o
    prefixo a ferramenta não escreve nada. */

int main (int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso correto: %s <arquivo da base de dados> <prefixo>\n", argv[0]);
        return 1;
    }

    const char* base = argv[1];
    const char* prefixo = argv[2];

    // Abre o arquivo da base de dados
    FILE* base = fopen(base, "r");

    if (base == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo da base de dados.\n");
        return 1;
    }
    
    // Cria a Trie
    Trie* raiz = criaTrie();

    // Lê a base de dados e insere as palavras na Trie
    char palavra[100];
    while (fscanf(base, "%s", palavra) != EOF) {
        insereTrie(raiz, palavra);
    }

    // Busca as palavras com o prefixo dado
    Lista* lista = buscaTrie(raiz, prefixo);

    // Imprime a lista
    imprimeTrie(raiz, lista);

    // Libera a memória da Trie e da lista
    liberaTrie(raiz);
    destroiTrie(raiz);

    // Fecha o arquivo
    fclose(base);
}