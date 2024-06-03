// OPEN HASH IMPLEMENTATION
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;

template <typename K, typename V>
class HashTable {
private:
    // Structure to represent a key-value pair entry in the hash table
    struct Entry {
        K key; // Key of the entry
        V value; // Value associated with the key
        Entry() {} // Default constructor
        Entry(const K& k, const V& v) : key(k), value(v) {} // Constructor to initialize key and value
    };

    int capacity; // Capacity of the hash table (number of buckets)
    int size; // Current number of elements in the hash table
    vector<list<Entry>> table; // Vector of lists, where each list represents a bucket in the hash table

    // Hash function to calculate the index of the bucket for a given key
    int hash(K key) {
        return key % 10; // Simple modulo hash function
    }

public:
    // Constructor to initialize a hash table with a given capacity
    HashTable(int capacity) : capacity(capacity), size(0) {
        // Initialize the table with 'capacity' empty lists
        table.assign(capacity, list<Entry>());
    }

    // Find the value associated with a given key
    V find(const K& key) {
        int h = hash(key); // Calculate the hash index for the key
        // Iterate through the list at the hash index
        for (auto& e : table[h]) {
            // If the key matches, return the associated value
            if (e.key == key) {
                return e.value;
            }
        }
        // If the key is not found, throw a runtime error
        throw runtime_error("Key not found");
    }

    // Insert a key-value pair into the hash table
    void insert(const K& key, const V& value) {
        try {
            // Try to find the key. If found, it means the key already exists and we don't need to insert.
            find(key);
            return; // Key already exists, so return
        } catch (runtime_error& e) {
            // If the key is not found, it's safe to insert
            int pos = hash(key); // Calculate the hash index for the key
            auto& l = table[pos]; // Get the list at the calculated hash index
            // Push the new Entry (key-value pair) to the back of the list
            l.push_back(Entry(key, value));
            // Increment the size of the hash table
            size++;
        }
    }

    // Remove the key-value pair associated with a given key
    void remove(const K& key) {
        // Check if the key exists in the table
        try {
            find(key); // Try to find the key
            int pos = hash(key); // Calculate the hash index for the key
            list<Entry>& l = table[pos]; // Get the list at the calculated hash index
            // Iterate through the list
            for (auto it = l.begin(); it != l.end(); ++it) {
                // If the key matches, erase the entry from the list
                if (it->key == key) {
                    l.erase(it);
                    // Decrement the size of the hash table
                    size--;
                    return; // Return after removing the key-value pair
                }
            }
        } catch (runtime_error& e) {
            // If the key is not found, throw a runtime error
            throw runtime_error("Key not found");
        }
    }

    // Clear the hash table by removing all entries
    void clear() {
        // Assign 'capacity' empty lists to the table, effectively clearing it
        table.assign(capacity, list<Entry>());
        // Set the size to 0
        size = 0;
    }

    // Get the current size of the hash table
    int getSize() {
        return size;
    }

    // Method to print the content of the hash table
    void printTable() {
        // Iterate through each bucket in the table
        for (int i = 0; i < capacity; i++) {
            // Print the index of the bucket
            cout << i << " ";
            // Iterate through the list at the current bucket index
            for (const auto& node : table[i]) {
                // Print the key of each entry in the bucket
                cout << node.key << " ";
            }
            cout << endl; // Print a newline after each bucket
        }
    }

    // Method to get and print all the keys in the hash table
    void getKeys() {
        cout << "Keys: ";
        // Iterate through each bucket in the table
        for (int i = 0; i < capacity; i++) {
            // Iterate through the list at the current bucket index
            for (const auto& node : table[i]) {
                // Print the key of each entry, only if it's not zero
                if (node.key != 0) {
                    cout << node.key << " ";
                }
            }
        }
        cout << endl; // Print a newline after all keys
    }

};

int main() {
    // Create a HashTable with capacity 10
    HashTable<int, string> hashTable(10);

    // Insert some key-value pairs
    hashTable.insert(1, "one");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(4, "four");
    hashTable.insert(5, "five");

    // Find and print the value associated with a key
    try {
        cout << "Value for 'two': " << hashTable.find(2) << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    // Remove a key-value pair
    hashTable.remove(2);

    // Find and print the value associated with a key that was removed
    try {
        cout << "Value for 'two': " << hashTable.find(2) << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    // Insert a new key-value pair
    hashTable.insert(2, "two");

    // Print the size of the HashTable
    cout << "Size of the HashTable: " << hashTable.getSize() << endl;
    hashTable.getKeys();
    // Clear the HashTable
    hashTable.clear();

    // Print the size of the HashTable after clearing
    cout << "Size of the HashTable after clearing: " << hashTable.getSize() << endl;

    return 0;
}