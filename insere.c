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


}
