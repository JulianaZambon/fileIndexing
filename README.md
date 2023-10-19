# Algoritmos e Estrutura de Dados III

## Trabalho Prático 2: Indexação de Arquivos
Este trabalho prático foi desenvolvido para a disciplina CI1057 - Algoritmos e Estruturas de Dados 3 do Departamento de Informática da UFPR. <br>
O objetivo do trabalho é a implementação de uma base de dados para localização de palavras em um conjunto de arquivos.

Equipe: 
- Juliana Zambon (jz22), GRR20224168;
- Millena Suiani Costa (msc22), GRR20221243.

### Base de Dados (trie.c e trie.h)
Os arquivos contém palavras que devem ser organizadas através de estruturas trie, ou seja, cada trie representa um arquivo.

#### Estrutura de dados da Trie

##### Struct Nó da Trie

```c
typedef struct no_trie {
    int valor; // valor do nó
    struct no_trie *filhos[26]; // ponteiros para os filhos
    int fimDaPalavra; // flag para indicar o fim da palavra
} no_trie;
```

##### Funções Desenvolvidas

- `no_trie *cria_trie();`
  - Cria uma nova trie;

- `void insere_chave(no_trie *raiz, char *chave, int valor);`
  - Insere uma chave na trie;


### Aplicações: insere e procura
- Função insere(base, texto) = Arquivo texto, caso exista, tem suas palavras encontradas inseridas numa estrutura trie, 
caso não, nada acontece. Arquivo base (caso não exista, é criado), caso a trie gerada não seja vazia, a recebe.

- Função procura(base, prefixo) = Busca na base de dados  e retorna na saída padrão stdout uma lista de arquivos que
contenham palavras que iniciam com o prefixo fornecido (um arquivo por linha precedido do prefixo procurado e um espaço “arquivo-1 prefixo-1”). 

