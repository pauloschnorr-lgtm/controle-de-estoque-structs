#include <iostream>
#include "console.h"
using namespace std;

void menu(Estoque &e) {
    int opcao;

    do {
        cout << "1 - Cadastrar produto" << endl;
        cout << "2 - Listar produtos" << endl;
        cout << "3 - Buscar produto" << endl;
        cout << "4 - Atualizar quantidade" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            Produto p;

            cout << "Codigo: ";
            cin >> p.codigo;

            cout << "Nome: ";
            cin >> p.nome;

            cout << "Marca: ";
            cin >> p.marca;

            cout << "Preco: ";
            cin >> p.preco;

            cout << "Categoria: ";
            cin >> p.categoria;

            cout << "Quantidade: ";
            cin >> p.quantidade;

            if (cadastrar(e, p))
                cout << "Produto cadastrado!" << endl;
            else
                cout << "Estoque cheio ou codigo repetido!" << endl;
        }

        else if (opcao == 2) {
            for (int i = 0; i < e.quantidade; i++) {
                cout << e.produtos[i].codigo << " - ";
                cout << e.produtos[i].nome << endl;
            }
        }

        else if (opcao == 3) {
            int codigo;

            cout << "Codigo para buscar: ";
            cin >> codigo;

            int pos = buscar(e, codigo);

            if (pos != -1)
                cout << "Produto encontrado: "
                     << e.produtos[pos].nome << endl;
            else
                cout << "Produto nao encontrado" << endl;
        }

        else if (opcao == 4) {
            int codigo, quantidade;

            cout << "Codigo do produto: ";
            cin >> codigo;

            int pos = buscar(e, codigo);

            if (pos != -1) {
                cout << "Nova quantidade: ";
                cin >> quantidade;

                if (quantidade >= 0) {
                    e.produtos[pos].quantidade = quantidade;
                    cout << "Quantidade atualizada!" << endl;
                }
                else {
                    cout << "Quantidade invalida!" << endl;
                }
            }
            else {
                cout << "Produto nao encontrado" << endl;
            }
        }

        else if (opcao != 0) {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);
}
