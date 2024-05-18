#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename E>
struct ArrayList{
private:
    int max_size;
    int size;
    int curr;
    E* array;

public:
    ArrayList(int tamanho){
        max_size = tamanho;
        size = curr = 0;
        array = new E[max_size];
    }

    void insert(E value){
        if(size >= max_size){throw std::runtime_error("Array is full");}
        int i = size;
        while(i>curr){
            array[i] = array[i - 1];
            i--;
        }
        array[curr] = value;
        size++;
    }

    void next() {
        if (curr < size - 1) { curr++; }
    }
    
    void prev(){
        if(curr > 0) { curr--;}
    }

    int count(E value){
        int count = 0;
        for(int i = 0; i < size; i++){
            if(array[i] == value){
                count++;
            }
        }
        return count;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << array[i] << endl;
        }
        cout << endl;
    }

    void printreverse(){
        for(int i = size - 1; i >= 0; i--){
            cout << array[i] << endl;
        }
        cout << endl;
    }

    int length(){
        return size;
        }

    E remove(){
        if ((curr < 0) || ( curr >= size)){ throw std::runtime_error("Index out of bounds");}
        int i = curr;
        E it = array[curr];
        while(i < size - 1){
            array[i] = array[i + 1];
            i++;
        }
        size--;
        return it;
    }
};



int main(){
    
    int c, n, value;
    string inputs;
    //inputss num de casos
    cin >> c;

    for(int i = 0; i < c; i++){
        ArrayList<int> countList(1000);
        ArrayList<int> list(1000);
        // inputss numero de operações
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> inputs;
            if(inputs == "insert"){
                cin >> value;
                list.insert(value);
            }else if(inputs == "remove"){
                list.remove();
            }else if(inputs == "next"){
                list.next();
            }else if(inputs == "prev"){
                list.prev();
            }else if(inputs == "count"){
                cin >> value;
                countList.insert(list.count(value));}
        }

    cout << "Caso "<< i+1 << ":" << endl;

    countList.printreverse();    
    
    }


    return 0;
}
