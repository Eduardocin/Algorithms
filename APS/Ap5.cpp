#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename E>
struct Node {
    E data;
    Node<E> *next;

    Node() : data(0), next(nullptr) {}
    Node(E data, Node<E> *nextpointer = nullptr) : data(data), next(nextpointer) {}
};

template <typename E>
struct Queue {
private:
    Node<E> *head;
    Node<E> *tail;
    int size;

public:
    Queue() : head(new Node<E>()), tail(head), size(0) {} // create a header node empty

    void enqueue(E value) {
        Node<E> *newNode = new Node<E>(value);
        tail->next = newNode;
        tail = tail->next;
        size++;
    }

    E dequeue() {
        if (size == 0) {
            throw std::runtime_error("Queue is empty");
        }
        E value = head->next->data;
        Node<E> *temp = head->next;
        head->next = head->next->next;
        if (head->next == nullptr) {
            tail = head;
        }
        size--;
        delete temp;
        return value;
    }

    void clear() {
        while (size > 0) {
            dequeue();
        }
    }

    E frontValue() {
        return head->next->data;
    }

    int length() {
        return size;
    }
};

template <typename E>
struct Stack {
private:
    Node<E> *top; // reference to the first element
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(E it) {
        top = new Node<E>(it, top);
        size++;
    }

    E pop() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty");
        }
        E it = top->data;
        Node<E> *temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }

    void clear() {
        while (top != nullptr) {
            Node<E> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    E topValue() const {
        if (top == nullptr) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    int length() const {
        return size;
    }
};

int main() {
    int c, value, contador; // number of cases
    string inputs;
    cin >> c;
    for (int i = 0; i < c; i++) {
        Stack<int> s;
        contador = 0;
        Queue<int> q;

        while (true) {
            cin >> inputs;
            if (inputs == "end") {
                break;
            }
            if (inputs == "push") {
                cin >> value;
                s.push(value);
            } else if (inputs == "pop") {
                cin >> value;
                for (int j = 0; j < value; j++) {
                    contador += s.pop();
                }
                q.enqueue(contador);
                contador = 0; // Reset contador after each pop operation
            }
        }
        cout << "Caso " << i + 1 << ":" << endl;
        while (q.length() > 0) {
            cout << q.dequeue() << endl;
        }
    }

    return 0;
}