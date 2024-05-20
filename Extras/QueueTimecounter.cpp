#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T> *next;

    Node():next(nullptr) {}
    Node(T data):data(data),next(nullptr) {}
};

template<typename T>
struct Queue{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue() : head(new Node<T>()), tail(head), size(0) {}

    void enqueue(T data){
        tail->next = new Node<T>(data);
        tail = tail->next;
        size++;}
    
    E dequeue(){
        if(size == 0){throw runtime_error("Queue is empty");}
        E it = head->next->data;
        Node<T> *temp = head->next;
        head->next = head->next->next;
        delete temp;
        size--;
        return it;
    }

    int length(){return size;}

    void clear(){
        while(size > 0){
            dequeue();
        }
    }

    void print(){
        Node<T> *temp = head->next;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
            }
            cout << endl;
    }


};



int main(  ){
    long long int N , distance, petrol;

    cin >> N ; // number of cases




    return 0;
}