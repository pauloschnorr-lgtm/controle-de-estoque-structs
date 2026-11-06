Controle de Estoque para Mercado (C++)

Sistema de terminal em C++ para cadastrar e consultar produtos do estoque de um mercado. Trabalho da disciplina de Algoritmos e Programação 2 do curso de Ciência da Computação da Univali, com foco em modularização em vários arquivos, structs e recursividade.

Esta é uma versão inicial do projeto, feita em sala. A lista de melhorias no final mostra o que falta para cumprir o enunciado completo.

Funcionalidades
Opção	O que faz
1 - Cadastrar produto	Cadastra código, nome, marca, preço, categoria e quantidade
2 - Listar produtos	Mostra o código e o nome de todos os produtos
3 - Buscar produto	Procura um produto pelo código, usando uma função recursiva
4 - Atualizar quantidade	Define a nova quantidade em estoque de um produto, pelo código
0 - Sair	Encerra o programa
Regras
Capacidade máxima de 100 produtos
Código único: não permite cadastrar dois produtos com o mesmo código
Não aceita quantidade negativa ao atualizar o estoque
Estrutura do projeto
produto.h / produto.cpp    struct Produto (código, nome, marca, categoria, preço, quantidade)
estoque.h / estoque.cpp    struct Estoque (vetor de 100 produtos + quantidade atual) e regras de estoque
console.h / console.cpp    menu e toda a leitura/escrita no terminal (cin e cout)
main.cpp                   cria o estoque e inicia o menu

O projeto separa as responsabilidades em módulos:

Isolamento de entrada e saída: os arquivos produto e estoque não usam cin nem cout. Eles só processam dados e devolvem valores. Toda a interação com o usuário fica em console.cpp.
Funções do estoque:
bool cadastrar(Estoque &e, Produto p) adiciona o produto, validando limite e código repetido. Recebe o estoque por referência e devolve true ou false.
int buscar(Estoque e, int codigo) devolve a posição do produto ou -1.
int buscarRecursivo(Estoque e, int codigo, int posicao) faz a busca de forma recursiva: a condição de parada é chegar ao fim dos produtos cadastrados (devolve -1) ou encontrar o código (devolve a posição), e o caso recursivo passa para a posição seguinte.
Como compilar e executar

Requer um compilador C++ (por exemplo, o g++). Dentro da pasta do projeto:

bash
g++ main.cpp console.cpp estoque.cpp produto.cpp -o estoque_mercado
./estoque_mercado

No Windows, execute estoque_mercado.exe.

Conceitos aplicados
Modularização com arquivos de cabeçalho (.h) e implementação (.cpp)
Guardas de inclusão (#ifndef, #define, #endif)
struct e vetor estático de structs
Passagem de parâmetros por valor e por referência
Recursividade com caso base e caso recursivo
Separação entre lógica do programa e interface com o usuário
Melhorias planejadas
Buscar também por categoria e listar produtos com estoque zerado, como pede o enunciado
Na opção 4, permitir dar baixa e repor o estoque (somar e subtrair), em vez de só definir um novo valor
Mostrar todos os dados do produto encontrado, e não só o nome
Aceitar nomes, marcas e categorias com mais de uma palavra (hoje a leitura usa cin >>)
Validar preço e quantidade no cadastro, e tratar entradas que não sejam números
Passar o Estoque por referência nas buscas, evitando copiar o vetor inteiro a cada chamada
Mover para produto.cpp as funções que operam sobre um produto
Ajustar o menu para a opção de saída ser a 5, como no enunciado
Autores
Paulo Conceição
