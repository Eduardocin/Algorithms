#include <iostream>

using namespace std;

// create Node structure
template<typename E>
struct Node{
    E data;
    Node<E>* next;

    Node(): data(0), next(nullptr){}     // contructor for dummy node
    Node(E value, Node<E>* nextpointer): data(value), next(nextpointer){}    // constructor for node with data
};


// create LinkedList structure
template<typename E>
struct LinkedList {
    Node<E>* head;
    Node<E>* curr;
    Node<E>* tail;
    int size;

    // constructor
    LinkedList() : head(new Node<E>()), curr(head), tail(head), size(0) {}

    void insert(E data) {
        curr->next = new Node<E>(data, curr->next); // create a new node to insert the value
        if (tail == curr) { tail = curr->next; } // check if there is only one node
        size++;
    }

    void prev() {
        if (curr == head) { throw runtime_error("No previous element"); }
        Node<E>* temp = head;
        while (temp->next != curr) { temp = temp->next; }
        curr = temp;
    }

    void print() {
        Node<E>* temp = head->next;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    E remove() {
        if (curr->next == nullptr) { return NULL; }
        E data = curr->next->data; // store the value to be removed
        if (tail == curr->next) { tail = curr; } // check if removing the last element
        Node<E>* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return data;
    }
}; 


int main(){
    LinkedList<int> list;

    cout << "Hello world" << endl;


    return 0;
}