#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "./list.h"
class Hash {

public:
     Hash(int M);// M é o tamanho da tabela hash
     Hash();
    ~Hash();

     int chaveAlfanumerica(char *palavra); // transforma string em valores numéricos para utiliza-la como chave
     void  insereDivisao(No registro);
     void insereMultiplicacao(No registro);

     No* busca(No registro); //retorna ponteiro para o registro procurado
     void remove(No registro);
     void imprimeInfo();//Imprime o número de colisões ocorridas nas inserções de dados na tabela ao usar uma determinada função hash.
     void imprimeTabela();

     int hashDivisao(int chave); //função hash com o metodo da divisao
     int hashMultiplicacao(int chave); //função hash com o metodo da multiplicacao
     void contaPalavras();

     int getColisoesDivisao();
     int getColisoesMultiplicacao();
     int getTotalPalavrasUnicas();
     int getM();
      ListaEncadeada **tabela;

private:

    int M;
    int totalPalavrasUnicas;
    int colisoesDivisao;
    int colisoesMultiplicacao;


};

#endif // HASH_H_INCLUDED
