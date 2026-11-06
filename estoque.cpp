#include "estoque.h"

bool cadastrar(Estoque &e, Produto p) {
    if (e.quantidade >= 100) {
        return false;
    }

    if (buscar(e, p.codigo) != -1) {
        return false;
    }

    e.produtos[e.quantidade] = p;
    e.quantidade++;

    return true;
}

int buscar(Estoque e, int codigo) {
    return buscarRecursivo(e, codigo, 0);
}

int buscarRecursivo(Estoque e, int codigo, int posicao) {
    if (posicao >= e.quantidade) {
        return -1;
    }

    if (e.produtos[posicao].codigo == codigo) {
        return posicao;
    }

    return buscarRecursivo(e, codigo, posicao + 1);
}
