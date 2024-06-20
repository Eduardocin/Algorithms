#include <iostream>
#include <vector>

using namespace std;

// Avl Tree
template<typename K>
class AvlTree {
private:
    struct Node {
        K key;
        Node* left;
        Node* right;
        int height;
        int sizeSubTrees;

        Node(K key) : key(key), left(nullptr), right(nullptr), height(0), sizeSubTrees(1) {}
        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* root;

    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    int sizeSubTrees(Node* node) {
        if (node == nullptr) return 0;
        return node->sizeSubTrees;
    }


    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node*  root) {
        Node* left = root->left;
        Node* leftRight = left->right;

        left->right = root;
        root->left = leftRight;

        root->height = 1 + max(height(root->left), height(root->right));
        left->height = 1 + max(height(left->left), height(left->right));

        root->sizeSubTrees = sizeSubTrees(root->left) + sizeSubTrees(root->right) + 1;
        left->sizeSubTrees = sizeSubTrees(left->left) + sizeSubTrees(left->right) + 1;

        return left;
    }

    Node* leftRotate(Node* root) {
        Node* right = root->right;
        Node* rightLeft = right->left;

        right->left = root;
        root->right = rightLeft;

        root->height = 1 + max(height(root->left), height(root->right));
        right->height = 1 + max(height(right->left), height(right->right));

        root->sizeSubTrees = sizeSubTrees(root->left) + sizeSubTrees(root->right) + 1;
        right->sizeSubTrees = sizeSubTrees(right->left) + sizeSubTrees(right->right) + 1;


        return right;
    }

    Node* insertHelp(Node* node, int key) {
        if (node == nullptr) return new Node(key);


        if(node->key > key){
            node->left = insertHelp(node->left, key);
        }
        else{
            node->right = insertHelp(node->right, key);
        }

        node->height = 1 + max(height(node->left), height(node->right));
        node->sizeSubTrees = 1 + sizeSubTrees(node->left) + sizeSubTrees(node->right);

        int balance = getBalance(node);

        // make rotations to balance tree
        if(balance < -1 && key >= node->right->key){
            return leftRotate(node);
        }
        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }
        if(balance > 1 && key >= node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }


        return node;
    }


    int findIndexHelp(Node* node, int key, int& index) {
        if (node == nullptr) return -1;
        
        if (key == node->key) {
            index += sizeSubTrees(node->left);
            return index;
        }
        if (key < node->key) {
            return findIndexHelp(node->left, key, index);
        } else {
            index += sizeSubTrees(node->left) + 1;
            return findIndexHelp(node->right, key, index);
        }
    }

public:
    AvlTree() : root(nullptr) {}
    
    ~AvlTree() {
        delete root;
    }

    void insert(int key) {
        root = insertHelp(root, key);
    }

    int findIndex(K key) {
        int index = 0;
        int result = findIndexHelp(root, key, index);
        return result == -1 ? -1 : index;
    }
};

int main() {
    int queries;
    cin >> queries;
    AvlTree<int>* tree = new AvlTree<int>();

    for (int i = 0; i < queries; i++) {
        int command, value;
        cin >> command;

        if (command == 1) {
            cin >> value;
            tree->insert(value);
        } else if (command == 2) {
            cin >> value;
            int index = tree->findIndex(value);
            if (index == -1) {
                cout << "Data tidak ada" << endl;
            } else {
                cout << index + 1 << endl;
            }
        }
    }

    delete tree;
    return 0;
}
