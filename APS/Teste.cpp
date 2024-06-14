#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/*
Shape property: a complete binary tree
Parental dominance: each node key is ≥/≤ than the childrens key
If ≥: max-heap
If ≤: min-heap
*/

class MaxHeap {
private:
    vector<char> arr;
    int maxSize;

    void heapifyUp(int index) {
        if (index <= 1) return; // If it's the root, no need to heapify up

        int parentIndex = index / 2;
        if (arr[index] > arr[parentIndex]) {
            swap(arr[index], arr[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild < arr.size() && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        if (rightChild < arr.size() && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int maxSize) : maxSize(maxSize) {
        arr.push_back('\0'); // Placeholder for index 0
    }

    char findMax() {
        if (arr.size() > 1) {
            return arr[1];
        } else {
            throw runtime_error("Não há elemento no topo.");
        }
    }

    char removeMax() {
        if (arr.size() > 1) {
            char max = arr[1];
            arr[1] = arr[arr.size() - 1];
            arr.pop_back();
            heapifyDown(1);
            return max;
        } else {
            throw runtime_error("Heap vazia!");
        }
    }

    void add(char value) {
        if (arr.size() - 1 >= maxSize) {
            throw runtime_error("Tamanho máximo atingido!");
        } else {
            arr.push_back(value);
            heapifyUp(arr.size() - 1);
        }
    }

    void printHeap() {
        for (int i = 1; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int sizeheap, numCommands;
    string command;
    char value;

    cin >> sizeheap >> numCommands;
    MaxHeap heap(sizeheap);

    for (int i = 0; i < numCommands; ++i) {
        cin >> command;
        if (command == "insert") {
            cin >> value;
            try {
                heap.add(value);
            } catch (runtime_error &e) {
                cout << e.what() << endl;
            }
        } else if (command == "max") {
            try {
                cout << heap.findMax() << endl;
            } catch (runtime_error &e) {
                cout << e.what() << endl;
            }
        } else if (command == "remove") {
            try {
                heap.removeMax();
            } catch (runtime_error &e) {
                cout << e.what() << endl;
            }
        }
    }

    return 0;
}