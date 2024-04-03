#include <iostream>
#include <windows.h>

int main(){
    // Configura a codificação de caracteres para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    //declarando variaveis
    std::string nome_vitima , nome_vilao, armadilha;
    float tempo;
    
    
    //inputs
    std::getline(std::cin, nome_vitima);
    std::getline(std::cin, nome_vilao);
    std::getline(std::cin, armadilha);
    std::cin >> tempo;
    tempo = tempo / 60;

    //condicionais
    if (nome_vilao == "John Kramer" && armadilha == "Armadilha de urso reversa") {
        if (tempo >= 5) {
            std::cout << "Com tempo de sobra, " << nome_vitima << " consegue retirar a armadilha de sua cabeça, sobrevivendo com sucesso ao jogo de Jigsaw.";

        }
    }




    return 0;
}