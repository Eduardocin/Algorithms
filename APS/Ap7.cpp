#include <iostream>
#include <string>
using namespace std;


template<typename K, typename V>
class BST{
private:

    struct Node{
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K key, V value):key(key), value(value), left(nullptr), right(nullptr){}

        ~Node(){
            delete left;
            delete right;
        }
    };

    Node* root;
    int size;

    V findhelp(Node*& root, K chave){
        if(root == nullptr){
            return -1;
        }
        if(root->key > chave){
            return findhelp(root->left, chave);
        }
        else if(root->key == chave){
            return root->value;
        }
        else{
            return findhelp(root->right, chave);
        }
    }

    Node* inserthelp(Node*& root, K chave, V value){
        if(root == nullptr){
            return new Node(chave, value);
        }
        if(root->key > chave){
            root->left = inserthelp(root->left, chave, value);
        }
        else{
            root->right = inserthelp(root->right, chave, value);
        }
        return root;
    }

    void preorderhelp(Node* root){
        if(root != nullptr){
            cout << root->key << " ";
            preorderhelp(root->left);
            preorderhelp(root->right);
        }
    }
    void inorderhelp(Node* root){
        if(root != nullptr){
            inorderhelp(root->left);
            cout << root->key << " ";
            inorderhelp(root->right);
        }
    }

    void postorderhelp(Node* root){
        if(root != nullptr){
            postorderhelp(root->left);
            postorderhelp(root->right);
            cout << root->key << " ";
        }
    }

public:
    BST():root(nullptr), size(0){}

    V find(const K& key){
        return findhelp(root, key);
    }

    void insert(const K& key, const V& value){
        root = inserthelp(root, key, value);
        size++;
    }
    
    void preorder(){
        preorderhelp(root);
    }

    void inorder(){
        inorderhelp(root);
    }

    void postorder(){
        postorderhelp(root);
    }

    ~BST(){}
};



int main() {
    string command;
    int numoperacoes, value;
    BST<int, int>* bst = new BST<int, int>();

    cin >> numoperacoes;
    for(int i = 0; i < numoperacoes; i++){
        cin >> command;
        if(command == "insert"){
            cin >> value;
            bst->insert(value, value);
        }
        else if(command == "pre"){
            bst->preorder();
            cout << endl;
        }
        else if(command == "in"){
            bst->inorder();
            cout << endl;
        }
        else if(command == "post"){
            bst->postorder();
            cout << endl;
        }

    }

    delete bst;


    return 0;
}