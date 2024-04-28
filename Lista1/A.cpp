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
        } while ((Arr[i] < pivot) && (i <= right));

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

int main() {

    #define tam 300000
    int NumChoco, NumCupons, total = 0, totalDiscount, indexDiscount;
    int arr1[tam], arr2[tam];

    cin >> NumChoco;

    for (int i = 0; i < NumChoco; i++) {
        cin >> arr1[i];
    }

    cin >> NumCupons;
    for (int i = 0; i < NumCupons; i++) {
        cin >> arr2[i];
    }

    QuickSort(arr1, 0, NumChoco - 1);

    for (int j = 0; j < NumChoco; j++) {
        total += arr1[j];
    }

    for (int i = 0; i < NumCupons; i++) {
        totalDiscount = total;
        
        indexDiscount = NumChoco - arr2[i];
        totalDiscount -= arr1[indexDiscount]; 
        
        cout << totalDiscount << endl;
    }
    return 0;
}
