#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    string marca;
    string categoria;
    float preco;
    int quantidade;
};

#endif
