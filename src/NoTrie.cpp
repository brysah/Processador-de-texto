#include "../include/NoTrie.h"
#include <bits/stdc++.h>

//
// Created by brysah on 18/07/22.
//
NoTrie :: NoTrie()
{
    end = 0;
    for (int i = 0; i < ALPHABET; ++i) {
        childNode[i] = nullptr;
    }
    isLeaf = false;
    frequencia = 1;
}
NoTrie :: ~NoTrie()
{
}
NoTrie* NoTrie :: getChildNode(int index)
{
    return childNode[index];
}
void NoTrie :: setChildNode(int index, NoTrie* node)
{
    childNode[index] = node;
}
int NoTrie :: getEnd()
{
    return end;
}
void NoTrie :: setEnd(int end)
{
    this->end = end;
}
bool NoTrie :: getIsLeaf()
{
    return isLeaf;
}
void NoTrie :: setIsLeaf(bool isLeaf)
{
    this->isLeaf = isLeaf;
}
vector <int> NoTrie :: getLinhas()
{
    auto cpy = unique(linhas.begin(), linhas.end());
    linhas.erase(cpy, linhas.end()); // retira linhas iguais
    return linhas;
}
void NoTrie :: setLinhas(vector <int> linhas)
{
    this->linhas = linhas;
}
void NoTrie :: adicionarLinha(int linha)
{
    linhas.push_back(linha);
}
int NoTrie :: getContagem()
{
    return frequencia;
}
void NoTrie :: setFrequencia(int frequencia)
{
    this->frequencia = frequencia;
}
void NoTrie :: adicionaFrequencia()
{
    frequencia++;
}
