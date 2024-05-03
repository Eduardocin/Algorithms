#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 

int hoarePartition(ll int Arr[], int left, int right) {
    ll int pivot = Arr[left];
    ll int i = left;
    ll int j = right + 1;

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


void QuickSort(ll int Arr[], ll int left, ll int right) {
    if (left < right) {
        ll int pIndex = hoarePartition(Arr, left, right);
        QuickSort(Arr, left, pIndex - 1);
        QuickSort(Arr, pIndex + 1, right);
    }
}


int main() {

    ll int NumChoco, NumCupons, total = 0;

    cin >> NumChoco;
    ll int * ChocoPrice = new ll int[NumChoco]; // criar o array dos valores de cada chocolate

    for (int i = 0; i < NumChoco; i++) {
        cin >> ChocoPrice[i];
    }

    cin >> NumCupons;
    ll int * ChocoCupons = new ll int[NumCupons]; // criar o array dos cupons
    for (int i = 0; i < NumCupons; i++) {
        cin >> ChocoCupons[i];
    }

    QuickSort(ChocoPrice, 0, NumChoco - 1);

    for (ll int j = 0; j < NumChoco; j++) {// calcula o valor total dos chocolates
        total += ChocoPrice[j];
    }

    for (ll int i = 0; i < NumCupons; i++) {
        cout << total -  ChocoPrice[NumChoco - ChocoCupons[i]] << endl;  // subtrai do valor total o desconto
    }


    delete [] ChocoCupons;
    delete [] ChocoPrice;

    return 0;
}
