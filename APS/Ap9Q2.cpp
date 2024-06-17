#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class MaxHeap {
private:
    vector<T> arr;
    int heapSize;

    void heapfyUp() {
        int i = heapSize;
        T parent = arr[i / 2];
        while (i > 1 && parent < arr[i]) {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    void heapfy() {
        for(int i = heapSize / 2; i > 0; i--) {
            int k = i;
            T v = arr[k];
            bool heap = false;

            while (!heap && 2 * k <= heapSize) {
                int j = 2 * k;
                if (j < heapSize){
                    if(arr[j] < arr[j + 1]) {
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
    }   

public:
    MaxHeap(int maxSize) : heapSize(0) {
        arr.resize(maxSize + 1); // Allocate space for maxSize elements plus dummy at index 0
    }

    void insert(T value) {
        if (heapSize < arr.size() - 1) {
            heapSize++;
            arr[heapSize] = value;
            heapfyUp();
        }
    }

    T findMax() {
        if (heapSize >= 1) {
            return arr[1];
        }
        return T(); // Return default value if the heap is empty
    }

    T removeMax() {
        if (heapSize >= 1) {
            T max = arr[1];
            arr[1] = arr[heapSize];
            heapSize--;
            heapfy();
            return max;
        }
        return T();
    }

    int getSize() {
        return heapSize;
    }
};

int main() {
    int maxSize, numQueries;
    string query;

    cin >> maxSize >> numQueries;

    MaxHeap<char> heap(maxSize);

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
