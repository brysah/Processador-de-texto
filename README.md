# Processamento de Texto

Como primeira parte , objetivo desta tarefa é desenvolver um programa para ler e processar arquivos ASCII para encontrar as palavras mais usadas na língua portuguesa. Para isso utilizei como base livros em língua portuguesa disponíveis em:  [Projeto Guteberg](https://www.gutenberg.org/browse/languages/pt) 
Como segunda parte, foi implementado o índice remissivo das palavras mais frequentes encontradas. O índice remissivo é aquele que mostra para cada palavra, as páginas que elas aparecem no texto. Neste projeto, ao invés de considerar as páginas onde essas palavras aparecem, iremos exibir as linhas. Além disso, para otimizar o armazenamento, foi desenvolver um método de compressão.

## Métodos
Há muitas maneiras de atingir esse objetivo, mas usei uma tabela hash para contar o número de vezes que cada palavra única ocorre à medida que digitalizamos o arquivo ascii. Quando terminar de processar o documento, a tabela de hash conterá N palavras exclusivas e seus contadores de palavras associados.

Existem várias questões-chave de design que foram abordadas neste projeto: 
1. como ler o arquivo de texto e extrair as palavras individuais;
2. como armazenar e acessar pares de "(palavras,contagem)" na tabela de hash;
3. como extrair e classificar pares de "(palavras/contagem)" para identificar as 50 palavras mais usadas no documento.


### Tipo Abstrado de Dados: Tabela Hash

O tipo abstrato de dados hash com encadeamento separado contém as seguintes rotinas implementadas:
1. *Construtor*: Deve receber como entrada o tamanho *M* da tabela.
2. *Insere*    : O parametro de entrada deve ser um registro. 
3. *Busca*     : Dado a chave de busca, a rotina deve retornar o ponteiro para o registro procurado. A função deve retornar *nullptr* caso a busca seja invalida.
4. *Remove*    : Dada uma chave de busca, deve-se remover o registro da tabela hash.
5. ImprimeInfo : Imprime o número de colisões ocorridas nas inserções de dados na tabela ao usar uma determinada função hash.
6. *Destrutor* : desaloca toda a memoria ocupada pela tabela hash.

### Caso 2: Funções Hash

Foi feito estudo comparativo entre diferentes funções hash. Para tanto, foi escolhido um 
texto disponível no Projeto Guteberg e indexou-se as palavras em tabelas hashes com funções distintas. O programa reporta o número de palavras e o total de colições para cada uma das funções testadas.

### Caso 3: Analisar o desempenho dos métodos de ordenação

Ao identificar as 50 palavras mais usadas de um livro, se analisou o desempenho de pelo menos 3 métodos de ordenação. 

### Caso 4: Identificar as 50 palavras mais usadas

É processado um conjunto de 10 livros. O programa é capaz de:
  - Identificar as 50 palavras mais usadas de cada livro. Para cada livro, foi feito o processamento e escrito em um arquivo ascii as 50 palavras mais frequentes com suas respectivas contagens.

  - Identificar as 50 palavras mais usadas no total. Foi escrito em um arquivo ascii as 50 palavras mais frequentes no total com suas respectivas contagens ordenadas em ordem decrescente.

Para padronizar a leitura dos dados, considere que os arquivos com os textos de entrada estejam dentro da pasta *input* do projeto raiz.  

**Observações**:
Palavras como artigos (o, a, um …), preposições (de, em, para, …) e pontuações (‘.’ , ‘ !’, ‘?’, ...) são nas contagens. 

### Forma de execução 
Para a execução do programa instale o [CMAKE](https://cmake.org/download/) em sua máquina.
 ```JavaScript
    cmake -B build
```
 ```JavaScript
  cmake --build build
```
- Primeira parte
 ```JavaScript
 ./build/main/main
```
- Segunda parte ( Trie )
 ```JavaScript
 ./build/main/mainTrie
```
- Segunda parte ( Huffman )
 ```JavaScript
 ./build/main/mainHuffman
```
