#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED
#include <algorithm>
#include <string.h>
#include <chrono>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include "./no.h"
#include "./hash.h"
#include <utility>
#include <bits/stdc++.h>
#include "./Trie.h"

using namespace std;

class Livro
{
public:
    Livro(string nomeLivro);
    Livro(string nomeLivro, bool flag);
    ~Livro();
    string getNomeLivro();
    void processarLivro(int indice);
    bool possuiPreposicaoArtigo(string palavra);
    void insereTabelaHash(vector <string> words);
    void insereTrie(vector <string> words);
    void imprimeDadosHash();
    void realizaComparacao();
    void ordenacaoQuicksort();
    void ordenacaoBubblesort();
    void ordenacaoCombsort();
    void percorreTabela();
    void criaArquivo50Palavras();
    bool isCarregado();
    void recolhePalavrasMaisUsadas(vector <No*> words);
    vector<string>  retiraPreposicaoArtigo(vector<string> words);
    string toLower(string s);
    vector <string> getWordsString();
    vector<No*>      getWords();
    void      setWords(vector<No*> words);
    void definePalavrasMaisUsadas();
    void removeItemsIguais();
    void gerarIndiceRemissivo(int indice);


private:
    string nomeLivro;
    ifstream         arquivoEntrada;
    Hash*           tabelaHash[2];
    Trie*           trie;
    vector<No*>      words;
    bool carregado;
};

#endif // LIVRO_H_INCLUDED
