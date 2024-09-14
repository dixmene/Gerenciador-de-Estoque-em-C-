### Gerenciador de Estoque em C++

### Objetivo do Projeto

O **Gerenciador de Estoque em C++** é uma aplicação de console desenvolvida para gerenciar um estoque de produtos. O objetivo é permitir que os usuários realizem operações básicas de controle de estoque, como adicionar, remover e listar produtos. Além disso, a aplicação é capaz de salvar e carregar os dados do estoque a partir de um arquivo, garantindo que as informações sejam preservadas entre sessões.

### Funcionalidades

1. **Adicionar Produtos**: Permite ao usuário inserir novos produtos no estoque.
2. **Remover Produtos**: Facilita a remoção de produtos existentes.
3. **Listar Produtos**: Exibe todos os produtos e suas informações atuais.
4. **Persistência de Dados**: Armazena e recupera os dados dos produtos de um arquivo de texto para garantir que as informações não sejam perdidas.

### Estruturas de Dados Utilizadas

- **Vetores**: Usados para armazenar a lista de produtos.
- **Strings**: Para armazenar os nomes dos produtos.
- **Floats**: Para armazenar o preço dos produtos.

### Código

Aqui está o código da aplicação com uma explicação detalhada de cada parte:

```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Estrutura para armazenar informações do produto
struct Produto {
    string nome;
    int quantidade;
    float preco;
};

// Função para adicionar um produto
void adicionarProduto(vector<Produto>& estoque) {
    Produto p;
    cout << "Nome do Produto: ";
    cin >> p.nome;
    cout << "Quantidade: ";
    cin >> p.quantidade;
    cout << "Preço: ";
    cin >> p.preco;
    estoque.push_back(p);
}

// Função para remover um produto
void removerProduto(vector<Produto>& estoque) {
    string nome;
    cout << "Nome do Produto a remover: ";
    cin >> nome;
    
    for (auto it = estoque.begin(); it != estoque.end(); ++it) {
        if (it->nome == nome) {
            estoque.erase(it);
            cout << "Produto removido com sucesso.\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

// Função para listar todos os produtos
void listarProdutos(const vector<Produto>& estoque) {
    for (const auto& p : estoque) {
        cout << "Nome: " << p.nome << ", Quantidade: " << p.quantidade << ", Preço: R$" << p.preco << endl;
    }
}

// Função para salvar os dados em um arquivo
void salvarDados(const vector<Produto>& estoque) {
    ofstream arquivo("estoque.txt");
    for (const auto& p : estoque) {
        arquivo << p.nome << "," << p.quantidade << "," << p.preco << endl;
    }
}

// Função para carregar os dados de um arquivo
void carregarDados(vector<Produto>& estoque) {
    ifstream arquivo("estoque.txt");
    string linha;
    while (getline(arquivo, linha)) {
        Produto p;
        stringstream ss(linha);
        getline(ss, p.nome, ',');
        ss >> p.quantidade;
        ss.ignore();
        ss >> p.preco;
        estoque.push_back(p);
    }
}

int main() {
    vector<Produto> estoque;
    carregarDados(estoque);

    int opcao;
    do {
        cout << "1. Adicionar Produto\n2. Remover Produto\n3. Listar Produtos\n4. Salvar e Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                adicionarProduto(estoque);
                break;
            case 2:
                removerProduto(estoque);
                break;
            case 3:
                listarProdutos(estoque);
                break;
            case 4:
                salvarDados(estoque);
                cout << "Dados salvos. Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 4);

    return 0;
}
```

### Explicação do Código

1. **Estrutura `Produto`**:
   - Define a estrutura de um produto, com atributos para nome, quantidade e preço.

2. **Função `adicionarProduto`**:
   - Solicita ao usuário as informações do produto e adiciona-o à lista de produtos.

3. **Função `removerProduto`**:
   - Permite a remoção de um produto pelo nome. Se encontrado, o produto é removido; caso contrário, uma mensagem de erro é exibida.

4. **Função `listarProdutos`**:
   - Exibe todos os produtos no estoque, mostrando detalhes como nome, quantidade e preço.

5. **Função `salvarDados`**:
   - Salva todos os produtos do estoque em um arquivo de texto chamado `estoque.txt`.

6. **Função `carregarDados`**:
   - Carrega produtos do arquivo `estoque.txt` e os adiciona ao estoque na inicialização da aplicação.

7. **Função `main`**:
   - O ponto de entrada do programa. Ele carrega os dados do arquivo, exibe um menu para o usuário e executa as ações conforme a escolha do usuário até que o programa seja encerrado.

### Como Utilizar

1. Compile o código em um ambiente de desenvolvimento C++ (como o Visual Studio).
2. Execute o programa.
3. Use o menu interativo para adicionar, remover ou listar produtos.
4. Ao terminar, escolha a opção para salvar os dados e sair do programa.

### Conclusão

Este projeto é uma excelente oportunidade para aprender a manipular dados e arquivos em C++. Ele demonstra conceitos básicos de gerenciamento de dados e persistência, fornecendo uma base sólida para projetos mais complexos.
