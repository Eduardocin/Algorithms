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


template<typename K, typename V>
class Heap {
private:
    struct Node {
        K key;
        V value;

        Node(K key, V value) : key(key), value(value) {}
    };

    vector<Node> arr;

    void heapify(int index) {
        if (index <= 1) return; // If it's the root, no need to heapify up

        int parentIndex = index / 2;
        if (arr[index].key > arr[parentIndex].key) {
            swap(arr[index], arr[parentIndex]);
            heapify(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild < arr.size() && arr[leftChild].key > arr[largest].key) {
            largest = leftChild;
        }

        if (rightChild < arr.size() && arr[rightChild].key > arr[largest].key) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    Heap() {
        arr.push_back(Node(K(), V())); // Placeholder for index 0
    }

    V findMax() {
        if (arr.size() > 1) {
            return arr[1].value;
        }
    }

    V removeMax() {
        if (arr.size() > 1) {
            Node max = arr[1];
            arr[1] = arr[arr.size() - 1];
            arr.pop_back();
            heapifyDown(1);
            return max.value;
        }
    }

    void add(K key, V value) {
        arr.push_back(Node(key, value));
        heapify(arr.size() - 1);
    }

    void printHeap() {
        for (int i = 1; i < arr.size(); ++i) {
            cout << arr[i].key << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap<int, string> heap;\
    heap.add(7, "seven");
    heap.add(10, "ten");
    heap.add(8, "eight");
    heap.add(5, "five");
    heap.add(2, "two");
    heap.add(1, "one");
    heap.add(6, "six");
    heap.add(3, "three");
    heap.add(5, "five");
    heap.add(1, "one");

    heap.printHeap(); // Should print the heap in a max-heap order

    cout << "Max value: " << heap.findMax() << endl; // Should print the max value
    cout << "Removed max value: " << heap.removeMax() << endl; // Should print and remove the max value

    heap.printHeap(); // Should print the heap after removal

    return 0;
}