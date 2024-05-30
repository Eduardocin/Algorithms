#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

template<typename K, typename V>
class HashTable{
private:

    struct Entry{
        K key;
        V value;
        Entry(const K& k, const V& v): key(k), value(v){}
    };

    int capacity;
    int size;
    vector<list<Entry>> table;

    int hash(const K& key){
        return abs(key) % 10;
    }

public:
    HashTable(int capacity): capacity(capacity), size(0){
        table.assign(capacity, list<Entry>());}

    V find(const K& key){
        int index = hash(key);
        for (const auto& entry : table[index]){
            if(node.key == key){
                return node.value;
            }
        }
        throw runtime_error("Key not found");
    }

    void insert(const K& key, const V& value){
        try{
            find(key);
            return;
        }catch(const runtime_error&){

        }

        int pos = hash(key);
        list<Entry>& l = table[pos];
        Entry entry(key, value);
        l.emplace_back(entry);
        size++;
    }

    void remove(const K& key){
        int pos = hash(key);
        list<Entry>& list = table[pos];
        for(auto& x : list){
            if(x.key == key){
                list.remove(x);
                size--;
                return;
            }
        }
        throw runtime_error("Key not found");

    }

    void clear(){
        table.assign(capacity, list<Entry>());
        size = 0;
    }

    int getSize() const{
        return size;
    }

    void print(){
        for(int i = 0; i < capacity; i++){
            cout << i << ": ";
            for(const auto& x : table[i]){
                cout << "(" << x.key << ", " << x.value << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }

};