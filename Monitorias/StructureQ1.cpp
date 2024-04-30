#include <iostream>

using namespace std;

struct Turma {
    float* nota;
    int numero;
};

int main(){

    Turma* salas;
    int num_turmas;

    cout << "Qual o número da turma" << endl;
    cin >> num_turmas;
    
    salas = new Turma[num_turmas];
    
    for(int i = 0; i < num_turmas; i++){
        cout << "Qual a quantidade de alunos da turma" << endl;
        cin >> salas[i].numero;
        salas[i].nota = new float[salas[i].numero];

        for(int j=0; j < salas[i].numero; j++){
            cout << "Qual a nota do aluno " << j+1 << endl;
            cin >> salas[i].nota[j];
        }
    }

    //calcular  a media de cada turma
    for(int i = 0; i < num_turmas; i++ ){
        float media = 0;
        for(int j = 0; j < salas[i].numero; j++){
            media += salas[i].nota[j];
    }  
        media /= salas[i].numero;
        cout << "A média da turma " << i+1 << " é " << media << endl;
    }   

    delete[] salas;


    return 0;
}