#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
private:
    vector<char> arr;
    int heapSize;

    void siftUp(int i) {
        while (i > 1 && arr[i / 2] < arr[i]) {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    void siftDown(int i) {
        int k = i;
        int v = arr[k];
        bool heap = false;

        while (!heap && 2 * k <= heapSize) {
            int j = 2 * k;
            if (j < heapSize) {
                if (arr[j] < arr[j + 1]) {
                    j++;
                }
            }
            if (v >= arr[j]) {
                heap = true;
            } else {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
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

    char removeMax() {
        if (heapSize >= 1) {
            char max = arr[1];
            arr[1] = arr[heapSize];
            heapSize--;
            siftDown(1);
            return max;
        }
        return '\0';
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
