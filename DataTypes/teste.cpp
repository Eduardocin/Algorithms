#include <iostream>

using namespace std;

template<typename E>
struct Node {
    E data;
    Node *next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(E value, Node *next) {
        data = value;
        this->next = next; // Use "this->next" to refer to the member variable.
    }
};

template<typename E>
struct LinkedList {
    Node<E> *head;
    Node<E> *tail;
    Node<E> *curr;
    int sizeList; 
    
    
    LinkedList() {
        head = tail = curr = new Node<E>();
        sizeList = 0;
    }

    void insert(E value) {
        Node<E> *newNode = new Node<E>(value, curr->next);
        curr->next = newNode;
        if (tail->next == curr) {
            tail = curr->next;
        }
        curr = curr->next; // Move "curr" to the newly inserted node.
        sizeList++;
    }

    E remove(int index) {
        
        if (curr->next == nullptr) { return nullptr; }
        
        E it = curr->next->data;
        if (tail == curr->next) { tail = curr;}
        curr->next =  curr->next->next;
        sizeList--;
        // make memory deallocation
        delete curr->next;
        curr->next = nullptr;
        //return value removed
        return it;
    }


    void moveToStart(){
        curr = head;
    }
    void prev(){
        if (curr == head) throw std::error_condition("");

        Node<E> *temp = head;
        while (temp->next!= curr) {
            temp = temp->next;
        }
        curr = temp;
    }
    
    void next(){
        if(curr != tail){
            curr = curr->next;
        }
    }

    void print() {
        Node<E> *temp = head->next; // Start from the first actual node, not the dummy header.
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.print(); // Print the list.
    cout << "Size of list: " << list.sizeList << endl;

    return 0;
}
