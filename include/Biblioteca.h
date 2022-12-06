#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <string>
#include <vector>
#include "Livro.h"
#include "no.h"
using namespace std;

class Biblioteca
{

public:
    Biblioteca();
    ~Biblioteca();
    void imprimirBiblioteca();
    vector <Livro*> getLivros();
private:
    vector <Livro*>   livros;
    ifstream arquivoLivros;
};

#endif // BIBLIOTECA_H_INCLUDED
