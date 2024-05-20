#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *next;

    Node(T value, Node<T> *nextptr = nullptr): data(value), next(nextptr){}
};

template <typename T>
struct Stack{
private:    
    Node<T> *top;
    int size;

public:
    Stack(): top(nullptr), size(0){}

    void push(T data){
        top = new Node<T>(data, top);
        size++;
    }
    
    T pop(){
        if(top == nullptr){throw std::out_of_range("Stack is empty");}
        T data = top->data;
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    T maxElement(){
        Node<T> *temp = top;
        T max = top->data;
        while(temp!= nullptr){
            if(temp->data > max){max = temp->data;}
            temp = temp->next;
        }
        return max;
    }

};

int main(){
    int n, type;
    long long int x;
    
    Stack<int> s;
    cin >> n; //cases
    for(int i = 0; i < n; i++){
        cin >> type;
        if(type == 1){
            cin >> x;
            s.push(x);
        }
        else if(type == 2){
            s.pop();
        }
        else if(type == 3){
            cout << s.maxElement() << endl;
            }
    }

    return 0;
}