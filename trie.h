#ifndef TRIE_H
#define TRIE_H

/*Struct para representar um nodo da trie.*/
typedef struct nodo {
    int caractere; //Valor do caractere armazenado no nó (ASCII)
    struct nodo *filhos[52]; //Ponteiros para os filhos (letras minúsculas e maiúsculas)
    char nomeArquivo[512]; //Nome do(s) arquivo(s) da palavra
} nodo;

/*Inicializa uma nova trie alocando memória para 
o nodo raiz e definindo um filho para cada letra 
inicial possível das palavras.*/
nodo *inicializaTrie();

/*Insere uma palavra na trie.*/
void insereChave(nodo *raiz, char *chave, char *nomeArqTexto);

/*Compara palavra a ser inserida com palavras já existentes*/
int comparaChave();

/*Libera a memória alocada para a trie.*/
void destroiTrie(nodo *raiz);

#endif
