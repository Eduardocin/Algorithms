#include <iostream>

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
        int size;

        Node(K key) : key(key), left(nullptr), right(nullptr), height(0), size(1){}
        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* root;


    int size(Node* node) {
        if (node == nullptr) return 0;
        return node->size;
    }
    
    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* root) {
        Node* left = root->left;
        Node* leftRight = left->right;

        left->right = root;
        root->left = leftRight;

        root->height = 1 + max(height(root->left), height(root->right));
        left->height = 1 + max(height(left->left), height(left->right));

        root->size = 1 + size(root->left) + size(root->right);
        left->size = 1 + size(left->left) + size(left->right);


        return left;
    }

    Node* leftRotate(Node* root) {
        Node* right = root->right;
        Node* rightLeft = right->left;

        right->left = root;
        root->right = rightLeft;

        root->height = 1 + max(height(root->left), height(root->right));
        right->height = 1 + max(height(right->left), height(right->right));

        root->size = 1 + size(root->left) + size(root->right);
        right->si4ze = 1 + size(right->left) + size(right->right);

        return right;
    }

    Node* insertHelp(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (node->key > key) {
            node->left = insertHelp(node->left, key);
        } else {
            node->right = insertHelp(node->right, key);
        }

        node->height = 1 + max(height(node->left), height(node->right));
        node->size = 1 + size(node->left) + size(node->right);

        int balance = getBalance(node);

        // make rotations to balance tree
        if (balance < -1 && key >= node->right->key) {
            return leftRotate(node);
        }
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }
        if (balance > 1 && key >= node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    int findIndexHelp(Node* node, K key) {
        if (node == nullptr) {
            return -1;
        }

        if (key < node->key) {
            return findIndexHelp(node->left, key);
        } else if (key > node->key) {
            int rightIndex = findIndexHelp(node->right, key);
            return (rightIndex == -1) ? -1 : size(node->left) + 1 + rightIndex;
        } else {
            return size(node->left);
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

    int findIndex(int key) {
        return findIndexHelp(root, key);
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