#include <iostream>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 35309d1a544313442a1e431f6bab7e2a97eab23e
#define ll long long 

int hoarePartition(ll int Arr[], int left, int right) {
    ll int pivot = Arr[left];
    ll int i = left;
    ll int j = right + 1;
<<<<<<< HEAD
=======
=======
int hoarePartition(int Arr[], int left, int right) {
    int pivot = Arr[left];
    int i = left;
    int j = right + 1;
>>>>>>> b2a4f16fb26c36e0010d120a45fd69939d17477c
>>>>>>> 35309d1a544313442a1e431f6bab7e2a97eab23e

    do {
        do {
            i++;
<<<<<<< HEAD
        } while ((Arr[i] < pivot) && (i < right));
=======
<<<<<<< HEAD
        } while ((Arr[i] < pivot) && (i < right));
=======
        } while ((Arr[i] < pivot) && (i <= right));
>>>>>>> b2a4f16fb26c36e0010d120a45fd69939d17477c
>>>>>>> 35309d1a544313442a1e431f6bab7e2a97eab23e

        do {
            j--;
        } while (Arr[j] > pivot);

        swap(Arr[i], Arr[j]);

    } while (!(i >= j));

    swap(Arr[i], Arr[j]);
    swap(Arr[left], Arr[j]);

    return j;
<<<<<<< HEAD
}


void QuickSort(ll int Arr[], ll int left, ll int right) {
    if (left < right) {
        ll int pIndex = hoarePartition(Arr, left, right);
        QuickSort(Arr, left, pIndex - 1);
        QuickSort(Arr, pIndex + 1, right);
    }
}

=======
}


void QuickSort(ll int Arr[], ll int left, ll int right) {
    if (left < right) {
        ll int pIndex = hoarePartition(Arr, left, right);
        QuickSort(Arr, left, pIndex - 1);
        QuickSort(Arr, pIndex + 1, right);
    }
}
>>>>>>> b2a4f16fb26c36e0010d120a45fd69939d17477c


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

<<<<<<< HEAD
    QuickSort(ChocoPrice, 0, NumChoco - 1);
=======
<<<<<<< HEAD
    QuickSort(ChocoPrice, 0, NumChoco - 1);
=======
    QuickSort(arr1, 0, NumChoco - 1);
>>>>>>> b2a4f16fb26c36e0010d120a45fd69939d17477c
>>>>>>> 35309d1a544313442a1e431f6bab7e2a97eab23e

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
