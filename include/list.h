#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "./no.h"
class ListaEncadeada
{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    bool busca(No registro);        // retorna true caso registro esteja na lista e false caso contrario
    bool vazia();
    void remove(No registro);
    void removeInicio();
    void removeFinal();
    void insereInicio(No registro); // insere um novo No contendo reg no início da lista
    No* getPrimeiro();              //retorna pornteiro para o primeiro no da lista

private:
    No *primeiro;
    No *ultimo;
    int n;         // numero de nos na lista

};

#endif // LIST_H_INCLUDED
