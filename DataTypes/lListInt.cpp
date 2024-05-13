#include <iostream>

// Definição da estrutura para um nó da lista
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Definição da estrutura para a lista ligada
struct LinkedList {
    Node* head;
    Node* tail;
    Node* curr;
    int count;

    // Construtor
    LinkedList() : head(nullptr), tail(nullptr), curr(nullptr), count(0) {}

    // Método para inserir um novo elemento na lista
    void insert(int data) {
        Node* newNode = new Node(data);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        count++;
    }

    // Método para remover um elemento da lista
    bool remove() {
        if (curr == nullptr || curr->next == nullptr) {
            return false;
        }
        Node* removeNode = curr->next;
        curr->next = removeNode->next;
        if (removeNode == tail) {
            tail = curr;
        }
        delete removeNode;
        count--;
        return true;
    }

    // Método para mover o cursor para o início da lista
    void moveToStart() {
        curr = head;
    }

    // Método para mover o cursor para o final da lista
    void moveToEnd() {
        curr = tail;
    }

    // Método para mover o cursor para o próximo nó
    void next() {
        if (curr != nullptr) {
            curr = curr->next;
        }
    }

    // Método para obter o tamanho da lista
    int length() const {
        return count;
    }

    // Método para imprimir todos os elementos da lista
    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    // Inserir elementos na lista
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Imprimir elementos da lista
    list.print(); // Saída: 10 20 30

    // Remover um elemento da lista
    list.moveToStart();
    list.next(); // Mover para o segundo nó
    list.remove();

    // Imprimir elementos após a remoção
    list.print(); // Saída: 10 30

    return 0;
}
