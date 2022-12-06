//
// Created by brysah on 18/07/22.
//
#ifndef NOTRIE_H
#define NOTRIE_H
#define ALPHABET 26
#include <vector>
#include <string>
using namespace std;
class NoTrie {
private:
    NoTrie *childNode[ALPHABET];
    int end;
    bool isLeaf;
    vector <int> linhas;
    int frequencia;
public:
    NoTrie();
    ~NoTrie();
    NoTrie* getChildNode(int index);
    void setChildNode(int index, NoTrie* node);
    int getEnd();
    void setEnd(int end);
    bool getIsLeaf();
    void setIsLeaf(bool isLeaf);
    vector <int> getLinhas();
    void setLinhas(vector <int> linhas);
    void adicionarLinha(int linha);
    int getContagem();
    void setFrequencia(int frequencia);
    void adicionaFrequencia();

};

#endif //NOTRIE_H