#include "../include/Livro.h"
#include "../include/Biblioteca.h"
#include "../include/Bubblesort.h"
#include <vector>
#include <iterator>
#include <iostream>
Bubblesort::Bubblesort(vector<No*> arr )
{
    this->arr = arr;
    numComparacoes = 0;
    numMovimentacoes = 0;

}
void Bubblesort::aplicaBubblesort()
{
    int i, j;
    for (i = 0; i < arr.size() - 1; i++)
    {
         for (j = 0; j < arr.size() - i - 1; j++)
         {
                numComparacoes++;
            if (arr[j]->getContagem() <= arr[j + 1]->getContagem())
            {
                numMovimentacoes++;
               swap(arr[j], arr[j + 1]);
            }
         }

    }

}
void Bubblesort::imprimirOrdenacao()
{
    for (const auto &no : arr)
    {
       cout << no->getPalavra() << " - " << "[ " << no->getContagem() <<  "]" << endl;
    }
}
int Bubblesort::getNumComparacoes(){ return this->numComparacoes;};
int Bubblesort::getNumMovimentacoes(){ return this->numMovimentacoes;};
