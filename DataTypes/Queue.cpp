#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T> *next;

    Node(): next(nullptr) {}
    Node(T data): data(data), next(nullptr) {}
};

template<typename T>
struct Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;


    Queue(): head(new Node<T>()), tail(head), size(0) {}//create a header node empty

    void enqueue(T value){
        Node<T> *newNode = new Node<T>(value);
        tail->next = newNode;
        tail = tail->next;
        size++;
    }

    T dequeue(){
        if(size == 0){throw std::runtime_error("Queue is empty");}
        T value = head->next->data;
        Node<T> *temp = front->next;
        front->next = front->next->next;
        if(front->next == nullptr){tail = head;}
        size--;
        delete temp;
        return value;
    }
};



int main()
{
    
    return 0;
}