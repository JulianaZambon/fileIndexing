# Algoritmos e Estrutura de Dados III

## Trabalho Prático 2: Indexação de Arquivos
Este trabalho prático foi desenvolvido para a disciplina CI1057 - Algoritmos e Estruturas de Dados 3 do Departamento de Informática da UFPR. <br>
O objetivo do trabalho é a implementação de uma base de dados para localização de palavras em um conjunto de arquivos.

Equipe: 
- Juliana Zambon (jz22), GRR20224168;
- Millena Suiani Costa (msc22), GRR20221243.

### Base de Dados (trie.c e trie.h)
Os arquivos contém palavras que devem ser organizadas através de estruturas trie, ou seja, cada trie representa um conjunto de palavras. Cada uma das tries geradas são adicionadas em um arquivo base (que representa a base de dados).

#### Estrutura de dados da Trie

##### Struct Nó da Trie

```c
typedef struct nodo {
    int caractere; //Valor do caractere armazenado no nó
    struct nodo *filhos[52]; //Ponteiros para os filhos (minúsculos + maiúsculos)
    int fimPalavra; //Flag para indicar o fim da palavra
} nodo;
```

##### Funções Desenvolvidas

- `nodo *inicializaTrie();`
  - Inicializa uma nova trie alocando memória para 
  o nodo raiz e definindo um filho para cada letra 
  inicial possível das palavras;

- `void insereChave(nodo *raiz, char *chave);`
  - Insere uma palavra na trie;

- `int procuraChave(nodo *raiz, char *chave);`
  - Busca uma palavra na trie e verifica se está 
  nela, se encontrar, retorna 1, se não, retorna 0;

- `void removeChave(nodo *raiz, char *chave);`
  - Remove uma palavra da trie, se encontrá-la;
 
- `void destroiTrie(nodo *raiz);`
  - Libera a memória alocada para a trie.

### Aplicações (aplicacoes.c e aplicacoes.h)

##### Aplicação insere(base, texto) 

Faz com que o arquivo texto, caso exista, tenha suas palavras inseridas numa estrutura trie, caso não exista, nada acontece. Também faz com que o arquivo base (caso não exista, seja criado), caso a trie gerada não seja vazia, a recebe. Inclui duas funções:

- `void insere(FILE *base, FILE *texto);`
  - Função que insere um texto em uma 
  base de dados em formato de trie;
 
- `void escreveTrie(FILE *base, nodo *atual, char *palavra, int nivel);`
  - Função auxiliar para escrever trie no 
  arquivo base de maneira recursiva.

##### Aplicação procura(base, prefixo) 

Busca prefixo indicado na base de dados e retorna, na saída padrão, uma lista de arquivos que o contenham. Inclui uma função: 

- `void procura(FILE *base, char *prefixo);`
  - Procura a palavra fornecida em uma base de dados que 
  contém uma ou mais estruturas de dados trie.