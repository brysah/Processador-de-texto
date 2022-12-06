//
// Created by brysah on 10/08/22.
//
#include <iostream>
#include "./Livro.h"
#include "./Biblioteca.h"
using namespace std;
int main() {
    cout << " -------- Indice Remissivo de Arquivos -------- " << endl;
    Biblioteca *b = new Biblioteca();
    vector < Livro * > l = b->getLivros();
    int opcao = -1;
    int livro;
    while (opcao != 0) {
        cout << "Selecione uma das opcoes: " << endl;
        cout << " [ 0 ] - Sair" << endl;
        cout << " [ 1 ] - Gerar Indice Remissivo " << endl;
        cin >> opcao;
        switch (opcao) {

            case 0:
                cout << "Saindo.." << endl;
                opcao = 0;
                break;
            case 1:
                cout << "Digite o numero do livro selecionado: " << endl;
                b->imprimirBiblioteca();
                cin >> livro;
                if (livro >= 0 && livro < l.size()) {
                    cout << "Gerando Indice Remissivo..." << endl;
                    l[livro]->gerarIndiceRemissivo(livro);
                } else {
                    cout << "Nenhum livro foi selecionado" << endl;
                }
                break;

            default:
                cout << "Opcao invalida" << endl;
                break;

        }


    }
}
