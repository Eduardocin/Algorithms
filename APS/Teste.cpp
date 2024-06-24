#include <iostream>

using namespace std;
// Avl tree
template<class T>
class Avltree{

private:
    struct Node{
        T key;
        Node* left;
        Node* right;
        int height;

        Node(T key):key(key),left(nullptr),right(nullptr),height(0){}

        ~Node{
            delete left;
            delete right;
        }
    };

    Node* root;
    
    int height(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }


    int getBalance(Node* node){
        if(node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* node){
        Node* left = node->left;
        Node* leftRight = left->right;

        left->right = node;
        node->left = leftRight;

        node->height = max(height(node->left),height(node->right)) + 1;
        left->height = max(height(left->left),height(left->right)) + 1;

        return left;
    }

    Node* leftRotate(Node* node){
        Node* right = node->right;
        Node* rightLeft = right->left;

        right->left = node;
        node->right = rightLeft;

        node->height = max(height(node->left),height(node->right)) + 1;
        right->height = max(height(right->left),height(right->right)) + 1;

        return right;
    }

public: 

    



};