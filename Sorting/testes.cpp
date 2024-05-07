#include <iostream>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
void merge(int Arr[], int left, int mid, int right) {
    int i1 = left, i2 = mid + 1;
    int temp[right - left + 1];
    int curr = 0;
=======
int HoarePartition(int Arr[], int left, int right){
    
    int pivot = Arr[left];
    int i = left;
    int j = right +1;

    do{ 
        do
        {
            i++;
        } while ((Arr[i] < pivot) && (i < right));
        do{
            j--;
        }while(Arr[j] > pivot);
        
        swap(Arr[i],Arr[j]);

    }while(!(i >= j));
    
    swap(Arr[i],Arr[j]);
    swap(Arr[left],Arr[j]);

    return j;

}




void Quicksort(int Arr[], int left, int right){
    if (left < right){
        
        int Pindex = HoarePartition(Arr,left, right);

        Quicksort(Arr,left,Pindex-1);
        Quicksort(Arr,Pindex+1,right);
    }
    
}
>>>>>>> b2a4f16fb26c36e0010d120a45fd69939d17477c

    while (i1 <= mid && i2 <= right) {
        if (Arr[i1] <= Arr[i2]) {
            temp[curr++] = Arr[i1++];
        } else {
            temp[curr++] = Arr[i2++];
        }
    }

    while (i1 <= mid) {
        temp[curr++] = Arr[i1++];
    }

    while (i2 <= right) {
        temp[curr++] = Arr[i2++];
    }

    for (int i = left; i <= right; i++) {
        Arr[i] = temp[i - left];
    }
}

void MergeSort(int Arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(Arr, left, mid);
        MergeSort(Arr, mid + 1, right);
        merge(Arr, left, mid, right);
    }
}

int main() {
    int NumChoco, NumCupons, total = 0;

    cin >> NumChoco;
    int *ChocoPrice = new int[NumChoco]; // criar o array dos valores de cada chocolate

    for (int i = 0; i < NumChoco; i++) {
        cin >> ChocoPrice[i];
    }

    cin >> NumCupons;
    int *ChocoCupons = new int[NumCupons]; // criar o array dos cupons
    for (int i = 0; i < NumCupons; i++) {
        cin >> ChocoCupons[i];
    }

    MergeSort(ChocoPrice, 0, NumChoco - 1);

    for (int j = 0; j < NumChoco; j++) { // calcula o valor total dos chocolates
        total += ChocoPrice[j];
    }

    for (int i = 0; i < NumCupons; i++) {
        int totalDiscount = total; // reseta o total

        totalDiscount -= ChocoPrice[NumChoco - ChocoCupons[i]]; // subtrai do valor total o desconto

        cout << totalDiscount << endl;
    }

    delete[] ChocoCupons;
    delete[] ChocoPrice;

    return 0;
}
