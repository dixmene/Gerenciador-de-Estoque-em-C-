#include <iostream>
#include <vector>
#include <string>

struct Produto {
    std::string nome;
    int quantidade;
    float preco;
};

int main() {
    std::vector<Produto> estoque;

    // Adicionando produtos ao estoque
    estoque.push_back({"Teclado", 10, 199.99f});
    estoque.push_back({"Mouse", 20, 79.99f});
    estoque.push_back({"Monitor", 5, 899.99f});

    // Listando produtos no estoque
    std::cout << "Produtos em estoque:\n";
    for (const auto& produto : estoque) {
        std::cout << "Nome: " << produto.nome
                  << ", Quantidade: " << produto.quantidade
                  << ", Preço: R$" << produto.preco << "\n";
    }

    return 0;
}
