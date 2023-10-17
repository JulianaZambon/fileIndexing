#include <stdio.h>
#include <stdlib.h>

/*A base de dados conterá as palavras existentes nos arquivos organizadas
 usando árvores digitais (tries) possivelmente implementadas com remoção 
 de nós com filho único. Cada registro (palavra) indicará a lista de 
 arquivos onde a palavra acontece. A base deve ser guardada em arquivo 
 para poder ser usada posteriormente. */

// struct para representar um nó da trie
typedef struct trie_node {
    int valor; // valor do nó
    struct trie_node *filhos[26]; // ponteiros para os filhos

} trie_node;

//Cria uma nova trie
trie_node *cria_trie();

//Insere uma chave na trie
void insere_chave(trie_node *root, char *key, int value);

//Busca uma chave na trie
int procura_chave(trie_node *root, char *key);

//Remove uma chave da trie
void remove_chave(trie_node *root, char *key);

//Libera a memória alocada pela trie
void destroi_trie(trie_node *root);

#endif
