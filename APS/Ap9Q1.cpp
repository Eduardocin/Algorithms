#include <iostream>
#include <vector>

using namespace std;

// Min-heap class for integers using arrays and bottom-up heapify technique
class MinHeap {
private:
    vector<int> arr;
    int heapSize;

    // Heapify function to maintain the heap property
    void heapify() {
        for(int i = heapSize / 2; i > 0; i--) {
            int k = i;
            int v = arr[k];
            bool heap = false;

            while (!heap && 2 * k <= heapSize) {
                int j = 2 * k;
                if (j < heapSize && arr[j] > arr[j + 1]) {
                    j++;
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

public:
    MinHeap(vector<int>& input) {
        // Adjust input array for 1-based indexing
        arr.push_back(0); // Placeholder for 1-based indexing
        for (int i = 0; i < input.size(); i++) {
            arr.push_back(input[i]);
        }
        heapSize = arr.size() - 1;
        heapify();
    }
    ~MinHeap() {}


    // Returns the smallest element in the heap
    int getMin() {
        return arr[1];
    }

    // Removes the smallest element from the heap
    int removeMin() {
        int min = arr[1];
        arr[1] = arr[heapSize];
        arr[heapSize] = min;
        heapSize--;
        heapify();
        return min;
    }

    void heapsort() {
        int originalSize = heapSize;
        for (int i = 1; i <= originalSize; i++) {
            // trocar o ultimo elemento com o primeiro e chamaar o heapify
            removeMin();
            
            if (heapSize > 0) {
                printHeap();
            }
        }
        heapSize = originalSize;
    }


    // Function to print the heap
    void printHeap() {
        for (int i = 1; i <= heapSize; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printInverseHeap() {
        for(int i = heapSize; i > 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    int numcasos;
    cin >> numcasos; // Read number of test cases

    for (int i = 0; i < numcasos; i++) {
        int tam_heap;
        cin >> tam_heap; // Read the size of the heap
        vector<int> arr;
        for (int j = 0; j < tam_heap; j++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        MinHeap* heap = new MinHeap(arr);
        heap->printHeap();
        heap->heapsort();
        heap->printInverseHeap();

        delete heap;
        cout << endl;
    }

    return 0;
}