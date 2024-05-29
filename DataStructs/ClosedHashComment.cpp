#include <string> 
#include <iostream> 
#include <vector> 
#include <stdexcept> 

using namespace std; // Usa o namespace padrão

template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key; // Chave da entrada
        V value; // Valor da entrada
        bool isEmpty; // Indica se a entrada está vazia
        bool isRemoved; // Indica se a entrada foi removida
        Entry() : isEmpty(true), isRemoved(false) {} // Construtor padrão
        Entry(K key, V value) : key(key), value(value), isEmpty(false), isRemoved(false) {} // Construtor com parâmetros
    };

    int capacity; // Capacidade da tabela hash
    int size; // Tamanho atual da tabela hash
    vector<Entry> table; // Vetor que representa a tabela hash

    int hashFunction(K key) {
        // Função de dobra para calcular o hash
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += int(key[i]); // Soma os valores ASCII dos caracteres da chave
        }
        return abs(sum) % capacity; // Retorna o hash calculado
    }

    int linearProbing(int hash, int i) {
        // Função de probing linear
        return (hash + i) % capacity; // Calcula a próxima posição
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        // Inicializa a tabela hash com a capacidade fornecida
        table.assign(capacity, Entry()); // Preenche o vetor com entradas vazias
    }

    void insert(K key, V value) {
        
        if (size < capacity) {
            try {
                find(key); // Verifica se a chave já existe
                return; // Se a chave já existe, não faz nada
            } catch (runtime_error& e) {
                // Se a chave não for encontrada, continua com a inserção
            }

            int hash = hashFunction(key); // Calcula o hash da chave
            int pos = hash; // Posição inicial é o hash calculado
            int i = 0; // Contador para probing linear
        
                // Procura posição para inserir
            while (!table[pos].isEmpty && !table[pos].isRemoved) {
                pos = linearProbing(hash, ++i); // Calcula a próxima posição
            }
            

            table[pos] = Entry(key, value); // Insere a nova entrada
            table[pos].isRemoved = false; // Certifica-se de que a entrada não está marcada como removida
            table[pos].isEmpty = false; // Certifica-se de que a entrada não está marcada como vazia
            size++; // Incrementa o tamanho da tabela
        
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            table[i] = Entry(); // Limpa todas as entradas da tabela
        }
        size = 0; // Reseta o tamanho da tabela
    }

    V find(K key) {
        int hash = hashFunction(key); // Calcula o hash da chave
        int pos = hash; // Posição inicial é o hash calculado
        int i = 0; // Contador para probing linear

        while (!table[pos].isEmpty) {
            if (!table[pos].isRemoved && table[pos].key == key) {
                return table[pos].value; // Retorna o valor se a chave for encontrada
            }
            pos = linearProbing(hash, ++i); // Calcula a próxima posição usando probing linear
        }

        throw runtime_error("Key not found"); // Lança exceção se a chave não for encontrada
    }

    void remove(K key) {
        int hash = hashFunction(key); // Calcula o hash da chave
        int pos = hash; // Posição inicial é o hash calculado
        int i = 0; // Contador para probing linear

        while (!table[pos].isEmpty) {
            if (!table[pos].isRemoved && table[pos].key == key) {
                table[pos].isRemoved = true; // Marca a entrada como removida
                size--; // Decrementa o tamanho da tabela
                return;
            }
            pos = linearProbing(hash, ++i); // Calcula a próxima posição usando probing linear
        }

        throw runtime_error("Key not found"); // Lança exceção se a chave não for encontrada
    }
};

int main() {
    HashTable<string, string> teste(10); // Inicializa a tabela hash com a capacidade fornecida

    teste.insert("abcd", "1234");
    teste.insert("badc", "1234");
    teste.insert("abdc", "1234");
    teste.insert("bacd", "1224");
    cout << teste.find("bacd")<< endl;
    teste.remove("abdc");
    cout << teste.find("bacd")<< endl;
    teste.insert("abdc", "1233");

    return 0;
}