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

// Template class for a Heap
template<typename K, typename V>
class Heap {
private:
    // Internal structure to represent a node in the heap
    struct Node {
        K key;    // Key of the node
        V value;  // Value of the node

        // Constructor for Node
        Node(K key, V value) : key(key), value(value) {}
    };

    vector<Node> arr;  // Vector to store heap elements
    int maxSize;       // Maximum size of the heap

    // Function to maintain heap property from bottom to top
    void heapifyUp(int index) {
        if (index <= 1) return; // If the node is the root, return

        int parentIndex = index / 2; // Calculate parent index
        // If the current node's key is greater than the parent's key, swap them
        if (arr[index].key > arr[parentIndex].key) {
            swap(arr[index], arr[parentIndex]);
            heapifyUp(parentIndex); // Recursively heapify the parent
        }
    }

    // Function to maintain heap property from top to bottom
    void heapifyDown(int index) {
        int leftChild = 2 * index;       // Index of left child
        int rightChild = 2 * index + 1;  // Index of right child
        int largest = index;             // Assume current node is the largest

        // If left child exists and is greater than the current largest, update largest
        if (leftChild < arr.size() && arr[leftChild].key > arr[largest].key) {
            largest = leftChild;
        }

        // If right child exists and is greater than the current largest, update largest
        if (rightChild < arr.size() && arr[rightChild].key > arr[largest].key) {
            largest = rightChild;
        }

        // If the largest is not the current node, swap and heapify down
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor for Heap
    Heap(int maxSize) : maxSize(maxSize) {
        arr.push_back(Node(K(), V())); // Placeholder for index 0
    }

    // Function to find the maximum element in the heap
    V findMax() {
        if (arr.size() > 1) {
            return arr[1].value; // Return the value of the root node
        } else {
            throw runtime_error("Não há elemento no topo."); // Throw error if heap is empty
        }
    }

    // Function to remove and return the maximum element in the heap
    V removeMax() {
        if (arr.size() > 1) {
            Node max = arr[1]; // Store the root node
            arr[1] = arr[arr.size() - 1]; // Replace root with the last element
            arr.pop_back(); // Remove the last element
            heapifyDown(1); // Heapify down from the root
            return max.value; // Return the value of the removed node
        } else {
            throw runtime_error("Heap vazia!"); // Throw error if heap is empty
        }
    }

    // Function to add a new element to the heap
    void add(K key, V value) {
        if (arr.size() - 1 >= maxSize) 
            throw(runtime_error("Tamanho máximo atingido!")); // Throw error if heap is full
        else {        
            arr.push_back(Node(key, value)); // Add new node to the end
            heapifyUp(arr.size() - 1); // Heapify up from the last element
        }
    }

    // Function to print the keys of the heap
    void printHeap() {
        for (int i = 1; i < arr.size(); ++i) {
            cout << arr[i].key << " "; // Print each key
        }
        cout << endl;
    }
};