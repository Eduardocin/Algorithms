#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

template<typename K, typename V>
class HashTable{
private:
    // Estrutura para armazenar pares chave-valor
    struct Entry{
        K key;
        V value;
        Entry(K k, V v):(key(k), value(v)){}
    };

    int capacity;
    int size;
    vector<list<Entry>> table;

    int hashFunction(K key){
        return abs(key) % capacity;
    }
public:
    HashTable(int capacity): capacity(capacity, size(0)){
        table.assign(capacity, list<Entry>());
    }

    V find(K key){
        int index = hashFunction(key);
        for(const auto& entry: table[index]){
            if(entry.key == key){
                return entry.value;
            }
        }
            throw runtime_error("Key not found!");
    }

    void insert(K key, V value){
        try{
            find(key);
            return;
        }catch(const runtime_error&){

        }
        int pos = hashFunction(key);
        auto& l = table[pos];
        Entry dict(key, value);
        l.push_back(dict);
        size++;
    }

    void remove(K key){
        int index = hashFunction(key);
        auto& l = table[index];

        for(auto it = chain.begin(); it != chain.end(); ++it){
            if(it->key == key){
                l.erase(it);
                size--;
                return;
            }
        }
    }   

    
    void clear(){
        for(int i=0; i<capacity; i++){
            table[i].clear();
        }
        size = 0;
    }

    int getSize(){
        return size;
    }

};