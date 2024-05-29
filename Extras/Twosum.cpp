#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename K, typename V>
class HashTable{
private:
    struct Entry{
        K key;
        V value;
        bool isDeleted;
        bool isEmpty;
        Entry(): isDeleted(false), isEmpty(true) {}
        Entry(K key, V value): key(key), value(value), isDeleted(false), isEmpty(false) {}
    };

    int capacity;
    int size;
    vector<Entry> table;

    int hashF(K key){
        int sum = 0;
        for(int i = 0; i < key.length(); i++){
            sum += int(key[i]);
        }
        return abs(sum) % capacity;
    }

    int linearProbing(int hash, int i){
        return (hash + i) % capacity;
    }
public:
    HashTable(int capacity): capacity(capacity), size(0){
        table.assign(capacity, Entry());}

    void find(K key){
        int hash = hashF(key);
        int pos = hash;
        int i = 0;

        while(!table[pos].isEmpty){

    }
     void insert(K key, V value){
        if(size < capacity){
            int hash = hashF(key);
            int pos = hash;
            int i = 0;

            while(!table[pos].isEmpty && !table[pos].isDeleted){
                pos = linearProbing(hash, ++i);
            }

            table[pos] = Entry(key, value);
            size++;
        }
    }

};

void insert(K key, V value){
    if(size < capacity){
        int hash = hashF(key);
        int pos = hash;
        int i = 0;

        while(!table[pos].isEmpty && !table[pos].isDeleted){
            pos = linearProbing(hash, ++i);
        }

        table[pos] = Entry(key, value);
        size++;
        cout << "Inserted at index: " << pos << endl; // Print the index where the value is inserted
    }
}