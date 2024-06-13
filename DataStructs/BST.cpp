#include <iostream>
#include <cassert>

using namespace std;

template<typename T, typename V>
class BST{
private:
    
    struct Node{
        T key;
        V value;
        Node* left;
        Node* right;

        Node(T key, V value):key(key), value(value), left(nullptr), right(nullptr){};

        //destructor
        ~Node(){
            delete left;
            delete right;
        }
    };

    Node* root;
    int size;

    V findhelp(Node*& root, T key){
        if(root == nullptr){
            return -1;
        }
        if(root->key > key){
            return findhelp(root->left, key);
        }
        else if(root->key == key){
            return root->value;
        }
        else{
            return  findhelp(root->right, key);
        }
    }

    Node* inserthelp(Node*& root, T key, V value){
        if(root == nullptr){
            return new Node(key, value);
        }
        
        if(root->key > key){
            root->left = inserthelp(root->left, key, value);
        }
        else{
            root->right = inserthelp(root->right, key, value);
        }
        return root;
    }

    Node* removehelp(Node*& root, T key){
        if(root == nullptr){
            return nullptr;
        }

        if(root->key > key){
            root->left = removehelp(root->left, key);
        }
        else if(root->key < key){
            root->right = removehelp(root->right, key);
        }
        else{
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }
            else{
                Node* temp  = getmin(root->right);
                root->value = temp->value;
                root->key = temp->key;
                root->right = deletemin(root->right);
            }
        }
    }

public:
    BST():root(nullptr), size(0){};




    V find(const T& key){
        return findhelp(root, key);
    }

    void insert(const T& key, const V& value){
        root = inserthelp(root, key, value);
        size++;
    }

    Node* getmin(Node*& root){
        if(root->left == nullptr){
            return root;
        }
        return getmin(root->left);
    }
    Node* deletemin(Node*& root){
        if(root->left == nullptr){
            return root->right;
        }
        root->left = deletemin(root->left);
        return root;
    }

    V remove(const T& key){
        V temp = findhelp(root, key);
        
        if(temp != -1){
            root = removehelp(root, key);
            size--;
        }

        return temp;
    }


    ~BST(){
        delete root;
    }

};

int main(){
    BST<int, int> bst;

    // Teste de inserção
    bst.insert(10, 100);
    bst.insert(20, 200);
    bst.insert(5, 50);
    bst.insert(15, 150);

    // Teste de busca
    assert(bst.find(10) == 100);
    assert(bst.find(20) == 200);
    assert(bst.find(5) == 50);
    assert(bst.find(15) == 150);
    assert(bst.find(25) == -1); 

    // Teste de remoção
    assert(bst.remove(10) == 100);
    assert(bst.find(10) == -1); 
    assert(bst.remove(20) == 200);
    assert(bst.find(20) == -1); 

    cout << "Todos os testes passaram!" << endl;

    return 0;
}