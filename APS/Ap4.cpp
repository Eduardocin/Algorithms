#include <iostream>
#include <exception>
#include <string>
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

    E remove() {
        
        if (curr->next == nullptr) { return 0; }
        
        E it = curr->next->data; // value to remove
        
        if (tail == curr->next) { tail = curr;} //verify that we removed the last element

        Node<E> *temp = curr->next; // create a pointer to the element that we are removing
        
        curr->next =  curr->next->next; // remove the element
        sizeList--;
        
        // make memory deallocation
        delete temp;
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
        if (curr == head) throw std::runtime_error(" ");

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

    int count(E value){
        int count = 0;
        Node<E> *temp = head->next; // Start from the first actual node, not the dummy header.
        while (temp != nullptr) {
            if(temp->data == value){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};



int main(){
    int c, n, value;
    string input;


    cin >> c; // number of cases
    for(int i = 0; i < c; i++){
        LinkedList<long long int> countlist;//create a list for count
        LinkedList<long long int> listint;//create a list of integers
        cin >> n;
        
        for(int j = 0; j < n; j++){
                cin >> input;
                if (input == "insert"){
                    cin >> value;
                    listint.insert(value);
                }
                else if (input == "remove"){
                    listint.remove();
                }
                else if( input == "count"){
                    int contagens = 0;
                    cin >> value;
                    contagens = listint.count(value);
                    countlist.insert(contagens);
                }
                else if(input == "next"){
                    listint.next();
                    }
                else{
                    listint.prev();
                }


                }
        // saidas apenas para os casos de count
        cout << "Caso "<< i+1 << ":" << endl;
        countlist.moveToStart();
        // move to the end of the countlist
        for(int k = 0; k < countlist.length(); k++){
            countlist.next();    
        }
        // print the values of the countlist
        for(int k = 0; k < countlist.length(); k++){
            cout << countlist.getValue() << endl;
            countlist.prev();
            }
        }
        return 0;
    }