//
// Created by brysah on 20/07/22.
//
#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include "./NoHuffman.h"

using namespace std;

class Huffman{

public:
    Huffman(string nomeArquivoEntrada);
    ~Huffman();
    void percorreHuffman(NoHuffman* no, string codigo); // percorre a arvore e gera o codigo de cada caracter
    int converterBinario(string binario);  // converte o codigo binario para decimal
    string converterDecimal(int decimal);  // converte o codigo decimal para binario
    void constroiHuffman();  // constroi a arvore de huffman
    void montaFila();//monta a fila de prioridades
    void calculaCodigoHuffman(); // calcula o codigo de cada caracter
    void imprimeFila();
    void montaArvore(string& str, char _codigo);
    void compressao();
    void descompressao();
    void reconstroiArvore();
    class compara{
    public:
        bool operator()(NoHuffman* a, NoHuffman* b){
            return a->getFrequencia() > b->getFrequencia();
        }
    };



private:

    NoHuffman* raiz;
    NoHuffman* filho;
    NoHuffman* pai;
    NoHuffman* vetorHuffman[128]; // vetor de nos de huffman
    char caracter;
    string nomeArquivoEntrada;
    string diretorio = "input/";
    priority_queue<NoHuffman*, vector<NoHuffman*>, compara> fila;



};
#endif //HUFFMAN_H
