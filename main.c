#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aplicacoes.h"
#include "trie.h"

/*
Faz a chamada dos programas contidos em aplicacoes.c no formato:	
Le linha do script;
    char aplicacao[] = primeira palavra de cada linha do script;
    char nomeBase[] = segunda palavra de cada linha do script;
    char textoPrefixo[] = terceira palavra de cada linha do script;
    FILE *base = fopen(“método”, nomeBase.txt);

while (base) {
    if (aplicacao == insere) {
        abre arquivo texto (“método”, textoPrefixo.txt); 
        insere(base, texto);
    } else if (aplicacao == procura)
        procura (base, textoPrefixo[0]);
        lê nova linha do script e armazena palavras nas respectivas 
    variáveis para executar nova ação;	
}
*/

int main(int argc, char *argv[]) {
    char *linha = NULL;
    size_t tam = 0;
    ssize_t lidos;
    char *aplicacao = NULL;
    char *nomeBase = NULL;
    char *textoPrefixo = NULL;
    FILE *base = NULL;
    FILE *texto = NULL;
    while ((lidos = getline(&linha, &tam, stdin)) != -1) {
        aplicacao = strtok(linha, " ");
        nomeBase = strtok(NULL, " ");
        textoPrefixo = strtok(NULL, " ");
        if (strcmp(aplicacao, "insere") == 0) {
            base = fopen(nomeBase, "a");
            texto = fopen(textoPrefixo, "r");
            insere(base, texto);
            fclose(base);
            fclose(texto);
        } else if (strcmp(aplicacao, "procura") == 0) {
            base = fopen(nomeBase, "r");
            procura(base, textoPrefixo);
            fclose(base);
        } else if (strcmp(aplicacao, "remove") == 0) {
            base = fopen(nomeBase, "r");
            remove(base, textoPrefixo);
            fclose(base);
        } else if (strcmp(aplicacao, "imprime_trie") == 0) {
            base = fopen(nomeBase, "r");
            imprime_trie(base, textoPrefixo);
            fclose(base);
        }
    }
    free(linha);
    return 0;
}

