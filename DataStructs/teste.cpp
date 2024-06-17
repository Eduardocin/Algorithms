#include <iostream>

using namespace std;

//dict AVL
template <typename K>
class AvlTree{
private:
    struct Node{
        K key;
        int height;
        Node* left;
        Node* right;

        Node(K key): key(key), height(0), left(nullptr), right(nullptr){}

        ~Node(){
            delete left;
            delete right;
        }
    };

    Node* root;
    int size;

    Node* rightRotate(Node* root){
        //ponteiros auxiliares
        Node* left = root->left;
        Node* leftRight = left->right;

        //rotacionar
        left->right = root;
        root->left = leftRight;

        //atualizar alturas
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

    Node* insertHelp(Node* root,const K& key){
        
        //check if root is null 
        if(root == nullptr){
            size++; // Increase size when a new node is inserted
            return new Node(key);
        }

        //inserir na subarvore esquerda ou direita de acordo com o valor do nó
        if(root->key > key){
            root->left = insertHelp(root->left, key);
        }
        else{
            root->right = insertHelp(root->right, key);
        }

        //atualizar a altura do nó
        root->height = 1 + max(height(root->left), height(root->right));
        
        //obter o fator de balanceamento do nó
        int balance = getBalance(root);
        
        // possiveis rotacoes
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
            cout << root->key << endl;
            preOrderHelp(root->left);
            preOrderHelp(root->right);
        }
    }


public:
    AvlTree(){
        root = nullptr;
        size = 0;
    }

    ~AvlTree(){
        delete root;
    }


    int height(Node* node){
        if(node == nullptr){
            return -1;
        }
        return node->height;
    }
    
    int getBalance(Node* node){
        if(node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }


    void preorder(){
        preOrderHelp(root);
    }

    void insert(const K& key){
        root = insertHelp(root, key); // Update root with the new subtree
    }

};


int main(){
    int numcasos;
    cin >> numcasos;
    for(int i = 0; i < numcasos; i ++){
        int numelemento;
        AvlTree<int>* tree = new AvlTree<int>();
        cin >> numelemento;
        for(int j = 0; j < numelemento; j ++){
            int elemento;
            cin >> elemento;
            tree->insert(elemento);
        }
        
        tree->preorder();
        cout << "END" << endl;
        delete tree; // Make sure to delete the tree to free memory
    }

    return 0;
}
