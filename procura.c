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

}