#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Implementation of closed hash table with linear probing
template <typename K, typename V>
class HashTable {
private:
    // Structure to hold key-value pairs and state of the entry
    struct Entry {
        K key;         // Key of the entry
        V value;       // Value of the entry
        int state;     // State of the entry: 0 (empty), 1 (occupied), 2 (deleted)

        Entry() : state(0) {}  // Default constructor, initializes state to empty
        Entry(const K& k, const V& v) : key(k), value(v), state(1) {}  // Parameterized constructor, initializes key, value, and sets state to occupied
    };

    int capacity;           // Maximum capacity of the hash table
    int size;               // Current number of elements in the hash table
    vector<Entry> table;    // Vector to hold the entries

    // Hash function to compute the hash value for a given key
    int hash(const K& key) {
        // Simple hash function for strings. For more general usage, std::hash can be used.
        int sum = 0;
        for (char c : key) {
            sum += int(c);
        }
        return abs(sum) % capacity;
    }

    // Linear probing function to handle collisions
    int linearProbe(int h, int i) const {
        return (h + i) % capacity;
    }

public:
    // Constructor to initialize the hash table with a given capacity
    HashTable(int capacidade) : capacity(capacidade), size(0) {
        table.assign(capacity, Entry());  // Initialize the table with empty entries
    }

    // Function to find the index associated with a given key
    int find(const K& k) {
        int h = hash(k);  // Compute the hash value for the key
        int pos = h;

        for(int i = 0; i < capacity; i++) {  // Iterate through the table to find the key
            pos = linearProbe(h, i);  // Compute the next position using linear probing
            if(table[pos].state == 1 && table[pos].key == k) {  // If the key is found
                return pos;  // Return the index of the entry
            }
            else if(table[pos].state == 0){  // If an empty entry is found
                break;  // Exit the loop as the key cannot be in the table
            }
        }
        throw std::runtime_error("Key not found");
    }

    // Function to insert a key-value pair into the hash table
    void insert(const K& k, const V& v) {
        if (size < capacity){  // Check if there is space in the table
            try {
                find(k);  // Check if the key already exists
                return;  // Do not insert if the key exists
            } catch (std::runtime_error& e) {
                // Continue to insertion if the key does not exist
            }

            int h = hash(k);  // Compute the hash value for the key
            int pos = h;
            int i = 0;

            // Find the next available position using linear probing
            while(table[pos].state != 0 && table[pos].state != 2) {
                pos = linearProbe(h, ++i);
            }

            // Insert the key-value pair at the available position
            table[pos] = Entry(k, v);
            table[pos].state = 1;  // Mark the entry as occupied
            size++;  // Increment the size of the table
        }
    }

    // Function to remove a key-value pair from the hash table
    void remove(const K& k) {
        int h = hash(k);  // Compute the hash value for the key
        int pos = h;
        int i = 0;

        try {
            find(k);  // Check if the key exists
            // Iterate through the table to find the key
            while (table[pos].state != 0) {
                pos = linearProbe(h, ++i);
                if (table[pos].state == 1 && table[pos].key == k) {  // If the key is found
                    table[pos].state = 2;  // Mark the entry as deleted
                    size--;  // Decrement the size of the table
                    return;
                }
            }
        } catch (std::runtime_error& e) {
            throw runtime_error("Key not found");  // Throw an exception if the key is not found
        }
    }

    // Function to clear the hash table
    void clear() {
        table.assign(capacity, Entry());  // Reinitialize the table with empty entries
        size = 0;  // Reset the size to 0
    }
};

int main() {
    int cases;
    cin >> cases; // Lê o número de casos
    HashTable<string, string> hashTable(cases); // Inicializa a tabela hash com a capacidade fornecida

    string command, key;
    while (cin >> command && command != "fim") {
        cin >> key; // Lê a chave

        if (command == "add") {
            hashTable.insert(key, key); // Insere a chave na tabela
        } else if (command == "rmv") {
            hashTable.remove(key); // Remove a chave da tabela
        } else if (command == "sch") {
            try {
                int index  = hashTable.find(key);
                cout << key << " " << index << endl; // Imprime a chave e o índice se encontrada
            } catch (runtime_error& e) {
                cout << key << " " << -1 << endl; // Imprime a chave e -1 se não encontrada
            }
        }
    }
    return 0;
}
