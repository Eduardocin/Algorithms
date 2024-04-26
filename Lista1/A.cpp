#include <iostream>
using namespace std;



int main(){
    // recieve number of chocolates inputs 2<n<3*10^5
    int  input, i = 0;
    int arr1[3*10^5], arr2[3*10^5] , arr3[3*10^5];
    
    while(cin >> input){
        arr1[i] = input;
        i++;
    }
    
    i = 0;
    // recieve price of chocolates bar inputs 
    while(cin >> input){
        arr2[i] = input;
    }

    i = 0;
    // recieve number of cupons i have
    while(cin >> input){
        arr3[i] = input;
    }

    return 0;
}
