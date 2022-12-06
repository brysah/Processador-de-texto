#ifndef COMBSORT_H_INCLUDED
#define COMBSORT_H_INCLUDED
#include "./no.h"
#include <iostream>
#include "./Biblioteca.h"
#include <vector>
#include <iterator>
class Combsort{
    public:
    Combsort(vector<No*> arr );
    void aplicaCombsort();
    void imprimirOrdenacao();
    int getNumComparacoes();
    int getNumMovimentacoes();

    ~Combsort();
    private:
    int numComparacoes;
    int numMovimentacoes;
    vector<No*> arr ;
};

#endif // COMBSORT_H_INCLUDED
