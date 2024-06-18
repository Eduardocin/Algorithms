#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> arr;
    int heapSize;

    void heapify() {
        for(int i = heapSize / 2; i > 0; i--) {
            int k = i;
            int v = arr[k];
            bool heap = false;

            while (!heap && 2 * k <= heapSize) {
                int j = 2 * k;
                if (j < heapSize){
                    if(arr[j] > arr[j + 1]) {
                        j++;
                    }
                }
                if (v <= arr[j]) {
                    heap = true;
                } else {
                    arr[k] = arr[j];
                    k = j;
                }
            }
            arr[k] = v;
        }
    }    

    void heapfyUp() {
        int k = heapSize;
        int v = arr[k];
        while (k > 1 && v < arr[k / 2]) {
            arr[k] = arr[k / 2];
            k = k / 2;
        }
        arr[k] = v;
    }


public:
    MinHeap(vector<int>& input) {
        arr.push_back(0); 
        for (int i = 0; i < input.size(); i++) {
            arr.push_back(input[i]);
        }
        heapSize = arr.size() - 1;
        heapify();
    }
    ~MinHeap() {}

    int getSize() {
        return heapSize;
    }

    // Removes the smallest element from the heap
    int removeMin() {
        if(heapSize > 0) {
            int min = arr[1];
            arr[1] = arr[heapSize];
            arr[heapSize] = min;
            heapSize--;
            heapify();
            return min;
        }
    }

    void insert(int val) {
        if(heapSize < arr.size()) {
            heapSize++;
            arr[heapSize] = val;
            heapfyUp();
        }
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
        
        MinHeap* minHeap = new MinHeap(input);
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