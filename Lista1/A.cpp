#include <iostream>
using namespace std;

void merge(int Arr[], int SizeArray, int left, int mid, int right) {
    int temp[SizeArray];
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
        } else if (temp[i1] <= temp[i2]) {
            Arr[curr] = temp[i1];
            i1++;
        } else {
            Arr[curr] = temp[i2];
            i2++;
        }
    }
}

void MergeSort(int Arr[], int SizeArr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(Arr, SizeArr, left, mid);
        MergeSort(Arr, SizeArr, mid + 1, right);
        merge(Arr, SizeArr, left, mid, right);
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

    MergeSort(arr1, NumChoco, 0, NumChoco - 1);

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
