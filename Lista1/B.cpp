#include <iostream>
#include <algorithm>
using namespace std;


int hoarePartition(int Arr[], int left, int right) {
    int pivot = Arr[left];
    int i = left;
    int j = right + 1;

    do {
        do {
            i++;
        } while ((Arr[i] < pivot) && (i < right));

        do {
            j--;
        } while (Arr[j] > pivot);

        swap(Arr[i], Arr[j]);

    } while (!(i >= j));

    swap(Arr[i], Arr[j]);
    swap(Arr[left], Arr[j]);

    return j;
}

void QuickSort(int Arr[], int left, int right) {
    if (left < right) {
        int partitionIndex = hoarePartition(Arr, left, right);
        QuickSort(Arr, left, partitionIndex - 1);
        QuickSort(Arr, partitionIndex + 1, right);
    }
}

int BinarySearch(int Arr[], int SizeArr, int K){
    int left = 0, right = SizeArr -1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(Arr[mid] == K)
            return mid;
        else if(Arr[mid] < K)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;

}



int main(){
    int numbers, k, pairs = 0, valor;

    cin >> numbers >> k;
    int Array[numbers];


    QuickSort(Array, 0, numbers-1);
    
    
    for (int i = 0; i <numbers; i++){
        cin >> Array[i];
    }

    QuickSort(Array, 0, numbers-1);
    
    
    for(int i = 0; i < numbers; i++) {
        valor =  Array[i] + k;
        if(BinarySearch(Array, numbers, valor) != -1) {
            pairs++;
        }
    }

    cout << pairs << endl;


    return 0;

}