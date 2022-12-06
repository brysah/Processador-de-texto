//
// Created by brysah on 13/08/22.
//
#include "../include/Huffman.h"
#include <cmath>

Huffman::Huffman(string nomeArquivoEntrada) {
    this->nomeArquivoEntrada = nomeArquivoEntrada;
    for (int i = 0; i < 128; i++)
    {
        vetorHuffman[i] = new NoHuffman();
        vetorHuffman[i]->setCaracter(i);
    }
}
Huffman::~Huffman() {

}
void Huffman::percorreHuffman(NoHuffman* no, string codigo) {
    if (no->getEsquerda() == NULL && no->getDireita() == NULL)
    {
        no->setCodigo(codigo);
    }else {
            percorreHuffman(no->getEsquerda(), codigo + '0');
            percorreHuffman(no->getDireita(), codigo + '1');

    }

}
int Huffman::converterBinario(string binario) {

    int decimal = 0;
    for (int i = 0; i < binario.size(); i++)
        decimal = decimal * 2 + binario[i] - '0';
    return decimal;

}
string Huffman::converterDecimal(int decimal) {
    string aux = "";
    string binario = "";
    while (decimal)
    {
        aux += ('0' + decimal % 2);
        decimal /= 2;
    }
    binario.append(8 - aux.size(), '0');
    for (int i = aux.size() - 1; i >= 0; i--)
    {
        binario += aux[i];
    }
    return binario;
}
void Huffman::constroiHuffman() {
    priority_queue<NoHuffman*, vector<NoHuffman*>, compara> auxiliar(this->fila);
    while(auxiliar.size() > 1)
    {
        this->raiz = new NoHuffman();
        this->raiz->setEsquerda(auxiliar.top());
        this->raiz->setFrequencia(auxiliar.top()->getFrequencia() + this->raiz->getFrequencia());
        auxiliar.pop();
        this->raiz->setDireita(auxiliar.top());
        this->raiz->setFrequencia(auxiliar.top()->getFrequencia() + this->raiz->getFrequencia());
        auxiliar.pop();
        auxiliar.push(this->raiz);
    }

}
void Huffman::calculaCodigoHuffman() {
    percorreHuffman(this->raiz, "");
}

void Huffman::montaFila(){
    ifstream arquivoEntrada(this->diretorio+this->nomeArquivoEntrada, ios::in);
    if (!arquivoEntrada.is_open())
    {
        cout << "Erro ao abrir o arquivo de entrada(Fila)" << endl;
        exit(1);
    }
     arquivoEntrada.get(this->caracter);
    int i = 0;
    while (!arquivoEntrada.eof())
    {
        vetorHuffman[this->caracter]->setFrequencia(vetorHuffman[this->caracter]->getFrequencia() + 1);
        arquivoEntrada.get(this->caracter);
        i++;
    }
    arquivoEntrada.close();
    for (int i = 0; i < 128; i++)
    {
        if (vetorHuffman[i]->getFrequencia() > 0)
        {
            this->fila.push(vetorHuffman[i]);
        }
    }
}
void Huffman::imprimeFila(){
    priority_queue<NoHuffman*, vector<NoHuffman*>, compara> auxiliar(this->fila);
    while(!auxiliar.empty()){
        cout << auxiliar.top()->getCaracter() << " " << auxiliar.top()->getFrequencia() << endl;
        auxiliar.pop();
    }
}

void Huffman::montaArvore(string& str, char _codigo)
{
    NoHuffman* atual = this->raiz;
    for(int i = 0; i < str.size() ; i++)
    {
        if(str[i] == '0')
        {
            if(atual->getEsquerda() == NULL)
            {
                atual->setEsquerda(new NoHuffman());
            }
            atual = atual->getEsquerda();
        }
        else //str[i] == '1'
        {
            if(str[i] == '1')
            {
                if(atual->getDireita() == NULL)
                {
                    atual->setDireita(new NoHuffman());
                }
                atual = atual->getDireita();
            }
        }

    }
    atual->setCaracter(_codigo);
}
void Huffman::compressao()
{
    ifstream arquivoEntrada(this->diretorio+this->nomeArquivoEntrada, ios::in);
   // ofstream arquivoSaida("Compressao"+ this->nomeArquivoEntrada, ios::out);
   ofstream arquivoSaida;

    string n = this->nomeArquivoEntrada;
    n.erase(n.end() - 4, n.end());
   arquivoSaida.open(n+ "Compressao.bin", ios::out | ios::binary);
    if (!arquivoEntrada.is_open())
    {
        cout << "Erro ao abrir o arquivo de entrada (Compressao)" << endl;
        exit(1);
    }
    if (!arquivoSaida.is_open())
    {
        cout << "Erro ao abrir o arquivo de saida (Compressao)" << endl;
        exit(1);
    }
    string entrada = "" ;
    string str = "" ;

    entrada +=(char) this->fila.size();
    priority_queue<NoHuffman*, vector<NoHuffman*>, compara> auxiliar(this->fila);
    while(!auxiliar.empty()){
        NoHuffman* atual = auxiliar.top();
        entrada += atual->getCaracter();
        str.assign( 127 - atual->getCodigo().size(), '0');
        str += '1';
        str.append(atual->getCodigo());
        entrada += (char) converterBinario(str.substr(0, 8));
        for(int i = 0; i < 15; i++)
        {
            str = str.substr(8);
            entrada += (char) converterBinario(str.substr(0, 8));
        }
        auxiliar.pop();
    }
    str.clear();

    arquivoEntrada.get(this->caracter);
    while(!arquivoEntrada.eof())
    {
        str += this->vetorHuffman[this->caracter]->getCodigo();
        while(str.size() > 8)
        {
            entrada += (char) converterBinario(str.substr(0, 8));
            str = str.substr(8);
        }
        arquivoEntrada.get(this->caracter);
    }
    int cont = 8 - str.size();
    if(str.size() < 8)
    {
        str.append(cont, '0');
    }
   entrada += (char) converterBinario(str);
   entrada += (char) cont;
   arquivoSaida.write(entrada.c_str(), entrada.size());
   arquivoEntrada.close();
   arquivoSaida.close();

}
void Huffman::reconstroiArvore(){
    cout << "\t Reconstruindo.." << endl;
    string n = this->nomeArquivoEntrada;
    n.erase(n.end() - 4, n.end());
    ifstream arquivoEntrada(n + "Compressao.bin", ios::in | ios::binary);
    if (!arquivoEntrada.is_open())
    {
        cout << "Erro ao abrir o arquivo de entrada (reconstruçao)" << endl;
        exit(1);
    }
    unsigned char tamanho;
    arquivoEntrada.read((char*)&tamanho, sizeof(tamanho));// deu nao
    //arquivoEntrada.read(reinterpret_cast<char*>(&tamanho), 1);
    this->raiz = new NoHuffman();
    for(int i = 0 ; i < tamanho ; i++)
    {
        char _codigo;
        unsigned char _cdHuffman[16];
        arquivoEntrada.read((&_codigo), 1);
        arquivoEntrada.read(reinterpret_cast<char*>(&_cdHuffman), 16);

        string str = "";
        for(int j = 0; j < 16; j++)
        {
            str += converterDecimal(_cdHuffman[j]);
        }
        int l = 0;
        while(str[l] == '0')
        {
            l++;
        }
        str = str.substr(l + 1);
        this->montaArvore(str, _codigo);
    }
    arquivoEntrada.close();
}

void Huffman::descompressao()
{
    //ifstream arquivoEntrada("Compressao" + this->nomeArquivoEntrada, ios::in | ios::binary);
    string n = this->nomeArquivoEntrada;
    n.erase(n.end() - 4, n.end());
    ifstream arquivoEntrada(n+"Compressao.bin", ios::in | ios::binary);
    ofstream arquivoSaida("Descompressao" + this->nomeArquivoEntrada, ios::out);
    if (!arquivoEntrada.is_open())
    {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        exit(1);
    }
    if (!arquivoSaida.is_open())
    {
        cout << "Erro ao abrir o arquivo de saida" << endl;
        exit(1);
    }
    unsigned char tamanho;
    arquivoEntrada.read(reinterpret_cast<char*>(&tamanho), 1);
    arquivoEntrada.seekg(-1, ios::end);
    char cont;
    arquivoEntrada.read(&cont, 1);
    arquivoEntrada.seekg(1 + 17 * tamanho, ios::beg);

    vector<unsigned char> texto;
    unsigned char _c;
    arquivoEntrada.read(reinterpret_cast<char*>(&_c), 1);
    while (!arquivoEntrada.eof())
    {
        texto.push_back(_c);
        arquivoEntrada.read(reinterpret_cast<char*>(&_c), 1);
    }
    NoHuffman* atual = raiz;
    string str;
    for (int i = 0; i < texto.size() - 1; i++)
    {
        str = converterDecimal(texto[i]);
        if (i == texto.size() - 2)
            str = str.substr(0, 8 - cont);
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '0')
                atual = atual->getEsquerda();
            else
                atual = atual->getDireita();
            if (atual->getEsquerda() == NULL && atual->getDireita() == NULL)
            {
                arquivoSaida.put(atual->getCaracter());
                atual = raiz;
            }
        }
    }
    arquivoEntrada.close();
    arquivoSaida.close();
}
