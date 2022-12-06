#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

class Bubblesort{
   public:
    Bubblesort(vector<No*> arr );
    void aplicaBubblesort();
    void imprimirOrdenacao();
    int getNumComparacoes();
    int getNumMovimentacoes();

    ~Bubblesort();
    private:
    int numComparacoes;
    int numMovimentacoes;
    vector<No*> arr ;
};

#endif // BUBBLESORT_H_INCLUDED
