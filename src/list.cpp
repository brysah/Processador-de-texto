#include <iostream>
#include <cstdlib>
#include "../include/list.h"


using namespace std;

ListaEncadeada::ListaEncadeada()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncadeada::busca(No val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getPalavra() == val.getPalavra())
            return true;
    return false;
}


void ListaEncadeada::insereInicio(No registro)
{
    No* p = new No();

    p->setChave(registro.getChave());
    p->setPalavra(registro.getPalavra());
    p->setProx(primeiro);

    primeiro = p;
    n++;

    if(n == 1) ultimo = p; //Lista com apenas um no
}

bool ListaEncadeada::vazia()
{
    return primeiro == NULL;
}

void ListaEncadeada::remove(No registro)
{
    if(vazia())
    {
        cout << endl << "Nao ha registros para remocao" << endl;
    }
    else if(n == 1 || primeiro->getPalavra() == registro.getPalavra())
    {
        removeInicio();
        return;
    }
    else
    {
        No *anterior = primeiro;
        No *p = anterior->getProx();
        while(p != NULL)
        {
            if(p->getPalavra()  == registro.getPalavra() )
            {
                break;
            }
            else
            {
                anterior = p;
                p = p->getProx();
            }
        }
        if(p != NULL)
        {
            if (ultimo == p)
            {
                ultimo = anterior;
            }
            anterior = anterior->getProx() ;
            anterior = p->getProx();
            delete p;
            n--;
        }
    }
}

void ListaEncadeada::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "Nao ha registros para remocao" << endl;
}

void ListaEncadeada::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "Nao ha registros para remocao" << endl;
}

No* ListaEncadeada::getPrimeiro()
{
    return primeiro;
}
