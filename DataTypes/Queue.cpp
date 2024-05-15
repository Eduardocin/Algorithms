#include <iostream>

template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T val) : value(val), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int length;

public:
    Queue() : front(nullptr), rear(nullptr), length(0) {}

    ~Queue() {
        clear();
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node<T>* temp = front;
        T value = front->value;
        front = front->next;
        delete temp;
        length--;
        if (isEmpty()) {
            rear = nullptr;
        }
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->value;
    }

    bool isEmpty() const {
        return length == 0;
    }

    int size() const {
        return length;
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element is: " << queue.peek() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    return 0;
}
