#ifndef TRIE_H
#define TRIE_H

/*Struct para representar um nodo da trie.*/
typedef struct nodo {
    int caractere; //Valor do caractere armazenado no nó
    struct nodo *filhos[52]; //Ponteiros para os filhos (minúsculas + maiúsculas)
    int fimPalavra; //Flag para indicar o fim da palavra
} nodo;

/*Inicializa uma nova trie alocando memória para 
o nodo raiz e definindo um filho para cada letra 
inicial possível das palavras.*/
nodo *inicializaTrie();

/*Insere uma palavra na trie.*/
void insereChave(nodo *raiz, char *chave);

/*Busca uma palavra na trie e verifica se está 
nela, se encontrar, retorna 1, se não, retorna 0.*/
int procuraChave(nodo *raiz, char *chave);

/*Remove uma palavra da trie, se encontrá-la.*/
void removeChave(nodo *raiz, char *chave);

/*Libera a memória alocada para a trie.*/
void destroiTrie(nodo *raiz);

#endif
