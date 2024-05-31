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
    int hash(K key) {
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

    // Function to find the value associated with a given key
    V find(const K& k) {
        int h = hash(k);  // Compute the hash value for the key
        int pos = h;

        for(int i = 0; i < capacity; i++) {  // Iterate through the table to find the key
            pos = linearProbe(h, i);  // Compute the next position using linear probing
            if(table[pos].state == 1 && table[pos].key == k) {  // If the key is found
                return table[pos].value;  // Return the associated value
            }
            else if(table[pos].state == 0){  // If an empty entry is found
                throw std::runtime_error("Key not found");  // Throw an exception
            }
        }
    }

    // Function to insert a key-value pair into the hash table
    void insert(const K& k, const V& v) {
        if (size < capacity){  // Check if there is space in the table
            try{
                find(k);  // Check if the key already exists
                return;  // Do not insert if the key exists
            }catch (std::runtime_error& e) {
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
            cout << "Value: " << v << " inserted in position: " << pos << endl;
        }
    }

    // Function to remove a key-value pair from the hash table
    void remove(const K& k) {
        int h = hash(k);  // Compute the hash value for the key
        int pos = h;
        int i = 0;

        try{
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
        }catch (std::runtime_error& e) {
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