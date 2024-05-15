#include <iostream>
#include <stdexcept> // Para lançar uma exceção em caso de lista vazia

// Definição da estrutura para um nó da lista usando template
template<typename E>
struct Node {
    E data; // value store in this node
    Node* next; // reference to next node

    // Construtor
    Node(const E& data = 0, Node* nextNode = nullptr) : data(data), next(nextNode) {
        
    }
};

// Definição da estrutura para a lista ligada usando template
template<typename E>
struct LinkedList {
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int listSize;

    // Construtor
    LinkedList() : listSize(0) {
        head = tail = curr = new Node<E>(); // Criar o nó header
    }

    // Método para inserir um novo elemento na lista
    void insert(const E& data) {
        Node<E>* newNode = new Node<E>(data);
        tail->next = newNode;
        tail = newNode;
        listSize++;
    }

    // Método para remover um elemento da lista
    E remove() {
        if (curr->next == nullptr) {
            throw std::runtime_error("Tentativa de remover de uma lista vazia.");
        }
        Node<E>* removeNode = curr->next;
        E removedData = removeNode->data;
        curr->next = removeNode->next;
        if (curr->next == tail) {
            tail = curr;
        }
        delete removeNode;
        listSize--;
        return removedData;
    }

    // Métodos restantes...

    // Método para imprimir todos os elementos da lista
    void print() const {
        Node<E>* temp = head->next; // Começar a partir do primeiro elemento, não do nó cabeçalho
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Criando uma nova lista ligada de inteiros
    LinkedList<int> intList;

    // Inserir elementos na lista
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);

    // Imprimir elementos da lista
    intList.print(); // Saída: 10 20 30

    // Remover um elemento da lista e imprimir o valor removido
    int removedValue = intList.remove();
    std::cout << "Valor removido: " << removedValue << std::endl;

    // Imprimir elementos da lista após a remoção
    intList.print(); // Saída: 20 30

    return 0;
}
