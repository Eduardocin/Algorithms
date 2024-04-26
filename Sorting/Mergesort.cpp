#include <iostream>
using namespace std;

// Une o fragmentos
void merge(int Arr[],int SizeArray, int left, int mid, int right) {
    // Array temporário que recebe os valores do Array original que estão sendo ordenados
    int temp[SizeArray];

    // Indices para percorrer o Array
    int i1 = left, i2 = mid + 1;

    // Copiar apenas os elementos  que estão sendo ordenados para temp
    for (int i = left; i <= right; i++) {
        temp[i] = Arr[i];
    }

    // Varia o curso  e verificar as condições
    for (int curr = left; curr <= right; curr++) {
        if(i1 == mid + 1){ // verifica se já foram copiados todos os elementos da primeira parte
            Arr[curr] = temp[i2];
            i2 ++;
        }
        else if (i2 > right){ // verifica se já foram copiados todos os elementos da segunra parte
            Arr[curr] = temp[i1];
            i1 ++;
        }
        else if( temp[i1] <= temp[i2]){ // verifica se o elemento da esquerda é menor que o da direita
            Arr[curr] = temp[i1];
            i1++;
        }
        else{Arr[curr] = temp[i2]; 
        i2++;
        }
    }
    }

/*
Divide o problema da  ordenação do Array inicial em ordenar subArrays cara vez menores até que o Array tenha somente um elemento
que, por definição, está ordenado.
*/

void MergeSort(int Arr[],int SizeArr, int left, int right) {
    // testa se o Array é unitário
    if (left < right) {
        // Encontrar o meio do Array
        int mid = (left + right) / 2;
        // Chamadas recusivas para os intervalos até o meio do Array e depois dele
        MergeSort(Arr, SizeArr, left, mid);
        MergeSort(Arr, SizeArr, mid + 1, right);

        //processo de conquista
        merge(Arr, SizeArr, left, mid, right);
    }
}



int main(){

    int Array[] = {5, 2, 1, 7, 0};

    int SizeArray = sizeof(Array) / sizeof(Array[0]);

    MergeSort(Array, SizeArray, 0, SizeArray-1);

    
    // printa o Array ordenado
    for(int n : Array){
        cout << n << " ";
    }


    return 0;
}