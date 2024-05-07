#include <iostream>
using namespace std;

struct Candidato {
    char nome[30];
    int nota;
    int idade;
    int ordem;
};

void merge(Candidato Arr[], int SizeArray, int left, int mid, int right) {
    Candidato temp[SizeArray];
    int i1 = left, i2 = mid + 1;
    
    for (int i = left; i <= right; i++) {
        temp[i] = Arr[i];
    }
    
    for (int curr = left; curr <= right; curr++) {
        if (i1 == mid + 1) {
            Arr[curr] = temp[i2];
            i2++;
        } else if (i2 > right) {
            Arr[curr] = temp[i1];
            i1++;
        } else if (temp[i1].nota < temp[i2].nota ||
                    (temp[i1].nota == temp[i2].nota && temp[i1].idade < temp[i2].idade) ||
                    (temp[i1].nota == temp[i2].nota && temp[i1].idade == temp[i2].idade && temp[i1].ordem > temp[i2].ordem)) {
            Arr[curr] = temp[i1];
            i1++;
        } else {
            Arr[curr] = temp[i2];
            i2++;
        }
    }
}

void MergeSort(Candidato Arr[],int SizeArr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(Arr, SizeArr, left, mid);
        MergeSort(Arr, SizeArr, mid + 1, right);
        merge(Arr, SizeArr, left, mid, right);
    }
}


int main() {
    int numCargos;
    cin >> numCargos;

    for (int i = 0; i < numCargos; i++) {
        int numInscritos, numVagas;
        cin >> numInscritos >> numVagas;

        Candidato candidatos[numInscritos];

        // infos dos candidatos
        for (int j = 0; j < numInscritos; j++) {
            cin >> candidatos[j].nome >> candidatos[j].nota >> candidatos[j].idade;
            candidatos[j].ordem = j + 1;
        }

        // ordenar
        MergeSort(candidatos, numInscritos, 0, numInscritos - 1);

        //imprimir aprovados
        cout << "cargo " << i + 1 << ":" << endl;
    
        for (int k = 0; k < numVagas; k++) {
            if (k < numInscritos)
                cout << candidatos[numInscritos - 1 - k].nome << '\n';
            else
                cout << "x" << '\n';
        }
    }
    return 0;
}
