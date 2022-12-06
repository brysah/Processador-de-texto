#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <memory>
#include <string.h>
#include <iostream>
#include <utility>
#include "../include/Quicksort.h"
#include "../include/Bubblesort.h"
#include "../include/Combsort.h"
#include "../include/Livro.h"
#include "../include/Trie.h"

using namespace std;

Livro::Livro(string nomeLivro)
{
    this->nomeLivro = nomeLivro;
    this->tabelaHash[0] = new Hash(1117);
    this->tabelaHash[1] = new Hash(1117);
    this->carregado = false;
    this->trie      = new Trie();

}

Livro::~Livro()
{
    this->tabelaHash[0]->~Hash();
    this->tabelaHash[1]->~Hash();
}
string Livro::getNomeLivro()
{
    return this->nomeLivro;
}
vector<No*> Livro::getWords()
{
    return  this->words;
}
void Livro::recolhePalavrasMaisUsadas(vector<No*> p)
{
    for (const auto &no : p)
    {
        this->words.push_back(no);
    }
}

void Livro:: gerarIndiceRemissivo(int indice)
{
    cout << "\t Processando arquivo " << nomeLivro << "..." << endl;
    if (indice == 0)this->arquivoEntrada.open("./input/engeitado.txt", ios::in);
    else if (indice == 1)this->arquivoEntrada.open("./input/garatujas.txt", ios::in);
    else if (indice == 2)this->arquivoEntrada.open("./input/As_Cinzas_de_Camillo.txt", ios::in);
    else if (indice == 3)this->arquivoEntrada.open("./input/monologo_vaqueiro.txt", ios::in);
    else if (indice == 4)this->arquivoEntrada.open("./input/o_doido_e_a_morte.txt", ios::in);
    else if (indice == 5)this->arquivoEntrada.open("./input/soldados_da_revolucao.txt", ios::in);
    else if (indice == 6)this->arquivoEntrada.open("./input/K4.txt", ios::in);
    else if (indice == 7)this->arquivoEntrada.open("./input/tropheo.txt", ios::in);
    else if (indice == 8)this->arquivoEntrada.open("./input/cinco_minutos.txt", ios::in);
    else if (indice == 9)this->arquivoEntrada.open("./input/a_pata_no_choco.txt", ios::in);
    string palavras []= {"ante", "apos", "ate", "com", "contra", "desde",
                         "entre", "para", "perante","por","sem", "sob",
                         "sobre", "tras", "que", "das", "dos","como",
                         "uma", "umas", "uns","—", "a", "e","o",
                         "as","os","um","de","do","da","dos",
                         "das","em"
    } ;


    string line;
    vector<string> words{};
    int linha = 1;
    while(!arquivoEntrada.eof())
    {
        getline(arquivoEntrada,line);
        line.erase(remove_if(line.begin(), line.end(),::ispunct), line.end());
        line.erase(remove_if(line.begin(), line.end(),::isdigit), line.end());// removendo numeros
        istringstream iss(line);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(words));
        vector<string>aux = retiraPreposicaoArtigo(words);
        //cout << "\t\t Linha " << linha << ": " << words.size() << " palavras" << endl;
        for(auto w:aux)
        {
            //cout << w <<" , " << linha<< endl;
            this->trie->insert(toLower(w),linha);
        }
        linha++;
        words.clear();
    }
    cout << "\t\t " << nomeLivro << " processado com sucesso" << endl;
    //char str[200000];
   // this->trie->print(trie->getRoot(),str,0);
    char str2[65464];
    this->trie->definePalavrasMaisUsadasAux(trie->getRoot(),str2,0);
    this->trie->ordenaFrequencia();
    this->trie->ordenaAlfabeto();
    //this->trie->imprimeOrdenado();
    this->trie->criaArquivo50Palavras(this->nomeLivro);
    arquivoEntrada.close();
    this->carregado = true;
    cout << "Arquivo processado " << endl;
}


void Livro::removeItemsIguais()
{
    vector <No*> aux ;
    for(auto const &str: this->words)
    {
        No* novo = new No();
        novo->setPalavra(str->getPalavra());
        novo->setContagem(str->getContagem());
        aux.push_back(novo);
    }
    int cont = 0;
    for(No* &p: this->words)
    {
        for(No* &str: aux)
        {
            if(str->getPalavra() != "invalido")
            {
                auto strChar = str->getPalavra().c_str();
                auto strP = p->getPalavra().c_str();
                if(!strcmp(strP,strChar))
                {
                    if(p->getContagem() > str->getContagem())
                    {
                        str->setPalavra("invalido");
                        str->setContagem(-1);
                    }

                }

            }

        }
        cont = 0;

    }
    int i = 0;
    this->words.clear();

    for(auto const &str : aux)
    {
        if(str->getPalavra() != "invalido")
        {
            this->words.push_back(str);
        }

    }

}

void Livro::processarLivro(int indice)
{
    cout << "Processando arquivo " << nomeLivro << "..." ;
    if (indice == 0)this->arquivoEntrada.open("./input/engeitado.txt", ios::in);
    else if (indice == 1)this->arquivoEntrada.open("./input/garatujas.txt", ios::in);
        else if (indice == 2)this->arquivoEntrada.open("./input/As_Cinzas_de_Camillo.txt", ios::in);
            else if (indice == 3)this->arquivoEntrada.open("./input/monologo_vaqueiro.txt", ios::in);
                else if (indice == 4)this->arquivoEntrada.open("./input/o_doido_e_a_morte.txt", ios::in);
                    else if (indice == 5)this->arquivoEntrada.open("./input/soldados_da_revolucao.txt", ios::in);
                        else if (indice == 6)this->arquivoEntrada.open("./input/K4.txt", ios::in);
                            else if (indice == 7)this->arquivoEntrada.open("./input/tropheo.txt", ios::in);
                                else if (indice == 8)this->arquivoEntrada.open("./input/cinco_minutos.txt", ios::in);
                                     else if (indice == 9)this->arquivoEntrada.open("./input/a_pata_no_choco.txt", ios::in);
                                

    string line;
    vector<string> words{};
    string word;
    while(!arquivoEntrada.eof())
    {
        getline(arquivoEntrada,line);
        line.erase(remove_if(line.begin(), line.end(),::ispunct), line.end()); // removendo pontuação
        line.erase(remove_if(line.begin(), line.end(),::isdigit), line.end());// removendo numeros
        istringstream iss(line);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(words));

    }
    words = retiraPreposicaoArtigo(words);
    insereTabelaHash(words);
    percorreTabela();
    arquivoEntrada.close();
    this->carregado = true;
    cout << "Arquivo processado " << endl;
    //this->tabelaHash[0]->~Hash();
    //this->tabelaHash[1]->~Hash();
}

void Livro::realizaComparacao()
{

    cout << "\t Realizando comparacao.." << endl;
    ordenacaoBubblesort();
    ordenacaoCombsort();
    ordenacaoQuicksort();
    cout << endl;
}
    void      Livro::setWords(vector<No*> palavras)
    {
        this->words = palavras;
    }

void Livro::criaArquivo50Palavras()
{
    cout << "Criando arquivo com a 50 palavras mais frequentes do livro " << this->nomeLivro << endl;
    ofstream arquivoSaida;
    string nomeArquivo ="50palavras" + this->nomeLivro;
    arquivoSaida.open(nomeArquivo, ios::out);
    if(!arquivoSaida.is_open()) cout << "Erro ao criar arquivo " << endl;
    int i = 1;
    for (const auto &no : words)
    {
        arquivoSaida << i << " " << no->getPalavra() << " " << no->getContagem() << endl;
        i++;
    }
    arquivoSaida.close();
    cout << "Arquivo criado" << endl;
}

string Livro::toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); }
    );
    //cout << "String convertida para minusculo" << endl;
    return s;
}
vector <string> Livro::getWordsString()
{
    vector<string>str;
    for (const auto &no : words)
    {
        str.push_back(no->getPalavra());
    }
    return str;
}
void Livro::ordenacaoQuicksort()
{
    //QuickSort
    Quicksort *quick = new Quicksort(this->words);
    auto inicioQuick  = std::chrono::high_resolution_clock::now();
    quick->aplicaQuicksort(0, this->words.size() - 1);
    auto resultadoQuick = std::chrono::high_resolution_clock::now() - inicioQuick;
    long long secondsQuick  = std::chrono::duration_cast<std::chrono::seconds>(resultadoQuick).count();
    cout << "\t ------ Metodo Quicksort ------" << endl;
    cout << "\t Numero de Comparacoes: " << quick->getNumComparacoes() <<endl;
    cout << "\t Numero de Movimentacoes: " << quick->getNumMovimentacoes() <<endl;
    cout << "\t Tempo gasto em segundos: " << secondsQuick << endl;
    this->words.clear();
    int i= 1;
    for (const auto &no : quick->getVetorOrdenado())
    {
        if(i>50)break;
        this->words.push_back(no);
        i++;
    }

    //quick->imprimirOrdenacao();
}

void Livro::ordenacaoBubblesort()
{
    //Bubblesort
    Bubblesort *bubble = new Bubblesort(this->words);
    auto inicioBubble  = std::chrono::high_resolution_clock::now();
    bubble->aplicaBubblesort();
    auto resultadoBubble    = std::chrono::high_resolution_clock::now() - inicioBubble;
    long long secondsBubble = std::chrono::duration_cast<std::chrono::seconds>(resultadoBubble).count();
    cout << endl;
    cout << "\t ------ Metodo Bubblesort ------" << endl;
    cout << "\t Numero de Comparacoes: " << bubble->getNumComparacoes() <<endl;
    cout << "\t Numero de Movimentacoes: " << bubble->getNumMovimentacoes() <<endl;
    cout << "\t Tempo gasto em segundos: " << secondsBubble << endl;
    cout << endl;
}

void Livro::ordenacaoCombsort()
{
    //Combsort
    Combsort *comb = new Combsort(this->words);
    auto inicioComb  = std::chrono::high_resolution_clock::now();
    comb ->aplicaCombsort();
    auto resultadoComb    = std::chrono::high_resolution_clock::now() - inicioComb;
    long long secondsComb = std::chrono::duration_cast<std::chrono::seconds>(resultadoComb).count();

    cout << endl;
    cout << "\t ------ Metodo Combsort ------" << endl;
    cout << "\t Numero de Comparacoes: " << comb ->getNumComparacoes() <<endl;
    cout << "\t Numero de Movimentacoes: " << comb ->getNumMovimentacoes() <<endl;
    cout << "\t Tempo gasto em segundos: " << secondsComb << endl;
    cout << endl;
}

void Livro::percorreTabela()
{
    for (int i = 0 ; i < this->tabelaHash[0]->getM() ; i++)
    {
        for(No *p =  this->tabelaHash[0]->tabela[i]->getPrimeiro() ; p != NULL ; p = p->getProx())
        {
            //cout << p->getPalavra() << " - " << p->getContagem() << endl;
            this->words.push_back(p);
        }
    }


}

vector<string> Livro::retiraPreposicaoArtigo(vector<string> words)
{
    int cont = 0;
    vector<string> wordsSemPreposicao;
    for (const auto &str : words)
    {

        if(str.size() >= 3 && possuiPreposicaoArtigo(str) == false)
        {
            //words.erase(std::remove(words.begin(), words.end(), str), words.end());
            wordsSemPreposicao.push_back(str);
        }
        cont++;
    }
    return wordsSemPreposicao;

}

void Livro::insereTabelaHash(vector <string> words)
{
    for (const auto &str : words)
    {
        unique_ptr<No> n(new No());
        n->setPalavra(toLower(str));
        this->tabelaHash[0]->insereDivisao(*n);
    }

    for (const auto &str : words)
    {
        unique_ptr<No> n(new No());
        n->setPalavra(toLower(str));
        this->tabelaHash[1]->insereMultiplicacao(*n);
    }
}
/*/
void Livro::insereTrie(vector <string> words)
{
    for ( string str : words)
    {
        this->trie->insert(toLower(str));
    }

}
/*/
bool Livro::possuiPreposicaoArtigo(string palavra)
{
    string palavras []= {"ante", "apos", "ate", "com", "contra", "desde",
                         "entre", "para", "perante","por","sem", "sob",
                         "sobre", "tras", "que", "das", "dos","como",
                         "uma", "umas", "uns","—", "a", "e","o",
                         "as","os","um","de","do","da","dos","das","em"
                        } ;

    palavra = toLower(palavra);
    auto p = palavra.c_str();
    if(palavra.length() < 3) return true;
    for(int cont = 0 ; cont < 22 ; cont++)
    {
        auto palavraChar = palavras[cont].c_str();
        if(!strcmp(palavraChar,p))
        {
            return true;
        }
    }
    return false;
}

void Livro::imprimeDadosHash()
{
    //this->tabelaHash[0]->imprimeTabela();
    cout << "\t ----- Dados Tabela Hash ----- " << endl;
    cout << "\t Numero de palavras : "  << this->tabelaHash[0]->getTotalPalavrasUnicas() <<  endl;
    cout << "\t ----- Metodo da Divisao -----"  << endl;
    cout << "\t Numero de colisoes: " << this->tabelaHash[0]->getColisoesDivisao() << endl;
    cout << "\t ----- Metodo da Multiplicacao -----"  << endl;
    cout << "\t Numero de colisoes: " << this->tabelaHash[1]->getColisoesMultiplicacao() << endl;
}
bool Livro::isCarregado()
{
    return this->carregado;
}
