#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Define the Stack class
class Stack {
private:
    Node* top;
    int length;

public:
    // Constructor
    Stack() : top(nullptr), length(0) {}

    // Clear the stack
    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        length = 0;
    }

    // Push an element onto the stack
    void push(int it) {
        Node* newNode = new Node(it);
        newNode->next = top;
        top = newNode;
        length++;
    }

    // Pop an element from the stack
    int pop() {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        length--;
        return value;
    }

    // Get the top value of the stack
    int topValue() const {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    // Get the length of the stack
    int getLength() const {
        return length;
    }
};

// Example usage
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top value: " << stack.topValue() << std::endl;
    std::cout << "Stack length: " << stack.getLength() << std::endl;

    std::cout << "Popping: " << stack.pop() << std::endl;
    std::cout << "New top value: " << stack.topValue() << std::endl;

    stack.clear();
    return 0;
}
