#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <string>
using namespace std;

class No
{
private:
    int    chave;
    string palavra;
    int    contagem;
    No     *prox; // ponteiro para o proximo No
public:
    No               ()           {contagem = 1; };
    ~No              ()           { };
    int getChave     ()           { return chave; };
    int getContagem  ()           { return contagem;};
    string getPalavra()           { return palavra;};
    No* getProx      ()           { return prox; };
    void setChave    (int val)    { chave = val; };
    void setContagem (int val)    { contagem = val;};
    void setPalavra(string str)   { palavra = str;};
    void setProx   (No *p)        { prox = p; };
    void adicionaContagem()        { contagem++; };
};
#endif // NO_H_INCLUDED
