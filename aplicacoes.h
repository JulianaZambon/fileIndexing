#ifndef APLICACOES_H
#define APLICACOES_H

/*Função que insere um texto em uma 
base de dados em formato de trie.*/
void insere(FILE *base, FILE *texto);

/*Função auxiliar para escrever trie no 
arquivo base de maneira recursiva.*/
void escreveTrie(FILE *base, nodo *atual, char *palavra, int nivel);

/*Procura a palavra fornecida em uma base de dados que 
contém uma ou mais estruturas de dados trie.*/
void procura(FILE *base, char *prefixo);

#endif


