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



public:
    // Constructor for Heap
    Heap() :  {
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
        else {        
            arr.push_back(Node(key, value)); // Add new node to the end
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