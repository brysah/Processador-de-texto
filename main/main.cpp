#include <iostream>
#include "./Biblioteca.h"
#include "./Livro.h"
#include "./no.h"
#include "./hash.h"
#include "./list.h"
#include "./Combsort.h"
#include "./Quicksort.h"
#include "./Bubblesort.h"


using namespace std;

int main()
{
    cout << " -------- Processamento de Arquivos -------- " << endl;
    Biblioteca *b = new Biblioteca();
    vector <Livro*> l = b->getLivros();
    int opcao = -1;
    int livro;
    while(opcao != 0)
    {
        cout << "Selecione uma das opcoes: " << endl;
        cout << " [ 0 ] - Sair" << endl;
        cout << " [ 1 ] - Funcoes Hash (Caso 2) " << endl;
        cout << " [ 2 ] - Analisar o desempenho dos métodos de ordenacao (Caso 3) " << endl;
        cout << " [ 3 ] - Identificar as 50 palavras mais usadas (Caso 4) " << endl;
        cin >> opcao;
        switch(opcao)
        {

        case 0:
            cout << "Saindo.." << endl;
            opcao = 0;
            break;
        case 1:
            cout << "Digite o numero do livro selecionado: " << endl;
            b->imprimirBiblioteca();
            cin >> livro;
            if(livro >= 0 && livro < l.size())
            {
                if(l[livro]->isCarregado() == false) l[livro]->processarLivro(livro);
                l[livro]->imprimeDadosHash();
            }
            else
            {
                cout << "Nenhum livro foi selecionado" <<endl;
            }
            break;

        case 2:
            cout << "Digite o numero do livro selecionado: " << endl;
            b->imprimirBiblioteca();
            cin >> livro;
            if(livro >= 0 && livro < l.size())
            {
                if(l[livro]->isCarregado() == false) l[livro]->processarLivro(livro);
                l[livro]->realizaComparacao();
            }
            else
            {
                cout << "Nenhum livro foi selecionado" <<endl;
            }
            break;

        case 3:
            cout << "Digite dez numeros de livros a serem processados: " << endl;
            b->imprimirBiblioteca();
            vector<No*> conjuntoDezLivros;
            int indiceLivros[10];
            int i = 0 ;

            while( i < 10)
            {

                cout << "Livro " << i + 1 << " : " ;
                cin >> livro;
                cout << endl;
                if(livro >= 0 && livro < l.size())
                {
                    indiceLivros[i] = livro;
                    i++;
                }
                else cout << "Nenhum livro foi selecionado" <<endl;
            }

            i = 0;
            Livro *geral = new Livro("geral.txt");
            while(i < 10)
            {
                if(l[indiceLivros[i]]->isCarregado() == false) l[indiceLivros[i]]->processarLivro(indiceLivros[i]);
                l[indiceLivros[i]]->ordenacaoQuicksort();
                l[indiceLivros[i]]->criaArquivo50Palavras();
                geral->recolhePalavrasMaisUsadas(l[indiceLivros[i]]->getWords());
                i++;
            }
            //
            geral->removeItemsIguais();
            geral->ordenacaoQuicksort();
            geral->criaArquivo50Palavras();
            break;


        }


    }






    return 0;
}
