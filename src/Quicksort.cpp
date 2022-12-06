#include "../include/Quicksort.h"

using namespace std;

Quicksort::Quicksort(vector<No*> arr )
{
    numComparacoes = 0;
    numMovimentacoes = 0;
    this->arr = arr;
}
Quicksort::Quicksort(vector<NoTrie*> arrTrie )
{
    numComparacoes = 0;
    numMovimentacoes = 0;
    this->arrTrie = arrTrie;
}
Quicksort::~Quicksort()
{

}
vector<No*> Quicksort::getVetorOrdenado()
{
    return this->arr;
}
vector<NoTrie*> Quicksort::getVetorOrdenadoTrie()
{
    return this->arrTrie;
}
void Quicksort:: aplicaQuicksort(int comeco, int fim)
{
    if (comeco < fim)
    {
        int pi = particao(comeco, fim);
        aplicaQuicksort( comeco, pi - 1);
        aplicaQuicksort(pi + 1, fim);
    }
}
int Quicksort:: particao(int comeco, int fim)
{
    int pivo = arr[fim]->getContagem();
    int i = (comeco - 1);

    for (int j = comeco; j < fim; j++)
    {
        numComparacoes++;
        if (arr[j]->getContagem() > pivo)
        {
            i++;
            numMovimentacoes++;
            swap(arr[i],arr[j]);
        }
    }

    numMovimentacoes++;
    swap(arr[i + 1],arr[fim]);

    return (i + 1);
}
void Quicksort:: imprimirOrdenacao()
{
    int i = 1;
    for (const auto &no : arr)
    {
        if( i <= 50)
        {
            cout << i << ": " << no->getPalavra() << " - " << "[ " << no->getContagem() <<  "]" << endl;
        }
        i++;
    }
}
int Quicksort:: getNumComparacoes()
{
    return this->numComparacoes;
}
int Quicksort:: getNumMovimentacoes()
{
    return this->numMovimentacoes;
}