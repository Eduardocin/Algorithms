#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

// Template para a classe HashTable, que pode armazenar pares chave-valor de tipos genéricos K e V
template<typename K, typename V>
class HashTable {
private:
    // Estrutura para armazenar pares chave-valor
    struct Node {
        K key;   // Chave
        V value; // Valor
        Node(){} // Construtor para inicializar chave e valor vazios
        Node(K k, V v) : key(k), value(v) {} // Construtor para inicializar chave e valor
    };

    int capacity; // Capacidade da tabela de dispersão
    int size; // Número de elementos no dicionário
    vector<list<Node>> table; // Vetor de listas para armazenar os nós
    
    int hashFunction(K key) {
        return key % 10; // Função de dispersão simples: h(k) = k mod 10
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.assign(capacity, list<Node>()); // inicializar o vetor de listas vazios
    }


    // Método para inserir um par chave-valor na tabela de dispersão
    void insert(K key, V value) {

        // Verificar se a chave já existe
        try{
            find(key);    // Se find não lançar exceção, a chave existe, então não fazemos nada
            return;
        }catch (const runtime_error&) {
            // Chave não existe, prosseguir com a inserção
        }

        int pos = hashFunction(key);     // Calcular a posição de dispersão
        auto& l = table[pos];     //  Obter a lista na posição calculada
        Node entry(key, value);         //  Criar uma nova entrada
        l.push_back(entry);         // Adicionar a nova entrada à lista
        size++;
        }

    V find(K key) {
    int index = hashFunction(key);      // Calcula o índice na tabela de dispersão usando a função de dispersão
    for (const auto& node : table[index]) {   // Itera sobre cada nó na lista localizada no índice calculado
        if (node.key == key) {    // Se a chave do nó atual for igual à chave procurada
            return node.value;     // Retorna o valor associado à chave
        }
    }
        throw runtime_error("key not find");     // Se a chave não for encontrada, lança uma exceção indicando que a chave não foi encontrada
}

    void remove(K key) {
    
    int index = hashFunction(key);     // Calcula o índice na tabela de dispersão usando a função de dispersão
    auto& list = table[index];     // Obtém a lista de nós localizada no índice calculado
    // Itera sobre cada nó na lista
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->key == key) {         // Se a chave do nó atual for igual à chave procurada
            list.erase(it);     // Remove o nó da list
            size--;
            return;
        }
    }
    // Se a chave não for encontrada, lança uma exceção indicando que a chave não foi encontrada
    throw runtime_error("Key not found");
}
    void clear() {
        table.assign(capacity, list<Node>()); // Inicializa o vetor de listas vazios
        size = 0; // Inicializa o tamanho da tabela de dispersão para 0
    }

    int getSize() {
        return size;
    }

    // Método para imprimir o conteúdo da tabela de dispersão
    void printTable() {
        for (int i = 0; i < capacity; i++) {
            cout << i << " ";
            for (const auto& node : table[i]) {
                cout << node.key << " ";
            }
            cout << endl;
        }
    }
};
