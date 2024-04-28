#include <iostream>
#include <algorithm>

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

        std::swap(Arr[i], Arr[j]);

    } while (!(i >= j));

    std::swap(Arr[i], Arr[j]);
    std::swap(Arr[left], Arr[j]);

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

    std::cout << "Sorted array: ";
    for (int n : Arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
