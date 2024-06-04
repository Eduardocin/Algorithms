#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template<typename K, typename V >
class HashTable{
private:
    struct Entry{
        K key;
        V value;
        int state; // 0: empty, 1:occupied
        Entry():state(0){}
        Entry(K key, V value):key(key), value(value),state(1){}
    };

    int size;
    int capacity;
    vector<Entry> table;

    int hash(K key){
        int temp = (int) floor((((double) key) / ((double) capacity))); 
        return (key - (capacity * temp)); 
    }
    
    int pseudo_random(int h, int i){
        return (h + perm[i - 1]) % capacity;
    }

public:
    vector<int> perm;
    
    HashTable(int capacity):size(0), capacity(capacity){
        table.assign(capacity, Entry());
        perm.resize(capacity-1);
    }

    V* find(const K& key){
        int h = hash(key);
        int pos = h;
        V* result = new V[2]; // allocate array for result
        if(table[pos].state == 1 && table[pos].key == key){
            result[0] = pos;
            result[1] = table[pos].value;
            return result;
        }
        else{
            for(int i = 1; i < capacity; i++){
                pos = pseudo_random(h, i);
                if(table[pos].state == 1 && table[pos].key == key){
                    result[0] = pos;
                    result[1] = table[pos].value;
                    return result;
                }
                else if(table[pos].state == 0){
                    result[0] = -1;
                    result[1] = V();
                    return result;
                }
            }
        }
        result[0] = -1;
        result[1] = V();
        return result;
    }

    void insert(const K& key, const V& value){
        
        if(size < capacity){
            V* result = find(key);
            if(result[0] != -1){
                delete[] result; // deallocate memory
                return;
            }
            delete[] result; // deallocate memory

            int h = hash(key);
            int pos = h;
            if(table[pos].state == 0){
                table[pos] = Entry(key, value);
                size++;
                return;
            }else{
                for(int i = 1; i < capacity; i++){
                    pos = pseudo_random(h, i);
                    if(table[pos].state == 0 ){
                        table[pos] = Entry(key, value);
                        size++;
                        return;
                    }
                }
            }
        }
    }
};

int main(){
    int tam_arr_perm, value_perm, num_operations, key, value;
    string command;
    
    while(true){
        cin >> tam_arr_perm;
        if(tam_arr_perm == 0){break;}

        HashTable<int, int> table(tam_arr_perm);

        for(int i = 0; i < tam_arr_perm-1; i++){
            cin >> value_perm;
            table.perm[i] = value_perm;
        }

        cin >> num_operations;
        for(int i = 0; i < num_operations; i++){
            cin >> command;
            if(command == "add"){
                cin >> key >> value;
                table.insert(key, value);
            }
            if(command == "find"){
                cin >> key;
                int* result = table.find(key);
                if(result[0] != -1){
                    cout << result[0] << " " << result[1] << endl;
                }
                else{
                    cout << -1 << endl;
                }
                delete[] result; // deallocate memory
            }
        }
    }

    return 0;
}
