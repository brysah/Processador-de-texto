//
// Created by brysah on 13/08/22.
//
#include "../include/NoHuffman.h"
NoHuffman::NoHuffman() {
    //this->caracter = '';
    this->frequencia = 0;
    this->esquerda = NULL;
    this->direita = NULL;
    this->codigo = "";
}
NoHuffman::~NoHuffman() {
    delete this->esquerda;
    delete this->direita;
}
void NoHuffman::setCaracter(char caracter) {
    this->caracter = caracter;
}
void NoHuffman::setFrequencia(int frequencia) {
    this->frequencia = frequencia;
}
void NoHuffman::setEsquerda(NoHuffman* esquerda) {
    this->esquerda = esquerda;
}
void NoHuffman::setDireita(NoHuffman* direita) {
    this->direita = direita;
}
void NoHuffman::setCodigo(string codigo) {
    this->codigo = codigo;
}
char NoHuffman::getCaracter() {
    return this->caracter;
}
int NoHuffman::getFrequencia() {
    return this->frequencia;
}
NoHuffman* NoHuffman::getEsquerda() {
    return this->esquerda;
}
NoHuffman* NoHuffman::getDireita() {
    return this->direita;
}
string NoHuffman::getCodigo() {
    return this->codigo;
}
