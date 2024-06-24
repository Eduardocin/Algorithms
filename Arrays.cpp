#include <iostream>
#include <vector>

using namespace std;

// Max heap
template<typename T>
class MaxHeap {
private:
    vector<T> arr;
    int heapSize;

    void heapifyDown() {
        for (int i = heapSize / 2; i >= 1; i--) {
            int k = i;
            T v = arr[k];
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
    }

    void heapifyUp() {
        int k = heapSize;
        T v = arr[k];

        while (k > 1 && v > arr[k / 2]) {
            arr[k] = arr[k / 2];
            k = k / 2;
        }
        arr[k] = v;
    }

public:
    MaxHeap() : heapSize(0) {
        arr.push_back(0);
    }

    ~MaxHeap() {}

    T getMax() {
        return arr[1];
    }

    int getSize() {
        return heapSize;
    }

    void printHeap() {
        for (int i = 1; i <= heapSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T deleteMax() {
        T max = arr[1];

        arr[1] = arr[heapSize];
        arr[heapSize] = max;
        heapSize--;
        heapifyDown();
        return max;
    }

    void heapsort() {
        int initialSize = heapSize;
        for (int i = heapSize; i >= 1; i--) {
            arr[i] = deleteMax();

            if (heapSize > 0) {
                printHeap();
            }
        }
        heapSize = initialSize;
    }

    void printInverse() {
        for (int i = heapSize; i >= 1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(T value) {
        arr.push_back(value);
        heapSize++;
        heapifyUp();
    }
};

int main() {
    int tam_heap, numcasos;
    cin >> tam_heap >> numcasos; // Read number of test cases

    MaxHeap<char>* heap = new MaxHeap<char>();

    for (int i = 0; i < numcasos; i++) {
        string query;
        cin >> query;

        if (query == "insert") {
            char value;
            cin >> value;
            if (heap->getSize() == tam_heap) {
                cout << "Tamanho máximo atingido!" << endl;
            } else {
                heap->insert(value);
            }
        } else if (query == "remove") {
            if (heap->getSize() == 0) {
                cout << "Heap vazia!" << endl;
            } else {
                heap->deleteMax();
            }
        } else if (query == "max") {
            if (heap->getSize() == 0) {
                cout << "Não há elemento no topo." << endl;
            } else {
                cout << heap->getMax() << endl;
            }
        }
    }
    delete heap;
    return 0;
}