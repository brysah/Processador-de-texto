#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include "./no.h"
#include <iostream>
#include "./Biblioteca.h"
#include <vector>
#include <iterator>
class Quicksort {
public:
    Quicksort(vector<No*> arr );
    Quicksort(vector<NoTrie*> arrTrie );
    void aplicaQuicksort( int comeco , int fim);
    int particao(int comeco , int fim);
    void imprimirOrdenacao();
    int getNumComparacoes();
    int getNumMovimentacoes();
    vector<No*> getVetorOrdenado();
    vector<NoTrie*> getVetorOrdenadoTrie();


    ~Quicksort();
private:
    int numComparacoes;
    int numMovimentacoes;
    vector<No*> arr ;
    vector<NoTrie*> arrTrie;
};

#endif // QUICKSORT_H_INCLUDED