#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class MinHeap{
private:
    vector<T> arr;
    int heapSize;

    void heapifyDown(){
        for(int i = heapSize/2; i > 0; i--){
            int k = i;
            T v = arr[i];
            bool heap = false;

            while(!heap && 2*k <= heapSize){
                int j = 2*k;
                if(j < heapSize){
                    if(arr[j] > arr[j+1]){
                        j++;
                    }
                }
                if(v <= arr[j]){
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

    void heapifyUp(){
        int k = heapSize;
        T v = arr[k];

        while(k > 1 && v < arr[k/2]){
            arr[k] = arr[k/2];
            k = k/2;
        }
        arr[k] = v;
    }

public:
    MinHeap(vector<T>& input): heapSize(0){
        arr.push_back(0);
        for(int i = 0; i < input.size(); i++){
            arr.push_back(input[i]);
        }
        heapSize = input.size();
        heapifyDown();
    }

    ~MinHeap(){};

    T find_min(){
        return arr[1];
    };

    T removeMin() {
        T min = arr[1];
        arr[1] = arr[heapSize];
        arr[heapSize] = min;
        heapSize--;

        heapifyDown();
        return min;
    }
    
    int getSize() const {
        return heapSize;
    }

    void insert(T value){
        heapSize++;
        arr[heapSize] = value;
        heapifyUp();
    }

};


int main() {
    int N;
    
    while (cin >> N && N != 0) {
        vector<int> input;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            input.push_back(num);
        }
        
        MinHeap<int>* minHeap = new MinHeap<int>(input);
        long long int totalCost = 0;
        
        while (minHeap->getSize() > 1) {
                int partialCost = minHeap->removeMin();
                partialCost += minHeap->removeMin();
                totalCost += partialCost;
                minHeap->insert(partialCost);
        }
        
        cout << totalCost << endl;
        delete minHeap;
    }
    
    return 0;
}