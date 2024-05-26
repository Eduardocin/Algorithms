#include <iostream>
#include <string>
#include <Windows.h>

#define TABLE_SIZE 100

using namespace std;

// Estrutura para armazenar os elementos da tabela hash
template <typename K, typename V>
struct HashEntry {
    K key;
    V value;
    bool isDeleted;

    HashEntry() : key(), value(), occupied(false) {}
};


// Classe para a tabela hash com sondagem linear
template <typename K, typename V>
class ClosedHashTable {
private:
    HashEntry<K, V> table[TABLE_SIZE];

    // Função hash simples
    int hashFunction(K key) {
        return static_cast<int>(key) % TABLE_SIZE;
    }

    //hash function for strings
    int hashFunction(string key) {
        int s = sizeof(key)/sizeof(key[0]);
        int sum = 0;
        for (int i = 0; i < s; i++) {
            sum += key[i];
        }
        return abs(sum) % TABLE_SIZE;

public:

    void linearProbing(K key, V value) {
        
    // Insere um elemento na tabela hash
    void insert(K key, V value) {
        int hash = hashFunction(key);
        int initialHash = hash; // Guarda o hash inicial para detecção de loop

        while (table[hash].occupied) {
            if (table[hash].key == key) {
                // Atualiza o valor se a chave já existir
                table[hash].value = value;
                return;
            }
            hash = (hash + 1) % TABLE_SIZE;
            if (hash == initialHash) {
                // A tabela está cheia
                cout << "Tabela hash cheia!" << endl;
                return;
            }
        }

        // Insere o novo elemento
        table[hash].key = key;
        table[hash].value = value;
        table[hash].occupied = true;
    }

    // Busca um elemento na tabela hash
    V find(K key) {
        int hash = hashFunction(key);
        int initialHash = hash;

        while (table[hash].occupied) {
            if (table[hash].key == key) {
                // Retorna o valor se a chave for encontrada
                return table[hash].value;
            }
            hash = (hash + 1) % TABLE_SIZE;
            if (hash == initialHash) {
                break; // Evita loops infinitos
            }
        }

        // Se a chave não for encontrada
        return V();
    }

    // Remove um elemento da tabela hash
    void remove(K key) {
        int hash = hashFunction(key);
        int initialHash = hash;

        while (table[hash].occupied) {
            if (table[hash].key == key) {
                // Remove o elemento se a chave for encontrada
                table[hash].occupied = false;
                return;
            }
            hash = (hash + 1) % TABLE_SIZE;
            if (hash == initialHash) {
                break; // Evita loops infinitos
            }
        }

        cout << "Chave não encontrada para remoção!" << endl;
    }
};


int main() {
    ClosedHashTable<int, string> hashTable;
    // Configura a codificação de caracteres para UTF-8
	SetConsoleOutputCP(CP_UTF8);

    // Exemplo de inserção
    hashTable.insert(1, "Valor1");
    hashTable.insert(2, "Valor2");

    // Exemplo de busca
    cout << "Valor encontrado: " << hashTable.find(1) << endl;

    // Exemplo de remoção
    hashTable.remove(1);
    cout << "Após remoção: " << hashTable.find(1) << endl;

    return 0;
}