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
        curr->next = newNode; // point to the next node value.
        if (tail == curr) {
            tail = curr->next;
        }    
        sizeList++;
    }

    E remove(int index) {
        
        if (curr->next == nullptr) { return nullptr; }
        
        E it = curr->next->data; // value to remove
        
        if (tail == curr->next) { tail = curr;} //verify that we removed the last element

        Node<E> *temp = curr->next; // create a pointer to the element that we are removing
        
        curr->next =  curr->next->next; // remove the element
        sizeList--;
        
        // make memory deallocation
        delete temp;
        temp = nullptr;
        //return value removed
        return it;
    }

void clear(){
    Node<E> *temp = head->next;
    while (temp!= nullptr) {
        Node<E> *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head = tail = curr = new Node<E>();
    sizeList = 0;
}

    int length(){
        return sizeList;
    }

    E getValue(){
        return curr->data;
    }

    void moveToStart(){
        curr = head;
    }
    void prev(){
        if (curr == head) throw std::error_condition(" ");

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
    list.next();
    list.insert(2);
    list.print(); // Print the list.
    cout << "Size of list: " << list.length() << endl;

    return 0;
}
