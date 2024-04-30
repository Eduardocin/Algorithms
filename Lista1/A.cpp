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
    int NumChoco, NumCupons, total = 0, totalDiscount;

    cin >> NumChoco;
    int * ChocoPrice = new int[NumChoco]; // criar o array dos valores de cada chocolate

    for (int i = 0; i < NumChoco; i++) {
        cin >> ChocoPrice[i];
    }

    cin >> NumCupons;
    int * ChocoCupons = new int[NumCupons]; // criar o array dos cupons
    for (int i = 0; i < NumCupons; i++) {
        cin >> ChocoCupons[i];
    }

    MergeSort(ChocoPrice, NumChoco, 0, NumChoco - 1);

    for (int j = 0; j < NumChoco; j++) {// calcula o valor total dos chocolates
        total += ChocoPrice[j];
    }

    for (int i = 0; i < NumCupons; i++) {
        totalDiscount = total; // reseta o total 

        totalDiscount -= ChocoPrice[NumChoco - ChocoCupons[i]];  // subtrai do valor total o desconto
        
        cout << totalDiscount << endl;
    }

    delete [] ChocoCupons;
    delete [] ChocoPrice;

    return 0;
}
