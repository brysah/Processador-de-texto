#include <string.h>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

#include "../include/Biblioteca.h"

using namespace std;

Biblioteca::Biblioteca()
{
    cout << "Carregando biblioteca..." << endl;
    this->arquivoLivros.open("./input/nome_livros.txt", ios::in);
    string line;
    while(!arquivoLivros.eof())
    {
        getline(arquivoLivros,line);
        Livro *l = new Livro(line);
        this->livros.push_back(l);
    }
    arquivoLivros.close();
}

Biblioteca::~Biblioteca()
{

}
vector <Livro*> Biblioteca::getLivros()
{
    return this->livros;
}
void Biblioteca::imprimirBiblioteca()
{
    int i = 0;

    for (Livro* &str : livros)
    {
        if(i>9)break;
        cout <<"\t " <<  "[ " << i << "] - "<<str->getNomeLivro() << endl;
        i++;
    }
}

