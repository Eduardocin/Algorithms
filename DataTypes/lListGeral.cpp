#include <iostream>

// Definição da estrutura para um nó da lista usando template
template<typename E>
struct Node {
    E data; // value store in this node
    Node* next; // reference to next node

    Node(E data) : data(data), next(nullptr) {}
};

// Definição da estrutura para a lista ligada usando template
template<typename E>
struct LinkedList {
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int count;

    // Construtor
    LinkedList() : head(nullptr), tail(nullptr), curr(nullptr), count(0) {}

    // Método para inserir um novo elemento na lista
    void insert(E data) {
        Node<E>* newNode = new Node<E>(data);
        if (tail != curr) {
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
        if (curr->next == nullptr) {
            return NULL;
        }
        Node<E>* removeNode = curr->next;
        curr->next = removeNode->next;
        if (curr->next == tail) {
            tail = curr;
        }
        delete removeNode;
        count--;
        return  ;
    }

    // Método para mover o cursor para o início da lista
    void moveToStart() {
        curr = head;
    }

    // Método para mover o cursor para o final da lista
    void prev() {
        if (curr == head ){ 
            Node *temp = head;
            while (temp->next!= curr) {
                temp = temp->next;
            }
            curr = temp;
            }
    }

    // Método para mover o cursor para o próximo nó
    void next() {
        if (curr != tail ) { curr = curr->next; }
    }

    // Método para obter o tamanho da lista
    int length() const {
        return count;
    }

    // Método para imprimir todos os elementos da lista
    void print() const {
        Node<E>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Instanciando uma lista ligada para inteiros
    LinkedList<int> intList;

    // Inserir elementos na lista
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);

    // Imprimir elementos da lista
    intList.print(); // Saída: 10 20 30

    // Instanciando uma lista ligada para strings
    LinkedList<std::string> stringList;

    // Inserir elementos na lista
    stringList.insert("Copilot");
    stringList.insert("é");
    stringList.insert("incrível!");

    // Imprimir elementos da lista
    stringList.print(); // Saída: Copilot é incrível!

    return 0;
}
