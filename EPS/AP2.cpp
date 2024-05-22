#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;

    Node(): next(nullptr){}
    Node(T value): data(value), next(nullptr){} 
};

template<typename T>
struct Queue{
private:
    Node<T>* front;
    Node<T>* rear;
    int size;
public:
    Queue(): front(new Node<T>()), rear(front), size(0){}

    void enqueue(T it){
        rear = rear->next = new Node<T>(it);
        size++;
    } 
    
    T dequeue(){
        if(size == 0){return -1;}
        Node<T> *temp = front->next;
        T it = front->next->data;
        front->next = front->next->next;
        if(front->next == nullptr){rear = front;}
        size--;
        delete temp;
        return it;
    }

    int length(){
        return size;
    }

    void print(){
        Node<T>* temp = front->next;
        while(temp != nullptr){
            if(temp->next == nullptr){
                cout << temp->data;
                temp = temp->next;
            }
            else{
            cout << temp->data << " ";
            temp = temp->next;
            }
            }
        
    }

};


int main(){
    string inp;
    int value, solved;
    Queue<int> q;
    
    
    bool check = true;
    while(check){
        cin >> inp;
        
        if (inp == "end"){
            check = false;
        }

        if(inp == "add"){
            cin >> value;
            q.enqueue(value);
        }else if(inp == "solve"){
            if(q.length() > 0){
                q.dequeue();
                solved +=1;
                }
        }else if (inp == "print"){
            if(q.length()>0){
                q.print();
                cout << endl;
            }
            else{cout << "x" << endl;}
        }else if(inp == "stats"){
            cout << solved << " " << q.length();
            cout << endl;
        }

    }
    return 0;
}