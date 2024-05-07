#include <iostream>

// Definição da estrutura
struct Pessoa {
    std::string nome;
    int idade;
};

int main() {
    // Declaração de um array de estruturas Pessoa
    const int tamanhoArray = 3;
    Pessoa pessoas[tamanhoArray];

    // Preenchendo o array com dados
    pessoas[0].nome = "João";
    pessoas[0].idade = 30;

    pessoas[1].nome = "Maria";
    pessoas[1].idade = 25;

    pessoas[2].nome = "Pedro";
    pessoas[2].idade = 40;

    // Exibindo os dados do array
    for (int i = 0; i < tamanhoArray; ++i) {
        std::cout << "Pessoa " << i+1 << ": " << pessoas[i].nome << ", " << pessoas[i].idade << " anos" << std::endl;
    }

    return 0;
}
