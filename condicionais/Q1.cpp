#include <iostream>
#include <locale>
#include <Windows.h>

using std::cin;
using std::cout;



int main() {
    std::string nome;
    
    std::getline(cin, nome);

    // Configura a codificação de caracteres para UTF-8
	SetConsoleOutputCP(CP_UTF8);

    if (nome == "Winifred Sanderson"){
        cout << "O livro!! Sem ele, a mais poderosa das bruxas não conseguirá realizar seus feitiços.";
    } 
    else if (nome == "Sarah Sanderson"){
        cout << "Tapem os ouvidos, sua voz pode hipnotizar!!";
    }
    else if (nome == "Mary Sanderson"){
        cout << "Seu ótimo olfato e péssimo senso de direção podem ser usados para confundí-la.";
    }
    else{
        cout << "Só mais uma criança fantasiada, continuem atentos!!";
    }

    return 0;
}
