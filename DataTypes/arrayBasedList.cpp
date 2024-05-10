#include <iostream>

using namespace std;

template<typename E>
struct List {
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

    void insert(E it) {
        if (listSize >= maxSize) {
            // Tratar erro, por exemplo, lançar uma exceção
            // throw std::runtime_error("List is full");
            return;
        }
        
        int i = listSize;
        while (i > curr) {
            listArray[i] = listArray[i - 1]; // shift right
            i--;
        }
        
        listArray[curr] = it;
        listSize++;
    }
};
    

template<typename E>
List<E>* create_list(int size) {
    List<E>* l = new List<E>;
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = new E[size];
    return l;
}


int main(){
    List<int>* r = create_list<int>(5);
    r->insert(2);
    r->insert(3);
    r->insert(4);
    // Exemplo de uso: imprimindo os valores da lista
    cout << "Valores da lista:" << endl;
    for (int i = 0; i < r->listSize; i++) {
        cout << r->listArray[i] << endl;
    }
    
    delete[] r->listArray;
    delete r;
    
    return 0;
}
