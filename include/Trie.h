//
// Created by brysah on 18/07/22.
//

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include "./NoTrie.h"
using namespace std;

class Trie{
private:
    NoTrie* root;
    vector<pair<string,NoTrie*>> words;
public:
    Trie();
    void insert (string str, int linha);
    NoTrie* search(string str);
    NoTrie* _delete(NoTrie* root , string str, int level);
    void print(NoTrie* root,char [] , int level);
    NoTrie* getRoot();
    bool haveChildren(NoTrie* node);
    void insertVector(vector <string> str);
    void definePalavrasMaisUsadasAux(NoTrie* root, char str[], int level);
    void imprimeOrdenado();
    vector<NoTrie*> getWords();
    void ordenaFrequencia();
    void criaArquivo50Palavras(string nomeLivro);
    void ordenaAlfabeto();





};
#endif //TRIE_H