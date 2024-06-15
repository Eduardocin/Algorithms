#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
private:
    vector<char> arr;
    int heapSize;

    void siftUp(int i) {
        // While the element is not at the root and the parent is smaller than the current element
        while (i > 1 && arr[i / 2] < arr[i]) {
            // Swap the current element with its parent
            swap(arr[i], arr[i / 2]);
            // Move up to the parent's index
            i = i / 2;
        }
    }

    void siftDown(int i) {
        // While the current node has at least one child
        while (2 * i <= heapSize) {
            // Assume the left child is the larger child
            int j = 2 * i;
            
            // If there is a right child and it's larger than the left child
            if (j < heapSize && arr[j] < arr[j + 1]) {
                // Use the right child instead
                j++;
            }
            
            // If the current element is greater than or equal to the largest child, stop
            if (arr[i] >= arr[j]) {
                break;
            }
            
            // Swap the current element with the larger child
            swap(arr[i], arr[j]);
            
            // Move down to the index of the larger child
            i = j;
        }
    }


public:
    MaxHeap(int maxSize) : heapSize(0) {
        arr.resize(maxSize + 1); // Allocate space for maxSize elements plus dummy at index 0
    }

    void insert(char value) {
        if (heapSize < arr.size() - 1) {
            heapSize++;
            arr[heapSize] = value;
            siftUp(heapSize);
        }
    }

    char findMax() {
        if (heapSize >= 1) {
            return arr[1];
        }
        return '\0'; // Return null character if the heap is empty
    }

    void removeMax() {
        if (heapSize >= 1) {
            arr[1] = arr[heapSize];
            heapSize--;
            siftDown(1);
        }
    }

    int getSize() {
        return heapSize;
    }
};

int main() {
    int maxSize, numQueries;
    string query;

    cin >> maxSize >> numQueries;

    MaxHeap heap(maxSize);

    for (int i = 0; i < numQueries; i++) {
        cin >> query;
        if (query == "insert") {
            char value;
            cin >> value;
            if (heap.getSize() < maxSize) {
                heap.insert(value);
            } else {
                cout << "Tamanho máximo atingido!" << endl;
            }
        } else if (query == "remove") {
            if (heap.getSize() == 0) {
                cout << "Heap vazia!" << endl;
            } else {
                heap.removeMax();
            }
        } else if (query == "max") {
            if (heap.getSize() == 0) {
                cout << "Não há elemento no topo." << endl;
            } else {
                cout << heap.findMax() << endl;
            }
        }
    }

    return 0;
}
