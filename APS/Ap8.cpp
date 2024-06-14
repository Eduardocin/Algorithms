#include <iostream>
#include <string>

using namespace std;

//Avl Tree
template<typename K>
class AvlTree{
private:
    struct Node{
        K key;
        Node* left;
        Node* right;
        int height;

        Node(K key):key(key),left(nullptr),right(nullptr), height(0){}
        ~Node(){
            delete left;
            delete right;
        }
    };

    Node* root;

    //obter a altura de um nó
    int height(Node* root){
        if(root == nullptr) return -1;
        return root->height;
    }

    //obter o fator de balanceamento de um nó
    int getBalance(Node* root){
        if(root == nullptr) return 0;
        return height(root->left) - height(root->right);
    }

    Node* rightRotate(Node* root){
        Node* left = root->left;
        Node* leftRight = left->right;

        //rotacionar
        left->right = root;
        root->left = leftRight;

        root->height = max(height(root->left), height(root->right)) + 1;
        left->height = max(height(left->left), height(left->right)) + 1;

        return left;
    }


    Node* leftRotate(Node* root){
        Node* right = root->right;
        Node* rightLeft = right->left;

        //rotacionar
        right->left = root;
        root->right = rightLeft;

        //atualizar alturas
        root->height = max(height(root->left), height(root->right)) + 1;
        right->height = max(height(right->left), height(right->right)) + 1;

        return right;
    }

    Node* insertHelp(Node* root, int key){
        if(root == nullptr){
            return new Node(key);
        }

        if(root->key > key){
            root->left = insertHelp(root->left, key);
        }
        else{
            root->right = insertHelp(root->right, key);
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if(balance < -1 && key >= root->right->key){
            return leftRotate(root);
        }

        if(balance > 1 && key < root->left->key){
            return rightRotate(root);
        }

        if(balance > 1 && key >= root->left->key){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && key < root->right->key){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrderHelp(Node* root){
        if(root != nullptr){
            cout << root->key << " ";
            preOrderHelp(root->left);
            preOrderHelp(root->right);
        }
    }

    void inOrderHelp(Node* root){
        if(root != nullptr){
            inOrderHelp(root->left);
            cout << root->key << " ";
            inOrderHelp(root->right);
        }
    }

    void postOrderHelp(Node* root){
        if(root != nullptr){
            postOrderHelp(root->left);
            postOrderHelp(root->right);
            cout << root->key << " ";
        }
    }

public:
    AvlTree():root(nullptr){}
    ~AvlTree(){
        delete root;
    }

    void insert(int key){
        root = insertHelp(root, key);
    }

    void preOrder(){
        preOrderHelp(root);
    }
    void inOrder(){
        inOrderHelp(root);
    }
    void postOrder(){
        postOrderHelp(root);
    }

}; 


int main(){
    string command;
    int numoperacoes, value;
    AvlTree<int>* avl = new AvlTree<int>();

    cin >> numoperacoes;
    for(int i = 0; i < numoperacoes; i++){
        cin >> command;
        if(command == "insert"){
            cin >> value;
            avl->insert(value);
        }
        else if(command == "pre"){
            cout << endl;
            avl->preOrder();
        }
        else if(command == "in"){
            cout << endl;
            avl->inOrder();
        }
        else if(command == "post"){
            cout << endl;
            avl->postOrder();
        }
    }

    delete avl;
    return 0;
}