#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Definição da estrutura Candidato
struct Candidato {
    string nome;
    int nota;
    int idade;
};

// Função de particionamento de Hoare
int HoarePartition(int Array[], Candidato Array2[], int left, int right) {
    int pivot = Array[left];
    int i = left, j = right + 1;

    do {
        do {
            i++;
        } while ((Array[i] > pivot) && (i < right));
        do {
            j--;
        } while (Array[j] < pivot);

        if (i < j) {
            swap(Array[i], Array[j]);
            swap(Array2[i], Array2[j]);
        }

    } while (i < j);

    swap(Array[left], Array[j]);
    swap(Array2[left], Array2[j]);

    return j;
}

// Função Quicksort
void Quicksort(int Array[], Candidato Array2[], int left, int right) {
    if (left < right) {
        int s = HoarePartition(Array, Array2, left, right);
        Quicksort(Array, Array2, left, s - 1);
        Quicksort(Array, Array2, s + 1, right);
    }
}

int main() {
    int numCargos;
    cin >> numCargos;

    for (int i = 0; i < numCargos; i++) {
        int numInscritos, numVagas;
        cin >> numInscritos >> numVagas;

        Candidato candidatos[numInscritos];

        // Ler os candidatos e suas informações
        for (int j = 0; j < numInscritos; j++) {
            cin >> candidatos[j].nome >> candidatos[j].nota >> candidatos[j].idade;
        }

        // Ordenar os candidatos por nota, idade e ordem de inscrição
        int notas[numInscritos];
        for (int j = 0; j < numInscritos; j++) {
            notas[j] = candidatos[j].nota;
        }
        Quicksort(notas, candidatos, 0, numInscritos - 1);

        cout << "Cargo " << i + 1 << ":" << endl;

        // Imprimir os candidatos classificados
        for (int j = 0; j < min(numInscritos, numVagas); j++) {
            cout << candidatos[j].nome << endl;
        }
        for (int j = min(numInscritos, numVagas); j < numVagas; j++) {
            cout << "x" << endl;
        }
    }

    return 0;
}
