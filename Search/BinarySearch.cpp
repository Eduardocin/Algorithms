#include <iostream>
#include <Windows.h>

using namespace std;

int BinarySearch(int Arr[], int SizeArr, int K){
    int left = 0, right = SizeArr -1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(Arr[mid] == K)
            return mid;
        else if(Arr[mid] < K)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;

}

int main(){
    int N, M, input, i;
    
    cin >> N;
    int Arr[N];

    while(cin >> input ){
        Arr[i] = input;
        i++;
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> input;
        cout << BinarySearch(Arr, N, input) << endl;
    }

    return 0;
}