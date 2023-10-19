#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef APLICACOES_H
#define APLICACOES_H

void insere(FILE *base, char *texto);

void procura(FILE *base, char *texto);

void remove(FILE *base, char *texto);

void imprime_trie(FILE *base, char *texto);

#endif


