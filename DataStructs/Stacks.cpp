#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data; 
    Node *next;

    Node(T value, Node* nextNode = NULL) : data(value), next(nextNode) {}
};



template<typename T>
struct Stack{
private:
    Node<T> *top;
    int size;

public:
    //constructor function
    Stack() : top(NULL) , size(0){}

    void push(T it){
        Node<T>* newNode = new Node<T>(it, top);
        top = newNode;
        size++;
    };

    T topValue(){
        if( top == nullptr ) throw std::runtime_error(" Stack is empty");
        return top->data;
    }

    int length(){
        return size;
    }

    T pop(){
        if( top == nullptr ) throw std::runtime_error(" Stack is empty");
        T it = top->data;// salva o valor a ser removido
        Node<T> *temp = top; // armazena o ponteiro para o valor removido
        top = top->next; // avança para o proxímo nó
        size--;
        delete temp; // libera memoria
    
        return it;
    };

};


int main(){
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    // Pop and print each element from the stack
    while (stack.size > 0) {
        cout << "Popped element: " << stack.pop() << endl;
    }
    return 0;
}