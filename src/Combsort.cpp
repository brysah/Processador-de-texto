#include "../include/Biblioteca.h"
#include "../include/Combsort.h"
#include <vector>
#include <iterator>
#include <iostream>
Combsort::Combsort(vector<No*> arr )
{
    this->arr = arr;
    numComparacoes = 0;
    numMovimentacoes = 0;

}
void Combsort::aplicaCombsort()
{
    int descanso = arr.size() ;
    while (descanso != 1)
    {
        descanso = int (descanso*10)/13;
        if (descanso < 1) descanso = 1;
        for (int i=0; i < arr.size() - descanso; i++)
        {
            numComparacoes++;
            if (arr[i]->getContagem() <= arr[i+descanso]->getContagem())
                {
                    swap(arr[i], arr[i+descanso]);
                    numMovimentacoes++;
                }
        }
    }

}
void Combsort::imprimirOrdenacao()
{
    for (const auto &no : arr)
    {
        cout << no->getPalavra() << " - " << "[ " << no->getContagem() <<  "]" << endl;
    }
}
int Combsort::getNumComparacoes()
{
    return this->numComparacoes;
};
int Combsort::getNumMovimentacoes()
{
    return this->numMovimentacoes;
};
