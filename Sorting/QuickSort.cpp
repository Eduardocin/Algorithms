#include <iostream>
#include <algorithm>

/*
particiona o array com os valores maiores do que o pivo a direita
e o valores menores a esquerda e retornar o índice do pivo após
a ser feita a partição.
*/
int hoarePartition(int arr[], int left, int right) {
    
    int pivot = arr[left]; // escolhe o pivo como o elemento mais a esquerda do array
    
    // variaveis auxiliares
    int i = left; // deve incrementar até que encontre um elemente maior do que o pivo
    int j = right + 1; // dev decrementar até que o elemento seja menor do que o pivo


    do {
        do {// incrementa i até que ele encontre uma elemente maior do que o pivo ou chegue ao limite do array

            i++; 
        } while ((arr[i] < pivot) || (i <= right)); 

        do { // decrementa j até que ele entre um elemente da menor do que o pivo
            j--;
        } while (arr[j] > pivot);

        std::swap(arr[i], arr[j]);

    } while (!(i >= j));
    
    // desfaz a ultima troca quando i >= j
    std::swap(arr[i], arr[j]);
    
    // coloca o pivo na sua posição correta
    std::swap(arr[left], arr[j]);

    return j; // retornar o indice de j
}

void QuickSort(int arr[], int left, int right) {
    // verificar se o intervalo é unitário
    if (left < right) {
        
        // particiona o intervalo
        int partitionIndex = hoarePartition(arr, left, right);
        
        // chamadas recursivas
        QuickSort(arr, left, partitionIndex -1); // chamada para o intervalo da esquerda
        QuickSort(arr, partitionIndex + 1, right); // chamada para o intervalo da direita
    }
}

int main() {
    int arr[] = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // (Array, LimiteEsquerdo, LimiteDireito)
    QuickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
