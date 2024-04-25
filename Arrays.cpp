#include <iostream>

using namespace std;


//create a func to sum of elements in a array
void doubleElements(int Array[], int size) {

    cout << sizeof(Array) << " " << sizeof(Array[0]) << endl;
    cout << Array[0] << endl;

    // dobrar cada elemento
    for (int i = 0; i < size; i++) {
        Array[i] = 2* Array[i];
    }
}



int main(){
     // A can be user for &A[0]
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int sizeA = sizeof(A) / sizeof(A[0]); 

    doubleElements(A,sizeA);
    for( int i = 0; i < sizeA; i++){
        cout << A[i] << " ";
    }

    return 0;
}