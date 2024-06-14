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
    int maxSize;

    void heapifyUp(int index) {
        if (index <= 1) return; // check if root

        int parentIndex = index / 2;
        if (arr[index].key > arr[parentIndex].key) {
            swap(arr[index], arr[parentIndex]);
            heapifyUp(parentIndex);
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
    Heap(int maxSize) : maxSize(maxSize) {
        arr.push_back(Node(K(), V())); // Placeholder for index 0
    }

    
    V findMax() {
        if (arr.size() > 1) {
            return arr[1].value;
        }
        else{
            throw runtime_error("Não há elemento no topo.");
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
        else{
            throw runtime_error("Heap vazia!");
        }
    }

    void add(K key, V value) {
        if(arr.size() - 1 >= maxSize) 
            throw(runtime_error("Tamanho máximo atingido!"));
        else{        
            arr.push_back(Node(key, value));
            heapifyUp(arr.size() - 1);
        }
    }

    void printHeap() {
        for (int i = 1; i < arr.size(); ++i) {
            cout << arr[i].key << " ";
        }
        cout << endl;
    }
};


int main(){
    int sizeheap, numCommands;
    string command;
    char value;
    
    cin >> sizeheap >> numCommands;
    Heap<char,char>* heap = new Heap<char,char>(sizeheap);

    for(int i = 0; i < numCommands; ++i){
        cin >> command;
        if(command == "insert"){
            cin >> value;
            try{
                heap->add(value, value);
            }catch(runtime_error &e){
                cout << e.what() << endl;
            }
        }
        else if(command == "max"){
            try{
                cout << heap->findMax() << endl;
            }
            catch(runtime_error &e){
                cout << e.what() << endl;
            }
        }
        else if(command == "remove"){
            try{
                heap->removeMax();
            }
            catch(runtime_error &e){
                cout << e.what() << endl;
            }
        }
    }

    delete heap;
    return 0;
}