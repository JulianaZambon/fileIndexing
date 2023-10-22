#include <stdio.h>
#include <string.h>
#include "trie.h"
#include "aplicacoes.h"

int main() {
    char linha[1024];
    char *aplicacao = NULL;
    char *nomeBase = NULL;
    char *textoPrefixo = NULL;
    FILE *base = NULL;
    FILE *texto = NULL;

    while ((fgets(linha, sizeof(linha), stdin)) != NULL) {
        aplicacao = strtok(linha, " \n");
        nomeBase = strtok(NULL, " \n");
        textoPrefixo = strtok(NULL, " \n");

        if (strcmp(aplicacao, "insere") == 0) {
            base = fopen(nomeBase, "a");
            texto = fopen(textoPrefixo, "r");

            if (texto != NULL) {
                fprintf(base, "[%s]\n", textoPrefixo);
                insere(base, texto);
            }

        } else if (strcmp(aplicacao, "procura") == 0) {
            base = fopen(nomeBase, "r");

            if (base != NULL) {
                procura(base, textoPrefixo);
                fclose(base);
            }
        }
    }
    return 0;
}

