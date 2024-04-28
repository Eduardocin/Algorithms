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

    } while (i < j);

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
    int Arr[] = {4, 3, 1, 5, 2};
    int SizeArr = sizeof(Arr) / sizeof(Arr[0]);

    QuickSort(Arr, 0, SizeArr - 1);

    cout << "Sorted array: ";
    for (int n : Arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
