#include <iostream>
#include <string.h>


using namespace std;
template<typename T>
struct Node{
    T data;
    Node<T> *next;


    Node(): next(nullptr){};
    Node(T value, Node<T> *nextptr): data(value), next(nextptr){}; 

};

template<typename T>
struct Linkedlist{
private:
    Node<T> *head;
    Node<T> *curr;
    Node<T> *tail;
    int size;
public:
    Linkedlist(): head(new Node<T>()), curr(head), tail(head), size(0){};

    void insert(T value){
        curr->next = new Node<T>(value, curr->next);
        if(tail == curr){tail = curr->next;}
        size++;
        curr = curr->next; // move to the next node
    }

    void moveToEnd(){
        curr = tail;
    }

    void moveToStart(){
        curr = head;
    }

    void next(){
        if(curr != tail){curr = curr->next;}
    }

    void print(){
        Node<T> *temp = head->next;
        while(temp!= nullptr){
            cout << temp->data;
            temp = temp->next;
        }
    }

};


int main() {
    Linkedlist<char> list;
    char frase[100001];

    while (scanf("%s", frase) != EOF) {
        list = Linkedlist<char>();
        int range = strlen(frase);
        for (int i = 0; i < range; i++) {
            if (frase[i] == '[') {
                list.moveToStart();
            } else if (frase[i] == ']') {
                list.moveToEnd();
            } else {
                list.insert(frase[i]);
            }
        }
        list.print();
        cout << endl; // Print each result on a new line
    }

    return 0;
}