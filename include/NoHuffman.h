//
// Created by brysah on 13/08/22.
//

#ifndef ED2_NOHUFFMAN_H
#define ED2_NOHUFFMAN_H
#include <iostream>
#include <string>

using namespace std;

class NoHuffman{
private:
    char caracter;
    int frequencia;
    NoHuffman* esquerda;
    NoHuffman* direita;
    string codigo;
public:
    NoHuffman();
    ~NoHuffman();
    void setCaracter(char caracter);
    void setFrequencia(int frequencia);
    void setEsquerda(NoHuffman* esquerda);
    void setDireita(NoHuffman* direita);
    void setCodigo(string codigo);
    char getCaracter();
    int getFrequencia();
    NoHuffman* getEsquerda();
    NoHuffman* getDireita();
    string getCodigo();
};
#endif //ED2_NOHUFFMAN_H
