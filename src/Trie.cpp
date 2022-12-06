//
// Created by brysah on 18/07/22.
//
#include "../include/Trie.h"
#include "./NoTrie.h"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
Trie::Trie()
{
    this->root = new NoTrie();
}
void Trie::insert(string str, int linha) {
    NoTrie* temp = search(str);
    if( temp != NULL)
    {
        temp->adicionaFrequencia();
        temp->adicionarLinha(linha);

    }else{
        //inicializando currentNode(ponteiroAtual) com a raiz da Trie
        NoTrie *currentNode = this->root;
        //Guarda o tamanho da string a ser inserida
        int length = str.size();


        for (int i = 0; i < length; i++)
        {
            int l = (int) str[i] - (int) 'a';
            if(currentNode->getChildNode(l) == NULL)
            {
                currentNode->setChildNode(l, new NoTrie());

            }
            //Move o no do ponteiro atual para o no que foi recentemente criado
            currentNode = currentNode->getChildNode(l);
        }
        currentNode->setEnd(currentNode->getEnd() + 1);
        currentNode->setIsLeaf(true);
        currentNode->adicionarLinha(linha);
       //currentNode->setPalavra(str);
    }

}
/*/
void Trie::insertVector(vector <string> str) {
    for (int i = 0; i < str.size(); i++)
    {
        cout << "ok1" << endl;
        this->insert(str[i]);
    }
}
/*/
NoTrie* Trie::search(string str)
{
    //inicializando currentNode(ponteiroAtual) com a raiz da Trie
    NoTrie *currentNode = root;
    //Guarda o tamanho da string a ser buscada
    int length = str.size();
    for (int i = 0; i < length; i++)
    {
        int l = (int) str[i] - (int) 'a';

        if(currentNode->getChildNode(l) == NULL)
        {
            //Se nulo a string nao esta contida na Trie
            return NULL;
        }

        currentNode = currentNode->getChildNode(l);
    }
    if(currentNode != NULL && currentNode->getEnd() > 0)
    {
        return currentNode;
    }
    return NULL;

}
NoTrie* Trie::_delete(NoTrie* root , string str, int level = 0)
{
    if (!root)
        return NULL;
    if (level == str.size()) {

        if (root->getIsLeaf())
            root->setIsLeaf(false);

        if (!haveChildren(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }


    int index = str[level] - 'a';
    //root->childNode[index] =
      //      _delete(root->childNode[index], str, level + 1);
    //root->getChildNode(index) = _delete(root->getChildNode(index), str, level + 1);

    if (!haveChildren(root) && root->getIsLeaf() == false) {
        delete (root);
        root = NULL;
    }

    return root;
}
bool Trie::haveChildren(NoTrie* node)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (node->getChildNode(i) != NULL)
            return true;    // filho encontrado

    }

    return false;
}
void Trie::print(NoTrie* root, char str[], int level)
{
    if (root->getIsLeaf() == true)
    {
        str[level] = '\0';
        cout << "\t" << str << " - " << "[ " << root->getContagem() << " ] ";
        cout << " : ";
        for(auto l: root->getLinhas())
        {
            cout << l << " ";
        }
        cout << endl;
    }

    int i;
    for (i = 0; i < ALPHABET; i++)
    {
        if (root->getChildNode(i))
        {
            str[level] = i + (int)'a';
            print(root->getChildNode(i), str, level + 1);
        }
    }

}
NoTrie* Trie::getRoot()
{
    return this->root;
}
/*/
void Trie::setRoot(NoTrie* root)
{
    this->root = root;
}/*/
void Trie::definePalavrasMaisUsadasAux(NoTrie* root, char str[], int level)
{
    if (root->getIsLeaf() == true)
    {
        str[level] = '\0';
        this->words.push_back(make_pair(str, root));
    }

    int i;
    for (i = 0; i < ALPHABET; i++)
    {
        if (root->getChildNode(i))
        {
            str[level] = i + (int)'a';
            definePalavrasMaisUsadasAux(root->getChildNode(i), str, level + 1);
        }
    }
}

void Trie::imprimeOrdenado() {
    for(auto w: this->words)
    {
        cout << w.first << " - " << w.second->getContagem() << endl;
    }
}
/*/
vector<NoTrie*> Trie::getWords()
{
    return this->words;
}
 /*/
void Trie::ordenaFrequencia()
{
    sort(this->words.begin(), this->words.end(), [](const auto &a, const auto &b) {
        return a.second->getContagem() > b.second->getContagem();
    });
     this->words.erase(this->words.begin() + 50, this->words.end());

}
void Trie::ordenaAlfabeto()
{
    sort(this->words.begin(), this->words.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

}

void Trie::criaArquivo50Palavras(string nomeLivro)
{
    ofstream arquivo;
    arquivo.open( "IndiceRemissivo_"+ nomeLivro, ios::out);
    int i = 1;
    for(auto w: this->words)
    {
        if(i > 50) break;
        arquivo << " [ " << i << " ] | " << w.first << " - " << " [ " << w.second->getContagem() << " ] : " ;

        for(auto l: w.second->getLinhas())
        {
            arquivo << l << " ";
        }

        arquivo << endl;
        i++;
    }
    arquivo.close();
}

