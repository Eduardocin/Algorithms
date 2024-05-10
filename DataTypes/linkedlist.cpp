#include <iostream>

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Define a LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
public:
    // Constructor to initialize the head pointer
    LinkedList() : head(nullptr) {}

    // Function to add a new node at the beginning of the list
    void insertAtBeginning(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Destructor to deallocate memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    // Create a linked list object
    LinkedList myList;

    // Insert some elements into the list
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    // Display the list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
