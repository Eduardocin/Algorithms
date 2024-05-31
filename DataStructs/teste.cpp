#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Implementation of closed hash table with linear probing
template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        int state;  // 0: empty, 1: occupied, 2: deleted

        Entry() : state(0) {}  // Default constructor
        Entry(const K& k, const V& v) : key(k), value(v), state(1) {}  // Parameterized constructor
    };

    int capacity;
    int size;
    vector<Entry> table;

    // Hash function
    int hash(K key) {
        // This is a simple example for strings. For a more generic approach, std::hash could be used.
        int sum = 0;
        for (char c : key) {
            sum += int(c);
        }
        return abs(sum) % capacity;
    }


    // Linear probing function
    int linearProbe(int h, int i) const {
        return (h + i) % capacity;
    }

public:
    HashTable(int capacidade) : capacity(capacidade), size(0) {
        table.assign(capacity, Entry());
    }

    V find(const K& k) {
        int h = hash(k);
        int pos = h;

    
        for(int i = 0; i < capacity; i++) {
            pos = linearProbe(h, i);
            if(table[pos].state == 1 && table[pos].key == k) {
                return table[pos].value;
            }
            else if(table[pos].state == 0){
                throw std::runtime_error("Key not found");
            }
        }
    }


    void insert(const K& k, const V& v) {
        if (size < capacity){
            
            try{
                find(k);
                return; // do not insert
            }catch (std::runtime_error& e) {
                // continue to insertion
            }

            int h = hash(k);
            int pos = h;
            int i = 0;
            
            while(table[pos].state!= 0 && table[pos].state!= 2) {
                pos = linearProbe(h, ++i);
            }

            table[pos] = Entry(k, v);
            table[pos].state = 1;
            size++;
            cout << "Value: " << v << " inserted in position: " << pos << endl;
        }
    }

    void remove(const K& k) {
        int h = hash(k);
        int pos = h;
        int i = 0;

        try{
            find(k); // verifica se a chave existe
            while (table[pos].state != 0) {
                pos = linearProbe(h, ++i);
                if (table[pos].state == 1 && table[pos].key == k) {
                    table[pos].state = 2;  // Mark as deleted
                    size--;
                    return;
                }
            }
        }catch (std::runtime_error& e) {
            throw runtime_error("Key not found");  // If the key is not found
        }

    }

    void clear() {
        table.assign(capacity, Entry());
        size = 0;
    }
};

int main() {
    // Initialize the hash table with the provided capacity
    HashTable<string, string> teste(10);

    // Insert some keys and values
    teste.insert("abcd", "1234");
    teste.insert("badc", "1234");
    teste.insert("abdc", "1234");
    teste.insert("bacd", "1224");

    // Find a key and print its value
    try {
        cout << "Value for 'bacd': " << teste.find("bacd") << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    // Remove a key and find it again
    teste.remove("abdc");
    try {
        cout << "Value for 'abdc': " << teste.find("abdc") << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    // Insert a new key-value pair
    teste.insert("abdc", "1233");

    return 0;
}