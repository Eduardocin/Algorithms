#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
private:
    vector<int> arr;
    int heapSize;

    void heapify(){
        for(int i = (heapSize / 2); i >= 0; i--){
            int k = i;
            int v = arr[k];
            bool heap = false;

            while(!heap && 2*k <= heapSize){
                int j = 2*k;
                if(j < heapSize){
                    if(arr[j] < arr[j+1]){
                        j++;
                    }
                }
                if(v >= arr[j]){
                    heap = true;
                }
                else{
                    arr[k] = arr[j];
                    k = j;
                }
            }
            arr[k] = v;
        }
    }
public:
    MaxHeap(vector<int>& input){
        arr.push_back(0);
        for(int i = 1; i <= input.size(); i++){
            arr.push_back(input[i]);
        }
        heapSize = arr.size() - 1;
        heapify();
    }

    ~MaxHeap(){}

    int findMax(){
        return arr[1];
    }
    
    int removeMax(){
        int max = arr[1];
        arr[1] = arr[heapSize];
        arr[heapSize] = max;
        heapSize--;
        heapify();
        return max;
    }

    void heapSort(){
        int initialSize = heapSize;
        for(int i = 1; i <= initialSize; i++){
            removeMax();
        }
        heapSize = initialSize;
    }
    
    void print(){
        for(int i = 1; i <= heapSize; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};