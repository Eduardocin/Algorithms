#include <iostream>
#include <algorithm>

/*
particiona o array com os valores maiores do que o pivo a direita
e o valores menores a esquerda e retornar o índice do pivo após
a ser feita a partição.
*/
int hoarePartition(int Arr[], int left, int right) {
    
    int pivot = Arr[left]; // escolhe o pivo como o elemento mais a esquerda do array
    
    // variaveis auxiliares
    int i = left; // deve incrementar até que encontre um elemente maior do que o pivo
    int j = right + 1; // dev decrementar até que o elemento seja menor do que o pivo


    do {
        do {// incrementa i até que ele encontre uma elemente maior do que o pivo ou chegue ao limite do array

            i++; 
        } while ((Arr[i] < pivot) && (i <= right)); 

        do { // decrementa j até que ele entre um elemente da menor do que o pivo
            j--;
        } while (Arr[j] > pivot);

        std::swap(Arr[i], Arr[j]);

    } while (!(i >= j));
    
    // desfaz a ultima troca quando i >= j
    std::swap(Arr[i], Arr[j]);
    
    // coloca o pivo na sua posição correta
    std::swap(Arr[left], Arr[j]);

    return j; // retornar o indice de j
}

void QuickSort(int Arr[], int left, int right) {
    // verificar se o intervalo é unitário
    if (left < right) {
        
        // particiona o intervalo
        int partitionIndex = hoarePartition(Arr, left, right);
        
        // chamadas recursivas
        QuickSort(Arr, left, partitionIndex -1); // chamada para o intervalo da esquerda
        QuickSort(Arr, partitionIndex + 1, right); // chamada para o intervalo da direita
    }
}

int main() {
    int Arr[] = {4 3 1 5 2};
    int SizeArr = sizeof(Arr) / sizeof(Arr[0]);

    // (Array, LimiteEsquerdo, LimiteDireito)
    QuickSort(Arr, 0, SizeArr - 1);


    std::cout << "Sorted array: ";
    for (int n : Arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
