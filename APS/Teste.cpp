#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> arr;
    int heapSize;

        // void heapify(int i) { // Corrected heapify function
        //     int largest = i; 
        //     int left = 2 * i; 
        //     int right = 2 * i + 1;

        //     if (left <= heapSize && arr[left] > arr[largest]) {
        //         largest = left;
        //     }

        //     if (right <= heapSize && arr[right] > arr[largest]) {
        //         largest = right;
        //     }

        //     if (largest != i) {
        //         swap(arr[i], arr[largest]);
        //         heapify(largest); // Recursively heapify the affected subtree
        //     }
        // }

    void heapifyUp(int i) {
    while (i > 1 && arr[i] > arr[i / 2]) { 
        swap(arr[i], arr[i / 2]);
        i /= 2; 
    }
}

public:
    MaxHeap() : heapSize(0) {
        arr.push_back(0); // Dummy element at index 0
    }

    void insert(int value) {
        arr.push_back(value);
        heapSize++;
        heapifyUp(heapSize); // Heapify from the newly inserted node
    }

    ~MaxHeap() {}

    int findMax() {
        return arr[1];
    }

    int removeMax() {
        int max = arr[1];
        arr[1] = arr[heapSize]; 
        arr[heapSize] = max;
        heapSize--;
        heapifyUp(heapSize); // Heapify from the root after removing the max
        return max;
    }

    void heapSort() {
        int initialSize = heapSize;
        for (int i = 1; i <= initialSize; i++) {
            removeMax();
        }
        heapSize = initialSize;
    }

    void print() {
        for (int i = 1; i <= heapSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Inserting values into the heap
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);

    // Printing the heap
    cout << "Heap after insertions: ";
    heap.print();

    // Finding the maximum
    cout << "Maximum value in the heap: " << heap.findMax() << endl;

    // Removing the maximum
    cout << "Removing the maximum: " << heap.removeMax() << endl;

    // Printing the heap after removing the maximum
    cout << "Heap after removing the maximum: ";
    heap.print();

    // Sorting the heap
    heap.heapSort();

    // Printing the heap after sorting
    cout << "Heap after sorting: ";
    heap.print();

    return 0;
}