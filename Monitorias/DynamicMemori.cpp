#include <iostream>

using namespace std;

int main(){
    int size;
    int* aptr;

    cout << "Enter the size of the array: ";
    cin >> size;

    aptr = new int[size];

    // fill the array with inputs
    for(int i = 0; i < size;i++) {
        cout << "Enter a number: ";
        cin >> aptr[i]; // or *(aptr + i)
    }

    delete[] aptr; // delete the entire array



    int* n = new int; // create two variable

    *n = 12;

    int* o;

    o = new int;

    int sum = *n + *o; 

    
    delete o;
    delete n;
    return 0;
}
