#include <iostream>

using namespace std;

template<typename K, typename V>
class BST {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K key, V value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    void preorderHelper(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
    }

    void inorderHelper(Node* root) {
        if (root != nullptr) {
            inorderHelper(root->left);
            cout << root->key << " ";
            inorderHelper(root->right);
        }
    }

    void postorderHelper(Node* root) {
        if (root != nullptr) {
            postorderHelper(root->left);
            postorderHelper(root->right);
            cout << root->key << " ";
        }
    }

    Node* insertHelper(Node*& root, K key, V value) {
        if (root == nullptr) {
            return new Node(key, value);
        }
        if (key < root->key) {
            root->left = insertHelper(root->left, key, value);
        } else {
            root->right = insertHelper(root->right, key, value);
        }
        return root;
    }

public:
    BST() : root(nullptr), size(0) {}

    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void postorder() {
        postorderHelper(root);
    }

    void insert(K key, V value) {
        root = insertHelper(root, key, value);
        size++;
    }

    ~BST() {}
};

int main() {
    int tam;
    cin >> tam;

    if (tam > 0) {
        BST<int, int>* bst = new BST<int, int>();
        for (int i = 0; i < tam; i++) {
            int value;
            cin >> value;
            bst->insert(value, value);
        }

        cout << "Pre order : ";
        bst->preorder();

        cout << "In order  : ";
        bst->inorder();

        cout << "Post order: ";
        bst->postorder();

        delete bst;

    }

    return 0;
}
