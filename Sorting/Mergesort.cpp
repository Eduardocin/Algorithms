#include <iostream>
using namespace std;

//Mergesort function
void merge(int* arr, int left, int mid, int right) {
    // Array temporário
    int temp[right - left + 1];
    int i1 = left, i2 = mid + 1, curr = left;

    // Copiar os elementos para temp
    for (int i = left; i <= right; i++) {
        temp[i - left] = arr[i];
    }

    // Condições para mesclar
    while (i1 <= mid && i2 <= right) {
        if (temp[i1 - left] <= temp[i2 - left]) {
            arr[curr++] = temp[i1 - left];
            i1++;
        } else {
            arr[curr++] = temp[i2 - left];
            i2++;
        }
    }

    // Copiar os elementos restantes de i1
    while (i1 <= mid) {
        arr[curr++] = temp[i1 - left];
        i1++;
    }

    // Copiar os elementos restantes de i2
    while (i2 <= right) {
        arr[curr++] = temp[i2 - left];
        i2++;
    }
}


void MergeSort(int* arr, int left, int right) {
    
    if (left < right) {
        // Encontrar o ponto médio
        int mid = (left + right) / 2;

        // Ordenar a primeira e a segunda metades
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // fundir as metades ordenadas
        merge(arr, left, mid, right);
    }
}



int main(){
    // define a array para testar o merge sort
    int array[6] = {1,6,3,7,12,8};

    int len_array = sizeof(array) / sizeof(array[0]);

    MergeSort(array, 0, len_array-1);

    
    // printa o array ordenado
    for(int n : array){
        cout << n << " ";
    }


    return 0;
}