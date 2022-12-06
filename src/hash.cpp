#include "../include/hash.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

Hash::Hash(int M)
{
    this->M = M;
    this->totalPalavrasUnicas = 0;
    this->colisoesDivisao = 0;
    this->colisoesMultiplicacao = 0;
    tabela = new ListaEncadeada* [M];
    for(int  i = 0 ; i  < M ; i++)
    {
        tabela[i] = new ListaEncadeada();
    }
}
Hash::Hash()
{
    this->M = 1031; // tabela hash com tamanho default
    this->totalPalavrasUnicas = 0;
    this->colisoesDivisao = 0;
    this->colisoesMultiplicacao = 0;
    tabela = new ListaEncadeada* [M];
    for(int  i = 0 ; i  < M ; i++)
    {
        tabela[i] = new ListaEncadeada();
    }
}


Hash::~Hash()
{
    for(int i=0; i < M; i++)
    {
        delete this->tabela[i]; // deletando lista encadeada
    }
    delete [] this->tabela; // deletando vetor hash
}

int Hash::chaveAlfanumerica(char *palavra)
{
    int soma = 7;
    int convertido = 0;
    for( int i =  1 ; i < strlen(palavra) ; i++ )
    {
        convertido = (int) palavra[i];
        soma = 31 * soma + (convertido << (i-1) % 8);
    }
    return (soma & 0x7FFFFFFF) ;//operacao bit a bit para evitar overflow

}


int Hash::hashDivisao(int chave)
{
    return (chave & 0x7FFFFFFF ) % this->M; //operacao bit a bit para evitar overflow
}


int Hash::hashMultiplicacao(int chave)
{
    double A =  (sqrt(5) - 1) / 2;
    double mult = (chave * A);
    mult = mult - (int) mult;
    return (int)(mult * M);
}




void Hash::insereDivisao(No registro)
{
    char* vetChar;
    string aux =  registro.getPalavra();
    vetChar = &aux[0];
    int chave = chaveAlfanumerica(vetChar);
    int indexTabela = hashDivisao(chave);
    registro.setChave(indexTabela);
    No *auxNo = busca(registro);
    if( auxNo != NULL)
    {
        auxNo->adicionaContagem();
    }
    else
    {
        //cout << "Palavra:" << registro.getPalavra() << " inserida na tabela" << endl;
        if(tabela[indexTabela]->getPrimeiro() != NULL)
        {
            this->colisoesDivisao++;
        }
        tabela[indexTabela]->insereInicio(registro);
        this->totalPalavrasUnicas++;
    }

}


void Hash::insereMultiplicacao(No registro)
{
    char* vetChar;
    string aux =  registro.getPalavra();
    vetChar = &aux[0];
    int chave = chaveAlfanumerica(vetChar);
    int indexTabela = hashMultiplicacao(chave);
    registro.setChave(indexTabela);
    No *auxNo = busca(registro);
    if(auxNo != NULL)
    {
        auxNo->adicionaContagem();
    }
    else
    {
        if(tabela[indexTabela]->getPrimeiro() != NULL)
        {
            this->colisoesMultiplicacao++;
        }
        tabela[indexTabela]->insereInicio(registro);
        this->totalPalavrasUnicas++;
    }
}


No* Hash::busca(No registro)
{
    for(int i = 0 ; i < this->M ; i++)
    {
        for(No *p = tabela[i]->getPrimeiro() ; p != NULL ; p = p->getProx())
        {
            if(!strcmp(p->getPalavra().c_str(),registro.getPalavra().c_str()))
            {
                 return p;
            }
        }
    }
    return NULL;
}
void Hash::remove(No registro)
{
    for(int i = 0 ; i < this->M ; i++)
    {
        for(No *p = tabela[i]->getPrimeiro() ; p != NULL ; p = p->getProx())
        {
            if(p->getChave() == registro.getChave() && p->getPalavra() == registro.getPalavra())
            {
                tabela[i]->remove(registro);
                totalPalavrasUnicas--;
            }
        }
    }

}
void Hash::imprimeInfo()
{
    cout << "Total de palavras: " << totalPalavrasUnicas << endl;
    cout << "Total de colisões(divisao): " << colisoesDivisao << endl;
    cout << "Total de colisões(multiplicacao): " << colisoesMultiplicacao << endl;

}

void Hash::imprimeTabela()
{
    for (int i = 0 ; i < M ; i++)
    {
        cout << endl ;
        for(No *p = tabela[i]->getPrimeiro() ; p != NULL ; p = p->getProx())
        {
            cout << p->getPalavra() << "[ " <<p->getContagem() << " ] "<< " --> " ;
        }
        cout << endl;
    }


}


int  Hash::getColisoesDivisao()
{
    return this->colisoesDivisao;
}
int  Hash::getColisoesMultiplicacao()
{
    return this->colisoesMultiplicacao;
}
int  Hash::getTotalPalavrasUnicas()
{
    return this->totalPalavrasUnicas;
}
int  Hash::getM()
{
    return this->M;
}

