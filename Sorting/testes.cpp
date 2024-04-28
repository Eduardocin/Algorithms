#include <iostream>
#include <algorithm>
using namespace std;

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






int main(){
    
    return 0;
}