//
// Created by brysah on 10/08/22.
//
#include <iostream>
#include "./Livro.h"
#include "./Biblioteca.h"
#include "./Huffman.h"
using namespace std;

int main() {



    Biblioteca *b = new Biblioteca();
    vector < Livro * > l = b->getLivros();
    int opcao = -1;
    int livro;
    while (opcao != 0) {
        cout << "Selecione uma das opcoes: " << endl;
        cout << " [ 0 ] - Sair" << endl;
        cout << " [ 1 ] - Compressao e Descompressao Huffman" << endl;
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
                    cout << " -------- Compressao Huffman -------- " << endl;
                    Huffman huffman(l[livro]->getNomeLivro());
                    huffman.montaFila();
                    huffman.constroiHuffman();
                    huffman.calculaCodigoHuffman();
                    huffman.compressao();
                    cout << "Compressao concluida" << endl;
                    long tamanho;

                    ifstream og("input/"+l[livro]->getNomeLivro(), ios::binary);
                    og.seekg(0, ios::end);
                    int file_size = og.tellg()/1000;
                    og.close();
                    cout << "Tamanho do arquivo original: " << file_size << "KB"<< endl;

                    string n = l[livro]->getNomeLivro();
                    n.erase(n.end()-4, n.end());
                    ifstream cmp(n+"Compressao.bin", ios::binary);

                    if(!cmp.is_open())cout << "Erro" << endl;
                    cmp.seekg(0, ios::end);
                    int file_size2 = cmp.tellg()/1000;
                    cmp.close();
                    cout << "Tamanho do arquivo comprimido: " << file_size2 << "KB"<< endl;
                    file_size2 = file_size2 * 100;
                    float compressao = file_size2/file_size;
                    cout << "Taxa de compressao: " << 100 - compressao<< "%"<< endl;

                    cout << " -------- Descompressao Huffman -------- " << endl;
                    huffman.reconstroiArvore();
                    huffman.descompressao();
                    cout << "Descompressao concluida" << endl;
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
