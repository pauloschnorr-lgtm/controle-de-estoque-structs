#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"



struct Estoque {
    Produto produtos[100];
    int quantidade;
};

bool cadastrar(Estoque &e, Produto p);
int buscar(Estoque e, int codigo);
int buscarRecursivo(Estoque e, int codigo, int posicao);

#endif
