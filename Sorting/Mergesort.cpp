#include <iostream>
using namespace std;

void merge(int Arr[],int SizeArray, int left, int mid, int right) {
    int temp[SizeArray];
    int i1 = left, i2 = mid + 1;
    for (int i = left; i <= right; i++) {
        temp[i] = Arr[i];
    }
    for (int curr = left; curr <= right; curr++) {
        if(i1 == mid + 1){
            Arr[curr] = temp[i2];
            i2 ++;
        }
        else if (i2 > right){
            Arr[curr] = temp[i1];
            i1 ++;
        }
        else if( temp[i1] <= temp[i2]){
            Arr[curr] = temp[i1];
            i1++;
        }
        else{
            Arr[curr] = temp[i2]; 
            i2++;
        }
    }
}

void MergeSort(int Arr[],int SizeArr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(Arr, SizeArr, left, mid);
        MergeSort(Arr, SizeArr, mid + 1, right);
        merge(Arr, SizeArr, left, mid, right);
    }
}

int main(){
    int Array[] = {5, 2, 1, 7, 0};
    int SizeArray = sizeof(Array) / sizeof(Array[0]);
    MergeSort(Array, SizeArray, 0, SizeArray-1);
    for(int n : Array){
        cout << n << " ";
    }
    return 0;
}
