#include <iostream>
#include <stdexcept>
using namespace std;


template<typename T>

struct Node{
    T value;
    Node *next;

    Node(): next(nullptr) {}
    Node(T value) : value(value), next(nullptr) {}
};

template<typename T>
struct Queue{
    Node<T> *front;
    Node<T> *rear;
    int size;

    Queue() {
        front = rear = new Node<T>(); // header node empty
        size = 0;
    }

    void enqueue(T item){
        Node<T> *newNode = new Node<T>(item);
        rear->next = newNode;
        rear = rear->next;
        size++;
    }

    T dequeue(){
        if(size == 0){throw std::runtime_error("Queue is empty");} // checkar se a fila está vazia
        T value = front->next->value; // store the value to be returned
        Node<T> *temp = front->next; // point to the value to be dequeued
        front->next = front->next->next;
        if (front->next == nullptr){// verify if only one element was present
            rear = front;
        }
        size--;
        delete temp;
        return value;
    }
    

};




int main(){
    
    Queue<int> q;

    // Test enqueue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Test dequeue and output the dequeued values
    cout << "Dequeued: " << q.dequeue() << endl; // should print 1
    cout << "Dequeued: " << q.dequeue() << endl; // should print 2
    cout << "Dequeued: " << q.dequeue() << endl; // should print 3

    
    return 0;

}